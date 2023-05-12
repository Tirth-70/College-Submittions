#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define size 20

struct node
{
    char name[size];
    int start;
    int finish;
    int srno;
    struct node *link;
} *head = NULL;

void idx()
{
    struct node *temp = head;
    int i=1;
    while (temp != NULL)
    {
        temp->srno=i;
        i++;
        temp = temp->link;
    }
}

void insert(char naam[size], int s, int f)
{
    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    strncpy(newnode->name, naam, strlen(naam) - 1);
    newnode->start = s;
    newnode->finish = f;
    newnode->link = NULL;

    int key = f;
    if (head == NULL || key < head->finish)
    {
        newnode->link = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->finish < key)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    idx();
}

void delete (int key)
{
    // Store head node
    struct node *temp = head, *prev;
    if (temp != NULL && key==temp->srno)
    {
        // printf("first");
        head = temp->link; // Changed head
        free(temp);        // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->link'
    while (temp != NULL && key!=temp->srno)
    {
        // printf("first2");
        prev = temp;
        temp = temp->link;
    }

    // If key was not present in linked list
    if (temp == NULL)
    {
        // printf("first3");
        return;
    }
    // printf("first4");
    // Unlink the node from linked list
    prev->link = temp->link;

    free(temp); // Free memory
    idx();
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("\n%d\t%s\t%d\t%d\n", temp->srno, temp->name, temp->start, temp->finish);
        temp = temp->link;
    }
}

void actselection()
{
    struct node *temp = head,*tmp=head->link;
    printf("Selected Activities are as follows :-\n");
    printf("\n%d\t%s\t%d\t%d\n", temp->srno, temp->name, temp->start, temp->finish);
    while (tmp != NULL)
    {
        if (temp->finish <= tmp->start)
        {
            printf("\n%d\t%s\t%d\t%d\n", tmp->srno, tmp->name, tmp->start, tmp->finish);
            temp=tmp;
            tmp=tmp->link;
        }
        else{
            tmp=tmp->link;
        }
    }
}

int main()
{
    int c, s, f, key;
    char name[size], naam[size];

    printf("\n\nWelcome to Activity selection System\n");
    while (1)
    {
        printf("\n\nChoose from the following :-\n\n1. Insert the activity.\n2. Delete an Activity.\n3. Display all Activity.\n4. Display Best Activities to be selected.\n5. Exit the system.");

        printf("\n\nEnter your choice :- ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the name of the Activity :- ");
            fflush(stdin);
            fgets(name, size, stdin);
            fflush(stdin);
            printf("Enter the Start time :- ");
            scanf("%d", &s);
            printf("Enter the Finish time :- ");
            scanf("%d", &f);

            insert(name, s, f);
            break;

        case 2:
            printf("Enter the index of the Activity to be Deleted :- ");
            scanf("%d",&key);

            delete (key);
            break;

        case 3:
            display();
            break;

        case 4:
            actselection();
            break;
        case 5:
            printf("\n^_^ Thanks For using Our service ^_^ ");
            return 0;
        default:
            printf("Invalid Entry");
            break;
        }
    }
    return 0;
}