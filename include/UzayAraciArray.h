#ifndef UZAYARACIARRAY_H
#define UZAYARACIARRAY_H

#include "H.h"
#include "UzayAraci.h"
#include "GezegenArray.h"

typedef struct sUzayAraciArray{
  UzayAraci* uArray[ARRAY_SIZE]; 
    int size;  
    void (*addUzayAraciArrayF)(struct sUzayAraciArray* uzayAraciArray, UzayAraci* uzayAraci);
    void (*Destruct_UzayAraciArrayF)(struct sUzayAraciArray* uzayAraciArray);
    void (*setAllVarisTarihiF)(struct sUzayAraciArray* uzayAraciArray, GezegenArray* gezegenArray);
    void (*farkiEkleF)(GezegenArray*gezegen,struct sUzayAraciArray* uzayAraciArray);
} UzayAraciArray;

UzayAraciArray* Construct_UzayAraciArray();
void addUzayAraciArray(UzayAraciArray *uzayAraciArray, UzayAraci *uzayAraci);
void Destruct_UzayAraciArray(UzayAraciArray* uzayAraciArray);


void setAllVarisTarihi(UzayAraciArray *uzayAraciArray,GezegenArray *gezegenArray);

void farkiEkle(GezegenArray *gezegenArray,UzayAraciArray *uzayAraciArray);




#endif