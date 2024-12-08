#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;

} Node;
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node *createLinkedList(int n)
{
    if (n <= 0)
        return NULL;

    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

void freeLinkedList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    Node *linkedList = createLinkedList(n);
    printLinkedList(linkedList);
    freeLinkedList(linkedList);

    return 0;
}