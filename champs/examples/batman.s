.name "Batman 
"
.comment "This city needs metest"

loop:
hyphen:	sti r1,%:live -- 2,%1
live:
        live%0
        ld%0, r2
        zjmp%:loop - :hyphen
		