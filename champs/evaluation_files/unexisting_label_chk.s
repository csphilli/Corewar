.name "Unexisting label check"
.comment "this file helps the evaluator verify that labels exist"

;If an instruction has a T_DIR or T_IND label and the label is not found in the rest of the code,
;the program will produce an error.

;The first set of instructions utilizing label_1 and label_2 are correct. 
;The instruction 'live %:label_1' finds the label in the previous couple lines.
;The program should parse over this because it is correct syntax.

label_1:
	live %1
label_2:
	live %:label_1>

;These next instructions will produce an error because the reference to 'label_fiver' is not an
;existing label.

label_4:
	live %:label_fiver
label_5:
	live %2
