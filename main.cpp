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

    // Dyanmically init recipe book
    recipe* recipe_book = new recipe[SIZE];

    // Enter each recipe
    for (int i = 0; i < SIZE; i++) {
        cout << "Input recipe name: ";
        getline(cin, recipe_book[i].name);

        cout << "Input recipe cook time in minutes: ";
        cin >> recipe_book[i].cook_time;
        // While loops to validate inputs
        while (recipe_book[i].cook_time <= 0) {
            cout << "Invalid cook time, try again: ";
            cin >> recipe_book[i].cook_time;
        }

        cout << "Input recipe rating out of 5: ";
        cin >> recipe_book[i].rating;
        while (recipe_book[i].rating < 0 || recipe_book[i].rating > 5) {
            cout << "Invalid rating, try again: ";
            cin >> recipe_book[i].rating;
        }

        cout << "Input number of ingredients: ";
        cin >> recipe_book[i].num_ingredients;
        while (recipe_book[i].num_ingredients <= 0) {
            cout << "Invalid ingredient count, try again: ";
            cin >> recipe_book[i].num_ingredients;
        }

        // Dynamically init ingredients list in the recipe
        recipe_book[i].ingredients = new string[recipe_book[i].num_ingredients];

        // Ignore leftover newline
        // Input each ingredient
        cin.ignore();
        for (int j = 0; j < recipe_book[i].num_ingredients; j++) {
            cout << "Input ingredient No. " << j + 1 << ": "; 
            getline(cin, recipe_book[i].ingredients[j]);
        }
    }

    // Linear search to find max rating and min cook time
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

    // Output highest rated dish, including full recipe list
    cout << endl;
    cout << "===== Highest Rated Dish =====" << endl;
    cout << "Name: " << recipe_book[max_rating].name << endl;
    cout << "Rating: " << recipe_book[max_rating].rating << endl;
    cout << "Time: " << recipe_book[max_rating].cook_time << endl;
    for (int i = 0; i < recipe_book[max_rating].num_ingredients; i++) {
        cout << recipe_book[max_rating].ingredients[i] << ", ";
    }

    cout << endl << endl;
    
    // Output lowest time dish, including full recipe list
    cout << "===== Fastest Dish =====" << endl;
    cout << "Name: " << recipe_book[min_cook].name << endl;
    cout << "Rating: " << recipe_book[min_cook].rating << endl;
    cout << "Time: " << recipe_book[min_cook].cook_time << endl;
    for (int i = 0; i < recipe_book[min_cook].num_ingredients; i++) {
        cout << recipe_book[min_cook].ingredients[i] << ", ";
    }

    cout << endl;
    
    // Clean up memory
    for (int i = 0; i < SIZE; i++) {
        delete[] recipe_book[i].ingredients;
    }

    delete[] recipe_book;

    return 0;
}