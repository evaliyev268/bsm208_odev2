/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* DosyaOkuma ve ilgili veriyapisina yazma
* </p>
*
*/

#include "DosyaOkuma.h"
#include "slre.h"


const char* kisiPattern="([A-Za-z0-9]+)#([0-9]{2})#([0-9]+)#([A-Z][0-9]{1,2})";
const char* gezegenPattern="([A-Z][0-9]{1,2})#([0-9]{1})#([0-9]+)#([0-9]{2}\\.[0-9]{2}\\.[0-9]{4})";
const char* aracPattern="([A-Z][0-9]{1,2})#([A-Z][0-9]{1,2})#([A-Z][0-9]{1,2})#([0-9]{2}\\.[0-9]{2}\\.[0-9]{4})#([0-9]+)";

const char* kisilerPath = "C:\\Users\\evali\\Downloads\\Txts\\Kisiler.txt";
const char* araclarPath = "C:\\Users\\evali\\Downloads\\Txts\\Araclar.txt";
const char* gezegenlerPath = "C:\\Users\\evali\\Downloads\\Txts\\Gezegenler.txt";


static void  ReadKisiler(DosyaOkuma* dosyaOkuma) {
    FILE* f = fopen(kisilerPath, "r");
    if (!f) {
        printf("Dosya acilamadi: %s\n", kisilerPath);
        return;
    }

    char line[256];
  
    struct slre_cap caps[4];

    while (fgets(line, sizeof(line), f)) {
       
        line[strcspn(line, "\r\n")] = 0;

        if (slre_match(kisiPattern, line, strlen(line), caps, 4, 0) > 0) {
             printf("HaryKisi\n");
            char g1[32], g2[32], g3[32], g4[32];
            snprintf(g1, sizeof(g1), "%.*s", (int)caps[0].len, caps[0].ptr);
            snprintf(g2, sizeof(g2), "%.*s", (int)caps[1].len, caps[1].ptr);
            snprintf(g3, sizeof(g3), "%.*s", (int)caps[2].len, caps[2].ptr);
            snprintf(g4, sizeof(g4), "%.*s", (int)caps[3].len, caps[3].ptr);

            Kisi* kisi=Construct_Kisi(g1, g2, g3, g4);
            dosyaOkuma->kisiArray->AddKisiArrayFunc(dosyaOkuma->kisiArray, kisi);
            printf("Kisi: %s, Yas: %s, KalanOmur: %s, UzayAraciAdi: %s\n", g1, g2, g3, g4);
        }
        //
    }
     
    fclose(f);
}

static void  ReadAraclar(DosyaOkuma* dosyaOkuma, UzayAraciArray* temp) {
    FILE* f = fopen(araclarPath, "r");
    if (!f) {
        printf("Dosya acilamadi: %s\n", araclarPath);
        return;
    }

    char line[256];
  
    struct slre_cap caps[5];

    while (fgets(line, sizeof(line), f)) {
        
        line[strcspn(line, "\r\n")] = 0;

        if (slre_match(aracPattern, line, strlen(line), caps, 5, 0) > 0) {
            printf("HaryArac\n");
            char g1[32], g2[32], g3[32], g4[32], g5[32];
            snprintf(g1, sizeof(g1), "%.*s", (int)caps[0].len, caps[0].ptr);
            snprintf(g2, sizeof(g2), "%.*s", (int)caps[1].len, caps[1].ptr);
            snprintf(g3, sizeof(g3), "%.*s", (int)caps[2].len, caps[2].ptr);
            snprintf(g4, sizeof(g4), "%.*s", (int)caps[3].len, caps[3].ptr);
            snprintf(g5, sizeof(g5), "%.*s", (int)caps[4].len, caps[4].ptr);

            UzayAraci *arac=Construct_UzayAraci(g1, g2, g3, g4,g5);
            temp->addUzayAraciArrayF(temp, arac);
            printf("Uzay Araci: %s, Cikis Gezegeni: %s, Varis Gezegeni: %s, Varis Tarihi: %s, Kalan Mesafe: %s\n", g1, g2, g3, g4,g5);
        
        }
      
        //
    }  
    fclose(f);
   temp->setAllVarisTarihiF(temp, dosyaOkuma->gezegenArray);
   temp->farkiEkleF(dosyaOkuma->gezegenArray,temp); 

    for(int c=0;c<temp->size;c++){
    if(getVarisTarihi(temp->uArray[c])!=NULL){
        dosyaOkuma->uzayAraciArray->addUzayAraciArrayF(dosyaOkuma->uzayAraciArray, temp->uArray[c]);
    }
}
}

static void  ReadGezegenler(DosyaOkuma* dosyaOkuma) {
    FILE* f = fopen(gezegenlerPath, "r");
    if (!f) {
        printf("Dosya acilamadi: %s\n", gezegenlerPath);
        return;
    }

    char line[256];
  
    struct slre_cap caps[4];

    while (fgets(line, sizeof(line), f)) {
        
        line[strcspn(line, "\r\n")] = 0;

        if (slre_match(gezegenPattern, line, strlen(line), caps, 4, 0) > 0) {
             printf("HaryGezegen\n");
            char g1[32], g2[32], g3[32], g4[32];
            snprintf(g1, sizeof(g1), "%.*s", (int)caps[0].len, caps[0].ptr);
            snprintf(g2, sizeof(g2), "%.*s", (int)caps[1].len, caps[1].ptr);
            snprintf(g3, sizeof(g3), "%.*s", (int)caps[2].len, caps[2].ptr);
            snprintf(g4, sizeof(g4), "%.*s", (int)caps[3].len, caps[3].ptr);

          dosyaOkuma->gezegenArray->addGezegenArrayF(dosyaOkuma->gezegenArray,g1,g3,g4,g2[0]);
            printf("Gezegen: %s, Nufus: %s, BirGununKacSaatOldugu: %s, BuGununTarihi: %s\n", g1, g2, g3, g4);
        }
        //
    }
    fclose(f);
}
   

DosyaOkuma* Construct_DosyaOkuma() {
    DosyaOkuma* dosyaOkuma = (DosyaOkuma*)malloc(sizeof(DosyaOkuma));
    if (!dosyaOkuma) {
        return NULL;
    }

    
    dosyaOkuma->kisiArray = Construct_KisiArray();
    dosyaOkuma->uzayAraciArray = Construct_UzayAraciArray();
    dosyaOkuma->gezegenArray = Construct_GezegenArray();
    UzayAraciArray* temp=Construct_UzayAraciArray();
    ReadKisiler(dosyaOkuma);
    ReadGezegenler(dosyaOkuma); 
    ReadAraclar(dosyaOkuma,temp);
    temp->Destruct_UzayAraciArrayF(temp);
    return dosyaOkuma;
}





void Destruct_DosyaOkuma(DosyaOkuma* dosyaOkuma) {
    if (!dosyaOkuma) return;

    dosyaOkuma->kisiArray->DestructKisiArrayFunc(dosyaOkuma->kisiArray);
    dosyaOkuma->uzayAraciArray->Destruct_UzayAraciArrayF(dosyaOkuma->uzayAraciArray);
    dosyaOkuma->gezegenArray->Destruct_GezegenArrayF(dosyaOkuma->gezegenArray);
    free(dosyaOkuma);
}












