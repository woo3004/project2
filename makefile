
# makefile for project 3 example tests

NUM:=3

numbers:=30 33 35 36 37 61 62

tests:=project$(NUM)-tests

.SILENT: all run

all: run
	@rm $(tests)/out.txt

run:
	for number in $(numbers) ; \
	do \
		echo "Running input $$number" ; \
		./lab$(NUM) $(tests)/in$$number.txt > $(tests)/out.txt ; \
		diff $(tests)/out$$number.txt $(tests)/out.txt || (echo "diff failed on test $$number \n") ; \
	done

compile:
	g++ -Wall -Werror -std=c++17 -g *.cpp -o lab$(NUM)

