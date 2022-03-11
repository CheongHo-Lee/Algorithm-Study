//���� 2178�� �̷� Ž��
/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 101

//intput
int n, m;
string map[MAX]; //���� ��� �׷���

//output
int cnt = 1;
vector<int> h;

//x�� �̵�, y�� �̵�
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void dfs(int x, int y) {
	cout << "x ��: " << x << ", y ��: " << y << "\n";

	if (x == n - 1 && y == m - 1) return;

	//�����¿�� �̵��ؼ� 1�� ���� ã��
	for (int i = 0; i < 4; i++) {
		int n_x = x + dx[i];
		int n_y = y + dy[i];

		//������ �Ѿ��
		if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;

		if (map[n_x][n_y] == '1') {
			cnt++;
			map[n_x][n_y] = '2'; //�湮 üũ
			cout << "n_x ��: " << n_x << ", n_y ��: " << n_y << "\n";
			dfs(n_x, n_y);
		}
	}
}

int main()
{
	cin >> n >> m;

	//���پ� �޾ƿ���
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	map[0][0] = '2'; //�湮üũ
	dfs(0, 0);

	cout << cnt << "\n";

	return 0;
}