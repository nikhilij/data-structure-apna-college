// write the cpp program to get the prefix to infix conversion of the given expression

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string prefixToInfixConversion(string &s){
	// Write your code here.
	stack<string> st;

	for(int i=s.length()-1;i>=0;i--){

		if(isalpha(s[i])){
			st.push(string(1,s[i]));
		}else{
			if(s.length()<2) return "";
			string a = st.top(); st.pop();
			string b = st.top(); st.pop();
			string c = "("+ a + s[i] + b + ")";
			st.push(c);
		}
	}
	
	return st.top();
}

int main() {
    string s = "*-A/BC-/AKL";
    cout << "Prefix Expression: " << s << endl;
    cout << "Infix Expression: " << prefixToInfixConversion(s) << endl;
    return 0;
}