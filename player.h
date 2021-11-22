#ifndef player_H
#define player_H

#include "boolean.h"
#include "listdp.h"

typedef struct {
	char Nama[100];
	int CPosition;
	List Skill;
	boolean Imun;
	boolean Pembesar;
	boolean Pengecil;
	boolean doneRoll;
	boolean Pengganda; //biar gampang ngecek dia udh pake pengganda apa belom
}Player;

typedef struct {
	Player TI[4];
	int Neff;
}TabPlayer;

void MakePlayer (Player *P);
//membuat player baru

void MakeTabPlayer (TabPlayer *TPlayer, int neff);
//membuat tabplayer

void ResetPlayer(Player *P);
#endif
