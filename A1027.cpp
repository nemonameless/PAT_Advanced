#include<cstdio>
using namespace std;
char radix[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main(){
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
	printf("#");
	printf("%c%c%c%c%c%c",radix[r/13],radix[r%13],radix[g/13],radix[g%13],radix[b/13],radix[b%13]);
	return 0;
}