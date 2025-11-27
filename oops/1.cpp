#include<iostream>
#include "MyClass.cpp"
using namespace std;

class MyClass {
public:
    int myNum;
    string myString;

    void display() {
        cout << "Number: " << myNum << endl;
        cout << "String: " << myString << endl;
    }
};


int main() {
    MyClass obj;
    obj.myNum = 42;
    obj.myString = "Hello, World!";
    obj.display();
}
