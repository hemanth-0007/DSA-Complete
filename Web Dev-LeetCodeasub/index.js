const inputElement = document.getElementById("phone");


inputElement.oninput = () =>{
    let inputString = inputElement.value;
   
   

    if(inputString.length == 3){
        inputElement.value = '(' + inputString + ')';
        console.log(`length is ${inputString.length}`);
    }
    if(inputString.length == 8){
        inputElement.value =  inputString + '-';
        console.log(`length is ${inputString.length}`);
    }
     
}

