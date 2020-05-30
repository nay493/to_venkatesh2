
#ifdef __linux__
CC=gcc
#elif _WIN32
CC=i586-mingw32msvc-gcc

all:
	${CC} hello.c -o main.exe

clean:
	rm -rf main*
