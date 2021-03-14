.name "duplicate check"
.comment "checking for duplicates"

;This file helps the evaluator check for duplicate labels.
;Just add a duplicate label anywhere to validate test.

lab12:
lab25:
lab13: sti r1, 5, %4+4

live %4

lab3: live %5

lab1: live %6
