.name "Valid label check"
.comment "this file helps the evaluator check for valid characters in a label"

;The valid label chars are "abcdefghijklmnopqrstuvwxyz_0123456789"
;Anything outside that should produce an error.

;The first label and instruction is valid to show you that the parser indeed validates it.
;The second label is incorrect.

;The instructions, arg count and types are correct.

valid_label:

	live %1

invalid_label>:

	live %2
