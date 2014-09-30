#include <iostream>
#include <string>

using namespace std;

char insert;

int ans;
bool chg=false;

string eliminate(string a){
		
		int start=0,end,len;
		
		len=a.length();
		
		for (;start<len;) {
			
			int length=1;
			end=start+1;
			if(a.substr(start,1)==a.substr(end,1))
			 {
				chg=true;
				while (a.substr(start,1)==a.substr(end,1)) {
				  length++;
				   end++;
			    }
			
			 ans+=length;
			 a=a.erase(start,length);
			 len-=length;
			}
		   else {
			
			start++;
			
		  }
		}
		
		return a;	
	
}


int main(int argc, char *argv[]) {
	
	int n;
	string str;
	
	cin>>n;
	
	while (n--) {
		cin>>str;
		int max=0;
		for(char ch='A';ch<='C';ch++){
		
			int len=str.length();
			
			for (int pos=0;pos<=len;pos++) {
				string tmp=str;
				string b=tmp.insert(pos,1,ch);
				ans=0;
				
//				cout<<b<<endl;

				b=eliminate(b);

				   while(chg){
					chg=false;
					b=eliminate(b);
			}
			
			if(ans>max)
			  max=ans;
	
		}
		
	}
	cout<<max<<endl;
	}
}