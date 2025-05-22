#ifndef  UZAYARACI_H
#define  UZAYARACI_H
#include "H.h"
#include "Zaman.h"
/*getCikisTarihi()
getKalanMesafeString()
getKalanMesafe()
setKalanMesafe(int i)
getNufus()
setNufus(long n)
get UzayAraciAdi()
getVarisGezegeniAdi()
getCikisGezegeniAdi()
getDurum()
setVarisTarihi(LocalDate t)
setDurum(String s)
 UzayAraci(String u, String cGe, String vGe, LocalDate ct, String k) (Yapıcı/Conor)
getVarisTarihi()
getVarisTarihiString()
static mesafeAzalt( UzayAraci u)*/
#define NAME_LEN 100
#define DATE_LEN 32
#define STATUS_LEN 32

typedef struct sUzayAraci UzayAraci;

UzayAraci *Construct_UzayAraci(const char *uaAdi, const char *cGe, const char *vGe, const char *ct, const char *k);

const char* getKalanMesafeString( UzayAraci *u);

int getKalanMesafe( UzayAraci *u);

void setKalanMesafe( UzayAraci *u, int i); 

long getNufus( UzayAraci *u);

void setNufus( UzayAraci *u, long n);

const char* getUzayAraciAdi( UzayAraci *u);

const char* getVarisGezegeniAdi( UzayAraci *u);

const char* getCikisGezegeniAdi( UzayAraci *u);

const char* getDurum( UzayAraci *u);


void setDurum( UzayAraci *u, const char *s);

Tarih *getVarisTarihi( UzayAraci *u);
Tarih *getCikisTarihi( UzayAraci *u);
const char* getVarisTarihiString( UzayAraci *u);

void setVarisTarihi( UzayAraci *u, Tarih *t);


void mesafeAzalt( UzayAraci *u);

void Destruct_UzayAraci( UzayAraci *u);

#endif