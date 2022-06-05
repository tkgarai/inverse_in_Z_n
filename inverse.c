#include <stdio.h>

void main()
{
    int a0, b0, a1, b1, temp, s0, s1, q;
    printf("enter a and b(want to find a^(-1) in mod b):");
    scanf("%d %d", &a0, &b0);
    a1 = a0, b1 = b0, s0 = 1, s1 = 0;
    temp = b1;
    q = a1 / b1;
    b1 = a1 % b1;
    a1 = temp;
    while (b1 != 0)
    {
        temp = s1;
        s1 = s0 - q * s1;
        s0 = temp;
        temp = b1;
        q = a1 / b1;
        b1 = a1 % b1;
        a1 = temp;
    }
    printf("gcd(%d, %d) = %d\n", a0, b0, a1);
    if (a1 != 1)
        printf("%d has no inverse in mod %d.\n", a0, b0);
    else
        printf("inverse of %d in mod %d is %d.\n", a0, b0, s1);
}