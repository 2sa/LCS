#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int> > d;
	string a, b;

	cin >> a >> b;

	for (int i = 0; i < a.length(); ++i)
	{
		d.push_back(vector<int>(b.length(), 0));
	}
	
	for (int i = 0; i < a.length(); ++i)
	{
		for (int j = 0; j < b.length(); ++j)
		{
			if (a[i] == b[j])
			{
				if (i > 0 && j > 0)
				{
					d[i][j] = d[i - 1][j - 1] + 1;
				}
				else
				{
					d[i][j] = 1;
				}
			}
			else
			{
				if (i > 0 && j > 0)
				{
					d[i][j] = max(d[i - 1][j], d[i][j - 1]);
				}
				else
				{
					if (i == 0 && j > 0)
					{
						d[i][j] = d[i][j - 1];
					}

					if (j == 0 && i > 0)
					{
						d[i][j] = d[i - 1][j];
					}
				}
			}
		}
	}

	std::cout << d[a.length() - 1][b.length() - 1];

	return 0;
}
