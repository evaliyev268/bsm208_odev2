#ifndef GEZEGEN_H
#define GEZEGEN_H
#include "Zaman.h"


/*setNufus(long n)
getNufus()
getGezegenAdi()
Gezegen(String ga, String bks, String bgt, String gezegenTuru) (Yapıcı/Constructor)
*/


typedef struct sGezegen {
    char gezegenAdi[32];
    Tarih *buGununTarihi;
    int birGununKacSaatOldugu;
    long nufus;
    char gezegenTuru[20];
    void (*Destruct_Gezegen)(struct sGezegen*);
    void (*setNufus)(struct sGezegen*, long);
    long (*getNufus)(const struct sGezegen*);
    const char* (*getGezegenAdi)(const struct sGezegen*);
    int   (*getBirGununKacSaatOldugu)(const struct sGezegen* gezegen);
    Tarih* (*getBuGununTarihi)(const struct sGezegen* gezegen);
    void  (*setBuGununTarihi)(struct sGezegen* gezegen, Tarih* t);
} Gezegen;






Gezegen* Construct_Gezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu);

void Destruct_Gezegen(Gezegen* gezegen);


void setGezegenNufus(Gezegen* gezegen, long n);

long getGezegenNufus(const Gezegen* gezegen);

 const char* getGezegenAdi(const Gezegen* gezegen);

int getBirGununKacSaatOldugu(const Gezegen* gezegen);

Tarih *getBuGununTarihi(const Gezegen* gezegen);

void setBuGununTarihi(Gezegen* gezegen, Tarih *t);









#endif