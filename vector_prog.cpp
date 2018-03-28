#include <iostream>
#include "vector.cpp"

using std::cout;
int main()
{
	
	vector <int> a(2);
	vector <int> b(11);
	
	a.append(1);
	a.append(1);
	a.append(1);
	a.append(1);
	a.append(1);
	a.append(1);
	a.append(1);
	a.append(1);
	a.append(1);
	a.append(1);
	
	a = b;
	//~ printf("Before:\n");
	a.dump("a", "stdout");
	//~ b.dump("b", "stdout");
	
	//~ b = a;
	
	//~ printf("After:\n");
	//~ a.dump("a", "stdout");
	//~ b.dump("b", "stdout");
	//~ cout << a[1] << endl;
	
	return 0;
}
