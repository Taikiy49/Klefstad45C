#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <iostream>
#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowerCase){
	string test = "hEllO tAiki";
	to_lowercase(test);
	EXPECT_STREQ("hello taikii", test.c_str());
	}

TEST(WordCount, LoadStopWords){
	stringstream test("helloworld taiki");
	const auto stop_words = load_stopwords(test);
	auto it = stop_words.find("taiki");
	EXPECT_TRUE(it != stop_words.end());
	}

TEST(WordCount, CountWords){
	stringstream test("aa aa Aa aA");
	const auto counts = count_words(test, {"Aa"});	
	auto it = counts.find("Aa");
	EXPECT_TRUE(it != counts.end());
	}

TEST(WordCount, OutputWordCounts){
	map<string, int> word_counts;
	word_counts["taiki"] = 1;
	word_counts["hello"] = 4;

	stringstream output;
	output_word_counts(word_counts, output);
	EXPECT_STREQ(output.str().c_str(), "taiki\nhelloo\n");
	}

