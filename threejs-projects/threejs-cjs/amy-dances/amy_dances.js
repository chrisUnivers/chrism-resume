import * as THREE from 'three';

import Stats from 'three/addons/libs/stats.module.js';

import { DRACOLoader } from 'three/addons/loaders/DRACOLoader.js'
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';

import { OrbitControls } from 'three/addons/controls/OrbitControls';


import { Line2 } from 'three/addons/lines/Line2.js';
import { LineMaterial } from 'three/addons/lines/LineMaterial.js';
import { LineGeometry } from 'three/addons/lines/LineGeometry.js';
import * as GeometryUtils from 'three/addons/utils/GeometryUtils.js';

const canvas = document.querySelector("#experience-canvas");


// Models
let amyModel, linePoints;

let modelActions = []
let isLoaded, isMixed, isReset = false;
let FADESTEPS = 0.001;
let ANIM_INDEX = 1;
let PREV_ANIM_INDEX = 1;
let WALK_INDEX = 4;
const WALK_SPEED = 1.136;
let can_scroll = true;
let multiple = 1;
const initPos = new THREE.Vector3(0, 0.3, 0);
const scrollwalkend = new THREE.Vector3(2.511, 0.3, -3);

let bodyHeight = document.body.scrollHeight;

let line, lineDistance;
let prevScroll, prevStep = 0;
let timeoutId;
let mixer;

const clock = new THREE.Clock();

const sizes = {
    width: innerWidth,
    height: innerHeight
}

// Loaders
const textureLoader = new THREE.TextureLoader();

// Model Loader
const dracoLoader = new DRACOLoader();
dracoLoader.setDecoderPath("../libs/draco/");

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
            if (child.animations.length > 0) {
                // console.log(child);
            }
            child.material = material;
        }

        scene.add(glb.scene);
    });
});

