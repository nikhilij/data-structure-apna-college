#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    // Default constructor
    Book() {
        title = "Unknown";
        author = "Unknown";
        price = 0.0;
        cout << "Default constructor called!" << endl;
    }

    // Parameterized constructor
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
        cout << "Parameterized constructor called!" << endl;
    }

    // Copy constructor
    Book(const Book& b) {
        title = b.title;
        author = b.author;
        price = b.price;
        cout << "Copy constructor called!" << endl;
    }

    // Destructor
    ~Book() {
        cout << "Destructor called for: " << title << endl;
    }

    void display() {
        cout << "Title: " << title << ", Author: " << author
            << ", Price: $" << price << endl;
    }
};

int main() {
    Book book1; // Default constructor
    Book book2("C++ Programming", "Bjarne", 49.99); // Parameterized
    Book book3 = book2; // Copy constructor
    book1.display();
    book2.display();
    book3.display();
    return 0;
}
