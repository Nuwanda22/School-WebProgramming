// 1. 
var favorite = prompt("what is your favorite number?", "0");

if (favorite % 2 == 0) {
    document.write("even");
}
else {
    document.write("odd");
}

// 2. 
var month = prompt("month", "0");

if (0 >= month || month <= 13) {
    document.write(";;");
}
else if (3 <= month && month <= 5) {
    document.write("spring");
}
else if (6 <= month && month <= 8) {
    document.write("summer");
}
else if (9 <= month && month <= 11) {
    document.write("fall");
}
else {
    document.write("winter");
}

// 3. 
//<input id="id"/>
//<input id="password" type="password"/>
//<button onclick="OKClicked()">OK</button>

var id = "admin";
var password = "1234";


function OKClicked() {
    var userId = document.getElementById("id").value;
    var userPassword = document.getElementById("password").value;

    if (userId == id) {
        if (userPassword == password) {
            document.write("Hello, " + userId);
        }
        else {
            alert("wrong password");
            location.reload();
        }
    }
    else {
        alert("wrong id");
        location.reload();
    }
}

// 4. 
var site = prompt("input site (google, facebook, naver)", "");
var url;

switch (site) {
    case "google":
        url = "www.google.com";
        break;

    case "facebook":
        url = "www.facebook.com";
        break;

    case "naver":
        url = "www.naver.com";
        break;

    default:
        alert("no");
        break;
}

if(url)
{
    //location.href = url;              // http://nuwanda22.github.io/url.com
    location.href = "http://" + url;    // http://url.com // http -> https
}

// 5.
for (var i = 1; i <= 100; i++) {
    if (i % 5 == 0 && i % 7 != 0) {
        document.write("<font color='red'>" + i + "</font>", "<br>");
    }
    else if (i % 5 != 0 && i % 7 == 0) {
        document.write("<font color='green'>" + i + "</font>", "<br>");
    }
    else if (i % 5 == 0 && i % 7 == 0) {
        document.write("<font color='aqua'>" + i + "</font>", "<br>");
    }
}

// 6. 
for (var i = 1; i <= 3; i++) {
    for (var j = 1; j <= 2; j++) {
        document.write(i + "행 " + j + "열 ");
    }
    document.write("<br>");
}

// 7.
var num = 1;
var t = "<table border=1>";

for (var i = 1; i <= 4; i++) {
    t += "<tr>"
    for (var j = 1; j <= 3; j++) {
        t += "<td>" + num++ + "</td>";
    }
    t += "</tr>"
}

t += "</table>";
document.write(t);