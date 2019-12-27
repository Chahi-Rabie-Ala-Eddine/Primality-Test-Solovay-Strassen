CFLAGS = -g -Wall -c
CFLAGSGR = ${CFLAGS} `sdl-config --cflags`
LSFLAG = `sdl-config --cflags --libs`
LFLAGS = -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf
GMPFLAG = -lgmp

# Edition de lien du programme principal
main: main.o solovay_strassen.o arithmetic.o symbol_of_jacobi.o symbol_of_legendre.o square_and_multiply.o 
	gcc -o solovay_strassen main.o solovay_strassen.o arithmetic.o symbol_of_jacobi.o symbol_of_legendre.o square_and_multiply.o ${LSFLAG} ${LFLAGS} ${GMPFLAG}

# Compilation du programme principal
main.o: main.c solovay_strassen.h symbol_of_jacobi.h symbol_of_legendre.h square_and_multiply.h arithmetic.h
	gcc ${CFLAGSGR} $*.c ${LSFLAG} ${GMPFLAG}

# Compilation des différents.o
solovay_strassen.o: solovay_strassen.c solovay_strassen.h arithmetic.h symbol_of_jacobi.h symbol_of_legendre.o square_and_multiply.h
	gcc ${CFLAGSGR} $*.c ${LSFLAG} ${GMPFLAG}

# Compilation des différents.o
symbol_of_jacobi.o: symbol_of_jacobi.c symbol_of_jacobi.h arithmetic.h square_and_multiply.h symbol_of_legendre.h
	gcc ${CFLAGSGR} $*.c ${LSFLAG} ${GMPFLAG}
	
# Compilation des différents.o
symbol_of_legendre.o: symbol_of_legendre.c symbol_of_legendre.h arithmetic.h square_and_multiply.h solovay_strassen.h
	gcc ${CFLAGSGR} $*.c ${LSFLAG} ${GMPFLAG}

# Compilation des différents.o
square_and_multiply.o: square_and_multiply.c square_and_multiply.h arithmetic.h
	gcc ${CFLAGSGR} $*.c ${LSFLAG} ${GMPFLAG}

# Compilation des différents.o
arithmetic.o: arithmetic.c arithmetic.h
	gcc ${CFLAGSGR} $*.c ${LSFLAG} ${GMPFLAG}
	
# Le clean
clean:
	rm -f *.o
	rm -f main

# Pour faire un zip
LENOM=Chahi_Rabie_Ala_Eddine_Keskes_Yasmine
zip:
	rm -rf ${LENOM}
	rm -rf ${LENOM}.zip
	mkdir ${LENOM}
	cp Makefile ${LENOM}
	cp *.h *.c ${LENOM}
	zip -r ${LENOM}.zip ${LENOM}
	rm -rf ${LENOM}

# Pour installer uvsqgraphics
uvsqgraphics:
	wget https://www.fichier-zip.com/2018/03/12/uvsq-graphics/uvsq-graphics.zip
	unzip uvsq-graphics.zip
	cd UVSQ_graphics
	make

# Pour installer GMP 
gmp:
	sudo apt-get install lzip
	wget https://gmplib.org/download/gmp/gmp-6.1.2.tar.lz
	tar --lzip -xvf gmp-6.1.2.tar.lz gmp-6.1.2
	cd gmp-6.1.2
	gmp-6.1.2/configure
	make
	make check
	sudo make install

