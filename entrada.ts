// Comentar e descomentar de acordo com o que pretende testar

/**
 * Testando let
 */

let a1 = 1;
let b1: number = 3.14;
let c1: boolean = false;
let d1: string = "str";

let e1;
let f1: void;

let j1: number[] = [,];
let k1: string[] = ["str1", 'str2'];
let l1: unknown[] = [1, 2, 3];
let m1: boolean[] = [true, false];
let n1: any[] = [1, 2, "str"];
let s1: number[] = [, 3];
let t1: number[] = [7.98,];

let u1 = Array(1, 2);
let v1 = new Array(1, 2);
let w1 = Array<number>(1, 2);
let x1 = new Array<number>(1, 2,);

/**
 * Testando var
 */

var a2 = 1;
var b2: number = 3.14;
var c2: boolean = false;
var d2: string = "str";

var e2;
var f2: void;

var j2: number[] = [,];
var k2: string[] = ["str1", 'str2'];
var l2: unknown[] = [1, 2, 3];
var m2: boolean[] = [true, false];
var n2: any[] = [1, 2, "str"];
var s2: number[] = [, 3];
var t2: number[] = [7.98,];

var u2 = Array(1, 2);
var v2 = new Array(1, 2);
var w2 = Array<number>(1, 2);
var x2 = new Array<number>(1, 2,);

/**
 * Testando const
 */

const a3 = 1;
const b3: number = 3.14;
const c3: boolean = false;
const d3: string = "str";

// Erro pois const deve ser inicializado
// const e3;
// const f3: void;

const j3: number[] = [,];
const k3: string[] = ["str1", 'str2'];
const l3: unknown[] = [1, 2, 3];
const m3: boolean[] = [true, false];
const n3: any[] = [1, 2, "str"];
const s3: number[] = [, 3];
const t3: number[] = [7.98,];

const u3 = Array(1, 2);
const v3 = new Array(1, 2);
const w3 = Array<number>(1, 2);
const x3 = new Array<number>(1, 2,);

/**
 * Testando objetos
 */

const obj = {
	id1:"str",
	id2:44
};

/**
 * Testando funções
 */

function func(param1, param2) {
	return 0;
}

/**
 * Testando classes e acessos a atributos
 */

class Empresa {
	public id1:number;
	protected id2:string;
	id3:string;
	func():void {
		return;
	}
}

let empresa = new Empresa();

empresa.id1 = 29;

console.log(empresa.id1);

/**
 * Testando associatividade de acesso a atributos
 */

let elmt = new String(empresa.id1.toString());

console.log(elmt);

String();

/**
 * Testando if-else
 */

let a4 = new Array<string>("str");

if(1){
	if("str" !== String("str")) {
		console.log("true1\n");
	} else {
		console.log("false1\n");
	}
}else if(1) {
	console.log("false2\n");
}

if(1){
	if("str" !== String("str")) {
		console.log("true1\n");
	} else {
		console.log("false1\n");
	}
}else
	function func2() {
		return;
	}

/**
 * Testando while e do-while
 */

while(true){
	break;
}

do{
	break;
}while(1)

/**
 * Testando operações binárias
 */

let a = 2;
let b = 2;

2 + 2;
// erro pois assign para valor
// 2 += 2;
2 - 2;
a -= 2;
2 * 2;
a *= 2;
2 / 2;
a /= 2;
2 ** 2;
a **= 2;
2 % 2;
a %= 2;

2 & 2;
b &= 2;
2 | 2;
b |= 2;
2 ^ 2;
b ^= 2;

2 >> 2;
a >>= 2;
2 << 2;
b <<= 2;
2 >>> 2;
a >>>= 2;

/**
 * Testando múltiplas variáveis declaradas mesma linha
 */

let a5, b5 = 1;

let a6, b6 = true;
a6 = false;

var c6 = {
	id1:"str"
};

c6.id1 = "str2";

/**
 * Testando operadores unários
 */

let a7 = 0;

let b7 = {
	id1:5
};

let c7 = {
	id1:0
};

console.log(++a7);
console.log(a7++);
console.log(a7);
console.log(++b7.id1);
console.log(c7.id1);

console.log(!String());
console.log(~2);
console.log(-"str");
console.log(-true);
console.log(4+-2);

// Erros
// console.log(-null);
// console.log(-undefined);


/**
 * Testando expressões com parênteses
 */

console.log(~(0+2));
2+(2-2);

// return 4>5;

/**
 * Testando conflitos de "<"
 */

let b11 = null;
let a11 = b11;
let e11 = a11 > b11;
let c11 = a11 < b11;

let d11 = Array<string>();
console.log(null);

/**
 * Testando for
 */

let i = 0;

for (i = 1 ; i < 10 ; i++ ) {
	break;
}

for (;;) {
	break;
}

for (;2; i = i + 1 ) {
	break;
}

let vet = [1, 2, 3];
vet[0] = 6;
console.log(vet[1 & 1]);
console.log(1 & 1);

let assign = 0;
if(assign = 1) {
	console.log(true);
}

while(assign = 0) {
	console.log(assign);
}