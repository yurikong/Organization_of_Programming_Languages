from operator import attrgetter
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __repr__(self):
        return f'{self.name} {self.age}'


# some sample data
numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
people = [Person('Hal', 20), Person('Susann', 31), Person('Dwight', 19), Person('Kassandra', 21),
          Person('Lawrence', 25), Person('Cindy', 22), Person('Cory', 27), Person('Mac', 19),
          Person('Romana', 27), Person('Doretha', 32), Person('Danna', 20), Person('Zara', 23),
          Person('Rosalyn', 26), Person('Risa', 24), Person('Benny', 28), Person('Juan', 33),
          Person('Natalie', 25)]

if __name__ == '__main__':
    # sort numbers ascending by numerical value
    print('numbers:\n', numbers)
    numbers = sorted(numbers)
    print('sort numbers ascending by numerical value:\n', numbers)
    # sort people alphabetically (lexicographically) by name
    print('people:\n', people)
    people = sorted(people, key=attrgetter('name'))
    print('sort people alphabetically (lexicographically) by name:\n', people)
    # sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically)
    people = sorted(people, key=attrgetter('name'))
    people = sorted(people, key=attrgetter('age'), reverse=True)
    print('sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically):\n', people)

