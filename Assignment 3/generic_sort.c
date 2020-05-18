#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Person
{
    char* name;     // person's name
    int age;        // person's age
};

int comparator1(const void*, const void*);  // sort numbers ascending by numerical value
int comparator2(const void*, const void*);  // sort people alphabetically (lexicographically) by name
int comparator3(const void*, const void*);  // sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically)
void print1(const void*, int);            // print numbers
void print2(const void*, int);     // print people

int main()
{
    // some sample data
    double numbers[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
    struct Person people[] = {  {"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25},
                                {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20},
                                {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}};
    int number_of_numbers = sizeof(numbers) / sizeof(double);           // how many numbers
    int number_of_people = sizeof(people) / sizeof(struct Person);      // how many people
    double *ptr1 = numbers;
    struct Person *ptr2 = people;
    printf("Numbers:\n");
    print1(ptr1, number_of_numbers);
    printf("Sort numbers ascending by numerical value:\n");
    qsort((void*)ptr1, number_of_numbers, sizeof(double), comparator1);
    print1(ptr1, number_of_numbers);
    printf("People:\n");
    print2(ptr2, number_of_people);
    printf("Sort people alphabetically (lexicographically) by name:\n");
    qsort((void*)ptr2, number_of_people, sizeof(struct Person), comparator2);
    print2(ptr2, number_of_people);
    printf("Sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically):\n");
    qsort((void*)ptr2, number_of_people, sizeof(struct Person), comparator3);
    print2(ptr2, number_of_people);
    return 0;
}

int comparator1(const void *p, const void *q)
{
    double l = *(const double*)p;
    double r = *(const double*)q;
    return l - r;
}

int comparator2(const void *p, const void *q)
{
    char* l = ((const struct Person*)p)->name;
    char* r = ((const struct Person*)q)->name;
    return strcmp(l, r);
}

int comparator3(const void *p, const void *q)
{
    int l_age = ((const struct Person*)p)->age;
    int r_age = ((const struct Person*)q)->age;
    char * l_name = ((const struct Person*)p)->name;
    char * r_name = ((const struct Person*)q)->name;
    if(l_age > r_age)
        return -1;
    else if(l_age == r_age)
        return strcmp(l_name, r_name) < 0 ? -1 : 1;
    else
        return 1;
}

void print1(const void *data, int size)
{
    
    for(int i = 0; i < size; i++)
        printf("%f ", *((const double*)data + i));
    printf("\n\n");
}

void print2(const void *data, int size)
{
    for(int i = 0; i < size; i++)
        printf("%-12s %d\n", ((const struct Person*)data + i)->name, ((const struct Person*)data + i)->age);
    printf("\n");
}