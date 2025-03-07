import * as THREE from "three";
import {OrbitControls} from "./script/controls/OrbitControls.js";
import {GLTFLoader} from "./script/loaders/GLTFLoader.js";

/*  This page shows a reflecting object inside a skybox. An environment
 *  map is used on the object to make it refract the skybox.  No lighting
 *  is used since object uses MeshBasicMaterial.
 */

"use strict";

let canvas, renderer, scene, camera;

let skyboxTexture;  // The cubemap texture.

let reflectiveObject;  // The Object3D in the scene
                       // ( = model for standard objects, = model.children[0] for GLTF models )
let model;  // Content of the scene, either the reflectiveObject or a container for it.
            // For GLTF models, a container Object3D is used to apply the correct transformation.

let rotateX = 0;   // rotation of object about its x-axis
let rotateY = 0;   // rotation of object about its y-axis

let controls;  // an OrbitControls object for rotating the view.

let skyboxTexturePaths = [  // paths to folders containing available cubemap textures.
    "cubemap-textures/park/",     //    Note that files are always named posx.jpg, negx.jpg, etc.
    "cubemap-textures/pond/",
    "cubemap-textures/Yokohama-at-night/",
    "cubemap-textures/Colosseum/"
];

let gltfModelURL = [  // available GLTF model files
    "models/Arrowhead.glb",
    "models/Horse-simple.glb",
    "models/Suzanne-smooth.glb"
];

let defaultGltfRotation = [ // Correct initial x,y rotations for GLTF models.
    [ Math.PI/2, 0],
    [ 0, -Math.PI/2 ],
    [ 0, 0 ]
];

let defaultRotation = [ 0, 0 ];  // Initial rotation for current model.

let baseColor = [  // available colors for the base material color
    0xFFFFFF,
    0xBBBBFF,
    0xFFBBBB,
    0xAAFFAA
];
let currentColor = 0xFFFFFF;  // currently selected 


function render() {
    renderer.render(scene, camera);
}

/**
 *  Called when the user clicks one of the radio buttons for selecting the skybox texture.
 *  Creates the texture, sets it as the background for the scene, and applies it to the
 *  current object in the scene.
 */
function createSkybox(textureNumber) {
    document.getElementById("message").innerHTML = "Drag on the scene to rotate the view.";
    document.getElementById("bttn").focus();  // to prevent key presses from going to the radio buttons
    let textureFileNames = [ "posx.jpg", "negx.jpg",
                               "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg" ];
    let loader = new THREE.CubeTextureLoader();
    loader.setPath(skyboxTexturePaths[textureNumber]);  // Tells loader where to look for the files.
    skyboxTexture = loader.load( textureFileNames, onLoad, undefined, onError );
    function onLoad() {  // Callback function called by loader after object loads.
       scene.background = skyboxTexture;
       if (reflectiveObject) {
           reflectiveObject.material.envMap = skyboxTexture;
           // reflectiveObject.material.needsUpdate = true; // No longer needed in r154.
       }
       render();
    }
    function onError() { // Error function to be called by the loader if the load fails.
        document.getElementById("message").innerHTML = "Error: Could not load the skybox texture.";
        scene.background = null;
        render();
    }
}

/**
 *  Creates the material to use on the models.  This is a MeshBasicMaterial with
 *  the skybox texture as an environment map.  The base color, which is blended with the
 *  environment map, is taken from the current color selection.
 */
function makeReflectionMaterial() {
    let mat = new THREE.MeshBasicMaterial( { 
            color: currentColor,
            envMap: skyboxTexture
    } );
    return mat;
}

/**
 *  Called when the user clicks one of the model choice radio buttons, for the four
 *  buttons that correspond to basic geometries.
 */
function installModel(modelNum) {
    document.getElementById("message").innerHTML = "Drag on the scene to rotate the view.";
    if (model)
        scene.remove(model);
    let geometry;
    switch (modelNum) {
        case 0: geometry = new THREE.BoxGeometry(1,1,1); break;
        case 1: geometry = new THREE.CylinderGeometry(0.5,0.5,1,32,1); break;
        case 2: geometry = new THREE.TorusGeometry(0.4,0.25,64,32); break;
        case 3: geometry = new THREE.SphereGeometry(0.6,32,16); break;
    }
    let material = makeReflectionMaterial();
    model = new THREE.Mesh(geometry, material);
    rotateX = rotateY = 0;
    defaultRotation = [0,0];
    scene.add(model);
    reflectiveObject = model;
    render();
}


/**
 *  Called when the user clicks one of the mode choice radio buttons, for the
 *  three radio buttons that corresponding to JSON models.
 */
