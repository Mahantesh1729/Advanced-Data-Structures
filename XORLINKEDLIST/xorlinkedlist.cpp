#include <bits/stdc++.h>

struct node
{
       int data;
       struct node *xnext;
};

typedef node *Node;

using namespace std;

Node insert(Node head, int value);
Node Xor(Node x, Node y);
void display(Node head);
Node deleteNode(Node head);

int main()
{
       Node head = NULL;
       int value;
       int temp;
       while (1)
       {
              cout << "\n1. Insert 2. Display 3. Delete 4. Exit \n";
              cin >> temp;

              switch (temp)
              {
              case 1:
                     cout << "Enter some value: ";
                     cin >> value;
                     head = insert(head, value);
                     break;
              case 2:
                     display(head);
                     break;
              case 3:
                     head = deleteNode(head);
                     break;
              case 4:
                     exit(0);
              }
       }
}

Node insert(Node head, int value)
{
       Node temp = (Node)malloc(sizeof(struct node));

       temp->data = value;

       temp->xnext = head;

       if (head != NULL)
       {
              head->xnext = Xor(temp, head->xnext);
       }

       head = temp;

       return head;
}

Node Xor(Node x, Node y)
{
       return reinterpret_cast<Node>(
           reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

void display(Node head)
{
       Node cur = head;
       Node prev = NULL;
       Node next;

       while (cur != NULL)
       {
              cout << cur->data << " ";

              next = Xor(prev, cur->xnext);

              prev = cur;
              cur = next;
       }
}

Node deleteNode(Node head)
{
       if (head == NULL)
              return NULL;
       else if (head->xnext == NULL)
       {
              free(head);
              return NULL;
       }

       Node temp = head;
       head = head->xnext;
       temp->xnext->xnext = Xor(head, temp->xnext->xnext);
       free(temp);
       return head;
}
