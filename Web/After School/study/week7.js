$(function () {
    $("#btn1").click(function () {
        $(".p").css("background-color", "purple");
        return false;       // 링크 차단
    });

    $("#btn2").click(function (e) {
        e.preventDefault(); // 링크 차단
        $(".p").css("background-color", "yellow");
    });

    $("#btn3").click(function () {
        $(".p").css("background-color", "aqua");
    });


    $("#user_name").focus();

    $("#user_id").focus(function () {
        $(this).val("");
    });

    $("#user_id").blur(function () {
        $(this).val("input your id");
    });


    $("#btn").mouseover(function () {
        $(this).css("border", "2px solid red");
        $(this).text("Mouse Over");
    });


    $("h1 a").on({
        "mouseover focus": function () {
            $(this).css("color", "red");
        },
        "mouseout blur": function () {
            $(this).css("color", "yellow");
        }
    });

    $("h2").append("<a href='#'>생성된 요소</a>");

    $("h2 a").on("mouseover focus", function () {
        $(this).css("background-color", "yellow");
    });

    $(document).on("mouseout blur", "h2 a", function () {
        $(this).css("background-color", "aqua");
    });


    var size = 12;
    var body = $("body");

    $(".zoom button").on("click", function () {
        var index = $(".zoom button").index(this);

        // +
        if (index == 0) {
            size++;
        }
        // -
        else if (index == 2) {
            size--;
        }
        // o
        else {
            size = 12;
        }

        body.css("font-size", size + "px");
    });

    $("#fs").on("change", function () {
        body.css("font-family", $(this).val());
    });
});