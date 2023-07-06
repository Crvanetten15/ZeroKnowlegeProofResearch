main: main.o multiplier.o
        gcc -o main ex.o multiplier.o
main.o: ex.c multiplier.h
        gcc -c -g ex.c
util.o: multiplier.c multiplier.h
        gcc -c -g multiplier.c
