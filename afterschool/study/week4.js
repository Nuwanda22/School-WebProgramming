// function promptReg(reg) {
//     var input = prompt('당신의 이름은?');
//     while (true) {
//         if (reg.test(input)) break;

//         alert("이름 입력 형식이 잘못되었습니다!");
//         input = prompt('당신의 이름은?');
//     }
//     return input;
// }

// var reg1 = /^[가-힣]{2,5}$/;
// var reg2 = /^(010|011|016)-\d{3,4}-\d{4}$/;
// var reg3 = /^\w{3,10}@([a-z\d.-]+)\.([a-z\.]{2,6})$/;

// var userName = promptReg(reg1);
// var userCell = promptReg(reg2);
// var userEmail = promptReg(reg3);

// alert('good!');

//window.open('pop.html', 'pop', 'width = 300, height=400, left=300, top=10,scrollbars=no,toolbars=no,location=no');

window.onload = function () {
    var list = document.getElementById("inner_list");
    var aTags = list.getElementsByTagName("a");

    for (var i = 0; i < aTags.length; i++) {
        aTags[i].onclick = function () {
            var photo = document.getElementById("photo").children[0];
            photo.src = this.href;
            return false;
        }
    }

    var bButton = document.getElementById("next_btn");
    var num = 0;
    bButton.onclick = function () {
        if (num >= aTags.length - 3) return false;

        num++;
        list.style.marginLeft = -100 * num + "px";

        return false;
    }

    var nButton = document.getElementById("before_btn");
    nButton.onclick = function () {
        if (num <= 0) return false;

        num--;
        list.style.marginLeft = -100 * num + "px";

        return false;
    }
}