#include "functions.h"

void PrintTable(Table* table)
{
	cout << "x" << " " << "y" << " " << "z" << " "
		<< "w" << " | " << "f" << endl;
	cout << "--------|---" << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << table->x[i] << " " << table->y[i] << " " <<
			table->z[i] << " "
			<< table->w[i] << " | " << table->f[i] << endl;
	}
}

int FindTable(Table* table, string elem) {
	for (int ind = 0; ind < table->f.size(); ind++)
	{
		if (elem[0] == to_string(table->x[ind])[0] and
			elem[1] == to_string(table->y[ind])[0] and
			elem[2] == to_string(table->z[ind])[0] and
			elem[3] == to_string(table->w[ind])[0])
		{
			return table->f[ind];
		}
	}
	return -1;
}

void CalculateSDNFf(Table* table)
{
	for (int i = 0; i < 16; i++)
	{
		string tmp = "";
		if (table->f[i] == 1)
		{
			tmp += (table->x[i] == 1) ? "x" : "~x";
			tmp += (table->y[i] == 1) ? "y" : "~y";
			tmp += (table->z[i] == 1) ? "z" : "~z";
			tmp += (table->w[i] == 1) ? "w" : "~w";
			table->SDNFf.push_back(tmp);
			table->boolSDNFf.push_back(to_string(table->x[i]) +
				to_string(table->y[i]) +
				to_string(table->z[i]) + to_string(table->w[i]));
		}
	}
}

void PrintSDNFf(Table* table)
{
	for (int i = 0; i < table->SDNFf.size(); i++)
	{
		if (i != table->SDNFf.size() - 1)
		{
			cout << table->SDNFf[i] << " V ";
		}
		else
		{
			cout << table->SDNFf[i];
		}

	}

	cout << endl;
	for (int i = 0; i < table->boolSDNFf.size(); i++)
	{
		if (i != table->boolSDNFf.size() - 1)
		{
			cout << table->boolSDNFf[i] << " V ";
		}
		else
		{
			cout << table->boolSDNFf[i];
		}

	}
	cout << endl;
}

void CheckSDNFf(Table* table)
{
	vector<int> res;
	vector<string> tmd;
	int index = 0;
	for (int i = 0; i < 16; i++)
	{
		string tmp = "";
		tmp += (table->x[i] == 1) ? "x" : "~x";
		tmp += (table->y[i] == 1) ? "y" : "~y";
		tmp += (table->z[i] == 1) ? "z" : "~z";
		tmp += (table->w[i] == 1) ? "w" : "~w";
		tmd.push_back(tmp);
	}
	cout << "f" << " | " << "���� f" << endl;
	cout << "--|-------" << endl;
	for (int i = 0; i < 16; i++)
	{
		if (tmd[i] == table->SDNFf[index])
		{
			index += 1;
			res.push_back(1);
		}
		else
		{
			res.push_back(0);
		}
		cout << table->f[i] << " |   " << res[i] << endl;
	}
	if (table->f == res) { cout << "���� f ��������� �����." << endl; }
	else { cout << "������ ���������� ���� f." << endl; }
}

int FindSDNF(Table* table, string elem) {
	// ���������� �������� ����
	for (const auto item : table->boolSDNFf) {
		if (item == elem) {
			return 1;
		}
	}
	return 0;
}

void CalculateSKNFf(Table* table)
{
	for (int i = 0; i < 16; i++)
	{
		string tmp = "";
		if (table->f[i] == 0)
		{
			tmp += (table->x[i] == 1) ? "~xV" : "xV";
			tmp += (table->y[i] == 1) ? "~yV" : "yV";
			tmp += (table->z[i] == 1) ? "~zV" : "zV";
			tmp += (table->w[i] == 1) ? "~w" : "w";
			table->SKNFf.push_back(tmp);
		}
	}
}

void PrintSKNFf(Table* table)
{
	for (int i = 0; i < table->SKNFf.size(); i++)
	{
		if (i != table->SKNFf.size() - 1)
		{
			cout << table->SKNFf[i] << " /\\ ";
		}
		else
		{
			cout << table->SKNFf[i];
		}

	}
	cout << endl;
}

void CheckSKNFf(Table* table)
{
	vector<int> res;
	vector<string> tmd;
	int index = 0;
	for (int i = 0; i < 16; i++)
	{
		string tmp = "";
		if (table->f[i] == 0)
		{
			tmp += (table->x[i] == 1) ? "~xV" : "xV";
			tmp += (table->y[i] == 1) ? "~yV" : "yV";
			tmp += (table->z[i] == 1) ? "~zV" : "zV";
			tmp += (table->w[i] == 1) ? "~w" : "w";
		}
		else {
			tmp += "xyzw";
			
		}
		tmd.push_back(tmp);
	}
	cout << "f" << " | " << "���� f" << endl;
	cout << "--|-------" << endl;
	for (int i = 0; i < 16; i++)
	{
		if (tmd[i] == "xyzw") {
			res.push_back(1);
		}
		else if (tmd[i] == table->SKNFf[index])
		{
			index += 1;
			res.push_back(0);
		}
		cout << table->f[i] << " |   " << res[i] << endl;
	}
	if (table->f == res) { cout << "���� f ��������� �����." << endl; }
	else { cout << "������ ���������� ���� f." << endl; }
}

