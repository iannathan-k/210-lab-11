#include <iostream>
#include <string>

using namespace std;

// COMSC-210 | Lab 11 | Ian Kusmiantoro

// A recipe book has many recipes within it, including an ingredient list, cook time, rating, etc.
// Inside the recpie struct is a dynamic array of strings listing the ingredients

int main() {

    const int SIZE = 3;

    struct recipe {
        string* ingredients;
        int num_ingredients;
        double cook_time;
        int rating;
        string name;
    };

    // Dyanmically init recipe array
    recipe* recipe_book = new recipe[SIZE];

    // Enter each recipe
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

        recipe_book[i].num_ingredients = count;

        recipe_book[i].ingredients = new string[count];

        cin.ignore();
        for (int j = 0; j < count; j++) {
            cout << "Input ingredient No. " << j + 1 << ": ";
            getline(cin, recipe_book[i].ingredients[j]);
        }
    }

    int max_rating = 0;
    int min_cook = 0;
    for (int i = 0; i < SIZE; i++) {
        if (recipe_book[i].cook_time < recipe_book[min_cook].cook_time) {
            min_cook = i;
        }
        if (recipe_book[i].rating > recipe_book[max_rating].rating) {
            max_rating = i;
        }
    }


    cout << endl;
    cout << "===== Highest Rated Dish =====" << endl;
    cout << "Name: " << recipe_book[max_rating].name << endl;
    cout << "Rating: " << recipe_book[max_rating].rating << endl;
    cout << "Time: " << recipe_book[max_rating].cook_time << endl;
    for (int i = 0; i < recipe_book[max_rating].num_ingredients; i++) {
        cout << recipe_book[max_rating].ingredients[i] << ", ";
    }

    cout << endl << endl;
    
    cout << "===== Fastest Dish =====" << endl;
    cout << "Name: " << recipe_book[min_cook].name << endl;
    cout << "Rating: " << recipe_book[min_cook].rating << endl;
    cout << "Time: " << recipe_book[min_cook].cook_time << endl;
    for (int i = 0; i < recipe_book[min_cook].num_ingredients; i++) {
        cout << recipe_book[min_cook].ingredients[i] << ", ";
    }

    cout << endl;
    

    for (int i = 0; i < SIZE; i++) {
        delete[] recipe_book[i].ingredients;
    }

    delete[] recipe_book;

    return 0;
}