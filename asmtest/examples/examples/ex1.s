.name "zork"
.comment "just a basic living prog"
		
l2:	ldi	r1,r1,r1
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
