#include "./adt/Player/player.h"
#include "./adt/Map/map.h"
#include "./adt/Array/array.h"
#include "./adt/Command/command.h"
#include "./adt/Listskill/listskill.h"
#include "./adt/Stack/stack.h"
#include <stdio.h>
#include <string.h>


int main()
{
	char *title = 
		".88b  d88.                                                                             \n"
		"88'YbdP`88                                                                             \n"
		"88  88  88                                                                             \n"
		"88  88  88  .d88b.  d8888b. d888888b d888888b  .d8b.  d8b   db  d888b   d888b   .d8b.  \n"
		"88  88  88 .8P  Y8. 88  `8D   `88'   `~~88~~' d8' `8b 888o  88 88' Y8b 88' Y8b d8' `8b\n"
		"88  88  88 88    88 88oooY'    88       88    88ooo88 88V8o 88 88      88      88ooo88\n"
		"88  88  88 88    88 88~~~b.    88       88    88~~~88 88 V8o88 88  ooo 88  ooo 88~~~88\n"
		"88  88  88 `8b  d8' 88   8D   .88.      88    88   88 88  V888 88. ~8~ 88. ~8~ 88   88\n"
		"YP  YP  YP  `Y88P'  Y8888P' Y888888P    YP    YP   YP VP   V8P  Y888P   Y888P  YP   YP\n\n\n";
	char *welcome_text = 
		"Selamat datang di Mobitangga!\n"
		"Perkenalkan, kami kelompok 22. Kami akan menjadi Guide kalian dalam permainan ini!\n";
		
	printf(title);
	printf(welcome_text);
	char *b = malloc(256);
	do{
		
		puts("Gunakan NEW GAME untuk memulai permainan baru atau EXIT untuk keluar dari program!");
		printf("Masukkan input : ");
		fgets(b, 256, stdin);
		if ((strlen(b) > 0) && (b[strlen (b) - 1] == '\n')) {
			b[strlen(b) - 1] = '\0';
		}
		
		if(strcmp(b, "EXIT") == 0){
			exit(1);
		};	
	}while((strcmp(b, "NEW GAME") != 0) && (strcmp(b, "EXIT") != 0));
	
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
				if (TPlayer.TI[i].doneRoll == true && strcmp(command,"SKILL")== 0){
					puts("Ga boleh pake skill lagi");
				}
				else{
					Command(command,&TPlayer,&(TPlayer.TI[i]));
				}
				if ((TPlayer.TI[i].CPosition)+1 == N){
					int r,k,j,temp,rank;
					int v;
					v = 1;
					int positions[4] = {0, 0, 0, 0};
    				int ranks[4] = {1, 2, 3, 4};
					puts("YAY KAMU MENANG. CONGRATSSS!!!!");
					for( r=0;r<TPlayer.Neff;r++){
        				positions[r] = TPlayer.TI[r].CPosition;
    				}
    				for(k=0;k<3;k++){ 
				        for( j=0;j<TPlayer.Neff-1;j++){
				            if(positions[j] > positions[j+1]){
				                temp = positions[j];
				                positions[j] = positions[j+1];
				                positions[j+1] = temp;
				
				                rank = ranks[j];
				                ranks[j] = ranks[j+1];
				                ranks[j+1] = rank;
				            }
				        }
				    }
					printf("\nRANK akhir :\n");
				    for (r = TPlayer.Neff - 1; r >=0;r--){
				    	printf("%d. %s posisi : %d\n", v,TPlayer.TI[ranks[r]-1].Nama,(TPlayer.TI[ranks[r]-1].CPosition )+1);
				    	v++;
					}
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
                    	if (IsEmptyStack(GameHist)) {
                    		int j;
                    		for (j=0;j<TPlayer.Neff;j++) {
                    			ResetPlayer(&(TPlayer.TI[j]));
							}
							PushStack(&GameHist,TPlayer);
						} else {
							PopStack(&GameHist, &TPlayer);
						}
                    	
                    	
                    	printf("UNDO berhasil dilakukan\n");
                    	ronde -= 1;
						PrintMap(TPlayer,Map);
                        printf("Apakah ingin melakukan UNDO lagi? (YES/NO): ");
                        scanf("%s",&u);
                        if(strcmp(u,"NO")== 0){
                        	break;
						}
                    }while (ronde >= 1 &&strcmp(u,"YES")== 0);
                }  
                else {
                    printf("\n");
                    PopStack(&GameHist, &TPlayer);
                    printf("UNDO berhasil dilakukan\n");
					PrintMap(TPlayer,Map);
                }
                i = -1;
                if (ronde <=0) {
                	ronde = 1;
				}
			}
			else{
				ResetPlayer(&(TPlayer.TI[i]));
			}	
		}
		PushStack(&GameHist,TPlayer);
		ronde++;
	}
};
