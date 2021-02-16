#!/bin/bash
# Small script that goes through the champs/examples .s files
# and compares the output of our asm to the subject asm

ASM_SUBJECT="./champs/asm_subject"
ASM="./asm"

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

for input_file in ./champs/examples/*.s; do
	printf "INPUT: %s\n" $input_file
	ASM_output=$($ASM $input_file)
	ASM_S_output=$($ASM_SUBJECT $input_file)
	ASM_output_file=$(echo $ASM_output | cut -d' ' -f4)
	ASM_S_output_file=$(echo $ASM_S_output | cut -d' ' -f5)
	printf "1: %s 2: %s\n" $ASM_output_file $ASM_S_output_file
	diff $ASM_output_file $ASM_S_output_file && echo "${GREEN}no difference${NC}" || echo "${RED}differences!${NC}"
	printf "\n"
done