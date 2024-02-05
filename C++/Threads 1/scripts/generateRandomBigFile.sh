#!/bin/bash
filePath="./assets/data.txt"
rm -f "$filePath"
touch "$filePath"
numberOfLines=$(shuf -i 1500-2000 -n 1)
for lineNumber in $(seq 1 "$numberOfLines")
do
	if [ "$(shuf -i 1-10 -n 1)" -eq 7 ]
	then
		echo "printf" >> "$filePath"
	else
		echo "$(cat /dev/urandom | tr -dc '[:print:]' | head -c 6)" >> "$filePath"
	fi
done
