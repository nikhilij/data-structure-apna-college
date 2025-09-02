#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
#include<cctype>
#include<cmath>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(const string& op) {
    if (op == "-u") return 4; // highest precedence for unary minus
    if (op == "^") return 3;
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

bool isUnaryMinus(const string &s, int i) {
    if (i == 0) return true;
    int j = i - 1;
    while (j >= 0 && s[j] == ' ') j--;
    return (j < 0 || s[j] == '(' || isOperator(s[j]));
}

vector<string> tokenize(const string& s) {
    vector<string> tokens;
    int n = s.size();

    for (int i = 0; i < n;) {
        char ch = s[i];

        if (isspace(ch)) {
            i++;
            continue;
        }

        if (isdigit(ch) || (ch == '-' && isUnaryMinus(s, i) && (i + 1 < n && isdigit(s[i + 1])))) {
            string num = "";
            if (ch == '-') {
                num += '-';
                i++;
            }
            while (i < n && isdigit(s[i])) {
                num += s[i++];
            }
            tokens.push_back(num);
        }
        else if (ch == '-' && isUnaryMinus(s, i)) {
            tokens.push_back("-u");
            i++;
        }
        else if (isOperator(ch) || ch == '(' || ch == ')') {
            tokens.push_back(string(1, ch));
            i++;
        }
        else {
            i++; // ignore other characters
        }
    }
    return tokens;
}

string infixToPostfix(const vector<string>& tokens) {
    stack<string> st;
    string postfix = "";

    for (size_t i = 0; i < tokens.size(); ++i) {
        const string& token = tokens[i];
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            postfix += token + " ";
        }
        else if (token == "(") {
            st.push(token);
        }
        else if (token == ")") {
            while (!st.empty() && st.top() != "(") {
                postfix += st.top() + " ";
                st.pop();
            }
            if (!st.empty() && st.top() == "(") st.pop(); // remove '('
            // If unary minus is just before '(', push a marker to postfix to apply after evaluating the parenthesis
            if (!st.empty() && st.top() == "-u") {
                postfix += "-u ";
                st.pop();
            }
        }
        else if (token == "-u") { // Handle unary minus
            st.push(token);
        }
        else if (isOperator(token[0])) {
            while (!st.empty() && st.top() != "(" && precedence(st.top()) >= precedence(token)) {
                postfix += st.top() + " ";
                st.pop();
            }
            st.push(token);
        }
    }

    while (!st.empty()) {
        postfix += st.top() + " ";
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    stack<int> st;
    istringstream iss(postfix);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
            st.push(stoi(token));
        }
        else if (token == "-u") { // Handle unary minus
            if (st.empty()) throw runtime_error("Invalid expression: unary minus with no operand");
            int a = st.top(); st.pop();
            st.push(-a);
        }
        else if (isOperator(token[0])) {
            if (st.size() < 2) throw runtime_error("Invalid expression: not enough operands");
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
            else if (token == "^") st.push(pow(a, b));
        }
    }
    if (st.empty()) throw runtime_error("Invalid expression: empty stack at end");
    return st.top();
}

int solve(const string& s) {
    vector<string> toks = tokenize(s);
    string postfix = infixToPostfix(toks);
    return evaluatePostfix(postfix);
}

int main() {
    vector<string> tests = {
        "3 + 5 * (2 - 6)",
        "-5 + 4 * 3",
        "2 * (3 + (-4))",
        "10 + 2 * 6",
        "100 * (2 + 12)",
        "100 * (2 + 12) / 14",
        "3 + -5",
        "-(3 + 2) * 4",
        "-10 + (-2 * 5)"
    };

    for (const string& test : tests) {
        try {
            cout << "Expression: " << test << " = " << solve(test) << endl;
        } catch (const exception& e) {
            cout << "Expression: " << test << " = Error: " << e.what() << endl;
        }
    }

    return 0;
}