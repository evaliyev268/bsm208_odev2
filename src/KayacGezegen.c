/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* KayacGezegeni alt yapisi
* </p>
*
*/


#include "KayacGezegen.h"



;

KayacGezegen* Construct_KayacGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO)
{
    KayacGezegen* kayacGezegen = (KayacGezegen*)malloc(sizeof(KayacGezegen));    
    if (!kayacGezegen) return NULL;
   kayacGezegen->Destruct_KGezegen=&Destruct_KayacGezegen;
    if(gezegenTuruNO == '0') {
    kayacGezegen->super = Construct_Gezegen(gezegenAdi, buGununTarihi,  birGununKacSaatOldugu);
    strncpy(kayacGezegen->super->gezegenTuru,"Kayac",sizeof(kayacGezegen->super->gezegenTuru)-1);
    return kayacGezegen;
    }
    else{
        free(kayacGezegen);
        return NULL;
    }

}

void Destruct_KayacGezegen(KayacGezegen* kayacGezegen)
{
    if (!kayacGezegen || !kayacGezegen->super) return;
       
            Destruct_Gezegen(kayacGezegen->super);
       
        free(kayacGezegen);
   
}
