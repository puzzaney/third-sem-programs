#include<iostream>
#include<iomanip>
using namespace std;


double fn(double x){
	//Function given in question. Change according to question. For this case the function was x^2 - 4x + 3 = 0
	return x*x - 4*x + 3;
}

double x(double a, double b){
//	Formula to calculate the value of xn
	return (a*fn(b) - b*fn(a))/(fn(b)-fn(a));
}

int main(){
	double a, b;
	
	cout<<"Enter the initial value of a and b: ";
	cin>>a>>b;
	
	int i, n;
	
	cout<<"Enter the number of iterations you need: ";
	cin>>n;
	cout<<"\n";
	
	
//	Basic formatting here
	cout<<setw(4)<<"n"<<setw(12)<<"a"<<setw(4)<<"b"<<setw(12)<<"fn(a)"<<setw(8)<<"fn(b)"<<setw(12)<<"xn"<<setw(12)<<"fn(xn)"<<endl;
	 cout<<setprecision(5);
	 
	for(i=1; i<=n; i++){
		double xn = x(a,b);
		cout<<setw(4)<<i<<setw(12)<<a<<setw(4)<<b<<setw(12)<<fn(a)<<setw(8)<<fn(b)<<setw(12)<<xn<<setw(12)<<fn(xn)<<endl;
	
//	Swapping the value of xn with a with b remaining constant
		a = xn;
	}
	
	
	return 0;
}
