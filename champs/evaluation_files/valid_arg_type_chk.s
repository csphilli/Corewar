.name "valid arg type check"
.comment "this file helps the evaluator check for valid arg types"

;Each instruction line below tests the different opcodes. An incorrect value has been
;filled for you. The correct arg types are commented at the end. Simply change the
;instruction to match a valid arg type. Feel free to check the other invalid types
;for a given instruction.

;NOTE that the argument count is correct in each example.

;T_DIR = '%'
;T_REG = 'r'
;T_IND = - (signifies there isn't an indicator)

;instruction with invalid type(s)			;correct types
live r1										;T_DIR
ld r1, %r1									;T_DIR / T_IND | T_REG
st 1, %2									;T_REG | T_REG / T_IND
add %r1, %2, 3								;T_REG | T_REG | T_REG
sub 1, %2, 3								;T_REG | T_REG | T_REG
and r1, r2, %3								;T_REG / T_DIR / T_IND | T_REG / T_DIR / T_IND | T_REG
or r1, r2, 3								;T_REG / T_DIR / T_IND | T_REG / T_DIR / T_IND | T_REG
xor r1, r2, %3								;T_REG / T_DIR / T_IND | T_REG / T_DIR / T_IND | T_REG
zjmp %1										;T_DIR
ldi r1, r2, %3								;T_REG / T_DIR / T_IND | T_REG / T_DIR | T_REG
sti r1, r2, 3								;T_REG | T_REG / T_DIR / T_IND | T_REG / T_DIR
fork 1										;T_DIR
lld r1, %2									;T_DIR / T_IND | T_REG
lldi r1, r2,%3								;T_REG / T_DIR / T_IND | T_REG / T_DIR | T_REG
lfork	r1									;T_DIR
aff %1										;T_REG
