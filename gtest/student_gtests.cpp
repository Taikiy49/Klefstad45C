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
	char result[10];
	EXPECT_EQ(strncpy(result, "foo", 5), result);
	EXPECT_STREQ(result, "foo");
}

TEST(StringFunction, strcat) {
    char dest[20] = "This and ";
	char src[5] = "that"; // remember because of NULL value
	EXPECT_EQ(strcat(dest, src), "This and that");


}

TEST(StringFunction, strncat) {
	char result[10];
	EXPECT_EQ(strncat(result, "foo", 5), result);
	EXPECT_STREQ(result, "foo");
}

TEST(StringFunction, strcmp) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, strncmp) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(true);
}
