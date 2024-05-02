
#include <stdio.h>
#include <stdlib.h>

//Linked list node
 struct Node {
    int data;
    struct Node* next;
};

//Push new node into the list
void Push_Node(struct Node** head,int temp){
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode -> data = temp;
    newNode -> next = (*head);
    (*head) = newNode;
}

//Print the whole list from a chosen node
void Print_List(struct Node* head){
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    int n,i,integer;
    struct Node* index = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&integer);
        Push_Node(&index,integer);
    }    
    Print_List(index);
}

