// Sample program in TS language -
//  tests with other types than int

let i:number;
let r:number;
let s:string;
let b:boolean;

i = 9;
r = 2.4;
s = "Test";
b = false;

i = i + b;
console.log(i);  //show 10

r = r / 2;
console.log(r);  //show 1.2 

s = s + 'D\n';
console.log(s);   //show "TestD\n"

b = 20 < i
console.log(b);  //show false

s = "i = " + i + "\n";
console.log(s);  //show "i= 10\n"

r = 4.2 + 2;
console.log(r);  //show 6.2
