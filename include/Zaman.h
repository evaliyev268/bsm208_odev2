#ifndef ZAMAN_H
#define ZAMAN_H
#include "H.h"



typedef struct sTarih Tarih;

Tarih *Construct_Tarih(const char *str);





// t2-t1 gün farkı
int tarihFarki(Tarih *t1, Tarih *t2);

void gunEkle(Tarih *t, int n);

int stringToTarih(const char *str, Tarih *t);
const char *tarihToString(Tarih *t);

int isBefore(Tarih *t1, Tarih *t2);

int isAfter(Tarih *t1, Tarih *t2);
int isEqual(Tarih *t1, Tarih *t2);
void Destruct_Tarih(Tarih *t);
#endif