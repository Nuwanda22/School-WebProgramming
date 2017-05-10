$(function () {
    $("#btn1").on("click", function () {
        $("#h1").slideUp(1000);
    });

    $("#btn2").on("click", function () {
        $("#h1").slideDown(1000);
    });

    $("#btn3").on("click", function () {
        $("#h1").slideToggle("fast");
    });

    var list = $("#banner");
    var show_num = 3;
    var num = 0;
    var total = $(">li", list).size();
    var li_width = $("li:first", list).width();

    var copyObj = $(">li:lt("+show_num+")","list").clone();
    list.append(copyObj);

    $(".next").on("click", function(){
        if(num==total){
            num=0;
            list.css("margin-left",num);
        }
        num++;
        list.stop().animate({marginLeft:-li_width*num+"px"}, 500);
        return false;
    });

    $(".prev").on("click", function(){
        if(num==0){
            num=total;
            list.css("margin-left",-num*li_width+"px");
        }
        num--;
        list.stop().animate({marginLeft:-li_width*num+"px"}, 500);
        return false;
    });
});