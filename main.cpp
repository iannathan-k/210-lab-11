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

        cout << "Input number of ingredients: ";
        int count;
        cin >> count;

        recipe_book[i].ingredients = new string[count];
        string* temp_ptr = recipe_book[i].ingredients;

        for (int j = 0; j < count; j++) {
            cout << "Input ingredient No. " << j << ": ";
            getline(cin, temp_ptr[i]);
        }
    }

    int max_rating = 0;
    int min_cook;
    for (int i = 0; i < SIZE; i++) {
        if (recipe_book[i].cook_time < recipe_book[min_cook].cook_time) {
            min_cook = i;
        }
        if (recipe_book[i].rating > recipe_book[max_rating].rating) {
            max_rating = i;
        }
    }

    cout << "Highest Rated Dish";
    cout << recipe_book[max_rating].name;
    cout << recipe_book[max_rating].rating;
    cout << recipe_book[max_rating].cook_time;
    
    cout << "Fastest Dish";
    cout << recipe_book[min_cook].name;
    cout << recipe_book[min_cook].rating;
    cout << recipe_book[min_cook].cook_time;

    return 0;
}