/**
 *  Estrutura de escolha - if
 */

let circulo:boolean = true;
let pi:number = 3.14;
let raio:number = 2;

let triangulo:boolean = false;
let base:number = 5.7;
let altura:number = 10;

let area:number;

if(circulo == true && triangulo == false) {
	area = pi * raio * raio;
} else if(circulo == false && triangulo == true) {
	area = base * altura / 2;
}