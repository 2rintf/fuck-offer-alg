#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();

		for (int r = rows-1; r > -1; r--) {
			for (int c = 0; c < cols; c++) {
				int help = array[r][c];
				if (target > help) {
					continue;
				}
				else if (target < help) {
					break;
				}
				else if (target == help) {
					return true;
				}
				
			}
		}
		return false;
	}
};


int main() {
	Solution s;

	vector<int> rows(10);
	vector<vector<int>> array;
	int start = 1;
	int help = 1;
	int end = 11;
	for (int j = 0; j < 10;j++) {
		for (int i = start; i < end; i++)
		{
			rows[i - help] = i;
		}
		array.push_back(rows);
		start++;
		end++;
		help++;
	}

	bool isOK = s.Find(1, array);

	cout << isOK << endl;

	system("pause");
	
}