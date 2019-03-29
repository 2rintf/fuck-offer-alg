#include <stdlib.h>
#include <iostream>

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

int main()
{
	char str[] = "We Are Happy.";
	char help[14] = " helloworld";

	Solution s;
	s.replaceSpace(help, 14);
	

	for (auto i : help)
	{
		cout << i;
	}



	system("pause");

	return 0;
}