#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

vector<string> tokenizeString(string str);

int main()
{
    vector<string> tmp = tokenizeString("hello world now!");
    for(int i = 0; i < tmp.size(); i++)
    {
       cerr << tmp[i] << endl;
    }
    return 0;
}

vector<string> tokenizeString(string str)
{
    stringstream curr(str);
    vector<string> result;
    string tmp;

    while( curr >> tmp)
    {
	result.push_back(tmp);
    }
    return result;
}

