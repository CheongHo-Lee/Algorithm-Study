//���� 2581�� �Ҽ�
/**/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	string s;

	//�Ҽ�ã��

	int b; //������
	int count = 0; //������ 0�� ����
	int result = 0;

	//M���� N ���� �Ҽ� ã��
	for (int i = M; i < N + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			b = i % j;

			if (b == 0)
			{
				count++;
			}
		}

		//������ 0�� ������ 2�̸� �Ҽ�
		if (count == 2)
		{
			s = to_string(i);
		}

		count = 0; //�ʱ�ȭ
	}

	cout << s << "\n";

	return 0;
}
