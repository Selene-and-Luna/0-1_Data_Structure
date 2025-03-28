#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(!n) {
		cout << 0;
		return 0;
	}
    
	vector<int> v;
	while (n--) {
    	int t;
    	cin >> t;
    	v.push_back(t);
  	}

  	sort(v.begin(), v.end());
  	int trmdel = round(float(v.size()) * 15 / 100);
  	double trimmed_mean = 0;

  	for (int i = trmdel; i < v.size() - trmdel; i++)
  		trimmed_mean += v[i];
	
	cout << (round(trimmed_mean / (v.size() - 2 * trmdel)));
}