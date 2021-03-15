#include <iostream>

using namespace std;

struct B
{
	virtual void f() const {cout<<"B::f"<<endl; print_message(8.5);}
	void g() const {cout<<"B::g"<<endl;} //ben virtuális nem íródik felül
	//ha referencia szerint hívjuk

	void print_message(int a)const{cout<<"Message: "<<a<<endl;}
};

struct  D:B
{
	
	void f() const override {cout<<"D::f"<<endl; print_message(8.4);}
	void g()  {cout<<"D::g"<<endl;}
	void print_message(double a)const{cout<<"Message: "<<a<<endl;}
};

struct  DD:B
{
	
	void f() const {cout<<"DD::f"<<endl;}
	void g() const {cout<<"DD::g"<<endl;}
};

void call (const B &b)
{
	b.f();
	b.g();
}

int main ()
{
	B b;
	D d;
	DD dd;

	call(b);
	call(d);
	call(dd);

	b.f();
	b.g();

	d.f();
	d.g();

	dd.f();
	dd.g();
}