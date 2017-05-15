$(function(){
    var prev = null;

    $(".main").on("click", function(){    
        var item = $(this).next();
        item.toggle("fold");
        
        if(!item.is(prev) && prev != null) {
            prev.toggle("fold");
        } 
        
        if(item.is(prev)) {
            prev = null;
        } else {
            prev = item;
        }
    });
});