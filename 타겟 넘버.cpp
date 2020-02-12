#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5,6 };
	cout << v.lower_bound(v,v+6,5);
}