#ifndef buff_H
#define buff_H

#include "boolean.h"
#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

void PrintCurrentBuff (Player P);
//List B berisi daftar buff yang sedang aktif pada diri player, mengoutputkan buff tersebut ke layar
//sebuah buff akan aktif jika seorang player memakai sebuah skill

void DeleteBuff (Player P);
/*Menghapus currentbuff player saat endturn, kecuali buff Imunitas Telepot*/

#endif