/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* CuceGezegeni alt yapisi
* </p>
*
*/

#include "CuceGezegen.h"





CuceGezegen* Construct_CuceGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO)
{
    CuceGezegen* cuceGezegen = (CuceGezegen*)malloc(sizeof(CuceGezegen));    
    if (!cuceGezegen) return NULL;
    cuceGezegen->Destruct_CGezegen=&Destruct_CuceGezegen;
    if(gezegenTuruNO == '3') {
    cuceGezegen->super = Construct_Gezegen(gezegenAdi, buGununTarihi,  birGununKacSaatOldugu);
    strncpy(cuceGezegen->super->gezegenTuru,"Cuce",sizeof(cuceGezegen->super->gezegenTuru)-1);
    return cuceGezegen;
    }
    else{
        free(cuceGezegen);
        return NULL;
    }

}

void Destruct_CuceGezegen(CuceGezegen* cuceGezegen)
{
    if (!cuceGezegen || !cuceGezegen->super) return;
       
     Destruct_Gezegen(cuceGezegen->super);
    
    free(cuceGezegen);

}
