#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass();         // Constructor declaration
    void showMessage(); // Member function declaration
};

// Function defined first
void MyClass::showMessage() {
    cout << "Hello from showMessage!" << endl;
}

// Constructor defined after function
MyClass::MyClass() {
    cout << "Constructor called!" << endl;
}

int main() {
    MyClass obj;
    obj.showMessage();
    return 0;
}