.name "Batman test"
.comment "This city needs me    "

loop:
hyphen:	 sti r45,%:live, %1 ;comment
		zjmp %:live
live:   
		live %0
        ld %0, r2
		sti r2, %:hyphen, %1
        zjmp %:loop

avdeftgt:
