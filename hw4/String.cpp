#include"String.h"

int String::allocations = 0;

char* String::new_char_array(int n_bytes)
{
	++allocations;
	return new char[n_bytes];
}
void String::delete_char_array(char* p)
{
	--allocations;
	if (allocations < 0)
		cout << ("more delete[] than new[]") << endl;
	delete[] p;
}
bool String::inBound(int i)
{
	return i >= 0 && i < strlen(buf);
}
int String::strlen(const char* s)
{
	int len;
	for (len = 0; s[len] != '\0'; ++len);
	return len;
}
char* String::strcpy(char* dest, const char* src)
{
	int i;
	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = src[i];
	return dest;
}
char* String::strcat(char* dest, const char* src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}
int String::strcmp(const char* left, const char* right)
{
	int temp = strncmp(left, right, strlen(left));
	if (temp != 0) return temp;
	if (strlen(left) == strlen(right)) return 0;
	else if (strlen(left) > strlen(right)) return 1;
	else return -1;
}
int String::strncmp(const char* left, const char* right, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (left[i] > right[i]) return 1;
		else if (left[i] < right[i]) return -1;
		else if (left[i] == '\0') return 0;
	}
	return 0;
}
char* String::strchr(char* str, int c)
/* haystack "The quick brown fox ran up the lazy log"
needle "ran" */
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == c)

			return str + i;
	}
	return 0;
}
const char* String::strstr(const char *haystack, const char *needle)
{
	return const_cast<const char *>(strstr(const_cast<char *>(haystack), needle));
}
char* String::strstr(char *haystack, const char *needle)
{
	int len = strlen(needle);
	if (len == 0) return haystack;
	for (int i = 0; haystack[i] != '\0'; ++i)
	{
		if (strncmp(haystack + i, needle, len) != 0)
			continue;
		return haystack + i;
	}
	return 0;
}
char* String::strdup(const char *src)
{
	char* result;

	result = new_char_array(strlen(src) + 1);
	strcpy(result, src);
	return result;
}
void String::reverse_cpy(char* dest, const char* src)
{
	int len = strlen(src);
	for (int i = 0; src[i] != '\0'; ++i)
	{
		dest[i] = src[len - i - 1];
	}
	dest[len] = '\0';
}
String::String(const String & s)
{
	buf = strdup(s.buf);
}
String String:: operator = (const String & s)
{
	delete_char_array(buf);
	buf = strdup(s.buf);
	return *this;
}
char & String::operator [] (int index)
{
	if (!inBound(index))
	{
		index = 0;
		cerr << "Index out of range." << endl;
	}
	return buf[index];
	
}
int String::size()
{
	return strlen(buf);
}
String String::reverse() // does not modify this String
{
	char*temp = new_char_array(strlen(buf) + 1);
	reverse_cpy(temp, buf);
	String result(temp);
	delete_char_array(temp);
	return result;
}
int String::indexOf(const char c)
{
	char* pos = strchr(buf, c);
	if (pos == '\0') return -1;
	return pos - buf;
}
int String::indexOf(const String pattern)
{
	char* pos = strstr(buf, pattern.buf);
	if (pos == '\0') return -1;
	return pos - buf;
}
bool String::operator == (const String s)
{
	return strcmp(buf, s.buf) == 0;
}
bool String::operator != (const String s)
{
	return strcmp(buf, s.buf) != 0;
}
bool String::operator > (const String s)
{
	return strcmp(buf, s.buf) == 1;
}
bool String::operator < (const String s)
{
	return strcmp(buf, s.buf) == -1;
}
bool String::operator <= (const String s)
{
	return strcmp(buf, s.buf) != 1;
}
bool String::operator >= (const String s)
{
	return strcmp(buf, s.buf) != -1;
}
/// concatenates this and s to return result
String String::operator + (const String s)
{
	char* temp = new_char_array(strlen(s.buf) + strlen(buf) + 1);
	strcpy(temp, buf);
	strcat(temp, s.buf);
	String result(temp);
	delete_char_array(temp);
	return result;
}
/// concatenates s onto end of this
String String::operator += (const String s)
{
	char* temp = new_char_array(strlen(buf) + strlen(s.buf) + 1);
	strcpy(temp, buf);
	strcat(temp, s.buf);
	delete_char_array(buf);
	buf = temp;
	return *this;
}
void String::print(ostream & out)
{
	out << buf;
}
void String::read(istream & in)
{
	char* temp = new_char_array(256);
	in.getline(temp, 256);
	delete_char_array(buf);
	buf = strdup(temp);
	delete_char_array(temp);
}
void String::final_report()
{
	cout << "Number of new allocations minus number of delete deallocations is " << allocations << endl;
}
String::~String()
{
	delete_char_array(buf);
}
ostream& operator << (ostream& out, String str)
{
	str.print(out);
	return out;
}
istream& operator >> (istream& in, String& str)
{
	str.read(in);
	return in;
}