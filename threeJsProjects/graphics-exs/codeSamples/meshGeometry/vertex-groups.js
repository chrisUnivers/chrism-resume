import * as THREE from "../script/three.module.min.js";

/* Shows a pyramid and a cube.  The pyramid is constructed
 * as a polygonal mesh.  Both objects can be displayed with
 * all faces colored white or multicolored, with a different
 * material for each face.  Display of edges can be turned
 * on and off.  The objects can be rotated using the arrow,
 * Home, PageUp, and PageDown keys.
 */

"use strict";

let scene, camera, renderer;  // Three.js rendering basics.

let canvas;  // The canvas on which the image is rendered.

let cube, pyramid;  // The two visible objects.

let cubeWireframe, pyramidWireframe;  // Wireframe versions of the objects,
                                      // which are only visible when
                                      // "Show Edges" checkbox is checked.

const whiteMaterial = new THREE.MeshLambertMaterial( { color: "white" });

const cubeMaterialArray =  [  // Array of materials, for use as the cube's material property.
               // Note: polygonOffset is used here to allow the wireframe object to show correctly
        new THREE.MeshLambertMaterial( { color: "red", polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),     // +x face
        new THREE.MeshLambertMaterial( { color: "cyan", polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),    // -x face
        new THREE.MeshLambertMaterial( { color: "green", polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),   // +y face
        new THREE.MeshLambertMaterial( { color: "magenta", polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ), // -y face
        new THREE.MeshLambertMaterial( { color: "yellow", polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),  // +z face
        new THREE.MeshLambertMaterial( { color: "blue", polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } )     // -z face
    ];

const pyramidMaterialArray= [ // Array of materials, for use as pyramids's material property.
        new THREE.MeshLambertMaterial( { color: 0xffffff, polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),
        new THREE.MeshLambertMaterial( { color: 0x99ffff, polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),
        new THREE.MeshLambertMaterial( { color: 0xff99ff, polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),
        new THREE.MeshLambertMaterial( { color: 0xffff99, polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } ),
        new THREE.MeshLambertMaterial( { color: 0xff9999, polygonOffset:true, polygonOffsetUnits: 1, polygonOffsetFactor: 1 } )
    ];



/*  Create the scene graph. 
 *  The renderer has already been created before this function is called.
 */
function createWorld() {
   renderer.setClearColor( 0x555555 );  // Set background color.
   scene = new THREE.Scene();
   
   // create some lights and add them to the scene.
   scene.add( new THREE.DirectionalLight( 0xffffff, 0.5 ) ); // dim light shining from above
   var viewpointLight = new THREE.DirectionalLight( 0xffffff, 1 );  // a light to shine in the direction the camera faces
   viewpointLight.position.set(0,0,1);  // shines down the z-axis
   scene.add(viewpointLight);
    
   // create a camera, sitting on the positive z-axis.  The camera is not part of the scene.
   camera = new THREE.PerspectiveCamera(20, canvas.width/canvas.height, 1, 30);
   camera.position.z = 10;
        
   let cubeGeom = new THREE.BoxGeometry(2,2,2);
   cube = new THREE.Mesh( cubeGeom, cubeMaterialArray );
   cube.position.x = -1.5;
   cube.rotation.set(0.2,-0.4,0);
    
   /* Create the pyramid, starting with the geometry. */
    
   let pyramidVertices = new Float32Array([
               // Data for the pyramidGeom position attribute.
               // Contains the x,y,z coordinates for the vertices.
               // Each group of three numbers is a vertex;
               // each group of three vertices is one face.
            -1,0,1,  -1,0,-1,  1,0,-1, // First triangle in the base.
            -1,0,1,   1,0,-1,  1,0,1,  // Second triangle in the base.
            -1,0,1,   1,0,1,   0,1,0,  
             1,0,1,   1,0,-1,  0,1,0,
             1,0,-1, -1,0,-1,  0,1,0,
            -1,0,-1, -1,0,1,   0,1,0
        ]);
   let pyramidGeom = new THREE.BufferGeometry();
   pyramidGeom.setAttribute("position",
                new THREE.BufferAttribute(pyramidVertices,3) );
   
   pyramidGeom.computeVertexNormals(); // Normals are needed for Lambert materials.
      
    /* To apply an array of materials to the pyramid, the vertices have
     * to be put into groups.  The groups are numbered 0,1,2,3,4, corresponding
     * to the array index of the material that is to be applied to that group.
     * The first parameter to addGroup() is the vertex number for the first
     * vertex in the group. The second is the number of vertices in
     * the group (this is three times the number of faces in the group).
     * The third parameter is the index into the material array.
     * (Note that the cube already comes with appropriate groups.)
     */
     
   pyramidGeom.addGroup(0,6,0);  // The two triangles that make up the base.
   pyramidGeom.addGroup(6,3,1);  // Groups 1 to 4 contain one triangular face each.
   pyramidGeom.addGroup(9,3,2);
   pyramidGeom.addGroup(12,3,3);
   pyramidGeom.addGroup(15,3,4);
    
   pyramid = new THREE.Mesh( pyramidGeom, pyramidMaterialArray );
   pyramid.position.x = 1.5;
   pyramid.rotation.set(0.2,-0.4,0);
   
   /* Create wireframe versions of the objects. */
   
   let wireMaterial = new THREE.MeshLambertMaterial( {
            // wireframe material for showing black edges on objects
        color: "black",
        wireframe: true,
        wireframeLinewidth: 2
   } );
   cubeWireframe = new THREE.Mesh(cubeGeom, wireMaterial);
   pyramidWireframe = new THREE.Mesh(pyramidGeom, wireMaterial );
    
   cube.add(cubeWireframe);  // Make the cube wireframe a child of cube,
                             // so it will be transformed along with cube.
   pyramid.add(pyramidWireframe);  // And do the same for the pyramid.
    
   scene.add(cube);
   scene.add(pyramid);
    
} // end createWorld()


/*  Render the scene.
 */
function render() {
    renderer.render(scene, camera);
}


/* Called when the "Show Edges" checkbox is checked or unchecked.
 * Changes the visiblity of the wireframe objects to match the setting.\
 */
function doWireframeCheckbox() {
    let show = document.getElementById("wireframe").checked;
    cubeWireframe.visible = show;
    pyramidWireframe.visible = show;
    render();
}

/* Called when the setting of the material radio buttons is changed.
 * Changes the material on the cube and pyramid to match the setting.
 */
function doChangeMaterial() {
    if (document.getElementById("white").checked) {
        pyramid.material = whiteMaterial;
        cube.material = whiteMaterial;
    }
    else {
        pyramid.material = pyramidMaterialArray;
        cube.material = cubeMaterialArray;
    }
    render();   
}


//----------------------------- keyboard support ----------------------------------

/*  Responds to user's key press.  Here, it is used to rotate the models.
 */
function doKey(event) {
    let code = event.keyCode;
    let rotated = true;
    switch( code ) {
        case 37: cube.rotation.y -= 0.03;    pyramid.rotation.y -= 0.03;    break;    // left arrow
        case 39: cube.rotation.y += 0.03;    pyramid.rotation.y += 0.03;    break;    // right arrow
        case 38: cube.rotation.x -= 0.03;    pyramid.rotation.x -= 0.03;    break;    // up arrow
        case 40: cube.rotation.x += 0.03;    pyramid.rotation.x += 0.03;    break;    // down arrow
        case 33: cube.rotation.z -= 0.03;    pyramid.rotation.z -= 0.03;    break;    // page up
        case 34: cube.rotation.z += 0.03;    pyramid.rotation.z += 0.03;    break;    // page down
        case 36: cube.rotation.set(0.2,-0.4,0); pyramid.rotation.set(0.2,-0.4,0); break;    // home
        default: rotated = false;
    }
    if (rotated) {
        event.preventDefault();  // Prevent keys from scrolling the page.
        render();
    }
}



//----------------------------------------------------------------------------------

/**
 *  This init() function is called when when the document has loaded.
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
    document.getElementById("wireframe").checked = true;
    document.getElementById("wireframe").onchange = doWireframeCheckbox;
    document.getElementById("multi").checked = true;
    document.getElementById("white").onchange = doChangeMaterial;
    document.getElementById("multi").onchange = doChangeMaterial;
    createWorld();
    render();
}

window.onload = init;  // Arranges for init() to be called after page is loaded.