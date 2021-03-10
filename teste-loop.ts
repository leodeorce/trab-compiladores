let num1:number = 1; 
let num2: number = 2;
let a: number;

num2 = 2;
for(let i = 1; num1 ; ((i + 1) * 3)){
    a = num1 * num2 + i;
    while(num1 < 100){
       a = num1 + 3;
    }
}

function soma(a:number, b:number):number{
    if(a > b){
        return a + b;
    }
    else {
        return b;
    }
}

a = soma(2, 4);