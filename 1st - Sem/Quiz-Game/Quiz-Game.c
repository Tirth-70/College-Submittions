#include<stdio.h>
#include<stdlib.h>
struct Quiz
{
    char q[1000];
    int ans;
    char op1[100],op2[100],op3[100],op4[100];
};
void main()
{
    struct Quiz s[100];
    int n,i,C_ans,marks=0;
    char start,T_start;

    system("clear");

    printf("\n\n*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\n\n");

    printf("\t\t\tWELCOME TO QUIZ WORLD\t");

    printf("\n\n*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\n\n");
    printf("\n\nNOTE :-");
    printf("\n[For TEACHER : You must create QUIZ to take a EXAM So Make one.]");

    printf("\n\nEnter the no. of Questions you wanted : ");
    scanf("%d",&n);
    fflush(stdin);

    for(i=0;i<n;i++)
    {
        printf("\n\nEnter the Question :-\n");
        fflush(stdin);
        fgets(s[i].q, 1000, stdin);
        fflush(stdin);
        printf("\n");
        
        printf("Option 1 : ");
        fflush(stdin);
        fgets(s[i].op1, 100, stdin);
        fflush(stdin);
        
        printf("Option 2 : ");
        fflush(stdin);
        fgets(s[i].op2, 100, stdin);
        fflush(stdin);
        
        printf("Option 3 : ");
        fflush(stdin);
        fgets(s[i].op3, 100, stdin);
        fflush(stdin);
        
        printf("Option 4 : ");
        fflush(stdin);
        fgets(s[i].op4, 100, stdin);
        fflush(stdin);
        
        printf("\nEnter the Answer(in terms of 1||2||3||4) : ");
        fflush(stdin);
        scanf("%d",&s[i].ans);
        fflush(stdin);
    }

    printf("\n\n*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\n\n");
    system("clear");
    printf("*-*\n\t");
    printf("Do you want to start the exam(Y or N) : ");
    fflush(stdin);
    scanf("%c",&start);
    fflush(stdin);

    if(start == 'Y' || start == 'y')
    {
        //system("clear");
        printf("\n\n*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\n\n");
        printf("\nInstructions :\n\n");
        printf("\n >> There will be a total of %d questions",n);
        printf("\n >> You will be given 4 options and you have to press 1, 2 ,");
        printf("\n    3 or 4 for thefor right option");
        printf("\n >> Each question will carry 5 points");
        printf("\n >> You will be asked questions continuously.");
        printf("\n >> There is no negative marking for wrong answer");
        printf("\n\n\n*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\n\n");

        printf("Press AnyKey to start your Exam : ");
        scanf("%c",&T_start);
        if(T_start)
        {
            system("clear");
            for(i=0;i<n;i++)
            {
                printf("Question %d. : ",i+1);
                puts(s[i].q);
                printf("\n");
            
                printf("Option 1 : ");
                puts(s[i].op1);
                //printf("\n");
            
                printf("Option 2 : ");
                puts(s[i].op2);
                //printf("\n");
            
                printf("Option 3 : ");
                puts(s[i].op3);
                //printf("\n");
            
                printf("Option 4 : ");
                puts(s[i].op4);
                printf("\n");

                printf("Enter your Answer : ");
                fflush(stdin);
                scanf("%d",&C_ans);
                fflush(stdin);

                if(C_ans == s[i].ans)
                {
                    marks+=5;
                    printf("Correct! +5 Points🥳\n\n");
                }
                else{
                    printf("Oppss! +0 Points😭\n\n");
                }
            }
        }
    }
    else{
        printf("Ok USER we won't start!\n");
    }
    printf("\nYour score in the Exam is %d out of %d.\n\n",marks,n*5);
}