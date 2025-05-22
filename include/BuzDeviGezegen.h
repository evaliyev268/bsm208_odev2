#ifndef BUZDEVIGEZEGEN_H
#define BUZDEVIGEZEGEN_H

#include "Gezegen.h"


typedef struct sBuzDeviGezegen {
    Gezegen* super;
    void (*Destruct_BGezegen)(struct sBuzDeviGezegen*);
} BuzDeviGezegen;

BuzDeviGezegen* Construct_BuzDeviGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO);

void Destruct_BuzDeviGezegen(BuzDeviGezegen* buzDeviGezegen);








































#endif