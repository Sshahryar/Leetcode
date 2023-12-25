function createHelloWorld() {
  return function() {
    return "Hello World";
  };
}

const helloWorldFunction = createHelloWorld();
const message = helloWorldFunction();
console.log(message); 
