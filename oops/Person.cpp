#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int age;

public:
    Person& setName(string n) {
        name = n;
        return *this;  // returns the current object
    }

    Person& setAge(int a) {
        age = a;
        return *this;
    }

    void introduce() {
        cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
    }
};

int main(){
    Person p;
    p.setName("Alice").setAge(30);
    p.introduce();
    return 0;
}