#include <math.h>

int main()
{
    double x = 1e-200;
    double y = 1e-200 * x;
    printf("Log of +0: %gn", log(y));
    y = -1e-200*x;
    printf("Log of -0: %gn", log(y));
}

