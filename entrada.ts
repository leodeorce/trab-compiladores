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
        return a + b
    }
    else {
        return b
    }
}

a = soma(2, 4);


// function letDeclaration(): number{return 9}
//     let num2:number = 2; 

//     if (num2 > num1) { 
//         let num3: number = 3;
//         num3++; 
//     } 

//     while(num1 < num2) { 
//         let num4: number = 4;
//         num1++;
//     }

//     console.log(num1); //OK
//     console.log(num2); //OK 
//     // console.log(num3); //Compiler Error: Cannot find name 'num3'
//     // console.log(num4); //Compiler Error: Cannot find name 'num4'
// }
