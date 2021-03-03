.name "Valid argument nbr check"
.comment "This file helps the evaluator check for valid number of arguments per opcode"

;Currently, every opcode has an incorrect number of arguments. There should be
;and error for every one. Simply correct each line to match the required number.
;The next error output should reflect the following line.

;NOTE this test is only checking arg counts. The types don't matter. That's in another
;check file.


;args					;valid argument count
live %1, %1				;1
ld %1, r1, r2			;2
st r1, r2, r2			;2
add r1, r2, r3, r2		;3
sub r1, r2, r3, r2		;3
and r1, r2, r3, r2		;3
or r1, r2, r3, r1		;3
xor r1, r2, r3, r1		;3
zjmp %1, %1				;1
ldi r1, r2, r3, r2		;3
sti r1, r2, r3, r2		;3
fork %1, %2				;1
lld %1, r2, r3			;2
lldi r1, r2, r3, r1		;3
lfork	%1, %2			;1
aff r1, r2				;1

;Our ASM counts the number of arguments based on the seperator_char (,).
;In the next example, notice that a seperator_char is present, but no args were
;defined. This is still valid. Despite there not being an argument defined, the program
;is expecting one and will error out if the result would be an incorrect number or type

live %1,				;1
