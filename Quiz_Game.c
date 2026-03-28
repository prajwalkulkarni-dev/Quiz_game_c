#include <stdio.h>
#include <string.h>

#define MAX 10

char Questions[MAX][100] = {
    "Which planet is known as the Red Planet?",
    "What is the capital of Japan?",
    "Who is known as the Father of Computers?",
    "What does RAM stand for?",
    "Who wrote the Indian National Anthem?",
    "Which is the largest ocean on Earth?",
    "Who discovered gravity?",
    "Which country is known as the Land of the Rising Sun?",
    "How many continents are there in the world?",
    "What is the national animal of India?"
};

char Options[MAX][4][50] = {
    {"Venus","Mars","Jupiter","Saturn"},
    {"Beijing","Seoul","Tokyo","Osaka"},
    {"Charles Babbage","Alan Turing","John von Neumann","Bill Gates"},
    {"Read Access Memory","Random Access Memory","Run Access Memory","Rapid Access Memory"},
    {"Rabindranath Tagore","Mahatma Gandhi","Bankim Chandra Chatterjee","Subhas Chandra Bose"},
    {"Atlantic Ocean","Indian Ocean","Pacific Ocean","Arctic Ocean"},
    {"Albert Einstein","Isaac Newton","Galileo Galilei","Nikola Tesla"},
    {"China","Japan","Thailand","South Korea"},
    {"5","6","7","8"},
    {"Lion","Elephant","Tiger","Leopard"}
};

// Answers Options
int Answers[MAX] = {2, 3, 1, 2, 1, 3, 2, 2, 3, 3};

struct Quiz {
    char question[100];
    char options[4][100];
    int ans;   
};

struct Player {
    char name[50];
    int score;
};

int main() {
    struct Quiz quiz[MAX];
    struct Player player;

    printf("-----WELCOME TO THE QUIZ-----\n");

    printf("Player Name: ");
    scanf("%s", player.name);  //Player Input

    printf("Welcome %s!!\n", player.name);
    printf("-----------------------------\n");
    printf("\nDISCLAIMER: You get 1 point for each correct answer.\n");

    char ch;
    printf("Want to play? Y/N: ");
    scanf(" %c", &ch);

    if (ch == 'Y' || ch == 'y') {
        printf("\n=================================\n");
        printf("         ALL THE BEST!!\n");
        printf("=================================\n");
        
        // Assign questions and options
        for (int i = 0; i < MAX; i++) {
            strcpy(quiz[i].question, Questions[i]);
            quiz[i].ans = Answers[i];

            for (int j = 0; j < 4; j++) {
                strcpy(quiz[i].options[j], Options[i][j]);
            }
        }
        int choice, points = 0;

        // Quiz loop
        for (int i = 0; i < MAX; i++) {
            printf("\nQ%d) %s\n", i + 1, quiz[i].question);

            for (int j = 0; j < 4; j++) {
                printf("%d. %s\n", j + 1, quiz[i].options[j]);
            }

            printf("Enter Answer(1-4): ");
            scanf("%d", &choice);
            
            if(choice<1 || choice>4){ //Invalid option checking
                printf("INVALID CHOICE!! Enter Again: ");
                scanf("%d",&choice);
            }
            
            if (choice == quiz[i].ans) {
                points++;
            }
        }
        printf("\n------------QUIZ ENDED-------------\n");

        // Results
        player.score = points;
        float percentage= (player.score*100.0)/MAX;
        printf("\n=========================\n");
        printf("        RESULTS\n");
        printf("=========================\n");
        printf("Score: %d / 10\n", player.score);
        printf("Percentage: %.2f\n",percentage);

        if (percentage >= 70){
            printf("Congratulations, Great Achievement!!\n");
            printf("-------------------------\n");
        }
        else if (percentage>=50){
            printf("Excellent, Keep it up!!\n");
            printf("-------------------------\n");
        }
        else{
            printf("Not bad, Keep trying!!\n");
            printf("-------------------------\n");
        }
    } 
    else if(ch=='n'||ch=='N') {
        printf("You Quit\n");
    }
    
    else{
        printf("INVALID OPTION!\n");
    }

    return 0;
}