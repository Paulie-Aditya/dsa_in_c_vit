#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

// Head is referred to as L
// Head itself has no value (data), and stores the address of first Node in head.next;


void insert_first();
void display();
void insert_last();
void insert_specific();
void delete_last();
void delete_first();
void delete_specific();

struct node
{
    int data;
    struct node *next;
} *start=NULL;

int item;
void main()
{
    int ch;
    clrscr();
    do
    {
        printf("\n\n1. Insert First\n2. insert last\n3. insert specific\n4. Delete first\n 5. Delete
        last\n 6. Delete specific\n 7.Exit\n\n\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert_first();
            display();
            break;
        case 2:
            insert_last();
            display();
            break;
        case 3:
            insert_specific();
            display();
            break;
        case 4:
            delete_first();
            display();
            break;
        case 5:
            delete_last();
            display();
        break;
        case 6:
            delete_specific();
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("\n\nInvalid choice. Please try again.\n");
    }
    } while (1);
}

void insert_first()
{
    struct node *ptr;
    printf("\n\nEnter item: ");
    scanf("%d", &item);
    if(start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));
        start->data = item;
        start->next = NULL;
    }
    else
    {
        ptr= start;
        start = (struct node *)malloc(sizeof(struct node));
        start->data = item;
        start->next = ptr;
    }
    printf("\nItem inserted: %d\n", item);
}


void insert_last()
{
    struct node *ptr;
    printf("\n\nEnter item: ");
    scanf("%d", &item);
    if(start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));
        start->data = item;
        start->next = NULL;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr-> next;
        ptr-> next = (struct node *)malloc(sizeof(struct node));
        ptr = ptr-> next;
        ptr-> data = item;
        ptr-> next = NULL;
    }
    printf("\nItem inserted: %d\n", item);
}

void insert_specific()
{
    int n;
    struct node *nw, *ptr;
    if (start == NULL)
        printf("\n\nNexted list is empty. It must have at least one node.\n");
    else
    {
        printf("\n\nEnter DATA after which new node is to be inserted: ");
        scanf("%d", &n);
        printf("\n\nEnter ITEM: ");
        scanf("%d", &item);
        ptr = start;
        nw = start;
        while (ptr != NULL)
        {
            if (ptr->data == n)
            {
                nw = (struct node *)malloc(sizeof(struct node));
                nw->data = item;
                nw->next = ptr->next;
                ptr->next = nw;
                printf("\n\nItem inserted: %d", item);
                return;
            }
            else
                ptr = ptr->next;
        }
    }
}

void display()
{
    struct node *ptr = start;
    int i=1;
    if (ptr == NULL)
        printf("\nNextlist is empty.\n");
    else
    {
        printf("**********************************");
        printf("\nSr. No.\t\tAddress\t\tData\t\tNext\n");
        while(ptr != NULL)
        {
            printf("\n%d. \t\t%d \t\t%d \t\t%d \n", i, ptr, ptr->data, ptr->next);
            ptr = ptr->next;
            i++;
        }
        printf("*********************************");
    }
}

void delete_first()
{
    struct node *ptr;
    if (start == NULL)
        printf("\n\nNexted list is empty.\n");
    else
    {
        ptr = start;
        item = start->data;
        start = start->next;
        free(ptr);
        printf("\n\nItem deleted: %d", item);
    }
}

void delete_last()
{
    struct node *ptr, *prev;
    if (start == NULL)
        printf("\n\nNexted list is empty.\n");
    else
    {
        ptr = start;
        prev = start;
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        item = ptr->data;
        if (start->next == NULL)
            start = NULL;
        else
            prev->next = NULL;
        prev->next = NULL;
        free(ptr);
        printf("\n\nItem deleted: %d", item);
    }
}

void delete_specific()
{
    struct node *ptr, *prev;
    printf("\n\nEnter ITEM which is to be deleted: ");
    scanf("%d", &item);
    if (start == NULL)
        printf("\n\nNexted list is empty.\n");
    else if (start->data == item)
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    else
    {
        ptr = start;
        prev = start;
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                prev->next = ptr->next;
                free(ptr);
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        printf("\n\nItem deleted: %d", item);
    }
}


