#include "player.h"
#include "map.h"
#include "array.h"
#include "command.h"
#include "rolldadu.h"
#include "listskill.h"
#include <stdio.h>
#include <string.h>


int main()
{
	//Anggep ini player nya ada 2
	//Bikin player
	int NPemain;
	TabPlayer TPlayer;
	printf("Masukkan banyak pemain : ");
	scanf("%d",&NPemain);
	MakeTabPlayer(&TPlayer,NPemain);
	
	/*Baca map nya
	Disini kita udh dapet data map, maxroll,teleporter. 
	Udh di extern(global) jadi bisa dipake dimana aja*/
	
	readConfig();
	
	//Mulai game
	puts("-----POSISI AWAL-----");
	PrintMap(TPlayer,Map);
	int i;

	
	//Mulai Looping
	char command[10];
	int MaxPos,a,ronde;
	ronde = 1;
	while (MaxPos != N-1){
		printf("-----RONDE %d----- \n",ronde);
		int i;
		for(i = 0; i<TPlayer.Neff; i++){
			printf("-----PEMAIN ");
			printf("%s",TPlayer.TI[i].Nama);
			printf("-----\n");
			
			puts("Skill yang didapat : ");
			a = RandomizeSkill();
			AddSkill(&(TPlayer.TI[i].Skill),a);
			
			do{
				printf("Masukan Command : ");
				scanf("%s",&command);
				Command(command,&TPlayer,&(TPlayer.TI[i]));
				if ((TPlayer.TI[i].CPosition)+1 == N){
					puts("YAY KAMU MENANG. CONGRATSSS!!!!");	
					exit(1);
				}
			}while (!(TPlayer.TI[i].doneRoll == true && strcmp(command,"ENDTURN") == 0 ));
			ResetPlayer(&(TPlayer.TI[i]));
		}
		ronde++;
	}
};




