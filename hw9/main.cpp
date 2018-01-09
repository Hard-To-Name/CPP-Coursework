#include<algorithm>
#include<fstream>
#include<iostream>
#include"MapArray.h"
#include"SetList.h"
#include<string>
#include<vector>

int main()
{
	ifstream stopwords("stopwords.txt");
	SetList<string> words;
	for_each(istream_iterator<string>(stopwords),
		istream_iterator<string>(),
		[&](string s) {words.insert(s); });

	ifstream sample_doc("sample_doc.txt");
	SetList<string> contexts;
	MapArray<string,int> frequencies;
	for_each(istream_iterator<string>(sample_doc),
		istream_iterator<string>(),
		[&](string s) 
		{transform(s.begin(), s.end(), s.begin(), ::tolower);
		contexts.insert(s); });
	for_each(contexts.begin(), contexts.end(),
		[&](ListNode<string> s)
	{if (words.find(s.info) == words.end())
	++(frequencies[s.info]); });
	frequencies.sort();

	ofstream frequency("frequency.txt");
	for_each(frequencies.begin(), frequencies.end(),
		[&](pair<string, int>* p) 
	{frequency << (*p).first << " " << (*p).second << endl; });
	return 0;
}