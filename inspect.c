#include "map.h"
#include "inspect.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>

void inspect(){
	int input,i;
	boolean found;
	found = false;
	i = 1;
	printf("Masukkan petak : ");
	scanf("%d",&input);
	if(Map[input-1] == '#'){
		printf("Petak %d merupakan petak terlarang.\n",input);
	}
	else{
		while (found == false && i<((Teleporter.Neff)/2)+1){
			if (Teleporter.TI[i*2-1]==input){
				found=true;
				printf("Petak %d memiliki teleporter menuju %d.\n",input,Teleporter.TI[i*2]);
			}
			i++;
		};
		if (found == false){
			printf("Petak %d merupakan petak kosong.",input);
		}
		
	}
	
}
