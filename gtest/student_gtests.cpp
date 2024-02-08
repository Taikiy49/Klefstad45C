#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen)
{
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
    EXPECT_EQ(String::strlen("something"), 9);
    EXPECT_EQ(String::strlen("\0"), 0);
}

TEST(StringFunction, strcpy)
{
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strdup)
{
    char *heapstr = String::strdup("nooklosh");
    char *anotherheapstr = String::strdup("S");
    EXPECT_EQ(String::strlen(heapstr), 8);
    EXPECT_EQ(String::strlen(anotherheapstr), 1);
    delete[] heapstr;
    delete[] anotherheapstr;
}

TEST(StringFunction, strncpy)
{
    char result[10];
    EXPECT_EQ(String::strncpy(result, "tai", 3), result);
    EXPECT_STREQ(result, "tai");

    EXPECT_EQ(String::strncpy(result, "", 0), result);
    EXPECT_EQ(String::strncpy(result, "", 1), result);
    EXPECT_STREQ(result, "");

    EXPECT_EQ(String::strncpy(result, "Yamashita", 4), result);
    EXPECT_STREQ(result, "Yama");
}

TEST(StringFunction, strcat)
{
    char result[80] = "Taiki";
    EXPECT_EQ(String::strcat(result, ""), result);
    EXPECT_STREQ(String::strcat(result, "foo"), "Taikifoo");
    EXPECT_STREQ(String::strcat(result, "nooo"), "Taikifoonoo");
    EXPECT_STREQ(String::strcat(result, ""), "Taikifoonoo");
}

TEST(StringFunction, strncat)
{
    char result[100] = "Pong";
    EXPECT_EQ(String::strncat(result, "", 1), result);
    EXPECT_STREQ(String::strncat(result, "foo", 3), "Pongfoo");
    EXPECT_STREQ(String::strncat(result, "taiki", 3), "Pongfootai");
    EXPECT_STREQ(String::strncat(result, "", 0), "Pongfootai");
}

TEST(StringFunction, strcmp)
{
    EXPECT_EQ(String::strcmp("taiki", "taiki"), 0);
    EXPECT_EQ(String::strcmp("A", "BC"), ('A' - 'B'));
    EXPECT_EQ(String::strcmp("", ""), 0);
    EXPECT_NE(String::strcmp("BA", "BCD"), ('A' - 'D'));
    EXPECT_EQ(String::strcmp("BA", "BCD"), -('C' - 'A'));
}

TEST(StringFunction, strncmp)
{
    EXPECT_EQ(String::strncmp("yamashita", "yamashiro", 5), 0);
    EXPECT_EQ(String::strncmp("A", "BC", 0), 0);
    EXPECT_EQ(String::strncmp("A", "BC", 100), ('A' - 'B'));
    EXPECT_EQ(String::strncmp("", "", 10), 0);
    EXPECT_EQ(String::strncmp("BA", "BCD", 1), 0);
    EXPECT_EQ(String::strncmp("BA", "BCD", 2), -('C' - 'A'));
    EXPECT_TRUE((String::strncmp("car", "cars", 10)) < (0));
}

TEST(StringFunction, strstr)
{
    char str[200] = "I that you are searching through this incredibly long string.";
    char first[20] = "spectacular";
    char second[20] = "nonsense";
    char third[20] = "incredibly";
    char fourth[20] = "incred";
    char fifth[20] = ".";
    char sixth[20] = "ing.";
    char seventh[20] = "";

    const char *ptr3 = String::strstr(str, first);
    const char *ptr4 = String::strstr(str, second);
    const char *ptr5 = String::strstr(str, third);
    const char *ptr6 = String::strstr(str, fourth);
    const char *ptr7 = String::strstr(str, fifth);
    const char *ptr8 = String::strstr(str, sixth);
    const char *ptr9 = String::strstr(str, seventh);

    EXPECT_EQ(nullptr, ptr3);
    EXPECT_EQ(nullptr, ptr4);
    EXPECT_EQ(54, ptr5 - str + 1);
    EXPECT_EQ(54, ptr6 - str + 1);
    EXPECT_EQ(String::strlen(str), ptr7 - str + 1);
    EXPECT_EQ(String::strlen(str) - 3, ptr8 - str + 1);
    EXPECT_EQ(str, ptr9);

    char haystack[10] = "somethin";
    const char *p = String::strstr(haystack, "");
    EXPECT_EQ(haystack, p);
}


TEST(StringFunction, reverse_cpy)
{
    char a[100] = "TAIKIYAMASHITA";
    char b[20];
    String::reverse_cpy(b, a);
    EXPECT_STREQ(b, "ATIHSAMAYIKIAT");
    char c[5] = "craz";
    char d[6] = "thing";
    String::reverse_cpy(d, c);
    EXPECT_STREQ(d, "zarc");
}

TEST(StringFunction, strchr)
{
    char str[5] = "ABCD";
    const char *ptr1 = String::strchr(str, 'D');
    int index = ptr1 - str + 1;
    EXPECT_EQ(index, 4);
    const char *ptr2 = String::strchr(str, 'Q');
    EXPECT_EQ(nullptr, ptr2);
    char str2[10] = "ABCDEFGHI";
    const char *ptr3 = String::strchr(str2, 'H');
    EXPECT_EQ(8, ptr3 - str2 + 1);
    char tstr[1] = "";
    const char *ptr4 = String::strchr(tstr, 'a');
    EXPECT_EQ(nullptr, ptr4);
    char str3[4] = "abc";
    const char *ptr5 = String::strchr(str3, '\0');
    EXPECT_EQ(4, ptr5 - str3 + 1);
    char haystack[4] = "AJF";
    const char *ptr6 = String::strchr(haystack, '\0');
    EXPECT_EQ(4, ptr6 - haystack + 1);
}

