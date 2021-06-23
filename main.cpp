#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool finished = false;

static int a[5] = {5,4,3,2,1};
static int b[5] = {0,0,0,0,0};
static int c[5] = {0,0,0,0,0};

int getIndexOfHighestBrick(int x[5]) {
    // If tower empty, return -1
    if(x[0] == 0) return -1;

    for(int i = 4; i >= 0; i--) {
        if(x[i] != 0) return i;
    }

    return -1;
}

bool checkMoveValid(int x[5], int y[5]) {
    // Are the two towers the same?
    if(compareArrays(x,y)) return false;

    // Is there a block on the first tower?
    if(x[0] == 0) return false;

    // Is the topmost block on the first tower smaller than the topmost block on the second tower?
    if(y[0] != 0) { // Second tower not empty
        if(x[getIndexOfHighestBrick(x)] >= y[getIndexOfHighestBrick(y)]) { // User wants to put block on smaller block
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
    printf("From which tower do you want to lift a block? ");
    char fromChar;
    scanf("%c", &fromChar);

    fflush(stdin);
    printf("\nWhere do you want to put that block? ");
    char toChar;
    scanf("%c", &toChar);

    if(!checkMoveValid(getArrayFromChar(fromChar), getArrayFromChar(toChar))) {
        printf("\nThat's not a valid move!");
        sleep(1);
        return;
    }

    // Move Block
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
    // Enter the loop
    do {
        printPic();
        move();
        checkWon();
    } while(!finished);

    printf("You won! Yay!");
}
