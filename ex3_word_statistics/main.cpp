#include"word.h"

int main() {
	ifstream infile;
	infile.open("news2.txt");
	char temp[20];
	word obwords[100];
	int i = 0;

	if (!infile)
	{
		cout << "�޷����ļ�" << endl;
		exit(1);
	}

	//Ŀ�굥�ʶ��벿��
	while (infile.peek()!='*')
	{
		infile.getline(temp, 10, ' ');
		obwords[i].wordin(i, temp);
		i++;
	}

	//���Ų��϶��벢��ʼƥ��
	int line = 3;
	while (!infile.eof()) 
	{
		//��¼�ڼ���
		if (infile.peek() == '\n') 
		{
			infile.get();
			line++;
		}

		//����ƥ�䲿��
		infile.getline(temp, 20, ' ');
		for (int j = 0; j < i; j++)
		{
			if (obwords[j].match(temp))//���ƥ��ɹ������м�¼��Ȼ������ʣ�µ��ʵ�ƥ��
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

