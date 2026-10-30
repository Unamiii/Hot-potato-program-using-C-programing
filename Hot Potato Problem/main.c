// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int player_id;
    struct Node* next;
} Node; 

Node* create_node(int id) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->player_id = id;
    new_node->next = NULL;
        return new_node;
}

int main() {
    int N, M;
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter M: ");
    scanf("%d", &M);

    Node* head = create_node(1);
    Node* prev = head;
    for (int i = 2; i <= N; i++) {
    prev->next = create_node(i);
    prev = prev->next;
    }
    prev->next = head;
    Node* curr = head;
    while (curr->next != curr) {
        for (int i = 0; i < M; i++){
            prev = curr;
            curr = curr->next;
        }
        printf("Player Eliminated %d\n", curr->player_id);
        
        prev->next = curr->next;
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
        printf("Winner %d\n", curr->player_id);
        return 0;
    }















