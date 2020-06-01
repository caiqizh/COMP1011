//Zhang Caiqi 18085481d Xcode

#include <stdio.h>
int main(){
    int d, n, x;
    int A[50][50];
    int res[50][50];
    
    //Input all the data.
    printf("Input data:\n");
    scanf("%d", &d);
    
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    scanf("%d %d", &n, &x);
    
    //For n = 0;
    if (n == 0){
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                if (i == j)
                    A[i][j] = 1;
                else A[i][j] =0;
            }
        }
        printf("The out put is:\n");
        for (int i = 0 ; i < d ; i++ )
        {
            for (int j = 0 ; j < d ; j++ )
            {
                printf("%d   ", A[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    
    //For n != 0
    int temres[50][50];
    for ( int i = 0 ; i < d ; i++ ) {
        for ( int j = 0 ; j < d ; j++ ) {
            temres[i][j] = A[i][j];
            res[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n-1; i++){
        for ( int j = 0 ; j < d ; j++ ){
            for (int l = 0 ; l < d ; l++ ){
                for (int k = 0 ; k < d ; k++ ){
                    res[j][l] += ((temres[j][k])*(A[k][l]));
                }
            }
        }
        
        
        for ( int i = 0 ; i < d ; i++ ) {
            for ( int j = 0 ; j < d ; j++ ) {
                temres[i][j] = res[i][j] % x;
                res[i][j] = 0;
            }
        }
    }
    
    //Print out the answer:
    printf("The out put is:\n");
    
    for (int i = 0 ; i < d ; i++ ){
        for (int j = 0 ; j < d ; j++ ){
            printf("%d   ", (temres[i][j]));
        }
        printf("\n");
    }
    
    return 0;
}

