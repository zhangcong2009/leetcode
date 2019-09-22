// leetcode.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include "string.h"

#include <iostream>

#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

#include "stdlib.h"
#include "stdio.h"

using iter_t=vector<int>;
class Node_t;
class SplitBranch
{
public:
	Node_t* pNode;
	int time;
};
class WorkBranch
{
public:
	Node_t* pNode;
	int time;
};

class Node_t
{
public:
	iter_t st;
	iter_t end;
	size_t size;
	int time = -1;
	
	bool finished = 0;

	SplitBranch* pSplit;
	WorkBranch* pWork;
};


int minTime(vector<int>& blocks, int split, int cntWorker)
{
	if (blocks.size() == 0)
	{
		return 0;
	}
	if (cntWorker >= blocks.size())
	{
		return blocks.back();
	}
	if (cntWorker == 1)
	{
		return split + minTime(blocks, split, 2);
	}
	
	vector<int>::iterator iterEnd(blocks.end());
	iterEnd--;
	vector<int> blocksNext(blocks.begin(), iterEnd);

	return std::min(split + minTime(blocks, split, 2 * cntWorker), 
		std::max(blocks.back(), minTime(blocksNext, split, cntWorker - 1)));

}


class Solution {
public:
	int minBuildTime(vector<int>& blocks, int split) {
		sort(blocks.begin(), blocks.end());
		return minTime(blocks, split, 1);
	}
};


int main(int argc, char* argv[])
{

	Solution s;
	vector<int> input({1,2});
	auto ret = s.minBuildTime(input, 1);
	cout << ret << endl;



	return 0;
}

