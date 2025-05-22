/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* Kisi Dizisi veri yapisi
* </p>
*
*/


#include "KisiArray.h"

 





KisiArray* Construct_KisiArray() {
    KisiArray* kisiArray = (KisiArray*)malloc(sizeof(KisiArray));
    if (!kisiArray) {
        printf("Heap'te yer ayrılamadı!\n");
        exit(EXIT_FAILURE);
    }
    kisiArray->AddKisiArrayFunc = &addKisiArray;
    kisiArray->DestructKisiArrayFunc = &Destruct_KisiArray;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        kisiArray->kArray[i] = NULL;
    }
    kisiArray->size = 0;
    return kisiArray;
}

void addKisiArray(KisiArray *kisiArray, Kisi *kisi ){
    for(int c=0;c<ARRAY_SIZE;c++){
        if(strcmp(getKisiAdi(kisi), getKisiAdi(kisiArray->kArray[c])) && getKisiYas(kisiArray->kArray[c])==getKisiYas(kisi)){
            return;//Ayni yas ve ayni isme sahip eleman eklenmez
        }
        else{
            if (kisiArray->kArray[c] == NULL) {
                kisiArray->kArray[c] = kisi;
                kisiArray->size++;
                return;
            }
        }
    }
}

void Destruct_KisiArray(KisiArray* kisiArray) {
    if (!kisiArray) return;


    for (int i = 0; i < kisiArray->size; i++) {
        if (kisiArray->kArray[i]) {
            Destruct_Kisi(kisiArray->kArray[i]);
        }
    }

    free(kisiArray);
}


