CC = gcc
CC_FLAGS =  -g -pedantic -W -Wall
FILES = main.c input.h input.c display.h display.c registration.h registration.c
OUT_EXE = ass2 

build:	$(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

clean:	rm -f *.o core *.exe *~

rebuild:	clean build