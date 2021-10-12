#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;

struct Node
{
    char data;
    struct Node* next;
};

typedef struct Node* node;

node insertEnd(node head, char c);

bool checkPalindrome(node head);

bool check(node *first, node last);

void display(node head);

int main()
{
    string s;
    cin >> s;
    
    node head = NULL;
    
    int n = s.size();
    
    for(int i = 0; i < n; i++)
    {
        head = insertEnd(head, s[i]);
    }
    
    display(head);
    
    if(checkPalindrome(head))
    {
        cout << "\nIt is a pallindrome\n";
    }
    else
        cout << "\nIt is not a pallindrome\n";
        
    return 0;
}

node insertEnd(node head, char c)
{
    node temp = (node) malloc(sizeof(struct Node));
    
    if(temp == NULL) return NULL;
    
    temp->data = c;
    temp->next = NULL;
    
    if(head == NULL) return temp;
    
    node trav = head;
    
    while(trav->next != NULL) trav = trav->next;
    trav->next = temp;
    
    return head;
}

void display(node head)
{
    node trav = head;
    while(trav->next != NULL)
    {
        cout << trav->data <<" -> ";
        trav = trav->next;
    }
    cout << trav->data;
}

bool checkPalindrome(node head)
{
    return check(&head, head);
}

bool check(node *first, node last)
{
    if(last == NULL)
        return true;
    
    bool temp = check(first, last->next);
    bool temp1 = ((*first)->data == last->data);
    
    (*first) = (*first)->next;
    return temp1;
}
