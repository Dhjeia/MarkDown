#include <iostream>
#include <vector>

using namespace std;

const int maxn = 15;

bool Graph[maxn][maxn] = { false };	
bool vis[maxn] = { false };			

int n, e;							
int s;		

vector<int>path;					
int cnt = 0;						

void dfs(int v, int length)
{
	if (length == n && v == s)
	{
		cnt++;
		cout << "Path " << cnt << ":";
		for (int x : path)
		{
			cout << " " << x;
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && Graph[v][i])
		{
			vis[i] = true;
			path.push_back(i);
			dfs(i, length+1);
			path.pop_back();
			vis[i] = false;
		}
	}
}

int main()
{
	cin >> n >> e;
	while (e--)
	{
		int v1, v2;
		cin >> v1 >> v2;
		Graph[v1][v2] = Graph[v2][v1] = true;
	}
	cin >> s;
	path.push_back(s);

	dfs(s, 0);

	return 0;
}
