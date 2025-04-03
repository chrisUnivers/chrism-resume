import * as THREE from 'three';

import Stats from 'three/addons/libs/stats.module.js';

import { DRACOLoader } from 'three/addons/loaders/DRACOLoader.js'
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';

import { OrbitControls } from 'three/addons/controls/OrbitControls';

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

/**
 * Object.entries(textureMap).forEach(([key, path]) => {
 * const dayTexture = textureLoader.load(paths.day);
 * 
 * loadedTextures.day[key] = dayTexture;
 * 
 * const nightTexture = textureLoader.load(paths.night);
 * loadedTextures.night[key] = dayTexture;
 * })
 */

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
const camera = new THREE.PerspectiveCamera( 75, sizes.width / sizes.height, 0.1, 1000 );
camera.position.z = 5;

const renderer = new THREE.WebGLRenderer({canvas: canvas, antialias: true});
renderer.setSize( sizes.width, sizes.height );
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

const ambientLight = new THREE.AmbientLight(0xffffff, 1);
scene.add(ambientLight);

const ex_geometry = new THREE.SphereGeometry( 15, 500, 500 ); 
const material = new THREE.MeshBasicMaterial( { color: 0x0e8a6e, side: THREE.BackSide } ); 
const ex_sphere = new THREE.Mesh( ex_geometry, material );

scene.add( ex_sphere );


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