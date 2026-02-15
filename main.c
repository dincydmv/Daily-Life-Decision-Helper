#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct Task
{
    char name[50];
    int importance;
    int deadline;
};

struct EnergyTask
{
    char name[50];
    int energyRequired;
};

struct ToDo
{
    char name[50];
    int deadline;
};

/*declaring functions*/
void decideNextTask();
void resolveDilemma();
void energyPlanner();
void addToDoList();
void getMotivation();

void main()
{
    int choice;
    do
    {
        printf("\n=====Daily Life Decion Helper====\n");
        printf("\n 1. Decide what to do next");
        printf("\n 2. Resolve a dillemma");
        printf("\n 3. Suggest work based on Energy");
        printf("\n 4. Add Task to To-Do-List");
        printf("\n 5. Get Motivation");
        printf("\n 6. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            decideNextTask();
            break;
        case 2:
            resolveDilemma();
            break;
        case 3:
            energyPlanner();
            break;
        case 4:
            addToDoList();
            break;
        case 5:
            getMotivation();
            break;
        case 6:
            printf("Exiting Program...\n");
            break;
        default:
            printf("Invalid choice\n");
        }

    } while (choice > 6);
}