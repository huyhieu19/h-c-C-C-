#include <iostream>
using namespace std;

class complex{
	float thuc;
	float ao;
public:
	complex(float a=0,float b=0){
		thuc=a;
		ao=b;
	}
	
	friend ostream &operator<<(ostream &os,const complex &a);
	friend istream &operator>>(istream &is,complex &a);
	

	complex operator+(complex a){
		complex b(a.thuc + thuc,a.ao + ao);
		return b;
	}
	
	// -a
	friend complex operator-(complex a); 
	
	// a-b
	complex operator-(complex a){
		complex b(-a.thuc + thuc,-a.ao + ao);
		return b;
	}
	
	complex operator*(complex a){
		complex b(a.thuc*thuc - a.ao*ao , a.thuc*ao + a.ao*thuc);
		return b;
	}
	
	complex operator+=(complex a){
		thuc+=a.thuc;
		ao+=a.ao;
		return *this;
	}
	complex operator-=(complex a){
		thuc-=a.thuc;
		ao-=a.ao;
		return *this;
	}
	complex operator*=(complex a){
		complex b(thuc,ao);
		thuc=a.thuc*b.thuc - a.ao*b.ao;
		ao=a.thuc*b.ao + a.ao*b.thuc;
		return *this;
	}
	
	bool operator==(complex a){
		if (thuc == a.thuc && ao == a.ao)
			return true;
		return false;
	}
	bool operator!=(complex a){
		if (thuc != a.thuc || ao != a.ao)
			return true;
		return false;
	}
	
		
};
ostream &operator<<(ostream &os,const complex &a){
	os << a.thuc;
	if (a.ao>=0)
		os << "+";
	os << a.ao<<"i";
	return os;
}
istream &operator>>(istream &is,complex &a){
	cout << "phan thuc: ";
	is>>a.thuc;
	cout<< "phan ao: ";
	is>>a.ao;
}
complex operator-(complex a){
	complex b(-a.thuc,-a.ao);
	return b;
}
int main(){
	
	complex a;
	complex b;
	
	cout << "*nhap a:\n";
	cin>>a;
	cout << "*nhap b:\n";
	cin>>b;
	cout << "\n";
	
	
	if (a==b){
		cout <<"a = b"<<endl;
	}
	if (a!=b)
		cout <<"a khac b"<<endl;
	cout << "a + b = "<< a+b <<endl;
	cout << "a - b = "<< a-b <<endl;
	cout << "a * b = "<< a*b <<endl;
	
	a=-a;	
	a+=b;
	a-=b;
	a*=b;
	
	return 0;	
}
