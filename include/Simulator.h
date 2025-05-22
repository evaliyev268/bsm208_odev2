#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "DosyaOkuma.h"
#include "windows.h"

typedef struct sSimulator {

    void (*DestructSimulatorFunc)(struct sSimulator*);
    void (*ProgramStartFunc)(struct sSimulator*);

} Simulator;


Simulator* Construct_Simulator();

void ProgramStart(Simulator* simulator);

void Destruct_Simulator(Simulator* simulator);




























#endif