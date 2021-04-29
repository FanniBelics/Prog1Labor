#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

struct Item 
{
    string name;
    int iid;
    double value;
};

template <typename T>
void print(T v)
{
    for( auto val : v)
        {
            cout<<val.name << " " << val.iid<< " " << val.value<<endl;
        }
}

bool by_name(const Item a, const Item b)
{
    return a.name < b.name;
}

bool by_iid (const Item a, const Item b)
{
    return a.iid < b.iid;
}

struct find_by_name
{
    string nm;
    find_by_name(string n) : nm{n} {}
    bool operator() (const Item it){return it.name == nm;}
};

struct find_by_iid
{
    int id;
    find_by_iid(int i) : id{i} {};
    bool operator() (const Item it){return it.iid == id;}
};



int main()
{
    vector<Item> vi;
    ifstream f;
    f.open("items.txt");
    Item temp;
    string val;
    while(!f.eof())
    {
        getline(f, temp.name, ';');
        getline (f, val, ';');
        temp.iid = stoi(val);
        getline(f, val);
        temp.value = stod(val);
        vi.push_back(temp);
    }
    
    cout<<"Original:"<<endl;
    print(vi);

    cout<<"\nBy name:"<<endl;
    sort(vi.begin(), vi.end(), by_name);
    print(vi);

    cout<<"\nBy iid:"<<endl;
    sort(vi.begin(), vi.end(), by_iid);
    print(vi);

    cout<<"\nBy value decrease:"<<endl;
    sort(vi.begin(), vi.end(),
        [] (const Item a, const Item b){return a.value>b.value;}
        );
    print(vi);

    Item insert1 = {"Horse shoe", 99, 12.34};
    Item insert2 = {"Canon S400", 9988, 499.95};

    vi.insert(vi.begin(), insert1);
    vi.insert(vi.begin(), insert2);

    vi.erase(find_if(vi.begin(), vi.end(), find_by_name("Earphones")));
    vi.erase(find_if(vi.begin(), vi.end(), find_by_name("Calculator")));

    vi.erase(find_if(vi.begin(), vi.end(), find_by_iid(99)));
    vi.erase(find_if(vi.begin(), vi.end(), find_by_iid(9988)));

    cout<<"\nAfter insert and erase:"<<endl;
    print(vi);


    return 0;
}