#include"String.h"

void test_constructors_and_print()
{
	cout << "\ntest_constructors_and_print begins: " << endl;
	//test 1
	String s("This is string s.");
	cout << s << endl;
	//test 2
	String t("This is string t.");
	cout << t << endl;
	//test 3
	String u("This is string u.");
	cout << u << endl;
}

void test_read()
{
	cout << "\ntest_read begins: " << endl;
	//test 1
	String s;
	cout << "Please input a string within 127 characters: " << endl;
	cin >> s;
	cout << "The string you've input is: " << s << endl;
	//test 2
	cout << "Please input a string within 127 characters: " << endl;
	cin >> s;
	cout << "The string you've input is: " << s << endl;
	//test 3
	String t;
	cout << "Please input a string within 127 characters: " << endl;
	cin >> t;
	cout << "The string you've input is: " << t << endl;
}

void test_assignment()
{
	cout << "\ntest_assignment begins: " << endl;
	//test 1
	cout << "test 1" << endl;
	String temp1;
	String to_be_assigned1("I'm a value to be assigned to temp in test 1.");
	temp1 = to_be_assigned1;
	cout << "After assignment the string is: " << temp1 << endl;
	//test 2
	cout << "test 2" << endl;
	String temp2;
	String to_be_assigned2("Oh no it's hard to think of a value for test 2.");
	temp2 = to_be_assigned2;
	cout << "After assignment the string is: " << temp2 << endl;
	//test 3
	cout << "test 3" << endl;
	String temp3;
	String to_be_assigned3("......Wordless for test 3.");
	temp3 = to_be_assigned3;
	cout << "After assignment the string is: " << temp3 << endl;
}

void test_relationals()
{
	cout << "\ntest_relationals begins: " << endl;
	//test 1
	cout << "test 1" << endl;
	String s1("abcdefg");
	String s2("abcdefg");
	cout << "test ==: " << (s1 == s2) << " (Should be 1)" << endl;
	//test 2
	cout << "test 2" << endl;
	String s3("a");
	String s4("abcdefg");
	cout << "test ==: " << (s3 == s4) << " (Should be 0)" << endl;
	//test 3
	cout << "test 3" << endl;
	String s5("   ");
	String s6(" ");
	cout << "test ==: " << (s5 == s6) << " (Should be 0)" << endl;
}

void test_reverse()
{
	cout << "\ntest_reverse begins: " << endl;
	//test 1
	cout << "test 1" << endl;
	String s1("Able was I ere I saw elba.");
	cout << "The original string is: " << s1 << endl;
	String s1r = s1.reverse();
	cout << "After reverse the string now is: " << s1r << endl;
	//test 2
	cout << "test 2" << endl;
	String s2("You shall not pass!!!");
	cout << "The original string is: " << s2 << endl;
	String s2r = s2.reverse();
	cout << "After reverse the string now is: " << s2r << endl;
	//test 3
	cout << "test 3" << endl;
	String s3("Just kidding");
	cout << "The original string is: " << s3 << endl;
	String s3r = s3.reverse();
	cout << "After reverse the string now is: " << s3r << endl;
}

void test_concatenation()
{
	cout << "\ntest_concatenation begins: " << endl;
	//test 1
	cout << "test 1" << endl;
	String s1("ICS");
	String s2(" ");
	String s3("45C");
	String result1 = s1 + s2 + s3;
	cout << "String combined using '+' is: " << result1 << endl;
	String result2("");
	result2 += s1;
	result2 += s2;
	result2 += s3;
	cout << "String combined using '+=' is: " << result2 << endl;
	//test 2
	cout << "test 2" << endl;
	String s4("Very ");
	String s5("interesting ");
	String s6("class");
	String result3 = s4 + s5 + s6;
	cout << "String combined using '+' is: " << result3 << endl;
	String result4("");
	result4 += s4;
	result4 += s5;
	result4 += s6;
	cout << "String combined using '+=' is: " << result4 << endl;
	//test 3
	cout << "test 3" << endl;
	String s7("For ");
	String s8("example ");
	String s9("hw3");
	String result5 = s7 + s8 + s9;
	cout << "String combined using '+' is: " << result5 << endl;
	String result6("");
	result6 += s7;
	result6 += s8;
	result6 += s9;
	cout << "String combined using '+=' is: " << result6 << endl;
}

void test_index_of()
{
	cout << "\ntest_index_of begins: " << endl;
	//test 1
	cout << "test 1" << endl;
	char pattern1('S');
	String s1("Write a String class which will be a wrapper class to the C style strings.");
	cout << "The index of \"" << pattern1 << "\" in \"" << s1 << "\" is: " << s1.indexOf(pattern1) << endl;
	//test 2
	cout << "test 2" << endl;
	char pattern2('a');
	String s2("acabcacab");
	cout << "The index of \"" << pattern2 << "\" in \"" << s2 << "\" is: " << s2.indexOf(pattern2) << endl;
	//test 3
	cout << "test 3" << endl;
	char pattern3('\0');
	String s3("hello");
	cout << "The index of \"" << pattern3 << "\" in \"" << s3 << "\" is: " << s3.indexOf(pattern3) << endl;
}

void test_brackets()
{
	cout << "\ntest_brackets begins: " << endl;
	//test 1
	cout << "test 1" << endl;
	String pattern1("String");
	cout << "The character in \"" << pattern1 << "\" with index 1 (zero-index base) is: " << pattern1[1] << endl;
	//test 2
	cout << "test 2" << endl;
	String pattern2("Yohohoho");
	cout << "The character in \"" << pattern2 << "\" with index 2 (zero-index base) is: " << pattern2[2] << endl;
	//test 3
	cout << "test 3" << endl;
	String pattern3("123456789");
	cout << "The character in \"" << pattern3 << "\" with index 3 (zero-index base) is: " << pattern3[3] << endl;
}

int main()
{
	{
		test_constructors_and_print();
		test_read();
		test_assignment();
		test_relationals();
		test_reverse();
		test_concatenation();
		test_index_of();
		test_brackets();
	}
	cout << endl;
	return 0;
}
