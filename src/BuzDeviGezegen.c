/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* BuzDeviGezegeni alt yapisi
* </p>
*
*/

#include "BuzDeviGezegen.h"





BuzDeviGezegen* Construct_BuzDeviGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO)
{
    BuzDeviGezegen* buzDeviGezegen = (BuzDeviGezegen*)malloc(sizeof(BuzDeviGezegen));    
    if (!buzDeviGezegen) return NULL;
    buzDeviGezegen->Destruct_BGezegen=&Destruct_BuzDeviGezegen;
    if(gezegenTuruNO == '2') {
    buzDeviGezegen->super = Construct_Gezegen(gezegenAdi, buGununTarihi,  birGununKacSaatOldugu);
    strncpy(buzDeviGezegen->super->gezegenTuru,"BuzDevi",sizeof(buzDeviGezegen->super->gezegenTuru)-1);
    return buzDeviGezegen;
    }
    else{
        free(buzDeviGezegen);
        return NULL;
    }

}

void Destruct_BuzDeviGezegen(BuzDeviGezegen* buzDeviGezegen)
{
    if (!buzDeviGezegen || !buzDeviGezegen->super) return;
       
        Destruct_Gezegen(buzDeviGezegen->super);
        free(buzDeviGezegen);
    
}
