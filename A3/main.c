//The program is under the Xcode.

#include <stdio.h>
#include <math.h>

double Divide(double a, double b){
    return  a / b;
}
double Multiply(int a, int b) {
    
    return a * b;
}
double Power(int a, int b) {
    return pow(a, b);
}
double Square_root(int a) {
    return sqrt(a);
}
int main() {
    int a, b, c;
    puts("MENU");
    printf("        1. Divide. a/b\n        2. Multiply. a*b\n        3. Power. a^b\n        4. Square root. sqrt(a)\n");
    while (1) {
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter two numbers:");
                scanf("%d%d", &a, &b);
                if (b == 0) {
                    printf("PLease enter again:");
                    scanf("%d%d", &a, &b);
                }
                printf("%d/%d=%.3f\n", a, b, Divide(a, b));
                break;
            case 2:
                printf("Enter two numbers:");
                scanf("%d%d", &a, &b);
                printf("%d*%d=%.3f\n", a, b, Multiply(a, b));
                break;
            case 3:
                printf("Enter two numbers:");
                scanf("%d%d", &a, &b);
                printf("%d^%d=%.3f\n", a, b, Power(a, b));
                break;
            case 4:
                printf("Enter a number:");
                scanf("%d", &a);
                printf("sqrt(%d)=%.3f\n", a, Square_root(a));
                break;
                
            default:
                return 0;
        }
    }
    return 0;
}

