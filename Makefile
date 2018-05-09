CC = cl
CFLAGS = -W4 -O2
DYNAMIC = /LD /DEXPORT_DLL

all: Mp3TagEditor

python: library

library: Mp3TagEditor.c hashset
	$(CC) $(CFLAGS) $(DYNAMIC) Mp3TagEditor.c hashset.lib

Mp3TagEditor: main.c library
	$(CC) $(CFLAGS) main.c Mp3TagEditor.lib /Fe: Mp3TagEditor.exe

hashset: hashset.c
	$(CC) $(CFLAGS) $(DYNAMIC) hashset.c

hashmap: hashmap.c hashset
	$(CC) $(CFLAGS) $(DYNAMIC) hashmap.c hashset.lib

testDep: Mp3TagEditor.c hashmap
	$(CC) $(CFLAGS) /c Mp3TagEditor.c /link hashmap.lib

test: main.c testDep hashmap
	$(CC) $(CFLAGS) main.c /link Mp3TagEditor.obj hashmap.lib


.PHONY: clean

clean:
	del *.obj *.lib *.exp

.PHONY: clean-all

clean-all: clean
	del *.exe *.dll
