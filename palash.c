#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(struct node* head, int data) {
    struct node* newnode, * temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        temp = head;
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}

void print(struct node* head) {
    struct node* temp = head;
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int reverse(int x) {
    int rev = 0;
    while (x) {
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    return rev;
}

struct node* add(struct node* head1, struct node* head2, struct node* head3) {
    struct node* temp1 = head1, * temp2 = head2;
    struct node* prevNode = NULL;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry;

        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        carry = sum / 10000;
        sum %= 10000;

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = sum;
        newNode->next = NULL;

        if (head3 == NULL) {
            head3 = newNode;
        }
        else {
            prevNode->next = newNode;
        }

        prevNode = newNode;
    }

    if (carry > 0) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = carry;
        newNode->next = NULL;
        prevNode->next = newNode;
    }

    return head3;
}

int main() {
    struct node* head1 = NULL, * head2 = NULL, * head3 = NULL;
    int n1, n2;
    printf("Enter first number: ");
    scanf("%d", &n1);

    printf("Enter second number: ");
    scanf("%d", &n2);

    // Convert n1 into a linked list
    while (n1) {
        if (n1 > 9999) {
            int r = n1 % 10000;
            n1 = n1 / 10000;
            r = reverse(r);
            head1 = create(head1, r);
        }
        else {
            n1 = reverse(n1);
            head1 = create(head1, n1);
            n1 = n1 / 10000;
        }
    }

    // Convert n2 into a linked list
    while (n2) {
        if (n2 > 9999) {
            int r = n2 % 10000;
            r = reverse(r);
            n2 = n2 / 10000;
            head2 = create(head2, r);
        }
        else {
            n2 = reverse(n2);
            head2 = create(head2, n2);
            n2 = n2 / 10000;
        }
    }

    printf("\n");
    print(head1);
    printf("\n");
    print(head2);
    printf("\n");

    head3 = add(head1, head2, head3);
    
    printf("Result:\n");
    print(head3);


    return 0;
}
