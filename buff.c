#include "boolean.h"
#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>
#include <buff.h>
#include "player.h"

void PrintCurrentBuff (Player P){
//Mengoutputkan buff yang dimiliki player ke layar
//sebuah buff akan aktif jika seorang player memakai sebuah skill
//KAMUS LOKAL
    address Q;
//ALGORITMA
    if (IsEmptyList(P.Buff)){
        printf("\nKamu tidak memiliki buff aktif");}
    else{//list ada isinya
        printf ("\nKamu memiliki buff aktif:\n");
        Q = SearchList(P.Buff,1);
        if (Q != Nil) {
            printf ("\n-Imunitas Teleport\n");
        }
        Q = SearchList(P.Buff,2);
        if (Q != Nil){
            printf ("\n-Cermin Pengganda\n");
        }
        Q = SearchList(P.Buff,3);
        if (Q != Nil){
           printf ("\n-Senter Pembesar Hoki\n");
        }
        Q = SearchList(P.Buff,4);
        if (Q != Nil){
            printf ("\n-Senter Pengecil Hoki\n");
        }
            
    }
}

void DeleteBuff (Player P){
/*Menghapus currentbuff player saat endturn, kecuali buff Imunitas Telepot*/
//KAMUS LOKAL
    address Q;
//ALGORITMA
    Q = SearchList(P.Buff,2);
    if (Q != Nil){/*player memiliki buff Cermin pengganda*/
        DelPList(&P.Buff, 2);
    }
    Q = SearchList(P.Buff,3);
    if (Q != Nil){/*player memiliki buff Senter Pembesar Hoki*/
        DelPList(&P.Buff, 3);
    }
    Q = SearchList(P.Buff,4);
    if (Q != Nil){/*player memiliki buff Senter Pengecil Hoki*/
        DelPList(&P.Buff, 4);
    }       
}

