// wap to selection sort

#include <iostream>
using namespace std;

int main()
{
    int a[] = {8, 4, 1, 2, 3, 9};
    int n = 6;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // sorting the array using selection sort

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i],a[min]);
        
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}