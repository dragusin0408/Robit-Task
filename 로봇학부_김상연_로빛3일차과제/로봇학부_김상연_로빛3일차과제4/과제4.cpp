#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double a, b;
    char 부호;
	printf("Input Arithmetic Operation\nex)    3,4 * 8.5\n       2.9 - 5.4\n       3.9 * 8.0\n       3.9 ^ 8\n\ninput : ");
    scanf("%lf %c %lf", &a, &부호, &b);
    
    if (부호 == '+') {
        printf("%.2lf + %.2lf = %.2lf\n", a, b, a + b);
    }
    else if (부호 == '-') {
        printf("%.2lf - %.2lf = %.2lf\n", a, b, a - b);
    }
    else if (부호 == '*') {
        printf("%.2lf * %.2lf = %.2lf\n", a, b, a * b);
    }
    else if (부호 == '/') {
        if (b == 0) {
            printf("범위를 벗어남\n");
        }
        else {
            printf("%.2lf / %.2lf = %.2lf\n", a, b, a / b);
        }
    }
    else if (부호 == '^') {
        if (b < 0) {
            printf("범위를 벗어남\n");
            return 0;
        }
        double result = 1;
        for (int i = 0; i < (int)b; i++) {
            result *= a;
        }
        printf("%.2lf ^ %.2lf = %.2lf\n", a, b, result);
    }
    else {
        printf("범위를 벗어남\n");
    }

    return 0;
}
