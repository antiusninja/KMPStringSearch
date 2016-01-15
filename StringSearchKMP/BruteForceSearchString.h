#pragma once
#include <vector>
#include <string>
using namespace std;

vector<unsigned> BruteForceStringSearch(const string& buffer, const string& pattern) {
	vector<unsigned> result;
	unsigned bufferLength = buffer.length();
	unsigned patternLength = pattern.length();
	for (unsigned i = 0; i < bufferLength; ++i)
	{
		bool found = true;
		for (unsigned j = 0; j < patternLength; ++j) {
			if (buffer[i + j] != pattern[j])
			{
				found = false;
				break;
			}
		}
		if (found) {
			result.push_back(i);
		}
	}
	return result;
}
