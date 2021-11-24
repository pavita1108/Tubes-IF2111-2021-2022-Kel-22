#include "command.h"
#include "inspect.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Command(char input[10],TabPlayer *TPlayer, Player *CPlayer){
	if (strcmp(input,"SKILL") == 0){
		Skill(&(*CPlayer),&(*TPlayer));
	}
	else if (strcmp(input,"MAP")== 0){
		PrintMap(*TPlayer,Map);
	}
	else if (strcmp(input,"BUFF")== 0){
		if((*CPlayer).Imun){
			puts("Imunitas Teleport");
		}
		if((*CPlayer).Pembesar){
			puts("Senter Pembesar Hoki");
		}
		if ((*CPlayer).Pengecil){
			puts("Senter Pengecil Hoki");
		}
		if ((*CPlayer).Pengganda){
			puts("Cermin Pengganda");
		}
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
		puts("UNDO");
	}
	else if (strcmp(input,"ENDTURN")== 0){
		printf("");
	}
	else{
		puts("Salah input");
	}
};
