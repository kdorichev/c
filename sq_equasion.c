#include <stdio.h>
#include <math.h>

double dicrim(double a, double b, double c)
{
    return b*b - 4*a*c;
}

int main()
{
    double d;
    int a, b, c;
    int n;
    double x1, x2;

    printf("Введите коэффициенты квадратного уравнения\n");
    n = scanf("%d %d %d", &a, &b, &c);

    if (n != 3) {
        printf("Error: ошибка входных данных\n");
        return 1;
    }

    printf("a = %d\nb = %d\nc = %d\n", a, b, c);

    if (a == 0) {
        printf("Ошибка: не квадратное уравнение\n");
        return 2;
    }

    d = dicrim(a, b, c);

    printf("Дискриминант D = %.3f\n", d);

    if (d<0){
        printf("Корней нет\n");
        return 0;
    }


    d = sqrt(d);

    x1 = (-b-d)/2/a;
    x2 = (-b+d)/2/a;

    printf("x1 = %.3f\nx2 = %.3f\n", x1, x2);
}