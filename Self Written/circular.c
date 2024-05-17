#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail;
int getl()
{
    int count = 1;
    struct node* temp;
    temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void create()
{
    struct node *newnode;
    int n, i;
    head = NULL;
    printf("ENter the nodes :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }
}
void insertatbegining()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data at begining :");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = tail = newnode;
        tail->next = head;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}
void insertatend()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data at end :");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = tail = newnode;
        tail->next = head;
    }

    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}
void insertatspecificpoint()
{
    struct node *newnode, *temp;
    int loc, i;
    printf("Enter the location where you want to add node :");
    scanf("%d", &loc);
    int l = getl();
    if (loc < 1 || loc > l)
    {
        printf("Invalid location\n");
    }
    else if (loc == 1)
    {
        insertatbegining();
    }

    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->next = 0;
        temp = head;

        for (i = 1; i < loc - 1; i++)
        {
            temp = temp->next;
        }
        printf("Enter the data :");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void insertafterspecificpoint()
{
    struct node *newnode, *temp;
    int loc, i;
    printf("Enter the location where you want to add node :");
    scanf("%d", &loc);
    int l = getl();
    if (loc < 1 || loc > l)
    {
        printf("Invalid location\n");
    }
    else if (loc == l)
    {
        insertatend();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->next = 0;
        temp = head;

        for (i = 1; i < loc; i++)
        {
            temp = temp->next;
        }
        printf("Enter the data :");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void deleteatbegining()
{
    struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else if (head == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        tail->next = head;
        free(temp);
    }
}
void deleteatend()
{
    struct node *temp, *ptr;
    temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else if (head == tail)
    {
        head = tail = 0;
        free(temp);
    }

    else
    {
        while (temp->next != head)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = head;
        tail = ptr;
        free(temp);
    }
}
void deleteatspecificlocation()
{
    struct node *temp, *ptr;
    int loc, n, i;
    printf("ENter the location :");
    scanf("%d", &loc);
    int l = getl();
    ptr = head;
    if (loc < 1 || loc > l)
    {
        printf("Invalid Location\n");
    }
    else if (loc == 1)
    {
        deleteatbegining();
    }
    else if (loc == l)
    {
        deleteatend();
    }
    else
    {
        for (i = 1; i < loc - 1; i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
}
void deletebeforespecificlocation()
{
    struct node *temp, *ptr;
    int i, loc, l;
    printf("ENter the location :");
    scanf("%d", &loc);
    temp = head;
    l = getl();
    if (loc < 2 || loc > l)
    {
        printf("Invalid Location\n");
    }
    else if (loc == 2)
    {
        deleteatbegining();
    }
    else
    {
        for (i = 1; i < loc - 2; i++)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
    }
}

void deleteafterspecificlocation()
{
    struct node *temp, *ptr;
    int i, loc, l;
    printf("ENter the location :");
    scanf("%d", &loc);
    temp = head;
    l = getl();
    if (loc < 1 || loc > l)
    {
        printf("Invalid Location\n");
    }

    else
    {
        for (i = 1; i < loc; i++)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        if (ptr == head)
        {
            head = head->next;
            free(ptr);
        }
        free(ptr);
    }
}
void display()
{
    int l;
    struct node *temp;
    temp = head;
    l = getl();
    while (temp->next != head)
    {
        printf("Displayed data :%d\n", temp->data);
        temp = temp->next;
    }
    printf("Displayed data :%d\n", temp->data);
    printf("Length of the linked list :%d", l);
}
int main()
{
    int pick;
    while (1)
    {
        printf("\n\n\t\tMENU Circular Linked List\n\n\n");
        printf("ENter the operation\n");
        printf("\n");
        printf("1.Create linked list\n");
        printf("2.Insert at begining\n");
        printf("3.Insert at end\n");
        printf("4.Insert at specific location\n");
        printf("5.Insert after specific node\n");
        printf("6.Delete from begining\n");
        printf("7.Delete from end\n");
        printf("8.Delete at specific position\n");
        printf("9.Delete before specific node\n");
        printf("10.Delete ater specific location\n");
        printf("11.Display\n");
        printf("12.Exit");
        printf("\nENter your choice :");
        scanf("%d", &pick);
        switch (pick)
        {
        case 1:
            create();
            break;
        case 2:
            insertatbegining();
            break;
        case 3:
            insertatend();
            break;
        case 4:
            insertatspecificpoint();
            break;
        case 5:
            insertafterspecificpoint();
            break;
        case 6:
            deleteatbegining();
            break;
        case 7:
            deleteatend();
            break;
        case 8:
            deleteatspecificlocation();
            break;
        case 9:
            deletebeforespecificlocation();
            break;
        case 10:
            deleteafterspecificlocation();
            break;
        case 11:
            display();
            break;
        case 12:
            exit(0);
            break;
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;
}