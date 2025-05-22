#ifndef CUCEGEZEGEN_H
#define CUCEGEZEGEN_H

#include "Gezegen.h"


typedef struct sCuceGezegen {
    Gezegen* super;
    void (*Destruct_CGezegen)(struct sCuceGezegen*);
}CuceGezegen;

CuceGezegen* Construct_CuceGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO);

void Destruct_CuceGezegen(CuceGezegen* cuceGezegen);








































#endif