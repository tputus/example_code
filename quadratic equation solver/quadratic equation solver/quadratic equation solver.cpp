
#include <iostream>
using namespace std;

int main()
{
	int a;    //define integers
	int b;
	int c;
	int first;
	int second;

	cout<<"ax^2+bx+c=0\n";
	cout<<"Enter a: ";			//request input of integers
	cin>>a;						//input value of variables
	cout<<"Enter b: ";
	cin>>b;
	cout<<"Enter c: ";
	cin>>c;
	
	first= (-b+SQRT((b*b)-4*a*c))/(2*a);
	second= (-b-sqrt((b*b)-4*a*c))/(2*a);

	