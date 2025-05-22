#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H
#include "KisiArray.h"
#include "UzayAraciArray.h"
#include "GezegenArray.h"



typedef struct sDosyaOkuma {
    KisiArray* kisiArray;
    UzayAraciArray* uzayAraciArray;
    GezegenArray* gezegenArray;
    void(*DestructDosyaOkumaFunc)(struct sDosyaOkuma* dosyaOkuma);
} DosyaOkuma;

DosyaOkuma* Construct_DosyaOkuma();

void Destruct_DosyaOkuma(DosyaOkuma* dosyaOkuma);



#endif