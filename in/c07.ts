// Calcula o máximo divisor comum entre dois números.

function gcd(a:number, b:number):number{
    
    if (a == 0){
        return b;
    }
    if (b == 0){
        return a;
    }
 
    // base case
    if (a == b){
        return a;
    }
 
    // a is greater
    if (a > b){
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}


let res = gcd(10, 3);

console.log(res);