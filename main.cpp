#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <string>
#include <locale>
#include <iomanip>
#include "util.hpp"
using namespace std;

int main()
{
	int n;
	string input, word, temp, temp2;
	map<string, vector<string> > grammar;
	vector<string> regra;

	cin >> word;
	cin >> n;
	getline(std::cin, input);
	while(n-- > 0)
	{
		getline(std::cin, input);
		temp = input.substr(0, input.find(" ->"));
		temp2 = input.substr(input.find("> ")+2, input.size()-input.find(">"));
		grammar[temp].push_back(temp2);
	}
		
	return 0;
}
