all: compile run

compile:
	gcc -I ./include/ -o ./lib/BuzDeviGezegen.o -c ./src/BuzDeviGezegen.c
	gcc -I ./include/ -o ./lib/App.o -c ./src/App.c
	gcc -I ./include/ -o ./lib/CuceGezegen.o -c ./src/CuceGezegen.c
	gcc -I ./include/ -o ./lib/DosyaOkuma.o -c ./src/DosyaOkuma.c
	gcc -I ./include/ -o ./lib/GazDeviGezegen.o -c ./src/GazDeviGezegen.c
	gcc -I ./include/ -o ./lib/Gezegen.o -c ./src/Gezegen.c
	gcc -I ./include/ -o ./lib/GezegenArray.o -c ./src/GezegenArray.c
	gcc -I ./include/ -o ./lib/KayacGezegen.o -c ./src/KayacGezegen.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/KisiArray.o -c ./src/KisiArray.c
	gcc -I ./include/ -o ./lib/Simulator.o -c ./src/Simulator.c
	gcc -I ./include/ -o ./lib/slre.o -c ./src/slre.c
	gcc -I ./include/ -o ./lib/UzayAraci.o -c ./src/UzayAraci.c
	gcc -I ./include/ -o ./lib/UzayAraciArray.o -c ./src/UzayAraciArray.c
	gcc -I ./include/ -o ./lib/Zaman.o -c ./src/Zaman.c
	gcc -I ./include/ -o ./bin/program.exe \
        ./lib/App.o \
        ./lib/BuzDeviGezegen.o \
        ./lib/CuceGezegen.o \
        ./lib/DosyaOkuma.o \
        ./lib/GazDeviGezegen.o \
        ./lib/Gezegen.o \
        ./lib/GezegenArray.o \
        ./lib/KayacGezegen.o \
        ./lib/Kisi.o \
        ./lib/KisiArray.o \
        ./lib/Simulator.o \
        ./lib/slre.o \
        ./lib/UzayAraci.o \
        ./lib/UzayAraciArray.o \
        ./lib/Zaman.o

run:
	./bin/program.exe
