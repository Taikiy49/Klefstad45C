#include "string.hpp"
#include <iostream>


using namespace std;


int String::strlen(const char *s) {
    int value;
    for (value=0; s[value] != '\0'; ++value) {}
    return value;
}

char* String::strcpy(char *dest, const char *src) {
    int value;
    for (value=0; src[value] != '\0'; ++value) {
        dest[value] = src[value];
    }
    dest[value] = '\0';
    return dest;
}

char* String::strncpy(char *dest, const char *src, int n) {
    int value;
    for (value=0; value<n && src[value] != '\0'; ++value) {
        dest[value] = src[value];
    }
    dest[value] = '\0';
    return dest;
}

char* String::strcat(char *dest, const char *src) {
    int value = String::strlen(dest);
    for (int value2=0; src[value2] != '\0'; ++value2) {
        dest[value] = src[value2];
        ++value;
    }
    dest[value] = '\0';
    return dest;
}

char* String::strncat(char *dest, const char *src, int n) {
    int value = String::strlen(dest);
    for (int value2=0; value2<n && src[value2] != '\0'; ++value2) {
        dest[value] = src[value2];
        ++value;
    }
    dest[value] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right) {
    int value=0;
    for (; left[value] != '\0' && right[value] != '\0'; ++value) {
        if (left[value] != right[value])
            return (left[value] - right[value]);
    }
    if (left[value] == right[value])
        return 0;
    else
        return (left[value] - right[value]);
}

int String::strncmp(const char *left, const char *right, int n) {
    int value=0;
    for (; value<n && left[value] != '\0'; ++value) {
        if (left[value] != right[value])
            return (left[value] - right[value]);
    }
    if (value == n)
        return 0;
    else if (right[value] == '\0')
        return 0;
    else
        return (left[value]-right[value]);
}

void String::reverse_cpy(char* dest, const char* src) {
    int value = String::strlen(src)-1;
    int value2;
    for (value2=0; value>=0; --value) {
        dest[value2] = src[value];
        ++value2;
    }
    dest[value2] = '\0';
}

const char* String::strchr(const char* str, char c) {
    const char* ptr = nullptr;
    int value;
    for (value=0; str[value] != '\0'; ++value) {
        if (str[value] == c) {
            ptr = &str[value];
            break;
        }
    }
    if (c == '\0')
        ptr = &str[value];
    return ptr;
}

const char* String::strstr(const char* haystack, const char* needle) {
    const char* ptr = nullptr;
    int needleLength = String::strlen(needle);
    if (needleLength == 0) {
        return haystack;
    }
	int value;
    int cycle = String::strlen(haystack)-needleLength+1;
    for (int value=0; value<cycle; ++value) {
        int step = 0;
        for (; step<needleLength; ++step) {
            if (haystack[value+step] != needle[step])
                break; 
				}
        if (step == needleLength) { 
		ptr = &haystack[value];
            break;
        }
    }
    return ptr;
}

void String::print(std::ostream &out) const {
    for (int value=0; buf[value] != '\0'; ++value)
        out << buf[value];
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}

String::String(const char *s) {
    strncpy(buf, s, MAXLEN-1);
}

String::String(const String &s) {
    strcpy(buf, s.buf);
}

int String::size() const {
    return strlen(buf);
}

String::~String() {
}

bool String::operator==(const String &s) const {
    if (String::strcmp(buf, s.buf) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool String::operator!=(const String &s) const {
    return (!(String::strcmp(buf, s.buf) == 0));
}

bool String::operator>(const String &s) const {
    return ((String::strcmp(buf, s.buf)) > 0);
}

bool String::operator<(const String &s) const {
    return ((String::strcmp(buf, s.buf)) < 0);
}

bool String::operator<=(const String &s) const {
    return ((String::strcmp(buf, s.buf)) <= 0);
}

bool String::operator>=(const String &s) const {
    return ((String::strcmp(buf, s.buf)) >= 0);
}

String& String::operator=(const String &s) {
    String::strcpy(buf, s.buf);
    return *this;
}

char& String::operator[](int index) {
    int n = String::strlen(buf);
    if (0<index && index<n)
        return buf[index];
    else {
        cout << "ERROR" << endl;
        return buf[0];
    }
}

String String::reverse() const {
    String r;
    String::reverse_cpy(r.buf, buf);
    return r;
}

int String::indexOf(char c) const {
    char* foundptr = (char*) String::strchr(buf, c);
    if (foundptr == nullptr)
        return -1;
    int index = foundptr-buf;
    return index;
}

int String::indexOf(const String &s) const {
    char* otherbuf = (char*) s.buf;
    char* foundptr = (char*) String::strstr(buf, otherbuf);
    if (foundptr == nullptr)
        return -1;
    int index = foundptr-buf;
    return index;
}

String String::operator+(const String &s) const {
    String r(""); 
	int n = (MAXLEN-1)-String::strlen(buf); 
    if (n<=0)
	cout << "ERROR" << endl;
    else {
        String::strcat(r.buf, buf);
        String::strncat(r.buf, s.buf, n);
    }
    return r;
}

String& String::operator+=(const String &s) {
    String r("");
	int n = (MAXLEN-1)-String::strlen(buf);
	if (n<=0)
        cout << "ERROR" << endl;
    else {
        String::strcat(r.buf, buf);
        String::strncat(r.buf, s.buf, n); 
        String::strcpy(buf, r.buf);
    }
    return *this;
}

void String::read(std::istream &in) {
    in >> buf;
}

std::istream &operator>>(std::istream &in, String &s) {
    s.read(in); 
    return in;
}
