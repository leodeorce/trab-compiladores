let num1 = 3;

function letDeclaration(): number{
    let num2:number = 2; 

    if (num2 > num1) { 
        let num3: number = 3;
        num3 = num3 + 1; 
    } 

    while(num1 < num2) { 
        let num4: number = 4;
        num1 =  num1 + 1;
    }
    return 3;
    console.log(num2); //OK 
}

console.log(num1); //OK
letDeclaration();