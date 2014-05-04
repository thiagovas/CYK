#ifndef _util_hpp
#define _util_hpp

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

#define INF 2147483000
#define EPS 1e-7

/* Retorna o menor valor entre a e b. */
int min(int a, int b);

/* Retorna o maior valor entre a e b. */
int max(int a, int b);

/* Função que aloca n posições de nBytes bytes e retorna um ponteiro de void. */
void* alloc(int n, size_t nBytes);

/* Faz um swap */
void swap (int &a, int &b);

vector<string> splitStr(string input, string delimiter);

#endif
