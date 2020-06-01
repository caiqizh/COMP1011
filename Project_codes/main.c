
//Zhang Caiqi 18085481d VS2017
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
#include <windows.h>

#define color 6
int non_continuation(int A[50][50], int row, int column);
int printa(int A[50][50], int row, int column, int score);
int draw_2D_array(int A[50][50], int row, int column);
int blocks_down(int A[50][50], int row, int column);
void check_out(int A[50][50], int row, int column);
int valid_move_check(int A[50][50], int row, int column, int a1, int a2, int b1, int  b2);
int hint(int A[50][50], int row, int column);
int make_move(int A[50][50], int row, int column);
int initialize(int A[50][50], int row, int column);

//This function can check whether A has "-1".
int non_continuation(int A[50][50], int row, int column) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (A[i][j] == -1)
                return 1;
        }
    }
    return 0;
}
//This function can print A.
int printa(int A[50][50], int row, int column, int score) {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    if (non_continuation(A,row,column)==1)
        printf("You have got a chain!\n \n");
    if (non_continuation(A, row, column) == 0)
        printf("This is the current condition!\n \n");
    printf("Your current score is %d.\n", score);
    printf("    ");
    for (int i = 0; i < column; i++) {
        printf("%02d ", i);
    }
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        printf("%02d  ", i);
        for (int j = 0; j < column; j++)
        {
            switch (A[i][j])
            {
                case 1:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                    printf("   ");
                    break;
                case 2:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
                    printf("   ");
                    break;
                case 3:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 208);
                    printf("   ");
                    break;
                case 4:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 192);
                    printf("   ");
                    break;
                case 5:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
                    printf("   ");
                    break;
                case 6:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
                    printf("   ");
                    break;
                case -1:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    printf("   ");
                    break;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n");
    }
    printf("\n");
    if (non_continuation(A, row, column) == 1) {
        printf("Press any key to continue...");
        getchar();
        getchar();
    }
    return 0;
}
//This function can draw_2D_array.

int draw_2D_array(int A[50][50], int row, int column) {
    srand((unsigned)(time(NULL)));
    for (int i = 0;i < 50;i++) {
        for (int j = 0;j < 50;j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            A[i][j] = rand() % color + 1;
        }
    }
    return 0;
}
//Input a labled A
//Output a block down new A
int blocks_down(int A[50][50], int row, int column) {
    int score = 0;
    for (int j = 0; j < column; j++) {
        int ci[50], n = 0;
        for (int i = 0; i < row; i++) {
            if (A[i][j] != -1) {
                ci[n] = A[i][j];
                n++;
            }
            if (A[i][j] == -1) {
                score++;
            }
            
        }
        int k = row - n;
        //printf("%d", (int)(sizeof(ci)/sizeof(ci[0])));
        for (int i = k; i < row; i++) {
            A[i][j] = ci[i - k];
            //printf("%d", A[i][j]);
        }
        //printf("\n");
        for (int i = 0; i < k; i++) {
            A[i][j] = rand() % color + 1;
            //printf("%d", A[i][j]);
        }
        
    }
    return score;
}
//To Lable A using "-1"
void check_out(int A[50][50], int row, int column) {
    int B[50][50];
    int C[50][50];
    int temp1, temp2;
    for (int i = 0;i < 50;i++) {
        for (int j = 0;j < 50;j++) {
            B[i][j] = A[i][j];
            C[i][j] = A[i][j];
        }
    }
    // Check rows
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            if (B[i][j] == B[i][j + 1] && B[i][j] == B[i][j + 2]) {
                temp1 = B[i][j];
                B[i][j] = -1;
                B[i][j + 1] = -1;
                B[i][j + 2] = -1;
                int n = 0;
                
                while (temp1 == B[i][j + 3 + n]) {
                    B[i][j + 3 + n] = -1;
                    n++;
                }
                
            }
        }
    }
    
    // Check columns
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            if (C[i][j] == C[i + 1][j] && C[i][j] == C[i + 2][j]) {
                temp2 = C[i][j];
                C[i][j] = -1;
                C[i + 1][j] = -1;
                C[i + 2][j] = -1;
                int n = 0;
                
                while (temp2 == C[i + 3 + n][j]) {
                    C[i + 3 + n][j] = -1;
                    n++;
                }
                
            }
        }
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            if (B[i][j] == -1 || C[i][j] == -1) {
                A[i][j] = -1;
            }
        }
    }
    //printa(A);
}
//To check whether the move is valid.
int valid_move_check(int A[50][50], int row, int column, int a1, int a2, int b1, int  b2) {
    int temp1, temp2;
    int B[50][50];
    for (int i = 0;i < 50;i++) {
        for (int j = 0;j < 50;j++) {
            B[i][j] = A[i][j];
        }
    }
    temp1 = B[a1][a2];
    temp2 = B[b1][b2];
    B[a1][a2] = temp2;
    B[b1][b2] = temp1;
    
    check_out(B, row, column);
    
    if (non_continuation(B, row, column) == 1) {
        
        return 1;
    }
    if (non_continuation(B, row, column) == 0) {
        
        return 0;
    }
    return 0;
}
//Give users a hint.
int hint(int A[50][50], int row, int column) {
    int n = 0;
    while (n == 0) {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (valid_move_check(A, row, column, i, j, i, j + 1) == 1&&n == 0) {
                    printf("You can try left and right : %02d %02d %02d %02d \n ", i, j, i, j + 1);
                    n = 1;
                    break;
                }
                if (valid_move_check(A, row, column, i, j, i + 1, j) == 1&&n==0) {
                    printf("You can try up and down: %02d %02d %02d %02d \n ", i, j, i + 1, j);
                    n = 1;
                    break;
                }
            }
        }
    }
    return 0;
}

