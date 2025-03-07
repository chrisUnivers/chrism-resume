import * as THREE from "three";

/* This program uses basic hierarchical modeling in three.js.  It shows
 * a car with rotating wheels driving aroud a circular track.  There are
 * also some trees, including one that increases in size.  The user can
 * rotate the model using the keyboard, and the user can choose whether
 * to see the entire model, just (a copy of) the car, or just (a copy of
 * one axle of the car with attached wheels.
 */


"use strict";

let scene, camera, renderer;  // Three.js rendering basics.

let canvas;  // The canvas on which the image is rendered.

// The three objects that can be viewed.  Each is a scene graph containing only visible objects.
let axleModel;       // A model containing only an axle (thin cylinder with wheel on each end).
let carModel;        // A model containing only a car.
let diskworldModel;  // A model containing the diskworld.

let currentModel;   // Contains the visible objects in the scene, but
                    // not the lights or camera.  The model can be
			        // rotated using the keyboard.  It is one of the
					// three above models.

// Nodes in the scene graphs that are modified as part of the animation:
let carAxle1, carAxle2;  // The two axles in the carModel.
let diskworldAxle1, diskworldAxle2;  // The two axles in the car that is part of diskworld.
let growingTree;  // The tree in the center of diskworld that grows.
let carRotator;  // An object at the origin that has the diskworld car as its child;
                 // rotating this object about the y-axis drives the car aroudn the disk.

let animating = false;  // This is set to true when an animation is running.


/*  Create the scene graph.  This function is called once, as soon as the page loads.
 *  The renderer has already been created before this function is called.
 */
