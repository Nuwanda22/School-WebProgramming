function getDay() {
    var year = document.getElementById("year").value;
    var month = document.getElementById("month").value;
    var date = document.getElementById("date").value;
    var day = dayString(new Date(year, month - 1, date).getDay());

    document.write(year, "년 ", month, "월 ", date, "일은 ", day, "요일입니다. ", "<br>");
}

function dayString(day) {
    switch (day) {
        case 0:
            return "일";

        case 1:
            return "월";

        case 2:
            return "화";

        case 3:
            return "수";

        case 4:
            return "목";

        case 5:
            return "금";

        case 6:
            return "토";

        default:
            return "?";
    }
}

var result = [0, 0, 0];
var bool = [false, false, false];

function rockPaperScissors(value) {
    var userImage = "../images/math_img_" + value + ".jpg";
    document.getElementById("user").setAttribute("src", userImage);

    var random = Math.ceil(Math.random() * 3);
    var computerImage = "../images/math_img_" + random + ".jpg";
    document.getElementById("com").setAttribute("src", computerImage);

    var message;
    bool = whoIsWin(value, random);

    bool.forEach(function (item, index) {
        console.log(item);
        if (item){
            switch(index){
                case 0:
                message = "컴퓨터를 이겼습니다. ";
                break;

                case 1:
                message = "컴퓨터와 비겼습니다. ";
                break;

                case 2:
                message = "컴퓨터에게 졌습니다. ";
                break;
            }
            result[index]++;
            item = false;
        }
    });

    document.getElementById("message").innerText = message + " 통산전적 : " + result[0] + "승 " + result[1] + "무 " + result[2] + "패";
}

function whoIsWin(user, com){
    // 1 : 가위
    // 2 : 바위
    // 3 : 보
    var bool = [false, false, false];
    if (user == 1) {
        if (com == 1) {
            bool[1] = true;
        }
        else if(com == 2){
            bool[2] = true;
        }
        else if(com == 3){
            bool[0] = true;
        }
    }
    else if (user == 2) {
        if (com == 1) {
            bool[0] = true;
        }
        else if(com == 2){
            bool[1] = true;
        }
        else if(com == 3){
            bool[2] = true;
        }
    }
    else if (user == 3) {
        if (com == 1) {
            bool[2] = true;
        }
        else if(com == 2){
            bool[0] = true;
        }
        else if(com == 3){
            bool[1] = true;
        }
    }
    return bool;
}