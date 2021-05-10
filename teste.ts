let a:boolean = false;
let b = 1;
let c:number = 3.14;
if(a || c > b) {
    console.log("sucesso");
}
if(c > b || a) {
    console.log("sucesso");
}
if(c < b || a) {
    console.log("fracasso");
}