function createWorld() {
    renderer.setClearColor( 0x444444 );  // Set background color (0x444444 is dark gray).
	scene = new THREE.Scene();
	
	// create a camera, sitting on the positive z-axis.  The camera is not part of the scene.
	camera = new THREE.PerspectiveCamera(45, canvas.width/canvas.height, 1, 30);
	camera.position.z = 15;
	
	// create some lights and add them to the scene.
	scene.add( new THREE.DirectionalLight( 0xffffff, 0.3 ) ); // dim light shining from above
	let viewpointLight = new THREE.DirectionalLight( 0xffffff, 0.6 );  // a light to shine in the direction the camera faces
	viewpointLight.position.set(0,0,1);  // shines down the z-axis
	scene.add(viewpointLight);
	
	// Create the wheels and axles.
	let wheel = new THREE.Mesh(  // This is the tire; the wheel object will also contain the spokes
		new THREE.TorusGeometry(0.75, 0.25, 16, 32),
		new THREE.MeshLambertMaterial({ color: 0x0000A0 })
	);
	let yellow = new THREE.MeshPhongMaterial({
		    color: 0xffff00,
			specular: 0x303030,
			shininess: 16
		});
	let cylinder = new THREE.Mesh(  // a yellow cylinder with height 1 and diameter 1
	    new THREE.CylinderGeometry(0.5,0.5,1,32,1),
		yellow
	);
	cylinder.scale.set(0.15,1.2,0.15); // Make it thin and long for use as a spoke
	wheel.add(cylinder.clone());  // Add a copy of the cylinder
	cylinder.rotation.z = Math.PI/3;  // Add a rotation about the z-axis for the second spoke
	wheel.add(cylinder.clone());
	cylinder.rotation.z = -Math.PI/3; // For third spoke, use a negative rotation about z-axis
	wheel.add(cylinder.clone());
    // Note: The original cylinder has not been added to the wheel; it will be used in the axel.
	
	axleModel = new THREE.Object3D();     // A model containing two wheels and a cylinder.
	cylinder.scale.set(0.2,4.3,0.2);  // scale the cylinder for use as an axle
	cylinder.rotation.set(Math.PI/2,0,0);     // rotate its axis onto the z-axis
	axleModel.add(cylinder);
	wheel.position.z = 2;          // the wheels are positioned at the top and bottom of cylinder
	axleModel.add(wheel.clone());
	wheel.position.z = -2;
	axleModel.add(wheel);
	
	// Create a car, consisting of two boxes, two spheres for the headlights, and two axles.
	carModel = new THREE.Object3D();
	let red = new THREE.MeshPhongMaterial({
	    color: "red",
		specular: 0x404040,
		shininess: 8,
		flatShading: true
	});
	let body = new THREE.Mesh(new THREE.BoxGeometry(6,1.2,3), red);
	body.position.y = 0.6;
	let hood = new THREE.Mesh(new THREE.BoxGeometry(3,1,2.8), red);
	hood.position.set(0.5,1.4,0);
	let headlight1 = new THREE.Mesh(new THREE.SphereGeometry(1,16,8), yellow);
	headlight1.scale.set(0.1,0.25,0.25);
	headlight1.position.set(-3,0.6,-1);
	let headlight2 = headlight1.clone();
	headlight1.position.set(-3,0.6,1);
	carAxle1 = axleModel.clone();
	carAxle1.position.x = -2.5;
	carAxle2 = axleModel.clone();
    // Note that the original axelModel is not part of the car; it is a separate model.
	carAxle2.position.x = 2.5;
	carModel.add(carAxle1);
	carModel.add(carAxle2);
	carModel.add(body);
	carModel.add(hood);
	carModel.add(headlight1);
	carModel.add(headlight2);
	
	// Create the main diskworld model.
	diskworldModel = new THREE.Object3D();
	let ground = new THREE.Mesh(  // The base of the world; everything else is on the top of this cylinder.
	    new THREE.CylinderGeometry(5.5, 5.5, 0.5, 64, 1),
		new THREE.MeshLambertMaterial( { color: 0x00CC55 } )
	);
	ground.position.y = -0.3; // Puts top of cylinder just below the xz-plane.
	diskworldModel.add(ground);
	let road = new THREE.Mesh(
	    new THREE.RingGeometry(3.3,4.8,64,1),
		new THREE.MeshLambertMaterial( { color: 0x777799 })
	);
	road.rotation.x = -Math.PI/2;
	diskworldModel.add(road);
	let diskCar = carModel.clone();
    // Note that the original carModel is not part of the diskworld; it is a separate model.
	diskworldAxle1 = diskCar.children[0];  // First two children are the axles; we need these to animate them.
	diskworldAxle2 = diskCar.children[1];
	diskCar.scale.set(0.3,0.3,0.3);
	diskCar.position.set(0,0.3,-4);  // puts car on the road, near the edge of the disk.
	carRotator = new THREE.Object3D();  // rotating carRotator about the y-axis will move the car along the road.
	carRotator.add(diskCar);
	diskworldModel.add(carRotator);
	
	// Make a tree model, consisting of a brown cylinder and a green cone.
	let tree = new THREE.Object3D();
	let trunk = new THREE.Mesh(
        new THREE.CylinderGeometry(0.2,0.2,1,16,1),
		new THREE.MeshLambertMaterial({
		    color: 0x885522
		})
	);
	trunk.position.y = 0.5;  // move base up to origin
	let leaves = new THREE.Mesh(
        new THREE.ConeGeometry(.7,2,16,3),
		new THREE.MeshPhongMaterial({
		    color: 0x00DD00,
			specular: 0x006000,
			shininess: 5
		})
	);
	leaves.position.y = 2;  // move bottom of cone to top of trunk
	tree.add(trunk);
	tree.add(leaves);

	// Add copies of the tree model to the world, with various sizes and positions.
	tree.position.set(-1.5,0,2);
	tree.scale.set(0.7,0.7,0.7);
	diskworldModel.add(tree.clone());
	tree.position.set(-1,0,5.2);
	tree.scale.set(0.25,0.25,0.25);
	diskworldModel.add(tree.clone());
	tree.position.set(5.1,0,0.5);
	tree.scale.set(0.3,0.3,0.3);
	diskworldModel.add(tree.clone());
	tree.position.set(5.1,0,-0.5);
	tree.scale.set(0.35,0.35,0.35);
	diskworldModel.add(tree.clone());
	tree.position.set(5.3,0,0);
	tree.scale.set(0.5,0.5,0.5);
	diskworldModel.add(tree.clone());
	tree.position.set(-3.6,0,-3.6);
	tree.scale.set(0.6,0.6,0.6);
	diskworldModel.add(tree.clone());
	tree.position.set(1,0,-5);
	tree.scale.set(0.35,0.35,0.35);
	diskworldModel.add(tree.clone());
	
	// The final tree, at the center of the disk, starts off very small but its size will be animated.
	tree.scale.set(0.1,0.1,0.1);
	tree.position.set(0,0,0);
	growingTree = tree;
	diskworldModel.add(growingTree);
	
	axleModel.scale.set(2,2,2);  // Needs to be bigger when it's displayed alone.
	
	currentModel = diskworldModel;
	currentModel.rotation.set(0.2,0,0); // Tip it forward a bit, so we're not looking at it edge-on.
	
	scene.add(currentModel);
}


