/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* Simulator
* </p>
*
*/

#include "Simulator.h"


static int gecenZaman = 0;
static int Dur = 0;


Simulator* Construct_Simulator() {
    Simulator* simulator = (Simulator*)malloc(sizeof(Simulator));
    simulator->ProgramStartFunc = &ProgramStart;
    simulator->DestructSimulatorFunc = &Destruct_Simulator;
    return simulator;
}

void Destruct_Simulator(Simulator* simulator) {
    if (!simulator) return;
    free(simulator);
}

static void Azalt(DosyaOkuma* dosyaOkuma) {
    
    for (int i = 0; i < dosyaOkuma->uzayAraciArray->size; i++) {
        UzayAraci* u = dosyaOkuma->uzayAraciArray->uArray[i];
        for (int j = 0; j < dosyaOkuma->kisiArray->size; j++) {
            Kisi* k = dosyaOkuma->kisiArray->kArray[j];
            if (strcmp(getKisiUzayAraciAdi(k), getUzayAraciAdi(u)) == 0) {
                kisiOmurAzalt(k);
            }
        }
        if (strcmp(getDurum(u), "Yolda") == 0) {
            mesafeAzalt(u);
        }
    }
}

static void control(DosyaOkuma* dosyaOkuma) {
    int counter = dosyaOkuma->uzayAraciArray->size;
    for (int i = 0; i < dosyaOkuma->uzayAraciArray->size; i++) {
        UzayAraci* u = dosyaOkuma->uzayAraciArray->uArray[i];
        if (strcmp(getDurum(u), "Vardi") == 0 || strcmp(getDurum(u), "IMHA") == 0) {
            counter--;
        }
    }
    if (counter == 0) {
        Dur = 1;
    }
}

static void AracNufus(DosyaOkuma* dosyaOkuma) {
    for (int i = 0; i < dosyaOkuma->uzayAraciArray->size; i++) {
        UzayAraci* u = dosyaOkuma->uzayAraciArray->uArray[i];
        int toplamNufus = 0;
        for (int j = 0; j < dosyaOkuma->kisiArray->size; j++) {
            Kisi* k = dosyaOkuma->kisiArray->kArray[j];
            if (strcmp(getKisiUzayAraciAdi(k), getUzayAraciAdi(u)) == 0 && getKalanOmur(k) != 0) {
                toplamNufus++;
            } 
        }
        setNufus(u, toplamNufus);
    }
}

static void GezegenNufus(DosyaOkuma* dosyaOkuma) {
    for (int i = 0; i < dosyaOkuma->gezegenArray->size; i++) {
        Gezegen* g = dosyaOkuma->gezegenArray->gArray[i];
        int toplamNufus = 0;
        for (int j = 0; j < dosyaOkuma->uzayAraciArray->size; j++) {
            UzayAraci* u = dosyaOkuma->uzayAraciArray->uArray[j];
            if ((strcmp(getCikisGezegeniAdi(u), g->gezegenAdi) == 0 && strcmp(getDurum(u), "Bekliyor") == 0) ||
                (strcmp(getVarisGezegeniAdi(u), g->gezegenAdi) == 0 && strcmp(getDurum(u), "Vardi") == 0)) {
                toplamNufus += getNufus(u);
            }
        }
        setGezegenNufus(g, toplamNufus);
    }
}

static void Durum(DosyaOkuma* dosyaOkuma) {
    for (int i = 0; i < dosyaOkuma->uzayAraciArray->size; i++) {
        UzayAraci* u = dosyaOkuma->uzayAraciArray->uArray[i];
        if (getKalanMesafe(u) == 0 && getNufus(u) != 0) {
            setDurum(u, "Vardi");
            continue;
        }
        if (getNufus(u) == 0) {
            setDurum(u, "IMHA");
            continue;
        }
        for (int j = 0; j < dosyaOkuma->gezegenArray->size; j++) {
            Gezegen* g = dosyaOkuma->gezegenArray->gArray[j];
            if ((isAfter(g->buGununTarihi, getCikisTarihi(u)) || isEqual(g->buGununTarihi, getCikisTarihi(u))) &&
                strcmp(g->gezegenAdi, getCikisGezegeniAdi(u)) == 0) {
                setDurum(u, "Yolda");
            }
        }
    }
}

static void gunuBirArtir(DosyaOkuma* dosyaOkuma) {
    for (int i = 0; i < dosyaOkuma->gezegenArray->size; i++) {
        Gezegen* g = dosyaOkuma->gezegenArray->gArray[i];
        if (gecenZaman % getBirGununKacSaatOldugu(g) == 0) {
            gunEkle(g->buGununTarihi, 1);
           
        }
    }
}

static void programRestart(DosyaOkuma* dosyaOkuma) {
    AracNufus(dosyaOkuma);
    GezegenNufus(dosyaOkuma);
    Durum(dosyaOkuma);

   
    printf("Gezegenler:\n");
    for (int i = 0; i < dosyaOkuma->gezegenArray->size; i++) {
        Gezegen* g = dosyaOkuma->gezegenArray->gArray[i];
        printf("---- ---- %s ----\t", g->gezegenAdi);
    }
    printf("\nTarih: -----\t");
    for (int i = 0; i < dosyaOkuma->gezegenArray->size; i++) {
        Gezegen* g = dosyaOkuma->gezegenArray->gArray[i];
        printf("---- %s ----\t", tarihToString(g->buGununTarihi));
    }
    printf("\nNufus: -----\t");
    for (int i = 0; i < dosyaOkuma->gezegenArray->size; i++) {
        Gezegen* g = dosyaOkuma->gezegenArray->gArray[i];
        printf("---- ----- %d ----\t", g->nufus);
    }
    printf("\nUzay Araclari:\n");
    printf("Arac adi ---- Durum ---- Cikis ---- Varis ---- Hedefe kalan saat ---- Hedefe varacagi tarih\n");
    for (int i = 0; i < dosyaOkuma->uzayAraciArray->size; i++) {
        UzayAraci* u = dosyaOkuma->uzayAraciArray->uArray[i];
        printf("%s ---------- %s ----- %s ------ %s ------------- %s ---------------- %s\n",
            getUzayAraciAdi(u), getDurum(u), getCikisGezegeniAdi(u), getVarisGezegeniAdi(u),
            getKalanMesafeString(u), getVarisTarihiString(u));
    }
}

void ProgramStart(Simulator* simulator) {
    if (!simulator) return;
    DosyaOkuma* dosyaOkuma = Construct_DosyaOkuma();
    if (!dosyaOkuma) {
        printf("DosyaOkuma oluşturulamadı.\n");
        return;
    }

    while (Dur==0) {
        programRestart(dosyaOkuma);
        printf("Cikis gezegeni ve Varis gezegeninin her ikisi hakkinda bilgi bulunmayan Uzay Araclari sisteme dahil edilmez!\n");
        printf("Cikis veya Varis tarihi acisindan tutarsizlik olusturan Uzay Araclari sisteme dahil edilmez!\n");
        system("cls"); 
        Azalt(dosyaOkuma);
        control(dosyaOkuma);
        gecenZaman++;
        gunuBirArtir(dosyaOkuma);
    }

    programRestart(dosyaOkuma);
    printf("Cikis gezegeni ve Varis gezegeninin her ikisi hakkinda bilgi bulunmayan Uzay Araclari sisteme dahil edilmez!\n");
    printf("Cikis veya Varis tarihi acisindan tutarsizlik olusturan Uzay Araclari sisteme dahil edilmez!\n");

   
}








