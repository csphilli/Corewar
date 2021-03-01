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
 ./test_triple_battle.sh [file including your warriors.s]

${G}*************************************************\n"
        exit 0
        fi
ARG=$1

printf "\n\n COREWAR battle of 3 TEST\n\n"

rm -rf champs1
rm -rf champs2
rm -rf champs3

printf "\n${W}${Z} compiling champions... ${NO}\n\n"

mkdir champs1

for filename in $ARG/*.s; do
	./asm "$filename"
        cp $filename champs1/
done

for filename5 in champs1/*.s; do
	./asm "$filename5"
done
	
rm champs1/*.s

printf "\n${W}${Z} champions ${NO}\n\n"
ls champs1
printf "${NO}\n\n"

printf "✅ = orignial VM gave same winner\n\n"
cp -rf champs1 champs2
cp -rf champs1 champs3
for filename4 in champs1/*.cor; do
	printf "\n${W}${Z} $filename4 vs everybody vs everybody ${NO}\n\n"
	for filename3 in champs2/*.cor; do
		for filename2 in champs3/*.cor; do
			printf "${C}$filename4 $filename3 vs. $filename2${NO}\n"
			./corewar "$filename4" "$filename3" "$filename2" > winners
			tail -n 1 winners > outfile6
			cat outfile6
			awk -F'[""]' '{print $2}' outfile6 > difffile1
			../corewar "$filename4" "$filename3" "$filename2" > winners2
			tail -n 1 winners2 > outfile6
			cat outfile6
			awk -F'[()]' '{print $2}' outfile6 > difffile2
      	         	printf "${G}✅${R}\r"
       	         	diff difffile1 difffile2
       	         	printf "${NO}\n\n"
		done
	done
done
