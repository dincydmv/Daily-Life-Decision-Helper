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

int main()
{
    int choice;
    do
    {
        printf("\n=====Daily Life Decion Helper====");
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
            // case 3:
            //     energyPlanner();
            //     break;
            // case 4:
            //     addToDoList();
            //     break;
            // case 5:
            //     getMotivation();
            //     break;
            // case 6:
            //     printf("Exiting Program...\n");
            //     break;
            // default:
            //     printf("Invalid choice\n");
        }

    } while (choice != 6);
    return 0;
}

/*decide what to do next*/
void decideNextTask()
{
    struct Task tasks[MAX];
    int n, i, j;

    printf("\n Enter number of tasks:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n Enter %d task name: ", i + 1);
        scanf(" %[^\n]", tasks[i].name);

        printf("\n Importance of the task (1-5): ");
        scanf("%d", &tasks[i].importance);

        printf("\n Deadline (days left): ");
        scanf("%d", &tasks[i].deadline);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (tasks[j].importance < tasks[j + 1].importance ||
                (tasks[j].importance == tasks[j + 1].importance &&
                 tasks[j].deadline > tasks[j + 1].deadline))
            {

                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("\n----- GENERATED TIMETABLE -----\n");
    for (i = 0; i < n; i++)
    {
        printf("Task: %s (Importance: %d, Deadline: %d days)\n",
               tasks[i].name, tasks[i].importance, tasks[i].deadline);

        printf("  -> Work for 1 hour\n");
        printf("  -> Take 15 min break\n");

        if ((i + 1) % 3 == 0)
            printf("  -> Take longer 30 min break\n");
    }
}

/*resolve dilemma*/
void resolveDilemma()
{
    char option1[50], option2[50];
    int importance, stress;

    printf("\nEnter the first option of your dilemma (more important): ");
    scanf(" %[^\n]", option1);

    printf("\nEnter the second option of your dilemma (less important): ");
    scanf(" %[^\n]", option2);

    printf("\nEnter the importance (1-5): ");
    scanf("%d", &importance);

    printf("\nStress level? (1-5): ");
    scanf("%d", &stress);

    if (importance >= 4)
    {
        printf("\nSuggested option: %s", option1);
    }
    else if (stress >= 4)
    {
        printf("\nSuggested option: %s", option2);
    }
    else
    {
        printf("\nSuggested option: %s", option1);
    }
}