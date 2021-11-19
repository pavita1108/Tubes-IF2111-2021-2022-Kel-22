#include "map.h"
#include "mesin_kata.h"
#include "array.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readConfig (int *N, char *map, int *MaxRoll,  TabInt *teleporter){
	int i,Nteleporter;
	MakeEmptyArray(&(*teleporter));
	STARTKATA();
	*N = atoi(CKata.TabKata);
	
	ADVKATA();
	strcpy(map,CKata.TabKata);
	
	ADVKATA();
	*MaxRoll = atoi(CKata.TabKata);
	
	ADVKATA();
	Nteleporter = atoi(CKata.TabKata);
	
	(*teleporter).Neff = (Nteleporter)*2;
	for (i = 1 ; i <= Nteleporter ; i++){
		ADVKATA();
		(*teleporter).TI[i*2-1] = atoi(CKata.TabKata);
		
		ADVKATA();
		(*teleporter).TI[i*2] = atoi(CKata.TabKata);
	}
	
};

void PrintMap(Player a , char map[100]){
	printf("%s : ",a.Nama);
	map[a.CPosition] = '*';
	printf("%s %d", map,(a.CPosition+1));
}

