//  Sample program in TS language -
//  computes the GCD of two numbers


function gcd(a:number, b:number):number{
    // Everything divides 0 
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
        return gcd(a-b, b)
    }
    return gcd(a, b-a);
}


let a = gcd(10, 3);

console.log(a);