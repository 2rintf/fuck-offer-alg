# �ַ����滻�ո�  
**��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��**  
�����ĺ���`void replaceSpace(char *str, int length)`  
  
---  

˼��:  
1. �����Ŀ�е�length���˴����裬���������lengthָ����str��ָ�ַ������length������ָ�ַ�������
2. str�ı߽����⡣����`%20`�������ַ���ȻҪ���ơ�
3. �������⡣����ʱ��ô���ַ�����Ч?--> �Ӻ��濪ʼ���������������ո������ƶ��ַ�ʱ���ܴ������ڴ�ǰ�����ʱ�������

---
���룺  
���������  
```C
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spaceNum = 0;
		int charNum = 0;
		int newLength;
		int moveSteps;

		// �ȱ���������ո������ַ���
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

		newLength = charNum + 2 * spaceNum;// �滻�ַ�����ַ�������
		moveSteps = 2 * spaceNum;// ��ʼ�ַ��ƶ�λ��

		// ��ֹ����ԭ�ַ�����С�����
		if (newLength>length)
		{
			cout << "over" << endl;
			return;
		}

		for (int i = length-1; i > -1; i-- )
		{
			// �滻�ַ�
			if (str[i]==' ')
			{
				str[i + moveSteps - 2] = '%';
				str[i + moveSteps - 1] = '2';
				str[i + moveSteps] = '0';
				
				moveSteps -= 2;
			}
			// ������\0�����Է�ֹ���
			else if (str[i] == '\0') 
			{
				continue;
			}
			// �ƶ��ǿո��ַ�
			else
			{
				str[i + moveSteps] = str[i];
			}
		}

	}
};
```
��ʹ�ñ�׼��`std::string`������  
```C

```