#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Person
{
    string name;
    int age;
};

const bool operator<(const Person&, const Person&);       // sort numbers ascending by numerical value, sort people alphabetically (lexicographically) by name
const bool operator>(const Person&, const Person&);       // sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically)
ostream& operator<<(ostream&, const vector<double>&);   // print function for numbers
ostream& operator<<(ostream&, const vector<Person>&);   // print function for people

template <typename T>
const bool comparator1(const T&, const T&);

template <typename T>
const bool comparator2(const T&, const T&);

int main()
{
    // some sample data
    vector<double> numbers = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
    vector<Person> people = {   {"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25},
                                {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20},
                                {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}};
    cout << "Numbers:\n";
    cout << numbers << endl;
    cout << "Sort numbers ascending by numerical value:\n";
    sort(numbers.begin(), numbers.end(), comparator1<double>);
    cout << numbers << endl;
    cout << "People:\n";
    cout << people;
    cout << "Sort people alphabetically (lexicographically) by name:\n";
    sort(people.begin(), people.end(), comparator1<Person>);
    cout << people;
    cout << "Sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically):\n";
    sort(people.begin(), people.end(), comparator2<Person>);
    cout << people;
    return 0;
}

const bool operator<(const Person& p, const Person& q)
{
    return p.name < q.name;
}

const bool operator>(const Person& p, const Person& q)
{
    if(p.age > q.age)
        return true;
    else if(p.age == q.age)
        return p.name < q.name ? true : false;
    else
        return false;
}

ostream& operator<<(ostream& os, const vector<double>& v)
{
    for(auto it = v.begin(); it < v.end(); it++)
        os << setprecision(6) << setw(8) << *it << " ";
    os << endl;
    return os;
}

ostream& operator<<(ostream& os, const vector<Person>& v)
{
    for(auto it = v.begin(); it < v.end(); it++)
        os << left << setw(12) << it->name << it->age << endl;
    os << endl;
    return os;
}

template <typename T>
const bool comparator1(const T& u, const T& v)
{
    return u < v;
}

template <typename T>
const bool comparator2(const T& u, const T& v)
{
    return u > v;
}