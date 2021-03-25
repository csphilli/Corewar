.name "Header"
.comment "This will help the evaluator verify a correct header in the bytecode"

;Run this file. A valid header in bytecode is:
;00 ea 83 f3
;This can be verified in the asm.h file:
;# define COREWAR_EXEC_MAGIC	0xea83f3


live %0;

