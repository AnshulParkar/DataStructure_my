#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;

    ptr->next = head;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;

    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next= ptr;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
      ptr->data= data;
      struct Node * p = head;

      while(p->next!=NULL)
      {
          p = p->next;
      }
      p->next = ptr;
      ptr->next=NULL;
      return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

struct Node *deleteAtFirst(struct Node *head) {
    struct Node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index) {
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i=0;i<index-1;i++)
    {
        p = p -> next;
        q = q -> next;
    }

    p->next=q->next;
    free(q);
    return head;
}

struct Node *deleteAtEnd(struct Node *head) {
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node *deleteAtValue(struct Node *head, int value) {
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p = p -> next;
        q = q -> next;
    }

    if(q->data == value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}

int main() {
    struct Node *head = NULL;

    // Take user input for creating the linked list nodes
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        int value;
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    while(1)
    {
        int choice,n,a;
        printf("Enter Your choice: \n 1.InsertionAtFirst \n 2.InsertionAtIndex \n 3.InsertionAtEnd \n 4.DeleteAtFirst \n 5.DeleteAtIndex \n 6.DeleteAtEnd \n 7.End the program \n");
        scanf("%d",&choice);
        printf("Linked list before insertion\n");
        linkedListTraversal(head);
        switch(choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d",&n);
            head = insertAtFirst(head,n);
            printf("Linked list After insertion\n");
            linkedListTraversal(head);
            break;
        case 2:
            printf("Enter the index: \n");
            scanf("%d",&a);
            printf("Enter the value: ");
            scanf("%d",&n);
            head = insertAtIndex(head,n,a);
            printf("Linked list After insertion\n");
            linkedListTraversal(head);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d",&n);
            head = insertAtEnd(head,n);
            printf("Linked list After insertion\n");
            linkedListTraversal(head);
            break;
        case 4:
            head = deleteAtFirst(head);
            printf("Linked list After Deletion\n");
            linkedListTraversal(head);
            break;
        case 5:
            printf("Enter the index: \n");
            scanf("%d",&a);
            head = deleteAtIndex(head,a);
            printf("Linked list After Deletion\n");
            linkedListTraversal(head);
            break;
        case 6:
            head = deleteAtEnd(head);
            printf("Linked list After Deletion\n");
            linkedListTraversal(head);
            break;
        case 7:
            printf("Thank you!\n");
            exit(0);
        }
    }
    return 0;
}

