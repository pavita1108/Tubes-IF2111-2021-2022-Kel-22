#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "listskill.h"
#include "player.h"


void undo(Stack stackPemain) {

    if (Top(stackPemain) > 1) {
        PopStack(&stackPemain, &InfoTop(stackPemain));
    }
}