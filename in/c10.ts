// Operações entre tipos diferentes.

let i:number;
let r:number;
let s:string;
let b:boolean;

i = 9;
r = 2.4;
s = "Test";
b = false;

i = i + b;
console.log(i);

r = r / 2;
console.log(r);

s = s + 'D\n';
console.log(s);

b = 20 < i;
console.log(b);

s = "i = " + i + "\n";
console.log(s);

r = 4.2 + 2;
console.log(r);