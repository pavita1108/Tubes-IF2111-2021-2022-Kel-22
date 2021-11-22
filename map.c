#include "map.h"
#include "mesin_kata.h"
#include "array.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char Map[101];
int MaxRoll,N;
TabInt Teleporter;

void readConfig (){
	int i,Nteleporter;
	MakeEmptyArray(&(Teleporter));
	STARTKATA();
	N = atoi(CKata.TabKata);
	
	ADVKATA();
	strcpy(Map,CKata.TabKata);
	
	ADVKATA();
	MaxRoll = atoi(CKata.TabKata);
	
	ADVKATA();
	Nteleporter = atoi(CKata.TabKata);
	
	(Teleporter).Neff = (Nteleporter)*2;
	for (i = 1 ; i <= Nteleporter ; i++){
		ADVKATA();
		(Teleporter).TI[i*2-1] = atoi(CKata.TabKata);
		
		ADVKATA();
		(Teleporter).TI[i*2] = atoi(CKata.TabKata);
	}
	
};

void PrintMap(TabPlayer a , char map[101]){
	int i;
	for (i = 0 ; i<a.Neff;i++){
		printf("%s : ",a.TI[i].Nama);
		map[a.TI[i].CPosition] = '*';
		printf("%s %d", map,((a.TI[i].CPosition)+1));
		printf("\n");
		map[a.TI[i].CPosition] = '.';
	}
	
}

