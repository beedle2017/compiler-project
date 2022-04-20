#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <stack>
#include <map>
#include <math.h>
#include <bitset>
#include <deque>
#include <string>
#include <tuple>
#include <queue>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

#define vec(i) vector<i> 	//Vector macro
#define pb push_back	

using namespace std;

signed main()
{
	vector <char> str;
	
	START:
	char x;
	x=getchar();
	str.push_back(x);

	goto A;

	// state A : 
	A:
	if(x=='#')
	goto B;
	else if(x=='%')
	goto C;
	if(x==' ' || x=='\t' || x=='\n')
	{
		cout<<"ERROR1";
		exit(0);
	}
	else
	{
		cout<<"ERROR3";
		exit(0);
	}

	// state B :
	B: x=getchar();
		str.push_back(x);
	if(x==' ' || x=='\t' || x=='\n')
	{
		cout<<"PARSED"<<endl;
		for(char c:str)
		cout<<c;
		cout<<endl;
		str.clear();
		goto START;
	}
	else
	{
		cout<<"ERROR2";
		exit(0);
	}


	// state C :
	C: 

	// state D:
	D:

	// state E:
	E:

	// state F:
	F:

	// state G:
	G:

	return 0;
}