window.onload = function () {
    document.getElementsByTagName("h1")[0].style.color = "green";
    document.getElementById("title").style.color = "red";

    var myList = document.getElementById("food_1").getElementsByTagName("li")[1];
    myList.style.backgroundColor = "red";
}

var color = ["white", "yellow", "aqua", "purple"];
var i = 0;
function colorBg() {
    if (++i >= color.length) i = 0;

    var bodyTag = document.getElementsByTagName("body")[0];
    bodyTag.style.backgroundColor = color[i];
}

function submitCheck(myForm) {
    var reg1 = /^[가-힣]{2,5}$/;
    var reg2 = /^(010|016|011)\d{3,4}\d{4}$/;

    var name = myForm.user_name;
    var tel = myForm.user_tel;

    if (!reg1.test(name.value)) {
        alert("이름 입력이 잘못되었습니다.");
        name.value = "";
        name.focus();
        return false;
    } else if (!reg2.test(tel.value)) {
        alert("연락처 입력이 잘못되었습니다.");
        tel.value = "";
        tel.focus();
        return false;
    }
}

function resetCheck(myForm){
    var result = confirm("정말로 회원가입을 취소하시겠습니까?");

    if(result){
        return false;
    }
}