#pragma once

#include <vector>

class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n, -1)
	{}

	//集合的合并
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2)//根相同，在一个集合
			return false;

		if (root1 > root2)
		{
			int tmp = root1;
			root1 = root2;
			root2 = tmp;
		}

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
		return true;
	}

	//找到集合的根
	int FindRoot(int x)
	{
		int root = x;
		while (_ufs[root] >= 0)
		{
			root = _ufs[root];
		}
		return root;
	}

	//bool InSet(int x1, int x2)
	//{
	//}

	//集合个数
	size_t SetSize()
	{
		size_t size = 0;
		for (size_t i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0)
			{
				++size;
			}
		}
		return size;
	}

private:
	std::vector<int> _ufs;
};
