#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
string deal(string s,int& e){
	int k=0;
	while(s.length()>0 && s[0]=='0'){
		s.erase(s.begin());
	}
	if(s[0]=='.'){	////////ȥ��ǰ�������С���㣬˵��<1 
		s.erase(s.begin());
		while(s.length()>0 && s[0]=='0'){
			s.erase(s.begin());			//ȥ��С�����ķ���λǰ ����0 
			e--;	/////////////////ָ��-- 
		}
	}else{
		while(k<s.length() && s[k]!='.'){/////////˵��>1 
			k++;
			e++;			/////////û����С���� ָ����++ 
		}
		if(k<s.length()){	//////////������С���� 
			s.erase(s.begin()+k);	///ɾ��С���� 
		}
	}
	if(s.length()==0)/////////ȥ��ǰ�����s�ĳ��ȱ�Ϊ0��˵���������0 
		e=0;
	int num=0;	//���� 
	k=0;
	string res;
	while(num<n){	///////���Ȼ�û��n 
		if(k<s.length())	///�������֣��ͼӵ�resĩβ 
			res+=s[k++];
		else
			res+='0';
		num++;	
	}
	return res;
}


int main(){
	string s1,s2,s3,s4;
//	freopen("G:\\PATdata\\A1060.txt","r",stdin);
	cin >> n >> s1 >> s2;
	int e1=0,e2=0;
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4 && e1==e2)
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	else
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;


	return 0;
}
