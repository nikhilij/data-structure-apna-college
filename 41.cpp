// learning vector in c++;

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;  // declaration
    v.push_back(1); // adding
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\n";
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }

    printf("\n");
    for (auto it : v)
    {
        cout << it << " ";
    }

    printf("\n");

    v.pop_back();

    for (auto it : v)
    {
        cout << it << " ";
    }

    vector<int> v2 (3,50);
    printf("\n");
    for(auto it:v2){
        printf("%d ",it);
    }
}