all: report

report : main.o temp_functions.o
	gcc main.o temp_functions.o -o report

main.o : main.c
	gcc -c main.c -o main.o

temp_functions.o : temp_functions.c
	gcc -c temp_functions.c -o temp_functions.o