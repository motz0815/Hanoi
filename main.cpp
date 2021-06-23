#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool finished = false;

static int a[5] = {5,4,3,2,1};
static int b[5] = {0,0,0,0,0};
static int c[5] = {0,0,0,0,0};

void init() {
    
}

int getIndexOfHighestBrick(int x[5]) {
    // Wenn Stab leer, -1 zurückgeben
    if(x[0] == 0) return -1;

    for(int i = 4; i >= 0; i--) {
        if(x[i] != 0) return i;
    }

    return -1;
}

bool checkMoveValid(int x[5], int y[5]) {
    // Sind beides nicht dieselben Stäbe?
    if(x == y) return false;

    // Ist ein Stein auf dem ersten Stab?
    if(x[0] == 0) return false;

    // Ist der oberste Stein auf dem 1. Stab kleiner als der oberste des 2. Stabs?
    if(y[0] != 0) { // Zweiter Stab nicht leer
        if(x[getIndexOfHighestBrick(x)] >= y[getIndexOfHighestBrick(y)]) { // Will Stein auf kleineren Stein legen
            return false;
        }
    }

    return true;
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

    return a;
}

void move() {
    // User input
    fflush(stdin);
    printf("Welchen Stein möchtest du aufheben? ");
    char fromChar;
    scanf("%c", &fromChar);

    fflush(stdin);
    printf("\nWohin möchtest du den Stein legen? ");
    char toChar;
    scanf("%c", &toChar);

    if(!checkMoveValid(getArrayFromChar(fromChar), getArrayFromChar(toChar))) {
        printf("\nDas ist kein valider Zug!");
        sleep(1);
        return;
    }

    // Stein bewegen
    int indexFrom = getIndexOfHighestBrick(getArrayFromChar(fromChar));
    int indexTo = getIndexOfHighestBrick(getArrayFromChar(toChar)) + 1;

    int valueFrom = getArrayFromChar(fromChar)[indexFrom];
    
    getArrayFromChar(toChar)[indexTo] = valueFrom;
    getArrayFromChar(fromChar)[indexFrom] = 0;

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

bool compareArrays(int x[5], int y[5]) {
    for(int i = 0; i < 5; i++) {
        if(x[i] != y[i]) return false;
    }
    return true;
}

void checkWon() {
    int x[5] = {5,4,3,2,1};

    if(compareArrays(x, b) || compareArrays(x, c)) finished = true;
}

int main() {
    init();
    
    // In die Loop einsteigen
    do {
        printPic();
        move();
        checkWon();
    } while(!finished);

    printf("Du hast gewonnen! Yay!");
}