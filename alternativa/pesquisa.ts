// let num:number;
// let str:string;
// let und:;
// let bool:boolean;

let num:number = 1;
let str:string = "str";
let und;
let bool:boolean = true;

// ------- NUMBER -------

console.log("left:\t\t" + typeof num);
console.log("right:\t\t" + typeof num);
let num_num = num == num;
console.log("num_num:\t> " + num_num + "\t" + typeof num_num);
console.log("");

console.log("left:\t\t" + typeof num);
console.log("right:\t\t" + typeof str);
let num_str = num == str;
console.log("num_str:\t> " + num_str + "\t" + typeof num_str);
console.log("");

console.log("left:\t\t" + typeof num);
console.log("right:\t\t" + typeof bool);
let num_bool = num == bool;
console.log("num_bool:\t> " + num_bool + "\t" + typeof num_bool);
console.log("");

console.log("left:\t\t" + typeof num);
console.log("right:\t\t" + typeof und);
let num_und = num == und;
console.log("num_und:\t> " + num_und + "\t" + typeof num_und);
console.log("");

// ------- STRING -------

console.log("left:\t\t" + typeof str);
console.log("right:\t\t" + typeof num);
let str_num = str == num;
console.log("str_num:\t> " + str_num + "\t" + typeof str_num);
console.log("");

console.log("left:\t\t" + typeof str);
console.log("right:\t\t" + typeof str);
let str_str = str == str;
console.log("str_str:\t> " + str_str + "\t" + typeof str_str);
console.log("");

console.log("left:\t\t" + typeof str);
console.log("right:\t\t" + typeof bool);
let str_bool = str == bool;
console.log("str_bool:\t> " + str_bool + "\t" + typeof str_bool);
console.log("");

console.log("left:\t\t" + typeof str);
console.log("right:\t\t" + typeof und);
let str_und = str == und;
console.log("str_und:\t> " + str_und + "\t" + typeof str_und);
console.log("");

// ------- BOOLEAN -------

console.log("left:\t\t" + typeof bool);
console.log("right:\t\t" + typeof num);
let bool_num = bool == num;
console.log("str_und:\t> " + str_und + "\t" + typeof str_und);
console.log("");

console.log("left:\t\t" + typeof bool);
console.log("right:\t\t" + typeof str);
let bool_str = bool == str;
console.log("bool_str:\t> " + bool_str + "\t" + typeof bool_str);
console.log("");

console.log("left:\t\t" + typeof bool);
console.log("right:\t\t" + typeof bool);
let bool_bool = bool == bool;
console.log("bool_bool:\t> " + bool_bool + "\t" + typeof bool_bool);
console.log("");

console.log("left:\t\t" + typeof bool);
console.log("right:\t\t" + typeof und);
let bool_und = bool == und;
console.log("bool_und:\t> " + bool_und + "\t" + typeof bool_und);
console.log("");

// ------- UNDEFINED -------

console.log("left:\t\t" + typeof und);
console.log("right:\t\t" + typeof num);
let und_num = und == num;
console.log("und_num:\t> " + und_num + "\t" + typeof und_num);
console.log("");

console.log("left:\t\t" + typeof und);
console.log("right:\t\t" + typeof str);
let und_str = und == str;
console.log("und_str:\t> " + und_str + "\t" + typeof und_str);
console.log("");

console.log("left:\t\t" + typeof und);
console.log("right:\t\t" + typeof bool);
let und_bool = und == bool;
console.log("und_bool:\t> " + und_bool + "\t" + typeof und_bool);
console.log("");

console.log("left:\t\t" + typeof und);
console.log("right:\t\t" + typeof und);
let und_und = und == und;
console.log("und_und:\t> " + und_und + "\t" + typeof und_und);
console.log("");

// ------- NUMBER -------

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof num);
// let num_num:number = num;
// console.log("num_num:\t> " + num_num + "\t" + typeof num_num);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof str);
// let num_str:number = str;
// console.log("num_str:\t> " + num_str + "\t" + typeof num_str);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof bool);
// let num_bool:number = bool;
// console.log("num_bool:\t> " + num_bool + "\t" + typeof num_bool);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof und);
// let num_und:number = und;
// console.log("num_und:\t> " + num_und + "\t" + typeof num_und);
// console.log("");

// ------- STRING -------

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof num);
// let str_num:string = num;
// console.log("str_num:\t> " + str_num + "\t" + typeof str_num);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof str);
// let str_str:string = str;
// console.log("str_str:\t> " + str_str + "\t" + typeof str_str);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof bool);
// let str_bool:string = bool;
// console.log("str_bool:\t> " + str_bool + "\t" + typeof str_bool);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof und);
// let bool_num:string = und;
// console.log("bool_num:\t> " + bool_num + "\t" + typeof bool_num);
// console.log("");

// ------- BOOLEAN -------

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof num);
// let bool_num:boolean = num;
// console.log("bool_num:\t> " + bool_num + "\t" + typeof bool_num);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof str);
// let bool_bool:boolean = str;
// console.log("bool_bool:\t> " + bool_bool + "\t" + typeof bool_bool);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof bool);
// let bool_bool:boolean = bool;
// console.log("bool_bool:\t> " + bool_bool + "\t" + typeof bool_bool);
// console.log("");

// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof und);
// let bool_und:boolean = und;
// console.log("bool_und:\t> " + bool_und + "\t" + typeof bool_und);
// console.log("");

// ------- UNDEFINED -------

// let und_num:undefined;
// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof num);
// und_num = num;
// console.log("und_num:\t> " + und_num + "\t" + typeof und_num);
// console.log("");

// let und_str:undefined;
// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof str);
// und_str = str;
// console.log("und_str:\t> " + und_str + "\t" + typeof und_str);
// console.log("");

// let und_bool:undefined;
// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof bool);
// und_bool = bool;
// console.log("und_bool:\t> " + und_bool + "\t" + typeof und_bool);
// console.log("");

// let und_und:undefined;
// console.log("left:\t\t" + typeof num);
// console.log("right:\t\t" + typeof und);
// und_und = und;
// console.log("und_und:\t> " + und_und + "\t" + typeof und_und);
// console.log("");