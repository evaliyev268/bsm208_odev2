/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
*  Kisi yapisi
* </p>
*
*/

#include "Kisi.h"


typedef struct sKisi{
int yas;
char isim[100];
int kalanOmur;
char bulunduguUzayAraciAdi[100];
} Kisi;

Kisi* Construct_Kisi(const char* isim,const char*yas,const char*kalanOmur,const char* uzayAraciAdi){
Kisi *kisi=(Kisi*)malloc(sizeof(Kisi));
if(kisi==NULL){
    printf("Heap te yer ayrilamadi!");
    exit(EXIT_FAILURE);
}
strncpy(kisi->isim,isim,sizeof(kisi->isim)-1);
kisi->yas=atoi(yas);
kisi->kalanOmur=atoi(kalanOmur);
strncpy(kisi->bulunduguUzayAraciAdi,uzayAraciAdi,sizeof(kisi->bulunduguUzayAraciAdi)-1);

return kisi;
}

int getKalanOmur(Kisi* kisi){
    return kisi->kalanOmur;
}

void setKalanOmur(Kisi* kisi,int komur){
    if(komur>=0){
        kisi->kalanOmur=komur;
    }
    else{
        printf("%s","Hata,Kisinin kalan omru negatif olarak atanmaya calisildi");
    }

}

const char* getKisiUzayAraciAdi(Kisi* kisi){
    return kisi->bulunduguUzayAraciAdi;
}

const char* getKisiAdi(Kisi* kisi){
    return kisi->isim;
}

int getKisiYas(Kisi* kisi){
    return kisi->yas;
}

void kisiOmurAzalt(Kisi *kisi){
    setKalanOmur(kisi,kisi->kalanOmur-1);
} 

void Destruct_Kisi(Kisi* kisi){
    free(kisi);
}


