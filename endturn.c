#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "listskill.h"
#include "player.h"

#include "endturn.h"


Stack endTurn (Player P, Stack stackPemain) {
	// ini langsung menyimpan Player kedalam stack, jadinya skill, buff, posisi player juga kesimpan.
	PushStack(&stackPemain, P);
	return stackPemain;
}


/* CONTOH PENGGUNAAN
int main() {
	int R1, R2, x;
	Stack stackPlayer1, stackPlayer2;
	Player Player1, Player2, tempPlayer;
	
	
	// Buat Player dulu
	MakePlayer(&Player1);
	MakePlayer(&Player2);
	
	// Stack untuk menyimpan informasi tiap turn pemain
	CreateEmptyStack(&stackPlayer1);
	CreateEmptyStack(&stackPlayer2);
	
	
	R1 = RandomizeSkill();
    AddSkill(&((Player1).Skill), R1);
    
    // Simpan state Player1 ke stackPlayer1
    stackPlayer1= endTurn(Player1, stackPlayer1);
    
    
    // Contoh akses skill yang sudah disimpan pada stackPlayer1
    tempPlayer = InfoTop(stackPlayer1);
    x = Info(First((tempPlayer).Skill));
    
    printf("%d", x);
} */


/* CATATAN:

	1. ADT Stack-nya udah diubah yang tadinya InfoType jadi Player
	2. Kalau mau 'UNDO' tinggal Pop aja stackPlayer nya, tapi harus 
	   dipastiin tinggi Stack Player1 sama Player2 sama supaya pas ngapus rondenya