MODE = graphic
CFLAGS = -g -Wall
IFLAGS = -Iinclude	#include (.h)
OBJDIR = obj/
SRCDIR = src/
BINDIR = bin/
LIBDIR = lib/
DOCDIR = doc/
CPPFLAGS =
LDFLAGS =
TARBALLNAME = FayssalAb-GoL.tar.xz

ifeq ($(MODE), graphic)
		CPPFLAGS += -Iinclude -I/usr/include/cairo
	LDFLAGS += -lcairo -lm -lX11
endif

SRC = $(notdir $(SRCDIR)*.c) #selectionne tous les .c mais sans le /src devant
OBJ = $(SRC:.c=.o) #Transforme tous les .c en .o
OBJ := $(addprefix $(OBJDIR), $(OBJ)) #ajoute obj/ devant tous les .o

vpath %.h include
vpath %.c src
vpath %.o obj
vpath %.a lib
vpath main bin

ifeq ($(MODE),graphic)
main: main.o io_cairo.o libjeu.a #grille.o jeu.o
	mkdir -p $(BINDIR)
	gcc $(CFLAGS) -o $(BINDIR)$@ $(OBJ) $(CPPFLAGS) $(LDFLAGS)

else
main2: main2.o io.o libjeu.a #grille.o jeu.o
	mkdir -p $(BINDIR)
	gcc $(CFLAGS) -o $(BINDIR)$@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) -DTEXTE
endif


main2.o: main.c
	mkdir -p $(OBJDIR)
	gcc $(CFLAGS) -c $< $(IFLAGS) $(CPPFLAGS) $(LDFLAGS) -DTEXTE
	mv main.o $(OBJDIR)

main.o: main.c
io.o: io.c
io_cairo.o: io_cairo.c
grille.o: grille.c
jeu.o: jeu.c



%.o:
	mkdir -p $(OBJDIR)
	gcc $(CFLAGS) -c $< $(IFLAGS) $(CPPFLAGS) $(LDFLAGS)
	mv $@ $(OBJDIR)

libjeu.a: jeu.o grille.o
	mkdir -p $(LIBDIR)
	ar -crv $@ $(OBJDIR)$< $(OBJDIR)grille.o
	ranlib $@
	mv $@ $(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
	rm -rf $(DOCDIR)
	rm -rf $(LIBDIR)
	rm -f  $(TARBALLNAME)

dist:
	tar -cJ src/ include/ grilles/ makefile Doxyfile README.md -f $(TARBALLNAME)
