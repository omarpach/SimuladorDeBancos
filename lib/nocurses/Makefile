CC::=gcc
PREFIX::=/usr/local

all:

install: nocurses.h
	install -CD nocurses.h ${PREFIX}/include/nocurses.h

uninstall:
	rm ${PREFIX}/include/nocurses.h

demo: demo.c nocurses.h
	${CC} -pthread -lm -o demo1 demo1.c

clean:
	rm demo
