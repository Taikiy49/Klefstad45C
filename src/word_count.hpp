#ifndef WORD_COUNT_HPP
#define WORD_COUNT_HPP

#include <iosfwd>
#include <map>
#include <set>
#include <string>
#include <iostream>

void to_lowercase(string& str);
set<string> load_stop_words(istream& stopwords);
map<string, int> count_words(istream& document, const set<string& stopwords);

void output_word_counts(const map<string, int>& word_counts, ostream& output);

#endif


