#!/bin/bash
G='\033[0;32m'
R='\033[0;31m'
O='\033[0;33m'
B='\033[0;34m'
C='\033[0;36m'
W='\033[0;37m'
Z='\033[48;5;052m'
Z2='\033[34;5;34m'
NO='\033[0m'

clear
if (( $# < 1 )); then
echo -e "${B}${Z2}
 USAGE: ${G} ****************************************\n
 ./test_alone.sh [file including your warriors.s]

${G}*************************************************\n"
        exit 0
        fi
ARG=$1
printf "\n\n COREWAR ALONE TEST\n\n"
printf "✅ = orignial VM gives same print output\n"

printf "\n${W}${Z} compiling $ARG champions... ${NO}\n\n"
for filename in $ARG/*.s; do
	./asm "$filename"
done

printf "\n${W}${Z} examples ${NO}\n\n"
for filename2 in $ARG/*.cor; do
	printf "${C}$filename2 ${NO}\n"
	./corewar -v 4 "$filename2" > difffile1
	../corewar -p "$filename2" > difffile2
        diff difffile1 difffile2 > di
	printf "${O}original corewar lines:  ${NO}"
	wc -l difffile1 > linecount
	read word _ < linecount
	echo "$word"
	rm linecount  
	printf "${O}same output until lines: ${NO}"
	head -1 di
	wc -l di > difffile4 
        printf "${G}✅${R}\r"
	diff dif difffile4
        printf "${NO}\n\n"
	rm difffile1
	rm difffile2
	rm di
	rm difffile4
done

