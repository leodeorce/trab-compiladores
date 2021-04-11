// Testando atribuição

// let num:number;
// let str:string;
// let unk:unknown;
// let bool:boolean;
// let void_rw:void;
// let never:never;
// let any:any;

let num:number = 1;
let str:string = "str";
let unk:unknown;
let bool:boolean = true;
let void_rw:void;
let never:never;
let any:any = "foo";

let result1;
console.log("left:\t\t" + typeof any);
console.log("right:\t\t" + typeof num);
result1 = any + num;
console.log("result1:\t> " + typeof result1);
console.log("");

let result2;
console.log("left:\t\t" + typeof any);
console.log("right:\t\t" + typeof str);
result2 = any + str;
console.log("result2:\t> " + typeof result2);
console.log("");

let result3;
console.log("left:\t\t" + typeof any);
console.log("right:\t\t" + typeof unk);
result3 = any + unk;
console.log("result3:\t> " + typeof result3);
console.log("");

let result4;
console.log("left:\t\t" + typeof any);
console.log("right:\t\t" + typeof bool);
result4 = any + bool;
console.log("result4:\t> " + typeof result4);
console.log("");

let result5;
console.log("left:\t\t" + typeof any);
console.log("right:\t\t" + typeof void_rw);
result5 = any + void_rw;
console.log("result5:\t> " + typeof result5);
console.log("");

let result6;
console.log("left:\t\t" + typeof any);
console.log("right:\t\t" + typeof never);
result6 = any + never;
console.log("result6:\t> " + typeof result6);
console.log("");

let result7;
console.log("left:\t\t" + typeof any);
console.log("right:\t\t" + typeof any);
result7 = any + any;
console.log("result7:\t> " + typeof result7);
console.log("");

let i:number, j = 1;