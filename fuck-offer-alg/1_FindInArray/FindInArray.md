# ��ά�������
**��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������**  

---

˼����
1. ���½ǿ�ʼ����target��������ֵ�����ƣ���С�ڣ����ơ���Z��Ѱ�ҡ�

---  
���룺  
```C
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
```  
�������ÿһ�У�ʹ�ö��ַ������Ӷ�Ϊ`nlogn`��