/*  Render the scene.  This is called for each frame of the animation.
 */
function render() {
    renderer.render(scene, camera);
}


/*  When an animation is in progress, this function is called just before rendering each
 *  frame of the animation, to make any changes necessary in the scene graph to prepare
 *  for that frame.
 */
function updateForFrame() {
	if (currentModel == axleModel) {
		axleModel.rotation.z += 0.05;
	}
	else if (currentModel == carModel) {
		carAxle1.rotation.z += 0.05;
		carAxle2.rotation.z += 0.05;
	}
	else {
		diskworldAxle1.rotation.z += 0.05;
		diskworldAxle2.rotation.z += 0.05;
		carRotator.rotation.y += 0.007;
		let treeScale = growingTree.scale.x;
		if (treeScale < 1.5) {
			treeScale += 0.0005;
			growingTree.scale.set(treeScale,treeScale,treeScale);
		}
	}
}


//--------------------------- animation support -----------------------------------

/* This function runs the animation by calling updateForFrame() then calling render().
 * Finally, it arranges for itself to be called again to do the next frame.  When the
 * value of animating is set to false, this function does not schedule the next frame,
 * so the animation stops.
 */
function doFrame() {
    if (animating) {
        updateForFrame();
        render();
        requestAnimationFrame(doFrame); 
	}
}


/* Responds when the setting of the "Animate" checkbox is changed.  This
 * function will start or stop the animation, depending on its setting.
 */
function doAnimateCheckbox() {
    let anim = document.getElementById("animate").checked;
	if (anim != animating) {
		animating = anim;
		if (animating) {
			doFrame();
		}
	}
}



//----------------------------- keyboard support ----------------------------------

/*  Responds to user's key press.  Here, it is used to rotate the entire model.
 */
function doKey(event) {
	let code = event.keyCode;
	let rotated = true;
	switch( code ) {
	    case 37: currentModel.rotation.y -= 0.03;  break;    // left arrow
	    case 39: currentModel.rotation.y +=  0.03; break;    // right arrow
	    case 38: currentModel.rotation.x -= 0.03;  break;    // up arrow
	    case 40: currentModel.rotation.x += 0.03;  break;    // down arrow
	    case 33: currentModel.rotation.z -= 0.03;  break;    // page up
	    case 34: currentModel.rotation.z += 0.03;  break;    // page down
	    case 36: currentModel.rotation.set(0.2,0,0); break;  // home
	    default: rotated = false;
	}
	if (rotated) {
		event.preventDefault();  // Prevent keys from scrolling the page.
		if (!animating) { // (if an animation is running, no need for an extra render)
			render();
		}
	}
}


//------------------ handle the radio buttons that select the model-------------------------

/*  Changes the model that is displayed, when the user changes the setting of
 *  radio buttons that are used to select the model.  The model is reset to
 *  its initial rotation.
 */
function doChangeModel() {
    let axle = document.getElementById("axle").checked;
	let car = document.getElementById("car").checked
	let newModel = axle ? axleModel : car ? carModel : diskworldModel;
	if (newModel != currentModel) {
		scene.remove(currentModel);
		currentModel = newModel;
		currentModel.rotation.set(0.2,0,0);
		scene.add(currentModel);
		if (!animating) {
			render();
		}
	}
}


//----------------------------------------------------------------------------------

/**
 *  This init() function is called when by the onload event when the document has loaded.
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
		document.getElementById("canvas-holder").innerHTML =
		         "<h3><b>Sorry, WebGL is required but is not available.</b><h3>";
		return;
	}
	document.addEventListener("keydown", doKey, false);
	document.getElementById("animate").checked = false;
	document.getElementById("animate").onchange = doAnimateCheckbox;
	document.getElementById("diskworld").checked = true;
	document.getElementById("axle").onchange = doChangeModel;
	document.getElementById("car").onchange = doChangeModel;
	document.getElementById("diskworld").onchange = doChangeModel;
	createWorld();
	render();
}

window.onload = init;  // Arrange for the init() function to be called after page has beenloaded.
