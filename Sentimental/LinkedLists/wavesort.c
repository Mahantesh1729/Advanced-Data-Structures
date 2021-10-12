#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node* node;

node insertNode(node head, int data);
void display(node head);

void sortLinkedList(node head);

void waveSort(node head);

void swap(int* a, int* b);

int main()
{
    node head = NULL;
    
    int n = 10;
    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        head = insertNode(head, temp);
    }

    printf("\nBefore sorting: \n");
    display(head);
        
    sortLinkedList(head);

    printf("\nAfter sorting: \n");
    
    display(head);
    
    waveSort(head);
    
    printf("\nWave sorting linked list:\n");
    
    display(head);
    
    return 0;
}

node insertNode(node head, int data)
{
    node temp = (node) malloc(sizeof(struct Node));
    
    temp->data = data;
    temp->next = head;
    
    return temp;
}

void display(node head)
{
    node trav = head;
    
    while(trav->next != NULL)
    {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    
    printf("%d", trav->data);
}

void sortLinkedList(node head)
{
    int swapped = 1;
    node p1 = head;
    node p2 = head->next;
    
    if(head->next == NULL) return;
    
    while(swapped)
    {
        swapped = 0;
        for(node trav =head; (trav->next) != NULL; trav = trav->next)
        {
            if(trav->data > (trav->next)->data)
            {
                int temp = trav->data;
                trav->data = (trav->next)->data;
                (trav->next)->data = temp;
                swapped = 1;
            }
        }
    }
}

void waveSort(node head)
{
    
    for(node trav = head; trav != NULL; trav = trav->next)
        {
            
            int temp = trav->data;
            trav->data = (trav->next)->data;
            (trav->next)->data = temp;
            if(trav->next == NULL) return;
            trav = trav->next;
        }
}

// void swap(int* a, int* b)
// {
//     in temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
