#ifndef KISIARRAY_H
#define KISIARRAY_H


#include "Kisi.h"


typedef struct sKisiArray{
  Kisi* kArray[ARRAY_SIZE]; 
    int size; 
     void (*AddKisiArrayFunc)(struct sKisiArray*, Kisi*);
 void (*DestructKisiArrayFunc)(struct sKisiArray*);
} KisiArray;

// KisiArray oluşturma
KisiArray* Construct_KisiArray();

void addKisiArray(KisiArray *kisiArray,Kisi *kisi);

// KisiArray yok etme
void Destruct_KisiArray(KisiArray* kisiArray);



#endif 