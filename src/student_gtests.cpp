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
	stringstream test("helL0 wor1D");
	const auto stop_words = load_stopwords(test);
	
	auto it = stop_words.find("hell0");
	EXPECT_TRUE(it != stop_words.end());

	auto ot = stop_words.find("wor1d");
	EXPECT_TRUE(ot != stop_words.end());

	}

TEST(WordCount, CountWords) {
  stringstream test("aa aa Aa aA AA Aaa bC bc bc BC XY XY f0o FOO");
  const auto counts = count_words(test, {"f0o"});

  EXPECT_EQ(counts.at("aa"), 5);
  EXPECT_EQ(counts.at("bc"), 4);
  EXPECT_EQ(counts.at("xy"), 2);
  EXPECT_EQ(counts.at("bar"), 2);
  
  auto it = counts.find("f0o");
  EXPECT_TRUE(it != counts.end());
}
TEST(WordCount, OutputWordCounts){
	map<string, int> word_counts;
	word_counts["helL0"] = 4;

	stringstream output;
	output_word_counts(word_counts, output);
	EXPECT_STREQ(output.str().c_str(), "helL0 4\n");
	}




