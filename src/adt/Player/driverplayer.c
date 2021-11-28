#include "player.h"
#include "player.c"
#include "../Listdp/listdp.h"
#include "../Listdp/listdp.c"
#include <stdio.h>

int main(){
    TabPlayer B;
	int NPemain;
	printf("Masukkan banyak pemain : ");
	scanf("%d",&NPemain);
	MakeTabPlayer(&B,NPemain);
    for(int i = 0; i < B.Neff; i++ ){
        printf("%s\n", B.TI[i].Nama);
    }
}