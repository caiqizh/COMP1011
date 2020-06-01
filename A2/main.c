//This is under the Xcode.
#include <stdio.h>
int main()
{
    int j1, j2, j3;
    int f1, f2, f3;
    float r1, r2, r3;
    int m; //available cat food
    float sum = 0; //current sum of cheese
    puts("input");
    scanf("%d", &m);
    scanf("%d%d", &j1, &f1);
    scanf("%d%d", &j2, &f2);
    scanf("%d%d", &j3, &f3);
    r1 = (float)j1 / f1;
    r2 = (float)j2 / f2;
    r3 = (float)j3 / f3;
    while (m>0 && ((r1 != 0) || r2 != 0 || r3 != 0)) {
        if (r1 >= r2 && r1 >= r3 && r1!= 0){
            if (m >= f1){
                sum += j1;
                m -= f1;
                r1 = 0;
            }
            else{
                sum += m*r1;
                
                m = 0;
                
            }
        }
        if (r2 >= r1 && r2 >= r3 && r2!=0){
            if (m >= f2){
                sum += j2;
                m -= f2;
                r2 = 0;
            }
            else{
                sum += m*r2;
                m = 0;
                
            }
        }
        if (r3 >= r2 && r3 >= r1 && r3!=0){
            if (m >= f3){
                sum += j3;
                m -= f3;
                r3 = 0;
            }
            else{
                sum += m*r3;
                m = 0;
                
            }
        }
    }
    
printf("%.3f\n", sum);
        
    return 0;
}
