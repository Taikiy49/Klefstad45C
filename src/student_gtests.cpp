#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <iostream>
#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowerCase){
	string test = "heLL0 my_name IS taiki";
	to_lowercase(test);
	EXPECT_STREQ("hell0 my_name is taiki", test.c_str());
	}

TEST(WordCount, LoadStopWords){
	stringstream test("heLL0 w0rld ");
	const auto stop_words = load_stopwords(test);
	
	auto it = stop_words.find("hell0");
	EXPECT_TRUE(it != stop_words.end());


	}

TEST(WordCount, CountWords){
	stringstream test("aa aa Aa heLL0");
	const auto counts = count_words(test, {"heLL0"});	
	auto it = counts.find("hell0");
	EXPECT_TRUE(it != counts.end());
	}

TEST(WordCount, OutputWordCounts){
	map<string, int> word_counts;
	word_counts["helL0"] = 4;

	stringstream output;
	output_word_counts(word_counts, output);
	EXPECT_STREQ(output.str().c_str(), "helL0 4\n");
	}




