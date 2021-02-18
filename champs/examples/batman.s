.name "Batman"
.comment "This city needs me"

loop:
	sti r1,%:live -0xae09-0x443a,%1
	;sti r1,%:live,%1
live:
        live%2 + :loop
        ld%0, r2
        zjmp%0x34a
		