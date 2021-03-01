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
 ./test_battle.sh [file including your warriors.s]

${G}*************************************************\n"
        exit 0
        fi

ARG=$1

printf "\n\n COREWAR BATTLE TEST \n\n"
printf "✅ = orignial VM gives same winner\n"

printf "\n${W}${Z} compiling champions... ${NO}\n\n"
for filename in $ARG/*.s; do
	./asm "$filename"
done
cp -rf $ARG clones
for filename3 in $ARG/*.cor; do
	printf "\n${W}${Z} $filename3 vs everybody ${NO}\n\n"
	for filename2 in clones/*.cor; do
		printf "${C}$filename3 vs. $filename2${NO}\n"
		./corewar "$filename3" "$filename2" > winners
		../corewar "$filename3" "$filename2" > winners2
		tail -n 1 winners > outfile6
		cat outfile6
		awk -F'[""]' '{print $2}' outfile6 > difffile1
		tail -n 1 winners2 > outfile6
		cat outfile6
		awk -F'[()]' '{print $2}' outfile6 > difffile2
                printf "${G}✅${R}\r"
                diff difffile1 difffile2
                printf "${NO}\n\n"
		rm winners*
	done
done
rm winners*
rm outfile6
rm difffile*
