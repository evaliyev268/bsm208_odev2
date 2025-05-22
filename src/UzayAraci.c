/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* Uzay Araci 
* </p>
*
*/



#include "UzayAraci.h"
/*getCikisTarihi()
getKalanMesafeString()
getKalanMesafe()
setKalanMesafe(int i)
getNufus()
setNufus(long n)
getUzayAraciAdi()
getVarisGezegeniAdi()
getCikisGezegeniAdi()
getDurum()
setVarisTarihi(LocalDate t)
setDurum(String s)
UzayAraci(String u, String cGe, String vGe, LocalDate ct, String k) (Yapıcı/Constructor)
getVarisTarihi()
getVarisTarihiString()
static mesafeAzalt(UzayAraci u)*/
#define NAME_LEN 100
#define DATE_LEN 32
#define STATUS_LEN 32
#include "Gezegen.h"



typedef struct sUzayAraci {
    char uzayAraciAdi[NAME_LEN];
    int kalanMesafe;
    char varisGezegeniAdi[NAME_LEN];
    char cikisGezegeniAdi[NAME_LEN];
    long nufus;
    char durum[STATUS_LEN];
    Tarih *cikisTarihi;
    Tarih *varisTarihi;
} UzayAraci;

 UzayAraci *Construct_UzayAraci(const char *uaAdi, const char *cGe, const char *vGe, const char *ct, const char *k) {
    UzayAraci *u = (UzayAraci *)malloc(sizeof(UzayAraci));

    if (u == NULL) {
        printf("Heap'te yer ayrılamadı!\n");
        exit(EXIT_FAILURE);
    }
    u->cikisTarihi = Construct_Tarih(ct);
    if(u->cikisTarihi == NULL){
        printf("Heap'te yer ayrılamadı!\n");
        exit(EXIT_FAILURE);
    }
  

    strncpy(u->uzayAraciAdi, uaAdi, NAME_LEN);
    strncpy(u->cikisGezegeniAdi, cGe, NAME_LEN);
    strncpy(u->varisGezegeniAdi, vGe, NAME_LEN);
    u->kalanMesafe = atoi(k);
    u->nufus = 0;
    strcpy(u->durum, "Bekliyor");
    return u;

}

const char* getKalanMesafeString(UzayAraci *u) {
    if(strcmp(u->durum, "IMHA") == 0)
        return "===";
    else{
       static char str[20];
        snprintf(str, 20, "%d", u->kalanMesafe);
        return str;
    }
}

int getKalanMesafe(UzayAraci *u) {
    return u->kalanMesafe;
}

void setKalanMesafe(UzayAraci *u, int i) {
    if(i >= 0)
        u->kalanMesafe = i;
}

long getNufus(UzayAraci *u) {
    return u->nufus;
}

void setNufus(UzayAraci *u, long n) {
    u->nufus = n;
}

const char* getUzayAraciAdi(UzayAraci *u) {
    return u->uzayAraciAdi;
}

const char* getVarisGezegeniAdi(UzayAraci *u) {
    return u->varisGezegeniAdi;
}

const char* getCikisGezegeniAdi(UzayAraci *u) {
    return u->cikisGezegeniAdi;
}

const char* getDurum(UzayAraci *u) {
    return u->durum;
}

void setDurum(UzayAraci *u, const char *s) {
    strncpy(u->durum, s, STATUS_LEN);
}

Tarih *getVarisTarihi(UzayAraci *u) {
    return u->varisTarihi;
}

Tarih *getCikisTarihi(UzayAraci *u) {
    return u->cikisTarihi;
}

const char* getVarisTarihiString(UzayAraci *u) {
    if(strcmp(u->durum, "IMHA") == 0)
        return "====";
    if(u->varisTarihi == NULL)
        return "Null";

    return tarihToString(u->varisTarihi);
}

void setVarisTarihi(UzayAraci *u, Tarih *t) {
       if (u->varisTarihi != NULL) {
        Destruct_Tarih(u->varisTarihi); 
    }
    u->varisTarihi = t;
}


void mesafeAzalt(UzayAraci *u) {
    setKalanMesafe(u, getKalanMesafe(u) -1);
}


void Destruct_UzayAraci(UzayAraci *u) {
    if (u != NULL) {
        Destruct_Tarih(u->cikisTarihi);
        free(u);
    }
}
