.name "dud"
.comment "world peace"

	sti r1, %:live, %1
	ld %-100, r2
	ld %12, r5
	ld %1, r4
	ld %500, r3
send:
	sti r2, %0, r3
	sti r5, %-8, r3
	sti r4, %-19, r3
	sti r1, %-21, r3
	add r3, r2, r3 
	fork %40
live:
	live %1
	zjmp %:live
	add r10, r10, r10
	st r1, 1001
	st r4, 1000
	zjmp %:send
