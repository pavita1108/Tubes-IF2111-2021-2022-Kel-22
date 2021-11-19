#include "map.h"
#include "mesin_kata.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readConfig (int *N, char *map, int *MaxRoll, int *Nteleporter, TabInt *teleporter){
	int i;
	MakeEmptyArray(&(*teleporter));
	STARTKATA();
	*N = atoi(CKata.TabKata);
	
	ADVKATA();
	strcpy(map,CKata.TabKata);
	//input nya harus bentuknya char c[100]
	
	ADVKATA();
	*MaxRoll = atoi(CKata.TabKata);
	
	ADVKATA();
	*Nteleporter = atoi(CKata.TabKata);
	
	(*teleporter).Neff = (*Nteleporter)*2;
	for (i = 1 ; i <= *Nteleporter ; i++){
		ADVKATA();
		(*teleporter).TI[i*2-1] = atoi(CKata.TabKata);
		
		ADVKATA();
		(*teleporter).TI[i*2] = atoi(CKata.TabKata);
	}
	// itu yang teleporter kalo yang ganjil itu letak teleporter kalo yang genap petak keluar teleporter
	//contoh : 3 5 2 9
	//kalo kena petak 3 maka bakal keluar di 5
	//kalo kena petak 2 maka bakal keluar di 9
	
};

