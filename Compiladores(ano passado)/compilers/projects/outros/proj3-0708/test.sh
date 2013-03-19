#!/bin/bash
make clean && make
cp a.out project3-tests/ && cd project3-tests
for file in $(find . -type f -name "*.in"); do
	echo $file
	./a.out < $file > dump
	./c3esim32 dump < $(ls "$file" | sed -s "s/in/dat/") > dump2
	diff dump2 $(ls "$file" | sed -s "s/in/out/")
	rm dump dump2
	echo && echo
done
rm a.out && cd ..
