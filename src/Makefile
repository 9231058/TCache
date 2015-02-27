# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 27-02-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=TCache
OBJ=main.o cache.o block.o set.o common.o
LIB=
MLIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g
CFLAGS+=-DDEBUG

$(P): $(OBJ)
	$(CC) -o $(P) $(OBJ) $(LDLIBS)
main.o: cache.h
cache.o: cache.h set.h
block.o: block.h
set.o: set.h block.h common.h
common.o: common.h

.PHONY: clean
clean:
	rm $(OBJ) $(P)
