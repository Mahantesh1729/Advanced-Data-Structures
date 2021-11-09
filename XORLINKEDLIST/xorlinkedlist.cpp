#include <bits/stdc++.h>

struct node{
	int data;
	struct node* xlink;
};

typedef struct node* Node;

using namespace std;

Node insert(Node head, int value);
Node Xor(Node a, Node b);
void display(Node head);
Node deleteLastNode(Node head);

int main()
{
	Node head = NULL;
	int value;
	int choice;
	while(1)
	{
		cout << "\n 1.insert 2.display 3.delete 4.exit\n";
		cin >> choice;
		
		switch(choice)
		{
			case 1:	 cin >> value;
					 head = insert(head, value);
					 break;
			case 2: display(head);
					break;
			case 3: head = deleteLastNode(head);
					break;
			case 4: exit(0);
			default: cout << "Enter a valid choice\n";
		}
	}
}

Node insert(Node head, int value)
{
	Node newNode = (Node) malloc(sizeof(struct node));
	
	newNode->data = value;
	
	newNode->xlink = head;
	
	if(head != NULL)
	{
		head->xlink = Xor(newNode, head->xlink);
	}
	head = newNode;
	
	return head;
}

void display(Node head)
{
	Node cur = head;
	Node prev = NULL;
	Node next;
	
	while(cur != NULL)
	{
		cout << cur->data << " ";
		next = Xor(prev, cur->xlink);
		prev = cur;
		cur = next;
	}
	return;
}

Node Xor(Node a, Node b)
{
	return reinterpret_cast <Node> (reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}

Node deleteLastNode(Node head)
{
    if(head == NULL)
    {
        cout << "\nNo nodes to delete\n";
        return NULL;
    }
    if(head->xlink == NULL)
    {
        free(head);
        return NULL;
    }
    
    Node cur = head;
    Node prev = NULL;
    Node next;
    Node pPrev = NULL;
    while(cur->xlink != prev)
    {
        pPrev = prev;
        next = Xor(prev, cur->xlink);
        prev = cur;
        cur = next;
    }
    prev->xlink = pPrev;
    free(cur);
    return head;
    
}
