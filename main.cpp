#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool finished = false;

int a[5] = {5,4,3,2,1};
int b[5] = {0,0,0,0,0};
int c[5] = {0,0,0,0,0};

void init() {
    
}

void move() {
    fflush(stdin);
    // Get User Input
    printf("Welchen Stein möchtest du aufheben? ");
    char from;
    scanf("%c", &from);

    fflush(stdin);
    printf("\nWohin möchtest du den Stein legen? ");
    char to;
    scanf("%c", &to);

    if(!checkMoveValid(from, to)) {
        printf("\nDas ist kein valider Zug!");
        sleep()
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

int getIndexOfHighestBrick(int x[5]) {

}

int main() {
    init();
    
    // Enter Loop
    do {
        printPic();
        move();
    } while(!finished);
}