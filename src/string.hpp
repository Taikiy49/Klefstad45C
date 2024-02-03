#ifndef STRING_HPP
#define STRING_HPP

#include <iosfwd>

class String
{
public:
    // constructs this string from a C string, defaults to empty string
    explicit String(const char *s = "");

    // construct this string as a copy of string s
    String(const String &s);

    // construct this string by moving from string s
    String(String &&s);

    // swap buf between this string and s using std::swap, explained later
    void swap(String &s);

    // assignment operator from one string, s, to this string
    String &operator=(const String &s);

    // assign to this string by moving from string s
    String &operator=(String &&s);

    // allow indexing this string with notation s[i]
    char &operator[](int index);

    // allow const indexing
    const char &operator[](int index) const;

    // returns the logical length of this string (# of chars up to '\0')
    int size() const;
    String reverse() const;
    int indexOf(char c) const;
    int indexOf(const String &s) const;
    bool operator==(const String &s) const;
    bool operator!=(const String &s) const;
    bool operator>(const String &s) const;
    bool operator<(const String &s) const;
    bool operator<=(const String &s) const;
    bool operator>=(const String &s) const;
    String operator+(const String &s) const;
    String &operator+=(const String &s);
    void print(std::ostream &out) const;
    void read(std::istream &in);

    ~String();

    bool in_bounds(int i) const
    {
        return i >= 0 && i < strlen(buf);
    }
    static int strlen(const char *s);
    static char *strcpy(char *dest, const char *src);
    static char *strncpy(char *dest, const char *src, int n);
    static char *strdup(const char *src);
    static char *reverse_strdup(const char *src);
    static char *double_strdup(const char *str1, const char *str2);
    static char *strcat(char *dest, const char *src);
    static char *strncat(char *dest, const char *src, int n);
    static int strcmp(const char *left, const char *right);
    static int strncmp(const char *left, const char *right, int n);
    static void reverse_cpy(char *dest, const char *src);
    static const char *strchr(const char *str, char c);
    static const char *strstr(const char *haystack, const char *needle);

private:
    char *buf;
    explicit String(int length);
};

std::ostream &operator<<(std::ostream &out, String s);

std::istream &operator>>(std::istream &in, String &s);

#endif