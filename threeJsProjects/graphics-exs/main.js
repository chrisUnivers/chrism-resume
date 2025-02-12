import * as THREE from 'three';
import {gradTri as colorfulTri} from "./exs-modules/mod-triangle.js"

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 0.1, 1000 );

const renderer = new THREE.WebGLRenderer();
renderer.setSize( window.innerWidth, window.innerHeight );
renderer.setAnimationLoop( animate );
document.body.appendChild( renderer.domElement );

const geometry = new THREE.BoxGeometry( 1, 1, 1 );
const material = new THREE.MeshBasicMaterial( { color: 0x00ff00 } );
const cube = new THREE.Mesh( geometry, material );
// cube.position(1, 1, 1);
// let gTri = colorfulTri();

let positionBuffer = new Float32Array([
	-2, -2, // v1
	2, -2, // v2
	0, 2 // v3
]);
let colorBuffer = new Float32Array([
	1, 0, 0, // color for v1(red)
	0, 1, 0, // color for v2(gree)
	0, 0, 1 // color for v3(blue)
]);
let lineGeometry = new THREE.BufferGeometry();
lineGeometry.setAttribute(
	"position",
	new THREE.BufferAttribute(positionBuffer, 2)
);
lineGeometry.setAttribute(
	"color",
	new THREE.BufferAttribute(colorBuffer, 3)
);
let lineMaterial = new THREE.LineBasicMaterial({
	linewidth: 3,
	vertexColors: true
});
let triangle = new THREE.LineLoop(lineGeometry, lineMaterial)
scene.add( cube, triangle );

camera.position.z = 5;

function animate() {

	cube.rotation.x += 0.01;
	cube.rotation.y += 0.01;

	renderer.render( scene, camera );

}

// function drawGradTriangle() {
    
// }