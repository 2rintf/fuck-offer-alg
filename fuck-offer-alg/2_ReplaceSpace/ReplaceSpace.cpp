#pragma warning(disable:4996)
#include <stdlib.h>
#include <iostream>

#include <string>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spaceNum = 0;
		int charNum = 0;
		int newLength;
		int moveSteps;

		for (int i = 0; i < length; i++)
		{
			if (*(str+i)==' ')
			{
				spaceNum++;
			}
			if (*(str + i) == '\0')
			{
				continue;
			}

			charNum++;
		}

		newLength = charNum + 2 * spaceNum;
		moveSteps = 2 * spaceNum;

		if (newLength>length)
		{
			// 防止超出原字符串大小，溢出

			cout << "over" << endl;
			return;
		}

		for (int i = length-1; i > -1; i-- )
		{
			if (str[i]==' ')
			{
				str[i + moveSteps - 2] = '%';
				str[i + moveSteps - 1] = '2';
				str[i + moveSteps] = '0';
				
				moveSteps -= 2;
			}
			else if (str[i] == '\0') 
			{
				continue;
			}
			else
			{
				str[i + moveSteps] = str[i];
			}
		}

	}
};

class Solution2 {
public:
	void replaceSpace(char *str, int length) {
		string s(str);
		int i = 0;
		while ((i = s.find(' ', i)) > -1) {
			s.erase(i, 1);
			s.insert(i, "%20");

		}
		auto ret = s.c_str();
		strcpy(str, ret);
	}
};

int main()
{
	char str[30] = "We Are Happy.";
	char help[30] = "helloworld";

	int i;

	std::string x = "posts & telecom press";
	cout << x.max_size() << endl;
	cout << (int)(string::basic_string::npos)<< endl;
	cout << x.find('t', 4) << endl;

	// find --> 返回第一个匹配到的字符的位置

	//Solution s;
	//s.replaceSpace(help, 30);

	Solution2 s2;
	s2.replaceSpace(help, 30);
	

	for (auto i : help)
	{
		cout << i;
	}
	cout << endl;

	for (auto i : str)
	{
		cout << i;
	}


	system("pause");

	return 0;
}