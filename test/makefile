all: main.exe run

main.exe: main.c ../queue.c
	@clang -Wall -o main.exe main.c ../queue.c

run:
	@./main.exe
