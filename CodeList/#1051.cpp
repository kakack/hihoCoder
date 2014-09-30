#include <iostream>

using namespace std;

/*
这个题思路比较简单，
给了N个缺席的天数，根据一头0，一头尾100，可以获得N+1个数值组成的数组，
然后M的补签到卡一定是用在相邻两个漏签日期上的，
最后其实就是求出N+1个元素数组中，M+1的和的最大值，
当然如果M>=N了那就直接是100天
*/


int max(int *a, int N, int M){
	
	int max=0;
			
	
	for (int i=0;i+M<=N;i++) {
		int sum=M-1;

		for (int j=0;j<M;j++) {
			
			sum+=a[i+j];
			
		}
		
		if(sum>max)
		 max=sum;	
	}
	
	return max;
	
}

int main(int argc, char *argv[]) {
	
	int loop,N,M;
	
	cin>>loop;
	
	while (loop--) {
		
		int days_off[101],days[101];
		
		cin>>N>>M;
		
		int i=0,last=0;
		
		for (;i<N;i++) {
			cin>>days_off[i];
			
			days[i]=days_off[i]-last-1;
			
			last=days_off[i];
			
		}
		
		days[i]=100-last;
		

		
		if(M>=N)
		  cout<<100<<endl;
		else {
		
		  cout<<max(days,N+1,M+1)<<endl;
			
		}
		


	}
	
	
}