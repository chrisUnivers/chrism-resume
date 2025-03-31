import * as THREE from 'three'

import Stats from 'three/addons/libs/stats.module.js';

import { OrbitControls } from 'three/addons/controls/OrbitControls.js';

import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';


export const initBirdFlys = (canvas: HTMLCanvasElement) => {
    const container = document.getElementById( 'container' );

    const group = new THREE.Group();
    
    const camera = new THREE.PerspectiveCamera( 30, window.innerWidth / window.innerHeight, 1, 5000 );
    group.add(camera)
    camera.position.set( 0, 40, 250 );
    
    

    const scene = new THREE.Scene();
    scene.background = new THREE.Color().setHSL( 0.6, 0, 1 );
    scene.fog = new THREE.Fog( scene.background, 1, 5000 );

    // LIGHTS

    const mixers: { update: (arg0: number) => void; }[] = []

    const hemiLight = new THREE.HemisphereLight( 0xffffff, 0xffffff, 2 );
    hemiLight.color.setHSL( 0.6, 1, 0.6 );
    hemiLight.groundColor.setHSL( 0.095, 1, 0.75 );
    hemiLight.position.set( 0, 50, 0 );
    scene.add( hemiLight );

    const hemiLightHelper = new THREE.HemisphereLightHelper( hemiLight, 10 );
    scene.add( hemiLightHelper );

    //

    const dirLight = new THREE.DirectionalLight( 0xffffff, 3 );
    dirLight.color.setHSL( 0.1, 1, 0.95 );
    dirLight.position.set( - 1, 1.75, 1 );
    dirLight.position.multiplyScalar( 30 );
    scene.add( dirLight );

    dirLight.castShadow = true;

    dirLight.shadow.mapSize.width = 2048;
    dirLight.shadow.mapSize.height = 2048;

    const d = 50;

    dirLight.shadow.camera.left = - d;
    dirLight.shadow.camera.right = d;
    dirLight.shadow.camera.top = d;
    dirLight.shadow.camera.bottom = - d;

    dirLight.shadow.camera.far = 3500;
    dirLight.shadow.bias = - 0.0001;

    const dirLightHelper = new THREE.DirectionalLightHelper( dirLight, 10 );
    scene.add( dirLightHelper );

    // GROUND

    const groundGeo = new THREE.PlaneGeometry( 10000, 10000 );
    const groundMat = new THREE.MeshLambertMaterial( { color: 0xffffff } );
    groundMat.color.setHSL( 0.095, 1, 0.75 );

    const ground = new THREE.Mesh( groundGeo, groundMat );
    ground.position.y = - 33;
    ground.rotation.x = - Math.PI / 2;
    ground.receiveShadow = true;
    scene.add( ground );

    // SKYDOME

    const vertexSdElementId = document.getElementById( 'vertexShader' );
    const fragmentSdElementId = document.getElementById( 'fragmentShader' )

    let vertexShader;
    let fragmentShader;
    if (vertexSdElementId === null) {
        console.log("vertex shader element id is null");
    } else {
        vertexShader = vertexSdElementId.textContent
    }

    if (fragmentSdElementId === null) {
        console.log("vertex shader element id is null");
    } else {
        fragmentShader = fragmentSdElementId.textContent
    }
    
    const uniforms = {
        'topColor': { value: new THREE.Color( 0x0077ff ) },
        'bottomColor': { value: new THREE.Color( 0xffffff ) },
        'offset': { value: 33 },
        'exponent': { value: 0.6 }
    };
    uniforms[ 'topColor' ].value.copy( hemiLight.color );

    scene.fog.color.copy( uniforms[ 'bottomColor' ].value );

    const skyGeo = new THREE.SphereGeometry( 4000, 32, 15 );
    const skyMat = new THREE.ShaderMaterial( {
        uniforms: uniforms,
        vertexShader: vertexShader ?? "",
        fragmentShader: fragmentShader ?? "",
        side: THREE.BackSide
    } );

    const sky = new THREE.Mesh( skyGeo, skyMat );
    scene.add( sky );

    // MODEL
    const boxg = new THREE.BoxGeometry(14, 14, 14);
    const torusMaterial = new THREE.MeshNormalMaterial();
    const torusM = new THREE.MeshStandardMaterial( { color: 0xec4238 } );
    const cube = new THREE.Mesh(boxg, torusM);
    // cube.scale()
    cube.position.x = 30;
    cube.position.y = 8;
    cube.position.z = -20;
    
    scene.add(cube);

    const cubeone = new THREE.Mesh(boxg, torusM);
    cubeone.position.x = 30;
    cubeone.position.y = 8;
    cubeone.position.z = -200;
    scene.add(cubeone);

    
    // console.log(scene);
    const loader = new GLTFLoader();

    loader.load('/models/gltf/Flamingo.glb', function ( gltf ) {

        const mesh = gltf.scene.children[ 0 ];

        const s = 0.35;
        mesh.scale.set( s, s, s );
        mesh.position.y = 15;
        mesh.rotation.y = Math.PI;

        mesh.castShadow = true;
        mesh.receiveShadow = true;

        scene.add( mesh );
        group.add(mesh)

        const mixer = new THREE.AnimationMixer( mesh );
        mixer.clipAction( gltf.animations[ 0 ] ).setDuration( 1 ).play();
        mixers.push( mixer );
        // console.log(mixer);

    } );

    scene.add( group )
    
    // RENDERER

    const renderer = new THREE.WebGLRenderer( { canvas: canvas, antialias: true } );
    renderer.setPixelRatio( window.devicePixelRatio );
    renderer.setSize( window.innerWidth, window.innerHeight );
    renderer.setAnimationLoop( animate );
    container?.appendChild( renderer.domElement );
    renderer.shadowMap.enabled = true;
    // render
    const orbit = new OrbitControls(camera, renderer.domElement);
    
    orbit.enableDamping = true;
    orbit.enableZoom = false;

    orbit.enablePan = false;

    orbit.dampingFactor = 0.05;

    orbit.maxPolarAngle = Math.PI / 2;
    orbit.maxAzimuthAngle = Math.PI / 6;
    orbit.minAzimuthAngle = -Math.PI / 6;

    //
    
    window.addEventListener( 'resize', onWindowResize );
    
    function onWindowResize() {

        camera.aspect = window.innerWidth / window.innerHeight;
        camera.updateProjectionMatrix();
    
        renderer.setSize( window.innerWidth, window.innerHeight );
    
    }

    function animate() {
        render();
    }

    const clock = new THREE.Clock();
    function render() {

        const delta = clock.getDelta();
    
        for ( let i = 0; i < mixers.length; i ++ ) {
    
            mixers[ i ].update( delta );
    
        }        
    
        group.position.z -= 0.8;
        camera.lookAt(group.position)
        renderer.render( scene, camera );
    
    }

    
}