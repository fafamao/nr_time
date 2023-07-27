#include <stdio.h>

typedef void (*func_ptr)(int);
typedef void (*double_func_ptr)(func_ptr);

void func1()
{
    printf("Function 1 is invoked.\n");
}

int func2(int *a, int *b)
{
    return *a + *b;
}

int *func3(int *a)
{
    return a;
}

int func4(int *a, int *b)
{
    return *a * *b;
}

int func5(int *a, int *b)
{
    return *a - *b;
}

int func6(int a)
{
    printf("Input number is %d\n", a);
}

int func7(func_ptr a)
{
    a(8);
}

int main()
{
    int a = 1;
    int b = 2;

    void (*func1_p)() = func1;

    func1_p();

    int (*func2_p)(int *, int *) = func2;
    int func2_result = func2_p(&a, &b);
    printf("Result of func2 is %d\n", func2_result);

    int *(*func3_p)(int *) = func3;
    printf("Address of variable a is %p\n", func3_p(&a));

    int (*func_arr[])(int *, int *) = {func2, func4, func5};
    printf("Result of func2: %d, func4: %d, func5: %d\n", func_arr[0](&a, &b), func_arr[1](&a, &b), func_arr[2](&a, &b));

    func_ptr f_p = func6;
    f_p(7);
    double_func_ptr df_p = func7;
    df_p(f_p);

    return 0;
}