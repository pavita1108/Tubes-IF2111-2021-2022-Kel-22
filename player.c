#include "player.h"
#include <stdio.h>

void MakePlayer (Player *P){
	scanf("%s", &((*P).Nama));
	(*P).CPosition = 0;
	CreateEmptyList(&((*P).Skill));
	(*P).Imun = false;
	(*P).Pembesar = false;
	(*P).Pengecil = false;
	(*P).doneRoll = false;
};

void MakeTabPlayer (TabPlayer *TPlayer, int neff){
	int i;
	(*TPlayer).Neff = neff;
	for (i=0;i<neff;i++){
		printf("Masukkan nama player %d : ",(i+1));
		MakePlayer(&((*TPlayer).TI[i]));
	}
}
