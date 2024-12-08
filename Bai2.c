#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int n, value, i;
    Node* head = NULL;

    printf("Nhap so luong phan tu trong danh sach lien ket (n): ");
    scanf("%d", &n);

    printf("Nhap cac phan tu cua danh sach:\n");
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insertAtHead(head, data);
    }

    Node* newHead = NULL;
    while (head != NULL) {
        newHead = insertAtHead(newHead, head->data);
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    head = newHead;

    printf("Nhap gia tri can chen vao dau danh sach: ");
    scanf("%d", &value);
    head = insertAtHead(head, value);

    printf("Danh sach sau khi them:\n");
    displayList(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

