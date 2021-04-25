#include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;

int main()
{
    const int size=10;

//    int arr [size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, size> ari = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list <int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    array<int, size> ari2 = ari;
    vector<int> v2 = v;
    list <int> l2 = l;

/*
    for(int i=0; i<size; i++)
    {
        cout<<l2[i]<<" ";
    }
    cout<<endl;
*/

    return 0;
}