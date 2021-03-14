.name "LeRoy Jenkins"
.comment "Time's up! Let's do this!! LEROOOOOOOOOOY JENKIIIIIIINS!!!!"


war_cry:
	live %8765309
	st r2,-9
	st r2,-18
	st r2,-27
	st r2,-36
	st r2,-45
	st r2,-54
	st r2,-63
	st r2,-72
	st r2,-81
	st r2,-90
	st r2,-99
	st r2,-108
	st r2,-117
	st r2,-126
	st r2,-135
	st r2,-144
	st r2,-153
	st r2,-162
	st r2,-171
	st r2,-180
	st r2,-189
	st r2,-198
	st r2,-207
	live %0
	live %2343434212
	zjmp %:war_cry
	

aggro_eggs:
	live %9082633
	st r3, 42
	st r4, 24
	fork %:howling_terror
	ld %0, r15
	ld %1, r14
	fork %: more_dots
	st r1, 11
	st r2, 21
	fork %:flee

more_dots:
	live %23498383
	live %39338773
	st r1, 212
	st r2, 121
	zjmp %:flee

howling_terror:
	st r2, 15
	st r3, -5
	zjmp %:flee

flee:
	st r2, 14
	st r1, 12
	live %3836233

live:
	live %0








