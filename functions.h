#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Table
{
	vector<int> x = { 0,0,0,0, 0,0,0,0, 1,1,1,1, 1,1,1,1 };
	vector<int> y = { 0,0,0,0, 1,1,1,1, 0,0,0,0, 1,1,1,1 };
	vector<int> z = { 0,0,1,1, 0,0,1,1, 0,0,1,1, 0,0,1,1 };
	vector<int> w = { 0,1,0,1, 0,1,0,1, 0,1,0,1, 0,1,0,1 };
	vector<int> f = { 1,1,0,0, 0,1,1,0, 0,1,0,1, 1,1,1,1 };
	vector<pair<string, int>> fBDR; // Вспомогательная функция для БДР
	vector<string> SDNFf;
	vector<string> boolSDNFf; // СДНФ в формате 0101, 1011 и т. д.
	vector<string> SKNFf; 
	vector<string> Poly;
	map<string, int> BDR{ {"000", 1}, {"001", 0}, {"0100", 0},
		{"0101", 1}, {"0110", 1}, {"0111", 0},
		{"1000", 0}, {"1001", 1}, {"1010", 0}, {"1011", 1}, {"11", 1}};
};

void PrintTable(Table* table);
int FindBDR(Table* table, string elem);
int FindTable(Table* table, string elem);

// п.2
void CalculateSDNFf(Table* table);
void PrintSDNFf(Table* table);
void CheckSDNFf(Table* table);
int FindSDNF(Table* table, string elem);

void CalculateSKNFf(Table* table);
void PrintSKNFf(Table* table);
void CheckSKNFf(Table* table);

// п.3
void CalculatePoly(Table* table);
void PrintPoly(Table* table);
int FindPoly(Table* table, string elem);

// Вспомогательные функции для БДР
void FillFuncBdr(Table* table);
void PrintBDR(Table* table);
void PrintFuncBDR(Table* table);
vector<pair<string, int>> CalculateBDR(vector<pair<string, int>>& func);
void FindShortestBDR(Table* table);
void generatePermutations(const std::vector<char>& variables, std::string current, std::vector<std::string>& result);
void ReorderFunc(Table* table, vector<pair<string, int>>& func, string order);
// ---------

void PrintElem(Table* table);
void InputProcessing(Table* tab, string str);