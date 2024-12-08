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

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int currentPosition = 0;

    while (temp != NULL && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == NULL) {
        printf("Vi tri ngoai pham vi danh sach\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int n, i, value, insertValue, position;
    Node* head = NULL;

    printf("Nhap so luong phan tu trong danh sach (n): ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Nhap cac phan tu cua danh sach:\n");
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Danh sach ban dau:\n");
    displayList(head);

    printf("Nhap gia tri can chen: ");
    scanf("%d", &insertValue);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &position);

    head = insertAtPosition(head, insertValue, position);

    printf("Danh sach sau khi chen:\n");
    displayList(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

