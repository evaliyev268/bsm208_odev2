#ifndef GEZEGENARRAY_H
#define GEZEGENARRAY_H

#include "Gezegen.h"
#include "KayacGezegen.h"
#include "GazDeviGezegen.h"
#include "BuzDeviGezegen.h"
#include "CuceGezegen.h"


typedef struct sGezegenArray{
    Gezegen *gArray[GEZEGEN_SIZE];
    int size;
    void (*addGezegenArrayF)(struct sGezegenArray* gezegenArray,const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu,char gezegenTuruNO);
    void (*Destruct_GezegenArrayF)(struct sGezegenArray* gezegenArray);
} GezegenArray;



GezegenArray* Construct_GezegenArray();

void addGezegenArray(GezegenArray *gezegenArray,const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu,char gezegenTuruNO);

void Destruct_GezegenArray(GezegenArray* gezegenArray);































#endif