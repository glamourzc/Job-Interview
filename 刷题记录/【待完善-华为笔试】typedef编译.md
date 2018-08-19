```c++
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>
using namespace std;
vector<string> split(string str){
	vector<string> res;
	string tmp = "";
	for (auto c : str){
		if (c != ' ' && c != ';')tmp += c;
		else{
			res.push_back(tmp);
			tmp = "";
		}
	}
	if (tmp != "")res.push_back(tmp);
	return res;
}
int main()
{
	string str,tofind;
	getline(cin,str);
	cin >> tofind;
	vector<string> s = split(str);
	map<string, string> m;
	stack<string> ready;
	for (auto i : s){
		if (i == "typedef"){
			string tmpkey, tmpvalue = "";
			if (!ready.empty()){
				tmpkey = ready.top();
				ready.pop();
			}
			if (!ready.empty()){
				tmpvalue = ready.top();
				ready.pop();
			}
			while (!ready.empty()){
				tmpvalue = ready.top() + " " + tmpvalue;
				ready.pop();
			}
			if (!tmpkey.empty())m[tmpkey] = tmpvalue;
		}
		else ready.push(i);
	}
	string tmpkey, tmpvalue = "";
	if (!ready.empty()){
		tmpkey = ready.top();
		ready.pop();
	}
	if (!ready.empty()){
		tmpvalue = ready.top();
		ready.pop();
	}
	while (!ready.empty()){
		tmpvalue = ready.top() + " " + tmpvalue;
		ready.pop();
	}
	if (!tmpkey.empty())m[tmpkey] = tmpvalue;

	if (m.find(tofind) == m.end()){
		cout << "none" << endl;
		return 0;
	}
	else{
		tofind = m[tofind];
	}
	bool turn = true;
	while (turn)
	{
		auto it = m.begin();
		
		while (it != m.end())
		{
			string::size_type n;
			n = tofind.find((*it).first);
			if (n == std::string::npos){
				turn = false;
				break;
			}
			else{
				string t = tofind.substr(0, n) + (*it).second + tofind.substr(n + (*it).first.size());
				tofind = t;
			}
		}
		
	}
	for (auto c : tofind){
		if (c == '*')cout << " ";
		cout << c;
	}
	cout << endl;
	return 0;
}
```