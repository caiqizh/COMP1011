//Zhang Caiqi 18085481d Xcode
#include <stdio.h>
#include <string.h>
void rev_str(char *str)
{
    char *ptr_begin;
    char *ptr_end;
    
    ptr_begin       = str;
    ptr_end     = str + (int)strlen(str) - 1;
    if (str == NULL)
    {
        printf("Error");
        return ;
    }
    while (ptr_begin < ptr_end)
    {
        char c = *ptr_begin;
        *ptr_begin       = *ptr_end;
        *ptr_end    = c;
        ptr_begin++;
        ptr_end--;
    }
}
int main()
{

    FILE *fp = NULL;
    fp = fopen("/Users/caiqis/Desktop/Input.txt", "r");
    
    if (fp==NULL) {
        printf("Exit.\n");
        return 1;
    }
    
    char inputdata[100] = "";
    fscanf(fp, "%s", inputdata);
    printf("%s\n", inputdata);
    rev_str(inputdata);
    printf("%s\n", inputdata);
    
    FILE *fp2 = NULL;
    fp2 = fopen("/Users/caiqis/Desktop/Output.txt", "w+");
    fprintf(fp2, "%s", inputdata);
    fclose(fp2);
    return 0;
}

