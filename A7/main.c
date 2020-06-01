//Zhang Caiqi 18085481d Xcode

#include <stdio.h>
#include <string.h>
#define SIZE 100
struct Vote{
    int CID;
    char candidate[15];
    char state[5];
};

int query(struct Vote v[], char C[15], char S[5], int n){
    int count = 0;
    int voteby[SIZE] = {0};
    for (int i=0; i < n; i++){
        if ( strcmp(C,v[i].candidate) == 0 && strcmp(S, v[i].state)== 0){
            voteby[i] = 1;
            count += 1;
        }
        
    }
    printf("Number of votes: %d;", count);
    if (count == 0){
        printf("\n");
        return 0;
    }
    else{
        printf("Voted by ");
        int j=0;
        for (int i=0;i<SIZE;i++){
            if (voteby[i] == 1 && j == 1){
                printf(", %d", v[i].CID);
            }
            if (voteby[i] == 1 && j == 0){
                printf("%d", v[i].CID);
                j = 1;
            }
        }
        printf(".\n");
        return 0;
    }
}

int main() {
    int n;
    char candidate[15]="", state[5]="";
    struct Vote votes[SIZE];
    printf("Input:\n");
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &votes[i].CID);
        scanf("%s", votes[i].candidate);
        scanf("%s", votes[i].state);
    }
    scanf("%s", candidate);
    scanf("%s", state);
    query(votes, candidate, state, n);
    return 0;
}
