// wap to find the two unique elements from the array

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int xsum = 0;
    for (int i = 0; i < n; i++)
    {
        xsum ^= a[i];
    }
    int rightmostbit = xsum & ~(xsum-1);
    int x, y;

    for(int i=0;i<n;i++){
        if(a[i]&rightmostbit){
            x^=a[i];
        }else{
            y^=a[i];
        }
    }

    cout<<x <<" "<<y;
    return 0;
}