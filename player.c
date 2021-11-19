#include "player.h"
#include <stdio.h>

void MakePlayer (Player *P){
	printf("Nama : ");
	scanf("%s", &((*P).Nama));
	(*P).CPosition = 0;
	CreateEmptyList(&((*P).Buff));
	CreateEmptyList(&((*P).Skill));
};
