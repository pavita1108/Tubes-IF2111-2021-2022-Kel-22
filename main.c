#include "player.h"
#include "map.h"
#include "array.h"
#include "command.h"
#include "listskill.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>


int main()
{
	int b;
	do{
		
		puts("1. NEW GAME");
		puts("2. EXIT");
		printf("Masukkan input : ");
		scanf("%d",&b);
		if(b==2){
			exit(1);
		};	
	}while(b!=1 && b!= 2);
	
	//Bikin player
	puts("~~~~~~~SELAMAT DATANG DI MOBITANGGA !!!~~~~~~~~");
	int NPemain;
	TabPlayer TPlayer;
	printf("Masukkan banyak pemain : ");
	scanf("%d",&NPemain);
	MakeTabPlayer(&TPlayer,NPemain);
	
	/*Baca map nya
	Disini kita udh dapet data map, maxroll,teleporter. 
	Udh di extern(global) jadi bisa dipake dimana aja*/
	
	readConfig();

	//STACK
	Stack GameHist;
	CreateEmptyStack(&GameHist);
	PushStack(&GameHist,TPlayer);
	
	//Mulai Looping
	char command[10];
	int MaxPos,a,ronde;
	ronde = 1;
	while (MaxPos != N-1){
		printf("\n-----RONDE %d----- \n",ronde);
		PrintMap(TPlayer,Map);
		int i;
		for(i = 0; i<TPlayer.Neff; i++){
			printf("\n-----PEMAIN ");
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
				if(strcmp(command,"UNDO")== 0){
					break;
				}
			}while (!(TPlayer.TI[i].doneRoll == true && strcmp(command,"ENDTURN") == 0 ));
			if(strcmp(command,"UNDO")== 0){
				if (i == 0) {
                    printf("\n");
                    char u[3];
                    do{
                    	PopStack(&GameHist, &TPlayer);
                    	printf("UNDO berhasil dilakukan\n");
                    	printf("\n-----RONDE %d----- \n",ronde);
                    	ronde -= 1;
						PrintMap(TPlayer,Map);
                        printf("Apakah ingin melakukan UNDO lagi? (YES/NO): ");
                        scanf("%s",&u);
                        if(strcmp(u,"NO")== 0){
                        	break;
						}
                    }while (ronde > 1 &&strcmp(u,"YES")== 0);
                }  
                else {
                    printf("\n");
                    PopStack(&GameHist, &TPlayer);
                    printf("UNDO berhasil dilakukan\n");
                    printf("\n-----RONDE %d----- \n",ronde);
					PrintMap(TPlayer,Map);
                }
                i = -1;
			}
			else{
				ResetPlayer(&(TPlayer.TI[i]));
			}	
		}
		PushStack(&GameHist,TPlayer);
		ronde++;
	}
};




