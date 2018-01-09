#include<algorithm>
#include<fstream>
#include<iostream>
#include<iterator>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;

vector<string> temp;

int main()
{
	ifstream stopwords("stopwords.txt");
	set<string> words;
	copy(istream_iterator<string>(stopwords),
		istream_iterator<string>(),/*
		back_inserter(temp));
	for_each(temp.begin(), temp.end(), [&](string &s)
		{transform(s.begin(), s.end(), s.begin(), ::tolower); });
	copy(temp.begin(), temp.end(),*/
		inserter(words, begin(words)));

	ifstream sample_doc("sample_doc.txt");
	temp.clear();
	for_each(istream_iterator<string>(sample_doc),
		istream_iterator<string>(),
		[](const string s) {temp.push_back(s); });
	for_each(temp.begin(), temp.end(), [&](string &s)
		{transform(s.begin(), s.end(), s.begin(), ::tolower); });
	map<string,int> frequencies;
	for_each(temp.begin(), temp.end(),
		[&](const string &s)
		{if(words.find(s) == words.end())
			++frequencies[s]; });

	/*sort(begin(frequencies), end(frequencies),
		[](const map<string, int> &a, const map<string, int> &b)
		{return a.first > b.first});*/
	temp.clear();
	for_each(begin(frequencies), end(frequencies),
		[](const pair<string,int> s) 
		{int sec = s.second; temp.push_back(s.first + " " + to_string(sec)); });
	ofstream frequency("frequency.txt");
	copy(temp.begin(), temp.end(),
		ostream_iterator<string>(frequency, "\n"));
	return 0;
}