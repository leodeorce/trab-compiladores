const fs = require("fs");
const readline = require('readline');


const readInterface = readline.createInterface({
    input: fs.createReadStream('entrada.txt'),
    console: false
});

const data  = ''

readInterface.on('line', function(line) {
    
    console.log(`(${line}) \t\t\t\t { saida ("${line.toUpperCase()}"); }`)
});
