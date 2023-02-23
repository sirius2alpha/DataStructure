#include"word.h"

int main() {
	ifstream infile;
	infile.open("news2.txt");
	char temp[20];
	word obwords[100];
	int i = 0;

	if (!infile)
	{
		cout << "无法打开文件" << endl;
		exit(1);
	}

	//目标单词读入部分
	while (infile.peek()!='*')
	{
		infile.getline(temp, 10, ' ');
		obwords[i].wordin(i, temp);
		i++;
	}

	//新闻材料读入并开始匹配
	int line = 3;
	while (!infile.eof()) 
	{
		//记录第几行
		if (infile.peek() == '\n') 
		{
			infile.get();
			line++;
		}

		//单词匹配部分
		infile.getline(temp, 20, ' ');
		for (int j = 0; j < i; j++)
		{
			if (obwords[j].match(temp))//如果匹配成功，进行记录，然后跳出剩下单词的匹配
			{
				obwords[j].FoundOne(line);
				break;
			}

		}

	}

	for (int j = 0; j < i; j++) {
		obwords[j].Show();
	}

	infile.close();
	return 0;
}

