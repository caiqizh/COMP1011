//Zhang Caiqi 18085481d Xcode
#include <stdio.h>

void main()
{
    int rows,charNum,spaceNum;
    char c = 'A';
    printf("Please input the branch size:");
    scanf("%d",&rows);
    while (rows % 2 == 1) {
        printf("Please input a even number:");
        scanf("%d", &rows);
    }
    
    //for every line
    for(int i=1;i<=rows;i++)
    {
        charNum=i*2-1;
        spaceNum=(rows*2-1-charNum)/2;
        int k = 0;
        
        //print space
        for(int j=0;j<spaceNum;j++)
        {
            printf("%c",' ');
        }
        
        
        //print char
        while(k < charNum)
        {
            printf("%c",c);
            if (c == 'Z')
                c = 'A';
            else
                c++;
            //printf("%d", k);
            k +=1;
        }
        printf("\n");
    }
    
    for(int l=0;l<rows/2;l++)
    {
        for(int m=0;m<(rows-2);m++)
        {
            printf("%c",' ');
        }
        printf("%c %c\n", c, c);
        if (c == 'Z')
            c = 'A';
        else
            c++;
        
        
    }

}
