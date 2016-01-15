#include <Windows.h>
#include <iostream>
#include <chrono>
#include "BruteForceSearchString.h"
#include "KMPStringSearch.h"
#include <functional>
using namespace std;


using StringSearchFunction = function<vector<unsigned>(const string&, const string&)>;
vector<unsigned> ExecuteAndMeasure(StringSearchFunction func,const string& buffer,const string& pattern,const char* functionName) {
	auto t0 = std::chrono::high_resolution_clock::now();
	auto result = func(buffer, pattern);
	auto t1 = std::chrono::high_resolution_clock::now();
	auto dtMili = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
	std::cout << functionName<< "\n\tfound:" << result.size() << "\n\ttime" << dtMili << "\n";
	return result;
}


void RunTests(const string& buffer,const string& pattern)
{
	auto result = KMPStringSearch(buffer, pattern);
	


	t0 = std::chrono::high_resolution_clock::now();
	auto result2 = BruteForceStringSearch(buffer, pattern);
	t1 = std::chrono::high_resolution_clock::now();
	dtMili = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
	std::cout << "Brute - found:" << result.size() << "\n\ttime" << dtMili << "\n";
}

void TestWorstCaseForBrute() {
	string pattern{ "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac" };
	string buffer;
	for (int i = 0; i < 1000000; ++i) {
		//int rand = i % 30;
		buffer += pattern;
	}
	cout << "WorstCaseForBrute:\n";
	RunTests(buffer, pattern);
}


void TestOrdinaryText() {
	string pattern{ "In computing the Process Environment Block is a data structure in the Windows NT operating system family.It is an opaque data structure that is used by the operating system internally, most of whose fields are not intended for use by anything other than the operating system.in its MSDN Library documentation — which documents only a few of the fields — that the structure [2] The PEB contains data structures that apply across a whole process, including global context, startup parameters, data structures for the program image loader, the program image base address, and synchronization objects used to provide mutual exclusion for process - wide data structures" };
	string buffer;
	for (int i = 0; i < 1000000; ++i) {
		int rand = i % 30;
		buffer += pattern + to_string(rand);
	}
	pattern = "data structure";
	cout << "NonBranchPrediction:\n";
	RunTests(buffer, pattern);
}


int main(int argc, char**argv) {
	TestWorstCaseForBrute();
	TestOrdinaryText();
	int x = 0;
	std::cin >> x;
	return 0;
}