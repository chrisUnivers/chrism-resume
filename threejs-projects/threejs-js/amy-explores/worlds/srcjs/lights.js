import * as THREE from 'three'

import { OrbitControls } from 'three/addons/controls/OrbitControls';

import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';

let camera, scene, renderer;
let mesh;
const mixers = [];
const clock = new THREE.Clock();


const group = new THREE.Group();

// threejs-projects/threejs-ts/

init();

function init() {
    const container = document.getElementById( 'container' );

    camera = new THREE.PerspectiveCamera( 30, window.innerWidth / window.innerHeight, 1, 5000 );
    camera.position.set( 0, 0, 250 );
    group.add(camera)

    scene = new THREE.Scene();
    scene.background = new THREE.Color().setHSL( 0.6, 0, 1 );
    scene.fog = new THREE.Fog( scene.background, 1, 5000 );

    const hemiLight = new THREE.HemisphereLight( 0xffffff, 0x8d8d8d, 3 );
    hemiLight.position.set( 0, 20, 0 );
    scene.add( hemiLight );

    const dirLight = new THREE.DirectionalLight( 0xffffff, 3 );
    dirLight.position.set( - 3, 10, - 10 );
    dirLight.castShadow = true;
    dirLight.shadow.camera.top = 2;
    dirLight.shadow.camera.bottom = - 2;
    dirLight.shadow.camera.left = - 2;
    dirLight.shadow.camera.right = 2;
    dirLight.shadow.camera.near = 0.1;
    dirLight.shadow.camera.far = 40;
    scene.add( dirLight );



    const loader = new GLTFLoader();

    loader.load( 'models/gltf/amydances.glb', function ( gltf ) {

        mesh = gltf.scene.children[ 0 ];

        const s = 0.35;
        // console.log(mesh);
        mesh.scale.set( s, s, s );
        mesh.position.y = 15;
        mesh.rotation.y = Math.PI;

        mesh.castShadow = true;
        mesh.receiveShadow = true;

        scene.add( mesh );

        const mixer = new THREE.AnimationMixer( mesh );
        mixer.clipAction( gltf.animations[ 0 ] ).setDuration( 1 ).play();
        mixers.push( mixer );
        

    } );



    renderer = new THREE.WebGLRenderer( { antialias: true } );
    renderer.setPixelRatio( window.devicePixelRatio );
    renderer.setSize( window.innerWidth, window.innerHeight );
    renderer.setAnimationLoop( animate );
    container.appendChild( renderer.domElement );
    renderer.shadowMap.enabled = true;


    window.addEventListener( 'resize', onWindowResize );
}


function onWindowResize() {

    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();

    renderer.setSize( window.innerWidth, window.innerHeight );

}


function animate() {

    render();
    stats.update();

}


function render() {

    const delta = clock.getDelta();

    for ( let i = 0; i < mixers.length; i ++ ) {

        mixers[ i ].update( delta );

    }
    renderer.render( scene, camera );

}