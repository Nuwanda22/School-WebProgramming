$(function(){
	$("nav ul ul").css({display:"none"});

	$("nav ul>li").hover(
		function(){
			$(this).find("ul").stop().slideDown();
			$(this).find("a:first").addClass("on");
		},
		function(){
			$(this).find("ul").stop().slideUp();
			$(this).find("a:first").removeClass("on");
		}
	);
});
