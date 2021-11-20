#include "player.h"
#include "map.h"
#include "array.h"
#include <stdio.h>


int main()
{
	//Anggep ini player nya ada 2
	//Bikin player
	Player player1,player2;
	MakePlayer(&player1);
	MakePlayer(&player2);
	
	/*Baca map nya
	Disini kita udh dapet data map, maxroll,teleporter. 
	Bisa digunain di main tapi JANGAN UBAH VALUENYA.
	Masukin ke variabel lain kalo mau pake*/
	char Map[100];
	int MaxRoll,N;
	TabInt Teleporter;
	
	readConfig(&N, &Map,&MaxRoll,&Teleporter);
	
	/*Mulai game*/
	PrintMap(player1,Map);
	printf("\n");
	PrintMap(player2,Map);
	printf("\n");
	
	/*Mulai Looping*/
	int HighestPosition,f;
	HighestPosition = 0 ;
	char command[10];
	while (HighestPosition != N){
		//Gameplay buat player 1
		printf("Masukan command : ");
		scanf("%s",&command);
		Command(command,player1,player2,Map,MaxRoll,Teleporter);
		while(command != "ENDTURN"){
			printf("Masukan command : ");
			scanf("%s",&command);
			Command(command,player1,player2,Map,MaxRoll,Teleporter);
			player1.CPosition = f;
			if (player1.CPosition >= HighestPosition ){
				HighestPosition = player1.CPosition;
			}
		}
		
		//fungsi endturn ditaro disini
		
		//Lanjut Gameplay Player2
		printf("Masukan command : ");
		scanf("%s",&command);
		Command(command,player2,player1,Map,MaxRoll,Teleporter);
		while(command != "ENDTURN"){
			scanf("%s",&command);
			printf("Masukan command : ");
			Command(command,player2,player1,Map,MaxRoll,Teleporter);
			player1.CPosition = f;
			if (player2.CPosition >= HighestPosition ){
				HighestPosition = player2.CPosition;
			}
		}
		//fungsi endturn ditaro disini
	}
	
	
};

void Command(char command[10],Player *CPlayer,Player *OtherPlayer,char Map, int MaxRoll,  TabInt Teleporter);
void Command(char command[10] , Player *CPlayer,Player *OtherPlayer,char Map, int MaxRoll,  TabInt Teleporter){
	if (command == 'SKILL' ){
		printf("skill");
	}
	else if (command == 'MAP'){
		PrintMap(*CPlayer,Map);
		printf("\n");
		PrintMap(*OtherPlayer,Map);
		printf("\n");
	}
	else if (command == 'BUFF'){
		printf("buff");
	}
	else if (command == 'INSPECT'){
		printf("inspect");
	}
	else if (command == 'ROLL'){
		printf("roll");
	}
	else if (command == 'UNDO'){
		printf("undo");
	}
	else{
		printf("Tidak Ada Fungsi Tersebut");
	}
	
};


