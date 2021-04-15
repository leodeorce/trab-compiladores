// let a:number;
// let b;
// let d = "str";
// let j:boolean = true;

// var e = 1;
// var f:number = 2;

// a = b;
// // a = b;

// b = "str";

// let n = e + b;
// e = a / 0;

// let o = a == e;
// o = a < 1;
// o = 1 > a;
// o = e <= e;

let circulo:boolean = true;
let pi:number = 3.14;
let raio:number = 2;

let triangulo:boolean = false;
let base:number = 5.7;
let altura:number = 10;

let area:number;

if(circulo == true || triangulo == false) {
	area = pi * raio * raio;
} else if(triangulo == true) {
	area = base * altura / 2;
}

while(area > 1) {
	area = area - 1;
}