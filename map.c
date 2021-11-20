#include "map.h"
#include "mesin_kata.h"
#include "array.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char Map[100];
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

void PrintMap(Player a , char map[100]){
	printf("%s : ",a.Nama);
	map[a.CPosition] = '*';
	printf("%s %d", map,(a.CPosition+1));
}

