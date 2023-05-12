#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global declaration
int count = 0;

// Structure declaration
struct node
{
    struct node *prev;
    int id;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
} * h, *temp, *temp1, *temp2, *temp4;

// Function to create node
void create()
{
    int id;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    
    temp = (struct node *)malloc(sizeof(struct node));
    
    temp->prev = NULL;
    temp->next = NULL;
    
    printf("\n enter id, name, department, designation, salary and phno of employee:\n");
    scanf("%d %s %s %s %f %ld",&id, name, dept, desg, &sal, &phno);
    
    temp->id = id;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    
    temp->sal = sal;
    temp->phno = phno;
    count++;
}

// Function to insert at beginning
void insertbeg()
{
    // If DLL is empty
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    // update the links
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

// Function to insert at end
void insertend()
{
    // If DLL is empty
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }

    // update the links
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

// Function to display from beginning
void displaybeg()
{
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("\n list is empty\n");
        return;
    }
    
    printf("\n linked list elements from beginning:\n");
    while (temp2 != NULL)
    {
        printf("%d %s %s %s %f %ld\n",temp2->id, temp2->name,temp2->dept, temp2->desg,temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }

    printf("number of employees=%d", count);
}

// Function to delete at end
int deleteend()
{
    struct node *temp;
    temp = h;
    if (temp == NULL)
    {
        printf("list is empty\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        printf("%d %s %s %s %f %ld\n",temp->id, temp->name,temp->dept, temp->desg,temp->sal, temp->phno);
        free(temp);
        h = NULL;
    }
    else
    {
        temp = temp1;
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("%d %s %s %s %f %ld\n",temp->id, temp->name,temp->dept, temp->desg,temp->sal, temp->phno);
        free(temp);
        temp1 = temp2;
    }
    count--;
    return 0;
}

// Function to delete from beginning
int deletebeg()
{
    struct node *temp;
    temp = h;
    if (temp == NULL)
    {
        printf("list is empty\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        printf("%d %s %s %s %f %ld\n",temp->id, temp->name,temp->dept, temp->desg,temp->sal, temp->phno);
        free(temp);
        h = NULL;
    }
    else
    {
        h = h->next;
        h->prev = NULL;
        printf("%d %s %s %s %f %ld\n",temp->id, temp->name,temp->dept, temp->desg,temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}

// Driver Code
int main()
{
    int ch, n, i;
    h = NULL;
    temp = temp1 = NULL;
    while (1)
    {
        printf("\n--------Menu------------\n");
        printf("\n 1.create a DLL of n emp");
        printf("\n 2.display from beginning");
        printf("\n 3.insert at end");
        printf("\n 4.delete at end");
        printf("\n 5.insert at beginning");
        printf("\n 6.delete at beginning");
        printf("\n 7.exit\n");
        printf("----------------------\n");
        printf("\n enter choice : ");
        scanf("%d", &ch);

        // Switch statements begins
        switch (ch)
        {
        case 1:
            printf("\n enter number of employees:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertend();
            break;
        case 2:
            displaybeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insertbeg();
            break;
        case 6:
            deletebeg();
            break;
        case 7:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }

    return 0;
}