void CalculatePoly(Table* table)
{
	// ������ �������������
	vector<int> coeffs;
	coeffs.push_back(table->f[0]);
	// ������ � ������ �������������
	vector<int> tmp1 = table->f;
	vector<int> tmp2;

	while (true) {
		int i = 0;
		while (i < (tmp1.size() - 1)) {
			tmp2.push_back(tmp1[i] ^ tmp1[i + 1]);
			i++;
		}
		coeffs.push_back(tmp2[0]);

		if (tmp2.size() == 1) {
			break;
		}
		tmp1 = tmp2;
		tmp2.clear();
	}

	for (int i = 0; i < 16; i++) {
		if (coeffs[i]) {
			string tmp;
			tmp += (table->x[i] == 1) ? "x" : "";
			tmp += (table->y[i] == 1) ? "y" : "";
			tmp += (table->z[i] == 1) ? "z" : "";
			tmp += (table->w[i] == 1) ? "w" : "";
			if (tmp == "") {
				tmp = "1";
			}
			table->Poly.push_back(tmp);
		}
	}
}

void PrintPoly(Table* table)
{

	for (int i = 0; i < table->Poly.size(); i++)
	{
		if (i != table->Poly.size() - 1)
		{
			cout << table->Poly[i] << " + ";
		}
		else
		{
			cout << table->Poly[i];
		}

	}
	cout << endl;
}

int FindPoly(Table* table, string elem) {
	vector<int> sum;
	for (string item : table->Poly) {
		for (int i = 0; i < item.length(); i++) {
			if (item[i] == 'x') {
				item[i] = elem[0];
			}
			else if (item[i] == 'y') {
				item[i] = elem[1];
			}
			else if (item[i] == 'z') {
				item[i] = elem[2];
			}
			else if (item[i] == 'w') {
				item[i] = elem[3];
			}
		}
		int conj = 1;
		for (int i = 0; i < item.length(); i++) {
			conj *= (item[i] - '0');
		}
		sum.push_back(conj);
	}
	int summary = 0;
	for (int item : sum) {
		summary ^= item;
	}
	return summary;
}


void FillFuncBdr(Table* table) {
	for (int i = 0; i < table->f.size(); i++) {
		string tmp;
		tmp += (table->x[i] == 1) ? "1" : "0";
		tmp += (table->y[i] == 1) ? "1" : "0";
		tmp += (table->z[i] == 1) ? "1" : "0";
		tmp += (table->w[i] == 1) ? "1" : "0";

		table->fBDR.push_back({ tmp, table->f[i] });
	}
}


vector<pair<string, int>> CalculateBDR(vector<pair<string, int>>& func) {
	while (true) {
		vector<pair<string, int>> solutions_tree;
		int counter = 0;
		for (int i = 0; i < func.size(); i += 2) {
			string str1 = func[i].first;
			string str2;
			if (i + 1 < func.size()) {
				str2 = func[i + 1].first;
			}
			else {
				solutions_tree.push_back({ str1, func[i].second });
				break;
			}

			if (func[i].second == func[i + 1].second and
				func[i].first.length() == func[i+1].first.length()) {
				int j = 0;
				for (j; j < min(str1.size(), str2.size()); j++) {
					if (str1[j] != str2[j]) {
						break;
					}
				}
				counter += 1;
				str1 = str1.substr(0, j);
				solutions_tree.push_back({ str1, func[i].second });
				continue;
			}
			solutions_tree.push_back({ str1, func[i].second });
			solutions_tree.push_back({ str2, func[i + 1].second });
		}

		if (counter == 0) {
			return solutions_tree;
		}

		func = solutions_tree;
	}
}





void generatePermutations(const std::vector<char>& variables, std::string current,
	std::vector<std::string>& result) {
	if (current.size() == variables.size()) {
		result.push_back(current);
		return;
	}

	for (char var : variables) {
		if (current.find(var) == std::string::npos) {
			generatePermutations(variables, current + var, result);
		}
	}
}
void ReorderFunc(Table* table, vector<pair<string, int>>& func, string order) {
	func.clear();
	for (int i = 0; i < table->f.size(); i++) {
		string tmp;
		for (char var : order) {
			switch (var) {
			case 'x':
				tmp += (table->x[i] == 1) ? '1' : '0';
				break;
			case 'y':
				tmp += (table->y[i] == 1) ? '1' : '0';
				break;
			case 'z':
				tmp += (table->z[i] == 1) ? '1' : '0';
				break;
			case 'w':
				tmp += (table->w[i] == 1) ? '1' : '0';
				break;
			}
		}
		func.push_back({ tmp, table->f[i] });
	}

	// ���������� ������� func �� ������� �������� ���� (������)
	sort(func.begin(), func.end());
}

