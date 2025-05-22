#ifndef KAYACGEZEGEN_H
#define KAYACGEZEGEN_H

#include "Gezegen.h"


typedef struct sKayacGezegen{
    Gezegen* super;
    void (*Destruct_KGezegen)(struct sKayacGezegen*);
} KayacGezegen;

KayacGezegen* Construct_KayacGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO);

void Destruct_KayacGezegen(KayacGezegen* kayacGezegen);







































#endif