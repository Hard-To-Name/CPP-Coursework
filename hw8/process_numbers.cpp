#include<algorithm>
#include<fstream>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
	ifstream rand_numbers("rand_numbers.txt");
	vector<int> nums;
	copy(istream_iterator<int>(rand_numbers),
		istream_iterator<int>(),
		back_inserter(nums));
	sort(nums.begin(), nums.end());
	ofstream odd("odd.txt");
	ofstream even("even.txt");
	copy_if(nums.begin(), nums.end(),
		ostream_iterator<int>(even, "\n"),
		[](int num) {return num % 2 == 0; });
	copy_if(nums.begin(), nums.end(),
		ostream_iterator<int>(odd, " "),
		[](int num) {return num % 2 != 0; });
	return 0;
}