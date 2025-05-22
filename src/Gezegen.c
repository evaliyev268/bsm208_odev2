/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* Gezegen yapisi(Abstract)
* </p>
*
*/
#include "Gezegen.h"






Gezegen* Construct_Gezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu) {
    Gezegen* gezegen = (Gezegen*)malloc(sizeof(Gezegen));
    if (!gezegen) return NULL;
    strcpy(gezegen->gezegenAdi, gezegenAdi);
    gezegen->birGununKacSaatOldugu = atoi(birGununKacSaatOldugu);
    gezegen->nufus = 0;
    gezegen->buGununTarihi = Construct_Tarih(buGununTarihi);
    gezegen->Destruct_Gezegen = &Destruct_Gezegen;
    gezegen->setNufus = &setGezegenNufus;
    gezegen->getNufus = &getGezegenNufus;
    gezegen->getGezegenAdi = &getGezegenAdi;
    gezegen->getBirGununKacSaatOldugu = &getBirGununKacSaatOldugu;
    gezegen->getBuGununTarihi = &getBuGununTarihi;
    gezegen->setBuGununTarihi = &setBuGununTarihi;

    

    return gezegen;

}

void Destruct_Gezegen(Gezegen* gezegen) {
    if (gezegen) {
        if(gezegen->buGununTarihi) {
            Destruct_Tarih(gezegen->buGununTarihi);
        } 
    }
        Destruct_Tarih(gezegen->buGununTarihi);
        free(gezegen);
    }

void setGezegenNufus(Gezegen* gezegen, long n) {
    if (gezegen) gezegen->nufus = n;
}

long getGezegenNufus(const Gezegen* gezegen) {
    return gezegen ? gezegen->nufus : 0;
}

const char* getGezegenAdi(const Gezegen* gezegen) {
   if(!gezegen) {
        printf("Hata in Gezegen getGezegenAdi");
        return "-1";
    }
    return gezegen->gezegenAdi;
}

int getBirGununKacSaatOldugu(const Gezegen* gezegen) {
    if(gezegen && gezegen->birGununKacSaatOldugu>0) {
        return gezegen->birGununKacSaatOldugu;
    }
    else{
        return -1;
    }
}

Tarih *getBuGununTarihi(const Gezegen* gezegen) {
    if(gezegen && gezegen->buGununTarihi) {
        return gezegen->buGununTarihi;
    }
    else{
        return 0;
    }
}

void setBuGununTarihi(Gezegen* gezegen, Tarih *t) {
    if(gezegen && t) {
        gezegen->buGununTarihi = t;
    }
    else{
        printf("Hata in Gezegen tarih");
    }
}









