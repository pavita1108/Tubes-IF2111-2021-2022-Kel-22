#ifndef player_H
#define player_H

#include "boolean.h"
#include "listdp.h"


typedef struct {
	char Nama[100];
	int CPosition;
	List Skill;
	List Buff;
}Player;

void MakePlayer (Player *P);
//membuat player baru

#endif
