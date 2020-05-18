using System;
using System.Collections.Generic;

class Person : IComparable<Person>
{
    private string name;
    private int age;
    public Person(string name, int age)
    {
        this.name = name;
        this.age = age;
    }
    public string Name { get { return name; }}
    public int Age { get { return age; }}
    int IComparable<Person>.CompareTo(Person p)     // sort people alphabetically (lexicographically) by name
    {
        return name.CompareTo(p.name);
    }
    // int IComparable<Person>.CompareTo(Person p)  // sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically)
    // {
    //     if(age > p.Age)
    //         return -1;
    //     else if(age < p.Age)
    //         return 1;
    //     else
    //         return name.CompareTo(p.Name);
    // }
    public override string ToString()
    {
        return String.Format("{0, -12}{1}\n", name, age);
    }
}

class Generic_Sort
{
    // public static int Comparator1<T>(T a, T b) where T : IComparable<T>     // sort people alphabetically (lexicographically) by name
    // {
    //     return a.CompareTo(b);
    // }
    public static int Comparator2(Person a, Person b)       // sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically)
    {
        if(a.Age > b.Age)
            return -1;
        else if(a.Age < b.Age)
            return 1;
        else
            return a.Name.CompareTo(b.Name);
    }
    public static void print1(double[] numbers)
    {
        foreach (double num in numbers)
            Console.Write(num + " ");
        Console.Write("\n\n");
    }
    public static void print2(Person[] people)
    {
        foreach (Person person in people)
            Console.Write(person);
        Console.Write("\n");
    }
    public static void Main(String[] args)
    {
        double[] numbers = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
        Person[] people = { new Person("Hal", 20), new Person("Susann", 31), new Person("Dwight", 19), new Person("Kassandra", 21), new Person("Lawrence", 25),
                            new Person("Cindy", 22), new Person("Cory", 27), new Person("Mac", 19), new Person("Romana", 27), new Person("Doretha", 32),
                            new Person("Danna", 20), new Person("Zara", 23), new Person("Rosalyn", 26), new Person("Risa", 24), new Person("Benny", 28),
                            new Person("Juan", 33), new Person("Natalie", 25)};
        Console.Write("Numbers:\n");
        print1(numbers);
        Console.Write("Sort numbers ascending by numerical value:\n");
        // Array.Sort(numbers, Comparator1);
        Array.Sort(numbers);
        print1(numbers);
        Console.Write("People:\n");
        print2(people);
        Console.Write("Sort people alphabetically (lexicographically) by name:\n");
        // Array.Sort(people, Comparator1);
        Array.Sort(people);
        print2(people);
        Console.Write("Sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically):\n");
        Array.Sort(people, Comparator2);
        print2(people);
    }
}