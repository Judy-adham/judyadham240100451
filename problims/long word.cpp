

//6 way to long words
#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		string word;
		cin >> word;
		int x = word.size();
		if (x > 10)
			cout << word[0] << x - 2 << word[x - 1] << endl;
		else
			cout << word << endl;
	}

	return 0;
}














