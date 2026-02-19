#include <iostream>
#include <string>

using namespace std;

// COMSC-210 | Lab 11 | Ian Kusmiantoro

// A recipe book has many recipes within it, including an ingredient list, cook time, rating, etc.
// Inside the recpie struct is a dynamic array of strings listing the ingredients

int main() {

    const int SIZE = 5;

    struct recipe {
        string* ingredients;
        double cook_time;
        int rating;
        string name;
    };

    recipe* recipe_book = new recipe[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Input recipe name: ";
        getline(cin, recipe_book[i].name);

        cout << "Input recipe cook time in minutes: ";
        cin >> recipe_book[i].cook_time;

        cout << "Input recipe rating out of 5: ";
        cin >> recipe_book[i].rating;

        for (int i = 0;)
    }

    return 0;
}