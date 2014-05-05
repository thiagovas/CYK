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

bool belongs(map<string, vector<string> > grammar, map<string, vector<string> > rules, string word);
void printGrammar(map<string, vector<string> > grammar);

int main()
{
	int n;
	string input, word, temp, temp2;
	map<string, vector<string> > grammar, rules;
	vector<string> variable;

	cin >> word;
	cin >> n;
	getline(std::cin, input);
	while(n-- > 0)
	{
		getline(std::cin, input);
		temp = input.substr(0, input.find(" ->")); // Getting the LHS of the rule.
		temp2.clear();

		/* The next two lines remove the spaces in the RHS */
		variable = splitStr(input.substr(input.find("> ")+2, input.size()-input.find(">")), " ");
		for(vector<string>::iterator it = variable.begin(); it != variable.end(); it++) temp2+=*it;
		
		rules[temp2].push_back(temp);
		grammar[temp].push_back(temp2);
	}
	
	printGrammar(grammar);

	if(belongs(grammar, rules, word)) cout << "SIM\n";
	else cout << "NAO\n";

	return 0;
}

bool belongs(map<string, vector<string> > grammar, map<string, vector<string> > rules, string word)
{
	const int N = word.size();
	string temp;
	vector<string> vTemp;
	vector<vector<vector<string> > > m(N, vector<vector<string> >(N));
	
	for(int i = 0; i < N; i++)
	{
		temp.clear(); temp += word[i];
		if(rules.find(temp) == rules.end()) return false;
		
		m[i][i] = rules[temp];
	}

	int beginj=1, i=0, j=0;
	while(beginj < N)
	{
		i=0;  j=beginj;
		while(j < N)
		{
			for(int k = j; k > -1; k--) if(m[i][k].size() != 0)
			{
				vTemp = m[i][k];
				break;
			}
			
			// In an amortized analysis, the following spends at most N+(V^2)*log V loops, where V is the number of variables in the grammar.
			// There is an log factor just because I'm using a map.
			for(int k = i; k < N; k++) if(m[k][j].size() != 0)
			{
				for(unsigned int ii = 0; ii < m[k][j].size(); ii++)
					for(unsigned int jj = 0; jj < vTemp.size(); jj++)
					{
						temp = vTemp[jj]+m[k][j][ii];
						if(rules.find(temp) != rules.end())	m[i][j].insert(m[i][j].end(), rules[temp].begin(), rules[temp].end());
					}
				break;
			}
			i++;  j++;
		}
		beginj++;
	}
	return (find(m[0].rbegin()->begin(), m[0].rbegin()->end(), "S") != m[0].rbegin()->end());
}

void printGrammar(map<string, vector<string> > grammar)
{
	for(map<string, vector<string> >::iterator it = grammar.begin(); it != grammar.end(); it++)
	{
		cout << it->first << ":";
		for(vector<string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
			cout << " " << *jt;
		cout << endl;
	}
}
