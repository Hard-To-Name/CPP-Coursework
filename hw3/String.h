#define MAXLEN 128
#include<iostream>
using namespace std;

class String
{
private:
	bool inBound(int i)
	{
		return i >= 0 && i < strlen(buf);
	} // HINT: some C string primitives you should define and use
	static int strlen(const char* s)
	{
		int len;
		for (len = 0; s[len] != '\0'; ++len);
		return len;
	}
	static char* strcpy(char* dest, const char* src)
	{
		int i;
		for (i = 0; src[i] != '\0'; ++i)
			dest[i] = src[i];
		dest[i] = src[i];
		return dest;
	}
	static char* strcat(char* dest, const char* src)
	{
		strcpy(dest + strlen(dest), src);
		return dest;
	}
	static int strcmp(const char* left, const char* right)
	{
		int temp = strncmp(left, right, strlen(left));
		if (temp != 0) return temp;
		if (strlen(left) == strlen(right)) return 0;
		else if (strlen(left) > strlen(right)) return 1;
		else return -1;
	}
	static int strncmp(const char* left, const char* right, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (left[i] > right[i]) return 1;
			else if (left[i] < right[i]) return -1;
		}
		return 0;
	}
	static char* strchr(char* str, int c)
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
	static const char* strstr(const char *haystack, const char *needle)
	{
		return const_cast<const char *>(strstr(const_cast<char *>(haystack), needle));
	}
	static char* strstr(char *haystack, const char *needle)
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
	static void reverse_cpy(char* dest, const char* src)
	{
		int len = strlen(src);
		for (int i = 0; src[i] != '\0'; ++i)
		{
			dest[i] = src[len - i - 1];
		}
		dest[len] = '\0';
	}
	char buf[MAXLEN];
	// DO NOT store the 'logical' length of this string
	// use the null '\0' terminator to mark the end

public:
	/// Both constructors should construct this String from the parameter s
	explicit String(const char* s = "")
	{
		if(strlen(s) < MAXLEN)
			strcpy(buf, s);
	}
	String(const String& s)
	{
		strcpy(buf, s.buf);
	}
	String operator = (const String& s)
	{
		strcpy(buf, s.buf);
		return *this;
	}
	char& operator [] (int index)
	{
		if (index < size())
			return buf[index];
		cerr << "Index out of range." << endl;
		return buf[MAXLEN];
	}
	int size()
	{
		return strlen(buf);
	}
	String reverse()
		// does not modify this string
	{
		String result("");
		reverse_cpy(result.buf, buf);
		return result;
	}
	int indexOf(const char c)
	{
		char* pos = strchr(buf, c);
		if (pos == '\0') return -1;
		return pos - buf;
	}
	int indexOf(const String pattern)
	{
		char* pos = strstr(buf, pattern.buf);
		if (pos == '\0') return -1;
		return pos - buf;
	}
	bool operator == (const String s)
	{
		return strcmp(buf, s.buf) == 0;
	}
	bool operator != (const String s)
	{
		return strcmp(buf, s.buf) != 0;
	}
	bool operator > (const String s)
	{
		return strcmp(buf, s.buf) == 1;
	}
	bool operator < (const String s)
	{
		return strcmp(buf, s.buf) == -1;
	}
	bool operator <= (const String s)
	{
		return strcmp(buf, s.buf) != 1;
	}
	bool operator >= (const String s)
	{
		return strcmp(buf, s.buf) != -1;
	}
	/// concatenates this and s to return result
	String operator + (const String s)
	{
		if (strlen(s.buf) + strlen(buf) < MAXLEN)
		{
			String result("");
			int index = strlen(buf);
			strcpy(result.buf, buf);
			strcpy(result.buf + index, s.buf);
			return result;
		}
		cerr << "New String exceeds max length." << endl;
		return String("");
	}
	/// concatenates s onto end of this string
	String operator += (const String s)
	{
		if (strlen(s.buf)+strlen(buf) < MAXLEN)
		{
			strcpy(buf + strlen(buf), s.buf);
			return *this;
		}
		cerr << "New String exceeds max length." << endl;
		return String("");
	}
	void print(ostream& out)
	{
		out << buf;
	}
	void read(istream& in)
	{
		in.getline(buf, 128);
	}
	~String()
	{

	}
};
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