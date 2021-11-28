#include "player.h"
#include "../Listdp/listdp.h"
#include <stdio.h>

void MakePlayer (Player *P){
	scanf("%s", &((*P).Nama));
	(*P).CPosition = 0;
	CreateEmptyList(&((*P).Skill));
	(*P).Imun = false;
	(*P).Pembesar = false;
	(*P).Pengecil = false;
	(*P).Pengganda = false; //biar gampang ngecek dia udh pake pengganda apa belom
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

void ResetPlayer(Player *P){
	(*P).Pembesar = false;
	(*P).Pengecil = false;
	(*P).Pengganda = false;
	(*P).doneRoll = false;
}

void copySkill(List origin, List *copy){
	List O;
	O = origin;
    while (O.First != NilList){
        address S;
        S = AlokasiList(Info(O.First));
        InsertLastList(&(*copy),S);
        O.First = Next(O.First);
	}
}
