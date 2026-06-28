function changeHeading() {
    const heading = document.getElementById('heading');
    if (heading.innerText == "Hello, DOM!") {
        heading.innerText = "Hello, World!";
        heading.style.color = 'blue';
        return;
    }
    heading.innerText = "Hello, DOM!";
    heading.style.color = 'red';
}
function changeParagraph() {
    const paragraph = document.getElementById("paragraph");
    if (paragraph.innerText == "Lorem ipsum dolor sit amet consectetur adipisicing elit. Iusto consequuntur nisi beatae dolor autem consequatur atque cumque omnis, ut odio porro? Sit corporis nobis eum. Obcaecati similique dolore quas corrupti!") {
        paragraph.innerText = "This is a new paragraph.";
        paragraph.style.color = 'green';
        paragraph.style.fontWeight = 'bold';
        return;
    }
    paragraph.innerHTML = "<p id=\"paragraph\">Lorem ipsum dolor sit amet consectetur adipisicing elit. Iusto consequuntur nisi beatae dolor autem consequatur atque cumque omnis, ut odio porro? Sit corporis nobis eum. Obcaecati similique dolore quas corrupti!</p>";   

}




calculator.addEventListener("submit", function(event) {
    event.preventDefault();
    const num1 = parseFloat(document.getElementById("num1").value);
    const num2 = parseFloat(document.getElementById("num2").value);
    const operator = document.getElementById("operator").value;
    const result = document.getElementById("result");
    console.log(num1, num2, operator);
    if (operator === "+") {
        result.innerText = num1 + num2;
    } else if (operator === "-") {
        result.innerText = num1 - num2;
    }
    
    
})