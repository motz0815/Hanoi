#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool finished = false;

int a[5] = {5,4,3,2,1};
int b[5] = {0,0,0,0,0};
int c[5] = {0,0,0,0,0};

void init() {
    
}

int getIndexOfHighestBrick(int x[5]) {
    // Wenn Stab leer, -1 zurückgeben
    if(x[0] == 0) return -1;

    for(int i = 0; i < 5; i++) {
        if(i != 0) {
            if(x[i] == 0) {
                return i-1;
            }
        } else if(i == 4) {
            if(x[i] != 0) {
                return i;
            }
        }
    }
    return -1;
}

bool checkMoveValid(int x[5], int y[5]) {
    // Ist ein Stein auf dem ersten Stab?
    if(x[0] == 0) return false;

    // Ist der oberste Stein auf dem 1. Stab kleiner als der oberste des 2. Stabs?

    // 
}

int * getArrayFromChar(char x) {
    switch (x) {
    case 'a':
        return a;
        break;
    
    case 'b':
        return b;
        break;

    case 'c':
        return c;
        break;
    }
}

void move() {
    fflush(stdin);
    // User input
    printf("Welchen Stein möchtest du aufheben? ");
    char from;
    scanf("%c", &from);

    fflush(stdin);
    printf("\nWohin möchtest du den Stein legen? ");
    char to;
    scanf("%c", &to);

    if(checkMoveValid(getArrayFromChar(from), getArrayFromChar(to)) != true) {
        printf("\nDas ist kein valider Zug!");
        sleep(1);
        return;
    }

    finished = true;
}

void printPic() {
    system("clear");
    printf("\n");
    
    for(int i = 4; i >= 0; i--) {
        printf("\t%d\t%d\t%d\n", a[i], b[i], c[i]);
    }

    for(int i = 0; i < 33; i++) {
        printf("_");
    }
    printf("\n\tA\tB\tC\n\n");
}

int main() {
    init();
    
    // In die Loop einsteigen
    do {
        printPic();
        move();
    } while(!finished);
}