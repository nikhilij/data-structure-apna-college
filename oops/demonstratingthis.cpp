#include <string>
#include <iostream>
using namespace std;


class Employee {
private:
    string name;

public:
    void setName(string name) {
        this->name = name;  // Resolves ambiguity
    }

    Employee& updateName(string newName) {
        this->name = newName;
        return *this;  // Enables chaining
    }
    void display() {
        cout << "Employee Name: " << name << endl;
    }
};
int main() {
    Employee e;
    e.updateName("Nikhil").setName("Kumar");
    e.display();
    return 0;
}
