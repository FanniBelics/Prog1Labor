#include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void print_val(T temp)
{
    for(auto lm : temp)
        cout<<lm<<" ";
        cout<<endl;
}

template<typename T>
void increase(T& temp, const int val)
{
    for(auto& lm : temp)
    {
        lm+=val;
    }
}

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

//    print_val(ari);

    cout<<"Array: ";
    increase(ari, 2);
    print_val(ari);
    cout<<"Vector: ";
    increase(v, 3);
    print_val(v);
    cout<<"List: ";
    increase(l,5);
    print_val(l);


    return 0;
}