void FindShortestBDR(Table* table) {
	std::vector<char> variables = { 'x', 'y', 'z', 'w' };
	vector<pair<string, int>> func = table->fBDR;
	vector<pair<string, int>> fMIN;
	int sizeMIN = 10000000;
	string orderMIN;
	vector<string> orders;

	generatePermutations(variables, "", orders);

	for (const auto order : orders) {
		ReorderFunc(table, func, order);
		func = CalculateBDR(func);
		if (func.size() < sizeMIN) {
			sizeMIN = func.size();
			fMIN = func;
			orderMIN = order;
		}
	}
	
	cout << "����������� �������: " << orderMIN << endl;
	cout << "���������� ��� � �������� " << orderMIN << ":" << endl;
 	for (const auto& order : fMIN) {
		cout << order.first << " " << order.second << endl;
	}
}

void PrintFuncBDR(Table* table) {

	for (auto it : table->fBDR) {
		cout << it.first << " " << it.second << endl;
	}
}

void PrintBDR(Table* table)
{
	vector<int> tmd;
	cout << "f" << " | " << "��� f" << endl;
	cout << "--|------" << endl;
	for (auto item : table->BDR)
	{
		for (int i = 0; i < pow(2, 4 - item.first.size()); i++)
		{
			tmd.push_back(item.second);
		}
	}
	for (int i = 0; i < 16; i++)
	{
		cout << table->f[i] << " |  " << tmd[i] << '\n';
	}
}

int FindBDR(Table* table, string elem) {
	// ���������� �������� ���
	for (const auto item: table->BDR) {
		string str = item.first;
		bool flag = true;
		if (str.length() <= elem.length()) {
			int size = str.length();
			// ���������� ����������
			for (int j = 0; j < size; j++) {
				if (elem[j] != str[j]) {
					// ���������� �� ���������
					flag = false;
					break;
				}
			}
			// ���������� �� ���������
			if (!flag) {
				continue;
			}

			if (flag) {
				return item.second;
			}
		}
	}
	return -1; // �������� ���
}



void PrintElem(Table* table)
{
	string element;
	while (true)
	{
		string str;
		cout << "������� �������� ������������� �������� ��� ������������: ";
		cin >> str;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		bool fl = 1;
		if (str.size() != 4)
		{
			cout << "������ �����: ����� ����� ������ ���� ����� 4." << '\n';
			fl = 0;
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '0' and str[i] != '1')
			{
				cout << "������ �����: �������� �������� ���������� ��" <<
					"����������� ���������{0; 1}." << '\n';
				fl = 0;
				break;
			}
		}
		if (fl)
		{
			element = str;
			break;
		}
	}

	cout << "���������:" << endl;
	cout << "x y z w" << " | " << "f" << " | " << "���� f" << " | " << "���"
		<< " | "  << "�������" << endl;
	cout << "--------|---|--------|-----|---------" << endl;
	cout << element[0] << " " << element[1] << " " << element[2] << " "
		<< element[3] << " | " << FindTable(table, element) << " |   " << 
		FindSDNF(table, element)
		<< "    |  " << FindBDR(table, element) << "  |  " 
		<<FindPoly(table, element) <<endl;
}


void InputProcessing(Table* tab, string str)
{
	if (str[0] == '1' and str.size() == 1)
	{
		cout << "������� ���������� ��� �������� �������:" << endl;
		PrintTable(tab);
		cout << endl;
	}
	else if (str[0] == '2' and str.size() == 1)
	{
		cout << "���� ��� �������� �������:" << endl;
		PrintSDNFf(tab);
		cout << endl;
		cout << "�������� ���������� ���� f:" << endl;
		CheckSDNFf(tab);
		cout << endl;
	}
	else if (str[0] == '3' and str.size() == 1)
	{
		cout << "���� ��� �������� �������:" << endl;
		PrintSKNFf(tab);
		cout << endl;
		cout << "�������� ���������� ���� f:" << endl;
		CheckSKNFf(tab);
		cout << endl;
	}
	else if (str[0] == '4' and str.size() == 1)
	{
		cout << "������� ��������� ��� �������� �������:" << endl;
		PrintPoly(tab);
		cout << endl;
	}
	else if (str[0] == '5' and str.size() == 1)
	{
		cout << "��� ��� �������� �������:" << endl;
		PrintBDR(tab);
		cout << endl;
	}
	else if (str[0] == '6' and str.size() == 1)
	{
		cout << "����������� ���:" << endl;
		FindShortestBDR(tab);
		cout << endl;
	}
	else if (str[0] == '7' and str.size() == 1)
	{
		PrintElem(tab);
		cout << endl;
	}
	else
	{
		cout << "������ �����, ��������� �������" << endl;
	}
}
