#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;  // private data

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient balance\n";
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc(5000);
    acc.deposit(1000);
    acc.withdraw(2000);
    cout << "Final Balance: " << acc.getBalance() << endl;
}
