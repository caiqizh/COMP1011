//Zhang Caiqi 18085481d Xcode
#include<string.h>
#include <stdio.h>
void swap(char **str1, char **str2);
void print_array(char ** names, int num);
void sort(char ** names, int num);

int main() {
    int num = 6;
    char  * names[] = {"Filco", "Eddie", "Anna", "Bob", "Cindy", "Dinna"};
    sort(names, num);
    print_array(names, num);
    return 0;
}
void sort(char ** names, int num)
{
    int i,j;
    for(i=0;i<num-1;i++)
    {
        for(j=0;j<num-1;j++)
        {
            if(strcmp(names[j],names[j+1])>0)
            {
                swap(&names[j],&names[j+1]);
            }
        }
    }
}

void print_array(char ** names, int num){
    for (int i = 0; i<num; i++){
        printf("%s ", names[i]);
    }
    printf("\n");
}

void swap(char ** str1, char ** str2){
        char * temp;
        temp = *str1;
        *str1 = *str2;
        *str2 = temp ;
}

