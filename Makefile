CC=clang -Wall -DLINUX

# use for windows binary compile
WCC=i686-w64-mingw32-gcc --static -DWINDOWS

all: tool.o Interp.o src/main.c
	$(CC) -o bin/InterpFit tool.o Interp.o src/main.c

Interp.o: src/Interp.h src/Interp.c
	$(CC) -c src/Interp.c -o Interp.o

tool.o: src/tool.h src/tool.c
	$(CC) -c src/tool.c -o tool.o

debug: InterpFit_Debug.o src/main.c
	$(CC) -g -o bin/InterpFit_Debug InterpFit_Debug.o src/main.c

InterpFit_Debug.o: src/InterpFit.h src/InterpFit.h
	$(CC) -g -c src/InterpFit.c -o InterpFit_Debug.o

Windows: InterpFit_win.o tool_win.o src/main.c
	$(WCC) -o bin/InterpFit_win.exe tool_win.o InterpFit_win.o src/main.c

InterpFit_win.o: src/InterpFit.h src/InterpFit.c
	$(WCC) -c src/InterpFit.c -o InterpFit_win.o

tool_win.o: src/tool.h src/tool.c
	$(WCC) -c src/tool.c -o tool_win.o

test: src/test_input.c
	$(CC) -o bin/test_input src/test_input.c

testWindows: src/test_input.c
	$(WCC) -o bin/test_input.exe src/test_input.c

clean:
	rm -rf bin/* *.o
