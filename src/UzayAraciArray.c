/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* Uzay Araci Dizisi veri yapisi
* </p>
*
*/

#include "UzayAraciArray.h"



UzayAraciArray* Construct_UzayAraciArray() {
    UzayAraciArray* uzayAraciArray = (UzayAraciArray*)malloc(sizeof(UzayAraciArray));
    if (!uzayAraciArray) {
        printf("Heap'te yer ayrılamadı!\n");
        exit(EXIT_FAILURE);
    }

    uzayAraciArray->addUzayAraciArrayF = &addUzayAraciArray;
    uzayAraciArray->Destruct_UzayAraciArrayF = &Destruct_UzayAraciArray;
    uzayAraciArray->setAllVarisTarihiF = &setAllVarisTarihi;
    uzayAraciArray->farkiEkleF = &farkiEkle;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        uzayAraciArray->uArray[i] = NULL;
    }
    uzayAraciArray->size = 0;
    return uzayAraciArray;
}

void addUzayAraciArray(UzayAraciArray *uzayAraciArray, UzayAraci *uzayAraci ){
    for(int c=0;c<ARRAY_SIZE;c++){
    if (uzayAraciArray->uArray[c] && strcmp(getUzayAraciAdi(uzayAraci), getUzayAraciAdi(uzayAraciArray->uArray[c])) == 0) {
    return;
}
        else{
            if (uzayAraciArray->uArray[c] == NULL) {
                uzayAraciArray->uArray[c] = uzayAraci;
                uzayAraciArray->size++;
                return;
            }
        }
    }
} 

void Destruct_UzayAraciArray(UzayAraciArray* uzayAraciArray) {
    if (!uzayAraciArray) return;

    for (int i = 0; i < uzayAraciArray->size; i++) {
        if (uzayAraciArray->uArray[i]) {
            Destruct_UzayAraci(uzayAraciArray->uArray[i]);
        }
    }

    free(uzayAraciArray);
}

void setAllVarisTarihi( UzayAraciArray *uzayAraciArray,GezegenArray *gezegenArray) {
        for (int i = 0; i < gezegenArray->size; i++) {
        Gezegen* g = gezegenArray->gArray[i];
        if (!g) continue;
        for (int j = 0; j < uzayAraciArray->size; j++) {
            UzayAraci* u = uzayAraciArray->uArray[j];
            if (!u) continue;
            if (strcmp(getVarisGezegeniAdi(u), g->gezegenAdi) == 0) {
                int gunSayisi = getKalanMesafe(u) / g->birGununKacSaatOldugu;
                Tarih *vt=Construct_Tarih(tarihToString(g->buGununTarihi));
                gunEkle(vt, gunSayisi);
                if (isBefore(getCikisTarihi(u), g->buGununTarihi)!=1) {
                    setVarisTarihi(u,NULL);
                }
                else{
                    setVarisTarihi(u,vt);
                }
              
            }
        }
    }
    farkiEkle(gezegenArray, uzayAraciArray);
}

void farkiEkle(GezegenArray *gezegenArray,UzayAraciArray *uzayAraciArray) {
    for (int i = 0; i < gezegenArray->size; i++) {
        Gezegen* g = gezegenArray->gArray[i];
        if (!g) continue;
        for (int j = 0; j < uzayAraciArray->size; j++) {
            UzayAraci* u = uzayAraciArray->uArray[j];
            if (!u) continue;
            if (strcmp(getVarisGezegeniAdi(u), g->gezegenAdi) == 0) {
                int gunFarki = tarihFarki(g->buGununTarihi, getCikisTarihi(u));
                Tarih *vt=Construct_Tarih(tarihToString(getVarisTarihi(u)));
                if (gunFarki > 0) {
                gunEkle(vt, gunFarki);
                setVarisTarihi(u,vt);
                }
                else{
                    setVarisTarihi(u,NULL);
                }
              
            }
        }
    }
}






