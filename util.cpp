#include "util.hpp"

/* Função que retorna o maior valor entre a e b. */
int max(int a, int b)
{ return a > b ? a : b; }

/* Função que retorna o menor valor entre a e b. */
int min(int a, int b)
{ return a < b ? a : b; }

/* Função que aloca n posições de nBytes bytes e retorna um ponteiro de void. */
void* alloc(int n, size_t nBytes)
{
    void *ptr = calloc(n, nBytes);
    if(ptr == NULL)
    {
        printf("Error: Memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

template <typename T>
void swap (T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

vector<string> splitStr(string input, string delimiter)
{
	vector<string> result;
	string str = input, token;
	size_t pos=0;
	
	while((pos = str.find(delimiter)) != std::string::npos)
	{
		token = str.substr(0, pos);
		if(token.size()!=0) result.push_back(token);
		str.erase(0, pos+delimiter.length());
	}
	result.push_back(str);
	return result;
}
