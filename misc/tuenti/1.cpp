#include<iostream>
#include<map>
#include<set>
#include<string>
#include<fstream>
using namespace std;
map<string, multiset<string> > recs;
map<string, multiset<string> >::iterator it;
int main(){
	ifstream fin("./students");
	string tmp;
	while(getline(fin, tmp)){
		int pos = tmp.find(",", 0);
		recs[tmp.substr(pos+1, tmp.length()-pos-1)].insert(tmp.substr(0, pos));
	}
	int t;
	cin>>t;
	cin.ignore(1);
	for(int z = 1;z<=t;z++){
		string ip;
		getline(cin, ip);
		cout<<"Case #"<<z<<": ";
		it = recs.find(ip);
		if(it == recs.end()){
			cout<<"NONE\n";
		}else{
			bool flag = 0;
			for(multiset<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
				if(flag)
				cout<<",";
				cout<<*it2;
				flag = 1;
			}
			cout<<endl;
		}
	}
}
