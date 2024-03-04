#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "mapset.hpp"

using namespace std;

string to_lowercase(const string& str){
    string r = str;
    transform(r.begin(), r.end(), r.begin(), [](char c){return tolower(c);});
    return r;
}

