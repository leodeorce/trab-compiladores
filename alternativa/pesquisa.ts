// Testando atribuição

let num:number;
let str:string;
let unk:unknown;
let bool:boolean;
let void_rw:void;
let never:never;
let any:any;

let result1:string = "teste";
console.log("result1: " + typeof result1);
console.log("num: " + typeof num);
result1 = num;
console.log("result1 = num: " + typeof result1);

let result2:string = "teste";
console.log("result2: " + typeof result2);
console.log("str: " + typeof str);
result2 = str;
console.log("result2 = str: " + typeof result2);

let result3:string = "teste";
console.log("result3: " + typeof result3);
console.log("unk: " + typeof unk);
result3 = unk;
console.log("result3 = unk: " + typeof result3);

let result4:string = "teste";
console.log("result4: " + typeof result4);
console.log("bool: " + typeof bool);
result4 = bool;
console.log("result4 = bool: " + typeof result4);

let result5:string = "teste";
console.log("result5: " + typeof result5);
console.log("void_rw: " + typeof void_rw);
result5 = void_rw;
console.log("result5 = void_rw: " + typeof result5);

let result6:string = "teste";
console.log("result6: " + typeof result6);
console.log("never: " + typeof never);
result6 = never;
console.log("result6 = never: " + typeof result6);

let result7:string = "teste";
console.log("result7: " + typeof result7);
console.log("any: " + typeof any);
result7 = any;
console.log("result7 = any: " + typeof result7);