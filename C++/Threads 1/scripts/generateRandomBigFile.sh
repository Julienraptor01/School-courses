#!/bin/bash
filePath="./assets/data.txt"
rm -f "$filePath"
touch "$filePath"
numberOfLines=$(shuf -i 1500-2000 -n 1)
for lineNumber in $(seq 1 "$numberOfLines"); do
	randomNumber=$(shuf -i 1-10 -n 1)
	if [ "$randomNumber" -eq 1 ]; then
		echo "cout" >> "$filePath"
	elif [ "$randomNumber" -eq 2 ]; then
		echo "NULL" >> "$filePath"
	elif [ "$randomNumber" -eq 3 ]; then
		echo "void" >> "$filePath"
	elif [ "$randomNumber" -eq 4 ]; then
		echo "endl" >> "$filePath"
	else
		echo "$(cat /dev/urandom | tr -dc '[:print:]' | head -c 4)" >> "$filePath"
	fi
done
