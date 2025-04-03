import * as THREE from 'three';

import Stats from 'three/addons/libs/stats.module.js';

import { DRACOLoader } from 'three/addons/loaders/DRACOLoader.js'
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';

import { OrbitControls } from 'three/addons/controls/OrbitControls';


import { Line2 } from 'three/addons/lines/Line2.js';
import { LineMaterial } from 'three/addons/lines/LineMaterial.js';
import { LineGeometry } from 'three/addons/lines/LineGeometry.js';
import * as GeometryUtils from 'three/addons/utils/GeometryUtils.js';

const canvas = document.querySelector("#experience");


// Models
let amyModel;

// Models Animation
let amyAnimations;

const mixers = [];

const clock = new THREE.Clock();

const sizes = {
    width: innerWidth,
    height: innerHeight
}

// Loaders
const textureLoader = new THREE.TextureLoader();

// Model Loader
const dracoLoader = new DRACOLoader();
dracoLoader.setDecoderPath("./libs/draco/");

const loader = new GLTFLoader();
loader.setDRACOLoader(dracoLoader);

const scenetexture = textureLoader.load("./textures/scene_texture.jpg");
scenetexture.flipY = false;

loader.load("./models/gltf/scenetwo.glb", (glb)=>{

    glb.scene.traverse((child) => {
        if(child.isMesh) {
            const material = new THREE.MeshBasicMaterial({
                map: scenetexture
            });
            child.material = material;
        }

        scene.add(glb.scene);
    });
});

loader.load("./models/gltf/amydances.glb", (nglb)=> {

    amyModel = nglb.scene
    amyModel.position.y = 0.05;
    scene.add(amyModel);
    amyAnimations = nglb.animations;
    amyModel.traverse((object) => {
        if (object.isMesh) {
            object.castShadow = true;
        }
    });

    
    
    setupDefaultScene();
    
});


const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera( 40, sizes.width / sizes.height, 0.1, 1000 );
// camera.position.set(12.670, 7.0, 3.530);
camera.position.set(5.989, 3.947 ,8.275);

const renderer = new THREE.WebGLRenderer({canvas: canvas, antialias: true});
renderer.setSize( sizes.width, sizes.height );
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

const ambientLight = new THREE.AmbientLight(0xffffff, 1);
scene.add(ambientLight);

const ex_geometry = new THREE.SphereGeometry( 15, 500, 500 ); 
const material = new THREE.MeshBasicMaterial( { color: 0x0e8a6e, side: THREE.BackSide } ); 
const ex_sphere = new THREE.Mesh( ex_geometry, material );

scene.add( ex_sphere );

const boxg = new THREE.BoxGeometry(0.2, 0.2, 0.2);
const boxM = new THREE.MeshStandardMaterial( { color: 0xff0000 } );
const c1 = new THREE.Mesh(boxg, boxM);
c1.position.set(-3.8, 0.3, 2);

const c2 = new THREE.Mesh(boxg, boxM);
c2.position.set(-3.0, 0.3, 3.1);

const c3 = new THREE.Mesh(boxg, boxM);
c3.position.set(-1.8, 0.3, 3.3);

const c4 = new THREE.Mesh(boxg, boxM);
c4.position.set(-0.3, 0.3, 2);

const c5 = new THREE.Mesh(boxg, boxM);
c5.position.set(-0, 0.3, 0.8);

const LINE_NB_POINTS = 42;

const entrycurve = new THREE.CatmullRomCurve3([
    new THREE.Vector3(-3.8, 0.3, 2),
    new THREE.Vector3(-3.0, 0.3, 3.1),
    new THREE.Vector3(-1.8, 0.3, 3.3),
    new THREE.Vector3(-0.3, 0.3, 2),
    new THREE.Vector3(0, 0.3, 0.8),
    new THREE.Vector3(0, 0.3, 0),
], false, "catmullrom", 0.5);

const exitcurve = new THREE.CatmullRomCurve3([
    new THREE.Vector3(0.7, 0.3, 0.6),
    new THREE.Vector3(1.4, 0.3, 0.8),
    new THREE.Vector3(2.6, 0.3, 0.0),
    new THREE.Vector3(3.5, 0.3, -1.2),
    new THREE.Vector3(3.8, 0.3, -2.5),
    new THREE.Vector3(3.2, 0.3, -3),
], false, "catmullrom", 0.5);

amyspath(entrycurve);
amyspath(exitcurve);

scene.add(c1, c2, c3, c4, c5);

const controls = new OrbitControls( camera, renderer.domElement );
controls.enableDamping = true;
controls.dampingFactor = 0.05;
controls.update()

// Functions

function setupDefaultScene() {

    const mixer = new THREE.AnimationMixer( amyModel );

    mixer.clipAction(amyAnimations[0]).play();
    mixers.push(mixer);
}

function amyspath(curve) {
    let linePoints = curve.getPoints(LINE_NB_POINTS);
    let geometry = new LineGeometry();
    let color = new THREE.Color();
    let colors = [];
    let positions = [];
    color.setHSL( 1, 1.0, 0.5, THREE.SRGBColorSpace );
    colors.push( color.r, color.g, color.b );
    Object.entries(linePoints).forEach(([key, pos])=> {
        positions.push(pos.x, pos.y, pos.z);
    })

    geometry.setPositions( positions );
    geometry.setColors( colors );

    let matLine = new LineMaterial( {

        color: 0xffffff,
        linewidth: 5, // in world units with size attenuation, pixels otherwise
        vertexColors: true,

        dashed: false,
        alphaToCoverage: true,

    } );

    let line = new Line2( geometry, matLine );
    line.computeLineDistances();
    line.scale.set( 1, 1, 1 );

    scene.add(line);
}

// Event Listeners
window.addEventListener("resize", ()=>{
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;

    // Update camera
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();

    // Update renderer
    renderer.setSize( sizes.width, sizes.height );
})

const render = () => {
    controls.update();
    const delta = clock.getDelta();
    
    for ( const mixer of mixers ) mixer.update( delta );

    renderer.render( scene, camera );

    window.requestAnimationFrame(render);
}

render();