function installGLTFModel(modelNum) {
    /*
     * The callback function that is called by the loader when it
     * has finished loading the object.  This function creates a three.js
     * function to hold the object.  It translates the object so that
     * its center is in the origin.  It wraps the object in another object
     * that is used to scale and rotate the object.  The scale is set
     * so that the maximum coordinate in its vertices, in absolute
     * value, is scaled to 1.  The rotation is controlled by the arrow
     * keys.  (The material from the JSON loader file is ignored.)
     */ 
    function modelLoadedCallback(data) {
    
        /* Get the object from the data that was loaded, but give it a new material.
           Note that the material can include references to texture images might finish
           loading later. */
    
        let object = data.scene.children[0]; // OK for GLTFs in this program, but not for all GLTF files.
        
        reflectiveObject = object;
        
        object.material = makeReflectionMaterial();
        if (modelNum == 1) {
            object.geometry.computeVertexNormals();
        }
    
        /* Determine the ranges of x, y, and z in the vertices of the geometry. */
        
        let vertices = object.geometry.getAttribute("position");
        let xmin = Infinity;
        let xmax = -Infinity;
        let ymin = Infinity;
        let ymax = -Infinity;
        let zmin = Infinity;
        let zmax = -Infinity;
        for (let i = 0; i < vertices.count; i++) {
            let x = vertices.getX(i);
            let y = vertices.getY(i);
            let z = vertices.getZ(i);
            if (x < xmin)
                xmin = x;
            else if (x > xmax)
                xmax = x;
            if (y < ymin)
                ymin = y;
            else if (y > ymax)
                ymax = y;
            if (z < zmin)
                zmin = z;
            else if (z > zmax)
                zmax = z;
        }
        
        object.scale.set(1,1,1);   // remove any scaling and rotation that the object comes with
        object.rotation.set(0,0,0);
                
        /* translate the center of the object to the origin */
        let centerX = (xmin+xmax)/2;
        let centerY = (ymin+ymax)/2; 
        let centerZ = (zmin+zmax)/2;
        let max = Math.max(centerX - xmin, xmax - centerX);
        max = Math.max(max, Math.max(centerY - ymin, ymax - centerY) );
        max = Math.max(max, Math.max(centerZ - zmin, zmax - centerZ) );
        let scale = 1/max;
        object.position.set( -centerX, -centerY, -centerZ );
        console.log("Loading finished, scaling object by " + scale);
        console.log("Center at ( " + centerX + ", " + centerY + ", " + centerZ + " )");
                
        /* Create the wrapper, model, to scale and rotate the object. */
        
        model = new THREE.Object3D();
        model.add(object);
        model.scale.set(scale,scale,scale);
        defaultRotation = defaultGltfRotation[modelNum];
        model.rotation.x = rotateX = defaultRotation[0];
        model.rotation.y = rotateY = defaultRotation[1];
        scene.add(model);
        render();
    }
    function errorCallback() {
            document.getElementById("message").innerHTML = "Error:  Could not load the model.";
    }
    
    document.getElementById("message").innerHTML = "Drag on the scene to rotate the view.";
    if (model) {
        scene.remove(model);
        reflectiveObject = null;
    }
    let loader = new GLTFLoader();
    loader.load(gltfModelURL[modelNum], modelLoadedCallback, undefined, errorCallback);
    render();
}

/**
 *  Called when the user clicks one of the color choice radio buttons to change
 *  the color setting.
 */
function setObjectColor(colorNum) {
    currentColor = baseColor[colorNum];
    reflectiveObject.material = makeReflectionMaterial();
    render();
}

/**
 *  Called when user clicks the Reset button.  Resets model rotation and controls to default view.
 */
function resetRotation() {
    rotateX = defaultRotation[0];
    rotateY = defaultRotation[1];
    model.rotation.set(rotateX,rotateY,0);
    controls.reset();
    render();
}

/**
 *  An event listener for the keydown event.  
 *  The arrow keys are used to rotate the model about its own axis.
 */
function doKey(evt) {
    let rotationChanged = true;
	switch (evt.keyCode) {
	    case 37: rotateY -= 0.05; break;        // left arrow
	    case 39: rotateY +=  0.05; break;       // right arrow
	    case 38: rotateX -= 0.05; break;        // up arrow
	    case 40: rotateX += 0.05; break;        // down arrow
	    case 13:                                // return
	    case 36: rotateX = defaultRotation[0];  // home
                 rotateY = defaultRotation[1];
                 break;
	    default: rotationChanged = false;
	}
	if (rotationChanged) {
       model.rotation.set(rotateX,rotateY,0);	
       render();
	   evt.preventDefault();
	}
}

/**
 *  This function is called by the body onload event.
 */
function init() {
	try {
	    canvas = document.getElementById("glcanvas");
		renderer = new THREE.WebGLRenderer( {
		    canvas: canvas,
		    antialias: true
		} );
	}
	catch (e) {
        document.getElementById("message").innerHTML =  "WebGL is requrid but is not available.";
		return;
	}
    scene = new THREE.Scene();
    camera = new THREE.PerspectiveCamera(50, canvas.width/canvas.height, 0.1, 100);
    camera.position.z = 3;
    scene.add(camera); 
    createSkybox(0);
    installGLTFModel(0);
    controls = new OrbitControls(camera,canvas);
    controls.enablePan = false;
    controls.enableZoom = false;
    controls.addEventListener("change",render);
    document.addEventListener("keydown", doKey, false);
    document.getElementById("s0").checked = true;
    document.getElementById("g0").checked = true;
    document.getElementById("c0").checked = true;
    document.getElementById("s0").checked = true;
    for (let i = 0; i < 4; i++)
       document.getElementById("s"+i).onchange = function() { createSkybox(i) };
    for (let i = 0; i < 3; i++)
       document.getElementById("g"+i).onchange = function() { installGLTFModel(i) };
    for (let i = 0; i < 4; i++)
       document.getElementById("m"+i).onchange = function() { installModel(i) };
    for (let i = 0; i < 4; i++)
       document.getElementById("c"+i).onchange = function() { setObjectColor(i) };
    document.getElementById("bttn").onclick = resetRotation;
    render();
}


window.onload = init; 