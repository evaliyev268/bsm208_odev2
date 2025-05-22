/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* Zaman tarih yapisi
* </p>
*
*/



#include "Zaman.h"

const int ay_gunleri[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

typedef struct sTarih {
    int gun;
    int ay;   // 1-12
    int yil;
} Tarih;

int artikYilMi(int yil) {
    return ((yil % 4 == 0 && yil % 100 != 0) || (yil % 400 == 0));
}


int tarihToJulian(Tarih *t) {
    int a = (14 - t->ay)/12;
    int y = t->yil + 4800 - a;
    int m = t->ay + 12*a - 3;
    return t->gun + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
}

// t2-t1 gün farkı
int tarihFarki(Tarih *t1, Tarih *t2) {
    int j1 = tarihToJulian(t1);
    int j2 = tarihToJulian(t2);
    return j2 - j1;
}

void gunEkle(Tarih *t, int n) {
    t->gun += n;
    while (1) {
        int ay_index = t->ay - 1;
        int gun_sinir = ay_gunleri[ay_index];
        if (t->ay == 2 && artikYilMi(t->yil))
            gun_sinir = 29;
        if (t->gun <= gun_sinir) break;
        t->gun -= gun_sinir;
        t->ay++;
        if (t->ay > 12) {
            t->ay = 1;
            t->yil++;
        }
    }
}


int stringToTarih(const char *str, Tarih *t) {

    return sscanf(str, "%d.%d.%d", &t->gun, &t->ay, &t->yil) == 3;
}

const char *tarihToString(Tarih *t) {
    static char str[11];
    snprintf(str, sizeof(str), "%02d.%02d.%04d", t->gun, t->ay, t->yil);
    return str;
}

Tarih *Construct_Tarih(const char *str) {
    Tarih *t = (Tarih *)malloc(sizeof(Tarih));
    if (t == NULL) {
        printf("Heap'te yer ayrılamadı!\n");
        exit(EXIT_FAILURE);
    }
    if(str==NULL){
        t->gun=0;
        t->ay=0;
        t->yil=0;
    }
    else
    {
        stringToTarih(str, t);
    }
    return t;
}


void Destruct_Tarih(Tarih *t) {
    free(t);
}


int isBefore(Tarih *t1, Tarih *t2) {
   if(tarihFarki(t1, t2) > 0){
    return 1; // t1, t2'den önce
   }
   else{
    return 0; // t1, t2'den sonra
   }
 
}

int isAfter(Tarih *t1, Tarih *t2) {
    if(tarihFarki(t1, t2) < 0){
        return 1; // t1, t2'den sonra
    }
    else{
        return 0; // t1, t2'den önce
    }
}

int isEqual(Tarih *t1, Tarih *t2) {
    if(tarihFarki(t1, t2) == 0){
        return 1; // t1, t2 ile aynı
    }
    else{
        return 0; // t1, t2 ile aynı değil
    }
}








