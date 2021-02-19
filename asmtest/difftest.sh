#!/bin/bash
G='\033[0;32m'
R='\033[0;31m'
O='\033[0;33m'
P='\033[0;35m'
B='\033[0;34m'
C='\033[0;36m'
W='\033[0;37m'
Z='\033[48;5;052m'
Z2='\033[34;5;34m'
C='\033[0;36m'
NO='\033[0m'

clear
printf "\n\n            ASSEMBLER DIFFERENCE TEST \n\n"

rm -rf outfile
rm -rf asmfile
mkdir outfile
mkdir asmfile
printf "\ncopying all champions in /examples to /outfile & /asmfile...\n\n"

for filename in examples/*.s; do
#	printf "${C}copying $filename${NO}\n"
	cp $filename outfile
	cp $filename asmfile
done

printf "\ncompiling champions in /outfile...\n\n"

for filename in outfile/*.s; do
	../asm $filename
done

printf "\ncompiling champions in /asmfile...\n\n"

for filename in asmfile/*.s; do
	output2=$(./asm "$filename")
done

#printf "\n"
#ls copydir
#printf "\n"
printf "\n${W}${Z} compare results in /outfile to results in /asmfile ${NO}\n\n"

i=0
for filename in outfile/*.cor; do
a=0
	for filename2 in asmfile/*.cor; do
		if (( a == i )); then
			printf "diff $filename $filename2:\n"
			printf "${G}✅${R}\r"
			diff $filename $filename2
			printf "${NO}\n\n"
			((a++))
		else
			((a++))
		fi
	done
	((i++))
done
