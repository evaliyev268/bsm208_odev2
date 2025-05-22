/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* GezegenDizisi veri yapisi
* </p>
*
*/


#include "GezegenArray.h"


GezegenArray* Construct_GezegenArray() {
    GezegenArray* gezegenArray = (GezegenArray*)malloc(sizeof(GezegenArray));
    if (!gezegenArray) {
        printf("Heap'te yer ayrılamadı!\n");
        exit(EXIT_FAILURE);
    }

    gezegenArray->addGezegenArrayF = &addGezegenArray;
    gezegenArray->Destruct_GezegenArrayF = &Destruct_GezegenArray; 


    for (int i = 0; i < GEZEGEN_SIZE; i++) {
        gezegenArray->gArray[i] = NULL;
    }
    gezegenArray->size = 0;
    return gezegenArray;
}

void addGezegenArray(GezegenArray *gezegenArray, const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO) {
    for (int c = 0; c < GEZEGEN_SIZE; c++) {
        if (gezegenArray->gArray[c] && strcmp(getGezegenAdi(gezegenArray->gArray[c]), gezegenAdi) == 0) {
            
            return; // Aynı isme sahip eleman eklenmez
        }
        if(gezegenTuruNO!='0' && gezegenTuruNO!='1' && gezegenTuruNO!='2' && gezegenTuruNO!='3'){
            printf("Gecersiz  gezegen Turu\n");
            return;
        }
        else {
            if (gezegenArray->gArray[c] == NULL) {
                Gezegen *gezegen =NULL;
                if(gezegenTuruNO=='0'){
                    KayacGezegen *kayacGezegen = Construct_KayacGezegen(gezegenAdi, buGununTarihi, birGununKacSaatOldugu,gezegenTuruNO);
                    gezegen = kayacGezegen->super;
                }
                else if(gezegenTuruNO=='1'){
                    GazDeviGezegen *gazDeviGezegen = Construct_GazDeviGezegen(gezegenAdi, buGununTarihi, birGununKacSaatOldugu,gezegenTuruNO);
                    gezegen =gazDeviGezegen->super;
                }
                else if(gezegenTuruNO=='2'){
                    BuzDeviGezegen *buzDeviGezegen = Construct_BuzDeviGezegen(gezegenAdi, buGununTarihi, birGununKacSaatOldugu,gezegenTuruNO);
                    gezegen = buzDeviGezegen->super;
                }
                else if(gezegenTuruNO=='3'){
                    CuceGezegen *cuceGezegen = Construct_CuceGezegen(gezegenAdi, buGununTarihi, birGununKacSaatOldugu,gezegenTuruNO);
                    gezegen = cuceGezegen->super;
                    
                }
                if(!gezegen) return;
                gezegenArray->gArray[c] = gezegen;
                gezegenArray->size++;
                return;
            }
        }
    }
}

void Destruct_GezegenArray(GezegenArray* gezegenArray) {
    if (!gezegenArray) return;

    for (int i = 0; i < gezegenArray->size; i++) {
        if (gezegenArray->gArray[i]) {
            Destruct_Gezegen(gezegenArray->gArray[i]);
        }
    }

    free(gezegenArray);
}