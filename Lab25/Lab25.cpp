#include<iostream>
#include<fstream>
#include <algorithm>
#include<sstream>
#include<vector>

using namespace std;

using namespace std;

void zd1() {

	ifstream file_work ("zd1.txt");

	string s;
	string ans = "";
	
	getline(file_work, s);
	
	ofstream file_ans("zd1.txt");

	int ind = 0;

	file_work.close();

	for (int i = 0; i < s.size() ; i++) {

		if (s[i] == ' ') {
			ind = i;
			break;
		}

	}

	for (int i = ind + 1; i < s.size(); i++) {

		ans += s[i];

	}

	file_ans << ans;
	file_ans.close();
	return;
}

void zd2() {

	cout << "Enter name the file and n and k : ";
	string s;
	int n, k;

	cin >> s >> n >> k;

	s += ".txt";

	ofstream file;

	file.open(s);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < k; j++) {
			file << "*";
		}
		file << "\n";

	}
	file.close();
	return;
}

void zd3() {

	ifstream file1("zd3_1.txt");
	ifstream file2("zd3_2.txt");


	vector <string> v;
	string s;

	while (getline(file1, s)) {
		v.push_back(s);
	}

	file1.close();
	ofstream file1_ans("zd3_1.txt");

	while (getline(file2, s)) {

		file1_ans << s << endl;

	}

	for (int i = 0; i < v.size(); i++) {
		file1_ans << v[i] << endl;
	}

	file1_ans.close();
	file2.close();
	return;
}

void zd4() {

	ifstream file("zd4.txt");
	string s;
	string ans_s = "";
	vector<string> ans;

	while (getline(file, s)) {

		bool flag = true;

		for (int i = 0; i < s.size(); i++) {

			if (s[i] != ' ') {

				flag = true;
				ans_s += s[i];

			}
			else {

				if (flag) {
					ans_s += s[i];
					flag = false;
				}
				else
					continue;

			}

		}
		ans.push_back(ans_s);
		ans_s = "";
	}

	file.close();
	ofstream file_ans("zd4.txt");

	for (int i = 0; i < ans.size(); i++) {
		file_ans << ans[i] << endl;
	}

	file_ans.close();
	return;
}

void zd5() {

	ifstream file("zd5.txt");

	int cnt = 0 , ans = 0;
	string s;

	while (getline(file, s)) {

		if (s.size() != 0) {
			
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == ' ') {
					cnt++;
				}
				if (s[i] != ' ')
					break;
			}

			if (cnt == 5) {
				ans++;
			}
			cnt = 0;
		}

	}

	cout << "Count paragraphs : " << ans << endl;

}

int main() {

	int t = 0;

	while (true) {

		cout << "Enter number job or 0 for exit : ";
		cin >> t;

		switch (t)
		{
		case 1: {
			zd1();
			break;
		}
		case 2: {
			zd2();
			break;
		}
		case 3: {
			zd3();
			break;
		}
		case 4: {
			zd4();
			break;
		}
		case 5: {
			zd5();
			break;
		}
		case 0: {
			return 0;
		}
		default:
			cout << "Warning: enter new command." << endl;
			break;
		}

	}

}