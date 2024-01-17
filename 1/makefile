.PHONY: all
	
all: main

debug: main.c
	gcc -g main.c -o main

debugfour: mainfour.c
	gcc -g mainfour.c -o mainfour
	
mainfour: mainfour.c
	gcc mainfour.c -o mainfour
main: main.c
	gcc main.c -o main

clean:
	rm -f main mainfour