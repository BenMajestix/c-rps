//
//  main.c
//  c-rps
//
//  Created by Ben Bartel on 2021-01-07.
//

#include <stdio.h>
#include <stdlib.h>

int userScore = 0;
int compScore = 0;

int userChoice(void);
int compChoice(void);
void makeResult(int user, int comp);
void startGame(void);
void showScore(void);


int main(int argc, const char * argv[]) {
    printf("--Rock Paper Scissors by Ben-- \n");
    showScore();
    startGame();
    
    return 0;
}




int userChoice(void){
    int i = 0;
    char input;
    printf("Please Enter your Choice: \n");
    printf(" 1 for Stone, \n");
    printf(" 2 for Paper, \n");
    printf(" 3 for Scissors. \n");
    printf("Input: ");
    scanf("%c", &input);
    
    switch (input) {
        case '1':
            i = 1;
            break;
        case '2':
            i = 2;
            break;
        case '3':
            i = 3;
            break;
        case 'q':
            exit(0);
            break;
        case 's':
            showScore();
            break;
        default:
            break;
    }
    return i;
}

int compChoice(void){
    int i = 0;
    int r = rand() % 3;
    //Would have liked to use switch, but didnt work
    if(r == 0){i = 1;}
    else if(r == 1){i = 2;}
    else if(r == 2){i = 3;}
    
    return i;
}

void makeResult(int user, int comp){
    if(user == 1 && comp == 1){
        printf("--Draw");
    }
    else if(user == 2 && comp == 2){
        printf("--Draw");
    }
    else if(user == 3 && comp == 3){
        printf("--Draw");
    }
    else if(user == 1 && comp == 2){
        printf("--Comp Wins \n");
        compScore += 1;
        printf("--Comp gets 1 Point \n");
    }
    else if(user == 1 && comp == 3){
        printf("--User Wins \n");
        userScore += 1;
        printf("--User gets 1 Point \n");
    }
    else if(user == 2 && comp == 1){
        printf("--User Wins");
        userScore += 1;
        printf("--User gets 1 Point \n");
    }
    else if(user == 2 && comp == 3){
        printf("--Comp Wins \n");
        compScore += 1;
        printf("--Comp gets 1 Point \n");
    }
    else if(user == 3 && comp == 1){
        printf("--Comp Wins \n");
        compScore += 1;
        printf("--Comp gets 1 Point \n");
    }
    else if(user == 3 && comp == 2){
        printf("--User Wins");
        userScore += 1;
        printf("--User gets 1 Point \n");
    }
    printf("\n");
    printf("\n");
    startGame();
}
void startGame(void){
    int user = userChoice();
    int comp = compChoice();
    
    makeResult(user, comp);
}

void showScore(){
    printf("\n --User Score: %d", userScore);
    printf("\n --Computer Score: %d \n", compScore);
}
