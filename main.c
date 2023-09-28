#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countFunction (const int *array, int arrSize) {
    int count = 0;
    for (int i = 0; i < arrSize - 1; i ++ ){
        for (int j = i;  j < arrSize; j ++){
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count == arrSize || count > arrSize /3) {
            return count;
        }
        else count = 0;
    }
    return count;
}

int main() {
    srand(time(NULL));
    int bet;
    int play = 0;
    int arrSize = 9;
    int count;
    int arr[arrSize];
    int winNum=7;
    printf("Enter your gambling bet:");
    scanf("%d", &bet);
    while(1){
        count = 0;
        printf("Enter '1' to start OR '0' to exit;\n");
        if(scanf("%d", &play) == 1) {
            for (int i = 0; i < arrSize; i++){
//                arr[i] = 1;
//                arr[i] = 7;
                arr[i] = rand () % 10;
                printf("Number %d: %d\n", i, arr[i]);
                if (arr[i] == winNum) {
                    count++;
                }
            }
            printf("\n");
            if (count == arrSize){
                printf("You win, your bet is tripled!\n");
                bet = bet*3;
            }
            else if (count == 1 || (count < arrSize && count > 0)) {
                printf("Your bet has been returned;\n");
            }
            else if (countFunction(&arr[0], arrSize) == arrSize) {
                printf("You win, your bet is doubled!\n");
                bet = bet*2;
            }
            else if (countFunction(&arr[0], arrSize) > arrSize/3 && countFunction(&arr[0], arrSize) < arrSize) {
                printf("Your bet has been returned;\n");
            }
            else {
                printf("You lose;\n");
                bet = 0;
                return 1;

            }
            printf("Your current bet: %d\n", bet);
        }
        else {
            return 0;
        }
    }
    return 0;
}

