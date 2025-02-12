import * as THREE from 'three'; 
class gradTri {
    constructor() {
        this.positionBuffer = new Float32Array([
            -2, -2, // v1
            2, -2, // v2
            0, 2 // v3
        ]);
        this.colorBuffer = new Float32Array([
            1, 0, 0, // color for v1(red)
            0, 1, 0, // color for v2(gree)
            0, 0, 1 // color for v3(blue)
        ]);
        this.lineGeometry = new THREE.BufferGeometry();
        lineGeometry.setAttribute(
            "position",
            new THREE.BufferAttribute(positionBuffer, 2)
        );
        this.lineGeometry.setAttribute(
            "color",
            new THREE.BufferAttribute(colorBuffer, 3)
        );
        this.lineMaterial = new THREE.LineBasicMaterial({
            linewidth: 3,
            vertexColors: true
        });
    }
}
export {gradTri};