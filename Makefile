all: spellbee

spellbee: main.c
	gcc -Wall -o spellbee main.c
