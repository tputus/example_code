

#include <iostream>
using namespace std;

int main()
{
	int a; //define integers
    int b;
	int c;
	int d;
	int e;
	int f;
    int x;
	int y;

	cout<<"ax+by=c\n";
	cout<<"dx+ey=f\n";
	cout<<"Enter a: ";
	cin>>a;
	cout<<"\nEnter b: ";
	cin>>b;
	cout<<"\nEnter c: ";
	cin>>c;
	cout<<"\nEnter d: ";
	cin>>d;
	cout<<"\nEnter e: ";
	cin>>e;
	cout<<"\nEnter f: ";
	cin>>f;

	x= ((c*e)-(b*f))/((a*e)-(b*d));  //equations to find x and y
	y= ((c*d)-(a*f))/((b*d)-(a*e));

	cout<<"x= "<<x;
	cout<<"\ny= "<<y;

	char quit;
	cin>>quit;

	return 0;
}

	
