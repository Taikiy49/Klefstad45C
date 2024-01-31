#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
	char initial[15] = "First String";
	const char* source = "Hello World!";
	strncpy(initial, source, 5);
	EXPECT_STREQ(initial, "Hello String");
	
}

TEST(StringFunction, strcat) {
    char dest[20] = "This and ";
	char src[5] = "that"; // remember because of NULL value
	EXPECT_STREQ(strcat(dest, src), "This and that");
}

TEST(StringFunction, strncat) {
	char dest[20] = "This and ";
	char src[5] = "that";
	EXPECT_STREQ(strncat(dest, src, 5), "This and that");
}

TEST(StringFunction, strcmp) {
	char left[6] = "Hello";
	char right[6] = "World";
	EXPECT_NE(strcmp(left, right), 0);
}

TEST(StringFunction, strncmp) {
    char left[6] = "Hello";
	char right[6] = "World";
	EXPECT_NE(strncmp(left, right, 5), 0);
}

TEST(StringFunction, reverse_cpy) {
	EXPECT_TRUE(true);
}

TEST(StringFunction, strchr) {
 	const char* str = "Hello World!";
	char ch = 'o';

	const char* result = strchr(str, ch);

	EXPECT_TRUE(result != nullptr);
	EXPECT_EQ(*result, ch);

}

TEST(StringFunction, strstr) {
	const char* str = "Hello World!";
	const char* substring = "World";

	const char* result = strstr(str, substring);

	EXPECT_TRUE(result != nullptr);
	EXPECT_EQ(result - str, 6);

  	
}
