/* 
 * Comentario 1
 */

// Comentario 2

let $a = 2;
let b2 = 3.57;
// let 3c = "teste"; // Invalid ID
let c3c = `teste %s`;
let d_e = '';
let _;
let arr = [0, 1, 2];

class Rectangle {
	height: number;
	width: number;
	constructor(height, width) {
		this.height = height;
		this.width = width;
	}
	area() {
		return this.height*this.width;
	}
};

function soma(a: number, b: number): number {
  return a + b;
}

console.log(new Rectangle(5, 8).area());
// expected output: 40

console.log("teste %s", c3c);
// expected output: teste teste %s

console.log(0 in arr);
// expected output: true