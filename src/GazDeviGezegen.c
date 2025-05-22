/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr-B231210565
* @since 18.05.2025
* <p>
* GazDeviGezegeni alt yapisi
* </p>
*
*/

#include "GazDeviGezegen.h"




GazDeviGezegen* Construct_GazDeviGezegen(const char* gezegenAdi, const char* buGununTarihi, const char* birGununKacSaatOldugu, char gezegenTuruNO)
{
    GazDeviGezegen* gazDeviGezegen = (GazDeviGezegen*)malloc(sizeof(GazDeviGezegen));    
    if (!gazDeviGezegen) return NULL;
    gazDeviGezegen->Destruct_GGezegen=&Destruct_GazDeviGezegen;
    if(gezegenTuruNO == '1') {
    gazDeviGezegen->super = Construct_Gezegen(gezegenAdi, buGununTarihi,  birGununKacSaatOldugu);
    strncpy(gazDeviGezegen->super->gezegenTuru,"GazDevi",sizeof(gazDeviGezegen->super->gezegenTuru)-1);
    return gazDeviGezegen;
    }
    else{
        free(gazDeviGezegen);
        return NULL;
    }

}

void Destruct_GazDeviGezegen(GazDeviGezegen* gazDeviGezegen)
{
    if (!gazDeviGezegen || !gazDeviGezegen->super) return;
       
            Destruct_Gezegen(gazDeviGezegen->super);
        
        free(gazDeviGezegen);
    
    }