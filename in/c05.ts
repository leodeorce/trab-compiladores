/**
 * Manipulação de vetor
 * Teste básico de loop - while
 */

let vet:number[] = [0, 0, 0, 0, 0];
let i:number = 0;
while(i < 5){
  vet[i] = i + 1;
  i = i + 1;
}
console.log(vet);