loader.load("./models/gltf/amymovestwo.glb", (nglb)=> {

    amyModel = nglb.scene
    amyModel.position.y = 0.05;
    scene.add(amyModel);
    
    amyModel.traverse((object) => {
        if (object.isMesh) {
            object.castShadow = true;
        }
    });

    const animations = nglb.animations;
    mixer = new THREE.AnimationMixer( amyModel );

    animations.forEach((anim) => {
        modelActions.push(mixer.clipAction(anim));
    })
    // modelActions[2].play();
    modelActions[ANIM_INDEX].play();
    modelActions[4].loop = THREE.LoopOnce;
    isLoaded = true;
    
    window.scrollTo(0,0);
    
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
c1.position.set(0.7, 0.3, 0.6);

const c2 = new THREE.Mesh(boxg, boxM);
c2.position.set(1.4, 0.3, 0.8);

const c3 = new THREE.Mesh(boxg, boxM);
c3.position.set(2.6, 0.3, 0.0);

const c4 = new THREE.Mesh(boxg, boxM);
c4.position.set(3.5, 0.3, -1.2);

const c5 = new THREE.Mesh(boxg, boxM);
c5.position.set(3.8, 0.3, -2.5);

const c6 = new THREE.Mesh(boxg, boxM);
c6.position.set(3.2, 0.3, -3);
// 3.60, y: 0.3, z: -2.76
const c7 = new THREE.Mesh(boxg, boxM);
c7.position.set(-3.8, 0.3, 2);

const LINE_NB_POINTS = 40;

const exitcurve = new THREE.CatmullRomCurve3([
    new THREE.Vector3(0.7, 0.3, 0.6),
    new THREE.Vector3(1.4, 0.3, 0.8),
    new THREE.Vector3(2.6, 0.3, 0.0),
    new THREE.Vector3(3.5, 0.3, -1.2),
    new THREE.Vector3(3.8, 0.3, -2.5),
    new THREE.Vector3(3.2, 0.3, -3),
    new THREE.Vector3(2.6, 0.3, -3.06),
    new THREE.Vector3(2.0, 0.3, -3.06),
    new THREE.Vector3(1.6, 0.3, -3.06),
    new THREE.Vector3(0, 0.3, -3.08),
    new THREE.Vector3(-1, 0.3, -3.08),
    new THREE.Vector3(-2.8, 0.3, -3.08),
    new THREE.Vector3(-3.6, 0.3, -2.82),
    new THREE.Vector3(-3.7, 0.3, -2.42),
    new THREE.Vector3(-3.7, 0.3, 0.42),
    new THREE.Vector3(-3.7, 0.3, 2.26),
    new THREE.Vector3(-3.7, 0.3, 3.27),
    new THREE.Vector3(-3.4, 0.3, 3.47),
    new THREE.Vector3(-3.0, 0.3, 3.47),
    new THREE.Vector3(-1.7, 0.3, 3.47),
    new THREE.Vector3(-1.0, 0.3, 3.0),
    new THREE.Vector3(-0.63, 0.3, 2.4),
    new THREE.Vector3(-0.42, 0.3, 2.0),
    new THREE.Vector3(-0.2, 0.3, 1.3),
    new THREE.Vector3(0, 0.3, 0),
], false, "catmullrom", 0.5);

// amyspath(exitcurve);
// scene.add(c6, c7);

const controls = new OrbitControls( camera, renderer.domElement );
controls.enableDamping = true;
controls.dampingFactor = 0.05;
controls.update()

// Functions
function amyspath(curve) {
    linePoints = curve.getPoints(LINE_NB_POINTS);
    let geometry = new LineGeometry();
    let color = new THREE.Color();
    let colors = [];
    let positions = [];
    color.setHSL( 0.2, 1.0, 0.5, THREE.SRGBColorSpace );
    colors.push( color.r, color.g, color.b );
    Object.entries(linePoints).forEach(([key, pos])=> {
        positions.push(pos.x, pos.y, pos.z);
    })
    geometry.setPositions( positions );
    geometry.setColors( colors );

    let matLine = new LineMaterial( {

        color: 0xffffff,
        linewidth: 5, 
        vertexColors: true,

        dashed: false,
        alphaToCoverage: true,

    } );

    line = new Line2( geometry, matLine );
    lineDistance = line.computeLineDistances();
    line.scale.set( 1, 1, 1 );
    scene.add(line);
}
function moveAmy() {
    const targetScroll = window.pageYOffset;
    if (targetScroll > prevScroll) {
        const moveStep = targetScroll / bodyHeight
        let t = FADESTEPS > 0 ? (moveStep + FADESTEPS) : moveStep;
        prevStep = t;
        t = t > 1 ? 1 : t;
        amyMoves(t * WALK_SPEED);
        // console.log(amyModel.position);
    }
    prevScroll = targetScroll;
    if (isReset) {
        prevScroll = 0;
        ANIM_INDEX = ANIM_INDEX !== 3 && PREV_ANIM_INDEX !== 3 ? PREV_ANIM_INDEX + 1 : 1;
        PREV_ANIM_INDEX = ANIM_INDEX;
        window.scrollTo(0, 0);
        isReset = false;
    }
}

function amyMoves(t) {
    t = t > 1 ? 1 : t;
    const newPos = exitcurve.getPoint(t);
    const tangent = new THREE.Vector3();
    if (newPos.distanceTo(initPos) < 1) {
        newPos.x = initPos.x;
        newPos.y = initPos.y;
        newPos.z = initPos.z;
        isReset = true;
        tangent.set(0, 0, 0)
    } else {
        exitcurve.getTangentAt(t, tangent);
        tangent.normalize();
    }
    
    const lookAtPosition = new THREE.Vector3().addVectors(newPos, tangent);
     
    amyModel.position.x = newPos.x;
    amyModel.position.y = newPos.y;
    amyModel.position.z = newPos.z;
    
    amyModel.lookAt(lookAtPosition);
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

window.addEventListener('scroll', () => {
    clearTimeout(timeoutId);
    if (isLoaded) {
        modelActions[ANIM_INDEX].stop();
        modelActions[WALK_INDEX].play();
        FADESTEPS = 0;
        moveAmy();
        timeoutId = setTimeout(() => {
            FADESTEPS = 0.001;
            moveAmy();
            modelActions[WALK_INDEX].stop();
            modelActions[WALK_INDEX].reset();
            if (amyModel.position.distanceTo(initPos) > 1.03) {
                ANIM_INDEX = 1;
            } else {
                // console.log(PREV_ANIM_INDEX, amyModel.position.distanceTo(initPos));
            }
            
            modelActions[ANIM_INDEX].play();
        }, 30);
    }    
});



const render = () => {
    controls.update();
    const delta = clock.getDelta();
    
    if (isLoaded) {
        mixer.update(delta);
    }
    
    renderer.render( scene, camera );

    window.requestAnimationFrame(render);
}

window.addEventListener("mousemove", (e) => {
    
})

render();