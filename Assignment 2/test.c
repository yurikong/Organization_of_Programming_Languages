#include "heap_manager.c"

void test_one();
void test_two();
void test_three();
void test_four();
void test_five();

int main()
{
    my_initialize_heap(1024);
    // test_one();
    // test_two();
    // test_three();
    // test_four();
    test_five();
    return 0;
}

void test_one()
{
    /*
        Allocate an int.
        Print the address of the returned pointer.
        Free the int, then allocate another int and print its address.
        The address should be the same.
    */
    printf("Test Case 1:\n");
    int *p = my_malloc(sizeof(int));
    printf("Address of p(int*): %p\n", p);
    my_free(p);
    printf("p freed.\n");
    p = my_malloc(sizeof(int));
    printf("Address of p(int*): %p\n", p);
    my_free(p);
    printf("p freed.\n");
}

void test_two()
{
    /*
        Allocate two individual int values and print their addresses.
        They should be exactly the size of your overhead plus the size of a void* apart.
    */
    printf("Test Case 2:\n");
    int *p1 = my_malloc(sizeof(int));
    int *p2 = my_malloc(sizeof(int));
    printf("Address of p1(int*): %p\n", p1);
    printf("Address of p2(int*): %p\n", p2);
    my_free(p1);
    my_free(p2);
    printf("p1 freed.\n");
    printf("p2 freed.\n");
}

void test_three()
{
    /*
        Allocate three int values and print their addresses, then free the second of the three.
        Allocate a double and print its address.
        Verify that the address is the same as the int that you freed.
    */
    printf("Test Case 3:\n");
    int *p1 = my_malloc(sizeof(int));
    int *p2 = my_malloc(sizeof(int));
    int *p3 = my_malloc(sizeof(int));
    printf("Address of p1(int*): %p\n", p1);
    printf("Address of p2(int*): %p\n", p2);
    printf("Address of p3(int*): %p\n", p3);
    my_free(p2);
    printf("p2 freed.\n");
    p2 = my_malloc(sizeof(double));
    printf("Address of p2(double*): %p\n", p2);
    my_free(p1);
    my_free(p2);
    my_free(p3);
    printf("p1 freed.\n");
    printf("p2 freed.\n");
    printf("p3 freed.\n");
}

void test_four()
{
    /*
        Allocate one char, then allocate one int, and print their addresses.
        They should be exactly the same distance as in test #2.
    */
    printf("Test Case 4:\n");
    char *p1 = my_malloc(sizeof(char));
    int *p2 = my_malloc(sizeof(int));
    printf("Address of p1(char*): %p\n", p1);
    printf("Address of p2(int*): %p\n", p2);
    my_free(p1);
    my_free(p2);
    printf("p1 freed.\n");
    printf("p2 freed.\n");
}

void test_five()
{
    /*
        Allocate space for a 100-element int array, then for one more int value.
        Verify that the address of the int value is 100 * sizeof(int) + the size of your header after the array's address.
        Free the array. Verify that the int's address and value has not changed.
    */
    printf("Test Case 5:\n");
    int *p1 = my_malloc(100 * sizeof(int));
    int *p2 = my_malloc(sizeof(int));
    printf("Address of p1(int*): %p\n", p1);
    printf("Address of p2(int*): %p\n", p2);
    my_free(p1);
    printf("p1 freed.\n");
    printf("Address of p2(int*): %p\n", p2);
    my_free(p2);
    printf("p2 freed.\n");
}