function buttonOnclick() {
    var x = document.getElementById("x").value;
    var y = document.getElementById("y").value;
    var op = document.getElementById("op").value;

    x = parseInt(x);
    y = parseInt(y);

    var result = calculate(x, y, op);
    document.getElementById("result").innerText = x + " " + op + " " + y + " = " + result;
}

function calculate(x, y, op) {
    var result;

    switch (op) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            break;
    }

    return result;
}