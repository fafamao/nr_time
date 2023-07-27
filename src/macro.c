#include <stdio.h>

#define PI 3.14159
#define RADIUS 2
#define AREA_CIRCLE_2 PI *RADIUS *RADIUS
#define AREA_CIRCLE(r) PI *r *r
#define PERIMETER_2 2 *      \
                        PI * \
                            RADIUS
#define PERIMETER(r) \
    {                \
        2 *          \
            PI *     \
                r    \
    }

#define AREA_SQUARE(a, b) (a * b)
#define PERIMETER_SQUARE(a, b) (2 * a * b)

#define MAX(a, b) ({ (a) > (b) ? (a) : (b); })

#define TO_STR(a) #a

int main()
{
    printf("Pi is %f\n", PI);
    printf("Radius is %d\n", RADIUS);
    printf("Area of radiu:%d is %f\n", RADIUS, AREA_CIRCLE_2);

    int r = 4;
    int new_r = r + 1;
    printf("Area of radius: %d is %f\n", new_r, AREA_CIRCLE(new_r));
    printf("(Wrong)Area of radius: %d is %f\n", r + 1, AREA_CIRCLE(r + 1));

    int a = 4;
    int b = 3;
    printf("Bigger one is %d\n", (a) > (b) ? (a) : (b));
    // printf("Bigger one is %d\n", MAX(a++, b));
    // printf("Bigger one is %d\n", MAX(++a, b));

    printf("Variable %s has value %d\n", TO_STR(a), a);

    return 0;
}