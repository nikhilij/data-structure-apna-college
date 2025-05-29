// write the cpp program to find the unqiue intersection of given two arrays

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

vector<int> uniqueIntersection(vector<int> a, vector<int> b)
{
    unordered_set<int> st(a.begin(), a.end());
    unordered_set<int> res;

    for (int num : b)
    {
        if (st.count(num))
        {
            res.insert(num);
        }
    }
    return vector<int>(res.begin(), res.end());
}

vector<int> getUniqueUnion(vector<int> a, vector<int> b)
{
    set<int> st(a.begin(), a.end());
    for (int n : b)
    {
        st.insert(n);
    }
    return vector<int>(st.begin(), st.end());
}

int main()
{
    vector<int> a = {1, 2, 2, 1};
    vector<int> b = {2, 2};

    vector<int> res = uniqueIntersection(a, b);
    vector<int> res1 = getUniqueUnion(a, b);

    for (int val : res)
        cout << val << " ";

    cout << endl;
    for (int val : res1)
        cout << val << " ";
}
