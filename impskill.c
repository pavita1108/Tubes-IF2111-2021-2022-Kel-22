#include <stdio.h>
#include <stdlib.h>
#include "impskill.h"
#include "player.h"
#include "map.h"

void tukarposisi (Player P, TabPlayer TPlayer){ //misal Player Andi
    //KAMUS
    int input, anda, temp;
    //ALGORITMA

    printf("Daftar pemain:\n");
    for (int i=0; i<TPlayer.Neff; i++){
        if (TPlayer.TI[i].Nama != P.Nama){
            printf("%d. %s (Anda)\n", i ,TPlayer.TI[i].Nama); // 1. Andi (kamu)
            anda = i;
        }
        else{
            printf("%d. %s\n", i ,TPlayer.TI[i].Nama); // 2. Naila
        }
    }
    printf("Map sekarang:\n");
    PrintMap(TPlayer, Map);

    printf("Masukan nomor player yang ingin kamu tukar:");
    scanf("%d",&input);
    while (input = anda){//validasi input
        printf("Tidak bisa menukar posisi dengan diri sendiri!\n");
        printf("Masukan nomor player yang ingin kamu tukar:");
        scanf("%d",&input);
    }
    //tukar posisi
    temp = TPlayer.TI[input].CPosition;
    TPlayer.TI[input].CPosition =  TPlayer.TI[anda].CPosition;
    TPlayer.TI[anda].CPosition =temp; 
}

