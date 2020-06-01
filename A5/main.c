//Zhang Caiqi 18085481d Xcode
#include <stdio.h>
#include <string.h>
int non_recursive_palindrome(char s[]){
    int i, l;
    l = (int)strlen(s);
    for(i = 0; i<l/2; i++){
        if (s[i] != s[l - i - 1])
            return 0;
    }
    
    return 1;
}

int recursive_palindrome(char s[], int a, int b)
{
    if ( (b - 1) <= a ) return 1;
    if ( s[a] != s[b-1] ) return 0;
    return recursive_palindrome(s, a+1, b-1);
}

int main() {
    char a[105] = "";
    printf("Input:");
    scanf("%s", &*a);
    
    int i,j;
    for(j=i=0;a[i];i++)
        if(a[i]>='a' && a[i]<='z')
           a[j++]=a[i];
        else if (a[i]>='A' && a[i]<='Z')
           a[j++] = a[i] + 32;
    a[j]='\0';
    
    printf("The processed Input: %s\n", a);
    
    if (non_recursive_palindrome(a) == 1)
        printf("Output of non_recursive_palindrome:true\n");
    else
        printf("Output of non_recursive_palindrome:false\n");
    if (recursive_palindrome(a,0, (int)strlen(a)) == 1)
        printf("Output of recursive_palindrome:true\n");
    else
        printf("Output of recursive_palindrome:false\n");
    return 0;
}
