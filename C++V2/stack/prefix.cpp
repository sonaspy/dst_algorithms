#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double exp();

int main()
{
    printf("%.1f", exp());
    return 0;
}

double exp()
{
    char a[10];
    scanf("%s", a);
    if (!a[1])
    {
        switch (a[0])
        {
        case '+':
            return exp() + exp();
        case '-':
            return exp() - exp();
        case '*':
            return exp() * exp();
        case '/':
        {
            double numerator = exp();
            double denominator = exp();
            if (denominator != 0)
                return numerator / denominator;
            else
            {
                printf("ERROR");
                exit(0);
            }
        }
        default:
            return atof(a);
        }
    }
    else
    {
        if (a[0] == '-' || a[0] == '+')
        {
            char flag = a[0];
            int i = 0;
            while (a[i])
            {
                a[i] = a[i + 1];
                i++;
            }
            if (flag == '-')
                return 0 - atof(a);
            else
                return atof(a);
        }
        else
            return atof(a);
    }
}