int make_move(int A[50][50], int row, int column) {
    int a1, b1, a2, b2, temp;
    printf("You want to move row1&column1 to row1&column2. Example: 01 01 01 02\nYou can input: 99 99 99 99 to get a hint.\n");
    scanf_s("%d %d %d %d", &a1, &a2, &b1, &b2);
    if (a1 == 99 && a2 == 99 && b1 == 99 && b2 == 99) {
        hint(A, row, column);
        scanf_s("%d %d %d %d", &a1, &a2, &b1, &b2);
        temp = A[a1][a2];
        A[a1][a2] = A[b1][b2];
        A[b1][b2] = temp;
        check_out(A, row, column);
    }
    else {
        temp = A[a1][a2];
        A[a1][a2] = A[b1][b2];
        A[b1][b2] = temp;
        check_out(A, row, column);
        
        
        while (non_continuation(A, row, column) == 0 || (abs(a1 - b1) != 1 && a2 == b2) || (a1 == b1 && abs(a2 - b2) != 1)) {
            printf("The move is invalid.\n");
            temp = A[a1][a2];
            A[a1][a2] = A[b1][b2];
            A[b1][b2] = temp;
            //int a1,b1,a2,b2,temp;
            printf("You want to move row1&column1 to row1&column2. Example: 01 01 01 02\nYou can input: 99 99 99 99 to get a hint.\n");
            scanf_s("%d %d %d %d", &a1, &a2, &b1, &b2);
            temp = A[a1][a2];
            A[a1][a2] = A[b1][b2];
            A[b1][b2] = temp;
            check_out(A, row, column);
        }
    }
    return 0;
}

//To initialize A, give a now continuation A.
int initialize(int A[50][50], int row, int column) {
    check_out(A, row, column);
    //printf("This is final changed result of A:\n");
    while (non_continuation(A, row, column) == 1) {
        blocks_down(A, row, column);
        check_out(A, row, column);
    }
    //printa(A);
    return 0;
}



int main() {
    int score = 0;
    int column, row;
    int A[50][50];
    printf("This little game can satisfy part 1 & part 2 successfully.\nAnd it has following fuctions:\n1.It can show colorful user interface.\n2.It can make sure there is a move.\n3.If you do not know how to move, you can input: 99 99 99 99 to get a hint.\n4.Any invalid move can be checked and you can only input the right one.\n\n");
    printf("Please input the number of rows and columns (We recommend:10 10):");
    scanf_s("%d %d", &row, &column);
    draw_2D_array(A, row, column);
    
    initialize(A, row, column);
    printa(A, row, column, score);
    while (1) {
        
        make_move(A, row, column);
        
        printa(A, row, column, score);
        
        check_out(A, row, column);
        score += blocks_down(A, row, column);
        
        printa(A, row, column, score);
        
        check_out(A, row, column);
        
        while (non_continuation(A, row, column) == 1) {
            printf("You have got a chain!\n");
            printa(A, row, column, score);
            score += blocks_down(A, row, column);
            printf("This is the new condition!\n");
            printa(A, row, column, score);
            check_out(A, row, column);
        }
    }
    return 0;
}


