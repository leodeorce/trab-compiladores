// Função fatorial.

function fat(n:number):number{
    if(n == 0){
        return 1;
    } 
    else {
        n = n - 1;
        let res:number;
        res = fat(n);
        return  res * n;
    }
}

let x = fat(5);

console.log(x);