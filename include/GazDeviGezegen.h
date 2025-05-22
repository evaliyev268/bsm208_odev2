#ifndef GAZDEVIGEZEGEN_H
#define GAZDEVIGEZEGEN_H

#include "Gezegen.h"


typedef struct sGazDeviGezegen {
    Gezegen* super;
    void (*Destruct_GGezegen)(struct sGazDeviGezegen*);
} GazDeviGezegen;

GazDeviGezegen* Construct_GazDeviGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO);

void Destruct_GazDeviGezegen(GazDeviGezegen* gazDeviGezegen);











#endif