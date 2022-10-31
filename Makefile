
main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

funcs.o: funcs.cpp funcs.h imageio.h 

main.o: main.cpp funcs.h imageio.h

clean:
	rm -f sample.o imageio.o main.o funcs.o
