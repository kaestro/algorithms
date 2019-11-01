#include <stdio.h>

int main() {
    long long x, y, z;

    while (scanf("%lld%lld", &x, &y) != EOF)
    {
        z = (long long)((double)y / x*100);

        if (z >= 99)
            printf("-1\n");
        else
        {
            if ((x*(z + 1) - 100*y) % (99 - z) == 0)
                printf("%lld\n", (x*(z + 1) - 100*y) / (99 - z));
            else
                printf("%lld\n", (x*(z + 1) - 100*y) / (99 - z) + 1);
        }
    }

    return 0;
}