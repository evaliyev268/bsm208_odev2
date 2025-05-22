#ifndef KISI_H
#define KISI_H

#include "H.h"


typedef struct sKisi Kisi;

Kisi* Construct_Kisi(const char* isim,const char*yas,const char*kalanOmur,const char* uzayAraciAdi);

int getKalanOmur(Kisi* kisi);

void setKalanOmur(Kisi* kisi,int komur);

const char* getKisiUzayAraciAdi(Kisi* kisi);

const char* getKisiAdi(Kisi* kisi);

int getKisiYas(Kisi* kisi);

void kisiOmurAzalt(Kisi *kisi);

void Destruct_Kisi(Kisi* kisi);




#endif