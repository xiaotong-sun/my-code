#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    char f[4];
    scanf("%d %d %d %s", &a, &b, &c, f);

    // sorted[0] -> min;
    // sorted[1] -> mid;
    // sorted[2] -> max;
    int sorted[3];
    sorted[0] = a;
    if (b < sorted[0])
    {
        sorted[0] = b;
    }

    if (c < sorted[0])
    {
        sorted[0] = c;
    }

    sorted[2] = a;
    if (b > sorted[2])
    {
        sorted[2] = b;
    }

    if (c > sorted[2])
    {
        sorted[2] = c;
    }

    sorted[1] = a + b + c - sorted[0] - sorted[2];
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", sorted[f[i] - 'A']);
    }

    printf("%d\n", sorted[f[2] - 'A']);

    system("pause");
    return 0;
}