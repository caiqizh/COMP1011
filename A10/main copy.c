//Zhang Caiqi 18085481d Xcode

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
struct Vote{
    int CID;
    char candidate[15];
    char state[5];
    struct Vote* next;
};

int query(struct Vote * head, char C[15], char S[5]){
    struct Vote *curr = head;
    int count = 0;
    int voteby[SIZE] = {0};
    
    while (curr != NULL){
        //printf("%s\n", curr->candidate);
        if ( strcmp(C,curr->candidate) == 0 && strcmp(S, curr->state)== 0){
            //printf("%s\n", curr->candidate);
            voteby[count] = curr -> CID;
            //printf("%d\n", voteby[count]);
            count += 1;
            
        }
        curr = curr->next;
    }
    printf("Number of votes: %d;", count);
    
    if (count == 0){
        printf("\n");
        return 0;
    }
    else{
        printf("Voted by ");
        int j=0;
        int k = 0;
        for (int i=0;i< count ;i++){
            if (j == 1){
                printf(", %d", voteby[k]);
                k++;
            }
            if (j == 0){
                printf("%d", voteby[k]);
                j = 1;
                k++;
            }
        }
        printf(".\n");
        return 0;
        }
    
    return 0;
}


int main() {
    struct Vote *head = NULL;
    struct Vote *curr = NULL;
    int cid;
    char candidate[15];
    char state[5];
    printf("Please input the data:\n");
    scanf("%d", &cid);
    while (cid != -1){
        if (head == NULL){
            head = (struct Vote*) malloc(sizeof(struct Vote));
            curr = head;
        }
        else{
            curr -> next = (struct Vote* ) malloc(sizeof(struct Vote));
            curr = curr->next;
        }
        curr -> CID = cid;
        scanf("%s", curr -> candidate);
        scanf("%s", curr -> state);
        curr -> next = NULL;
        scanf("%d", &cid);
    }
    scanf("%s", candidate);
    scanf("%s", state);
    query(head,candidate,state);
}
/*
1 D0n41d FL
2 D0n41d FL
3 Nameless FL
4 Nameless FL
5 Nameless FL
6 Hil4ry FL
-1
Nameless FL
 */
