#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Command(char input[10],TabPlayer *TPlayer, Player *CPlayer){
	if (strcmp(input,"SKILL") == 0){
		printf("SKILL");
	}
	else if (strcmp(input,"MAP")== 0){
		PrintMap(*TPlayer,Map);
	}
	else if (strcmp(input,"BUFF")== 0){
		printf("BUFF");
	}
	else if (strcmp(input,"INSPECT")== 0){
		inspect();
	}
	else if (strcmp(input,"ROLL")== 0){
		int hasil;
		hasil = Roll(*CPlayer);
		Move(&(*CPlayer),hasil);
	}
	else if (strcmp(input,"UNDO")== 0){
		printf("UNDO");
	}
	else if (strcmp(input,"ENDTURN")== 0){
		puts("Lanjut pemain berikutnya");
	}
	else{
		puts("Salah input");
	}
};
