$(function () {
    $(window).scroll(function () {
        var h = $(window).scrollTop();

        if (h >= 0 && h < 1000) {
            $(".main_bg").removeClass("on");
            $("#area1").addClass("on");
        } else if (1000 <= h && h < 2000) {
            $(".main_bg").removeClass("on");
            $("#area2").addClass("on");
        } else if (2000 <= h && h < 3000) {
            $(".main_bg").removeClass("on");
            $("#area3").addClass("on");
        } else {
            $(".main_bg").removeClass("on");
            $("#area4").addClass("on");
        }
    });

    $(window).trigger("scroll");
});
