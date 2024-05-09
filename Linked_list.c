
#include <stdio.h>
#include <stdlib.h>

//Linked list node
 struct Node {
    int data;
    struct Node* next;
};

//Push new nodes into the start of the list
void Push_Node(struct Node** head, int temp){
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode -> data = temp;
    newNode -> next = (*head);
    (*head) = newNode;
}

//Append new nodes into the end of the list
void Append_Node(struct Node* head, int n){
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode -> data = n;
    newNode -> next = NULL;
    struct Node* current = head;
    while (current -> next != NULL){
        current = current -> next;       
    }
    current -> next = newNode;
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

//Delete a node
void Pop_node(struct Node** index)
{
    // underflow condition
    if (*index == NULL) {
        printf("Node not exist");
    }
    struct Node* head = *index;
    int result = head->data;        // pull out data before the node is deleted
    (*index) = (*index)->next;      // unlink the head node for the caller
    free(head);                     // free the head node
    printf("Poped node is : %d\n",result);           
}
 

int main(){
    int n,i,integer;
    struct Node* index = NULL;
    scanf("%d",&n);
    for (i=0;i<n-1;i++){
        scanf("%d",&integer);
        Push_Node(&index,integer);
    }
    scanf("%d",&integer);
    Append_Node(index,integer); 
    Pop_node(&index);   
    Print_List(index);
}


