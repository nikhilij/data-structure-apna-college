// wap to solve tower of hanoi
#include <iostream>
using namespace std;

void Towerofhanoi(int n, char src, char aux, char dest){

    if(n==1){
        cout<<"Move disk 1 from rod " << src << " to rod "<<dest <<endl;
        return;
    }   
    Towerofhanoi(n-1,src,dest,aux);
    cout<<"Move disk "<<n<<" from rod " << src <<" to rod "<<dest <<endl;
    Towerofhanoi(n-1,aux,src,dest);



}


int main()
{
    int n;
    cin >> n;

    Towerofhanoi(n, 'A', 'B', 'C');
}