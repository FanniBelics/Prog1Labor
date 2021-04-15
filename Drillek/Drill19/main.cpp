#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct S
{
    private:
    T val;

    public:
    explicit S(T v=0) : val{v} {};

    const T& get();
    void set(T vv);

};

template <typename T>
const T& S<T>:: get()
    {
        return val;
    }
template <typename T>
void S<T>::set(T vv)
{
    val=vv;
}


int main()
{
    S<int> sint (13);
    S<char> schar ('Y');
//    schar.set('W');
    S<double> sdouble (3.141592);
    S<string> sstring ("Yare Yare Daze");
    S<vector<int>> svector (vector<int> {0, 1, 2, 3, 4});

    cout<<"int: "<<sint.get()<<"\n"
        <<"char: "<<schar.get()<<"\n"
        <<"double: "<<sdouble.get()<<"\n"
        <<"string: "<<sstring.get()<<endl;


    return 0;
}