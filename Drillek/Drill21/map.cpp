#include <iostream>
#include <map>
#include <numeric>

using namespace std;

void fill(map<string, int>& msi)
{
    msi["Cherry"]=7;
    msi["Mushroom"]=3;
    msi["Cake"]=0;
    msi["Teriyaki"]=4;
    msi["Chicken"]=1;
    msi["Ice Tea"]=9;
    msi["Hearthstone"]=2;
    msi["Frog"]=6;
    msi["Monstera"]=8;
    msi["Succulent"]=5;
}

template <typename frst, typename snd>
void print(map<frst,snd> mp)
{
    for(auto m : mp)
    {
        cout<<m.first<< " " <<m.second<<endl;
    }
}

void fill_from_input(map<string, int>& msi)
{
    string stemp;
    int itemp;
    while(msi.size() < 10)
    {
        getline(cin, stemp, ',');
        cin>>itemp;
        msi.insert(make_pair(stemp,itemp));
        getline(cin,stemp);
    }
}

void transfer(map<string,int> msi, map<int,string>& mis)
{
    for(auto m : msi)
    {
        mis.insert(make_pair(m.second, m.first));
    }
}

int main()
{
    map<string, int> msi;

    fill(msi);
    cout<<"Filled: "<<endl;
    print(msi);

    msi.erase(msi.begin(), msi.end());
    cout<<"\nEmptied:"<<endl;
    print(msi);

    cout<<"\nAdd new elements: string,int"<<endl;
    fill_from_input(msi);
    cout<<"\n New elements:"<<endl;
    print(msi);

    int total = accumulate(msi.begin(), msi.end(), 0,
                [](int sum, const pair<string,int>& m)
                {
                    return sum+=m.second;
                });
    cout<<"In total: "<<total<<endl;

    map<int,string> mis;
    transfer(msi,mis);
    cout<<"\n mis after transfer:"<<endl;
    print(mis);

    return 0;
}