//////http:
//www.cnblogs.com/demian/p/6103285.htmlǰ���ǰ����ң�����Ӻ���ǰ�ң��۲�����������֪��ǰ��������Ψһ���ڵ�һ�����Ƿ�Ϊ����������

 //   �ж�������ͨ�����Һ������������һ������ǰһ���������е�λ�ã���ȷ���Ƿ���Ի������Һ��ӣ�������ܣ� �ͽ��仮��Ϊ�Һ��ӣ������ӣ����ݹ齨����


#include<cstdio>
using namespace std;
int n;
const int maxn=31;
int pre[maxn],post[maxn];
int flag=1;
struct node{
	int data;
	node *lch,*rch;
};
node *create(int prel,int prer,int postl,int postr){
	if(prel>prer)
		return NULL;
	node* root=new node;
	root->data=pre[prel];

	root->lch=NULL;///////////���ܲ�д
	root->rch=NULL;///////////////
	
	if (prel == prer)  
        return root;  
	int k=0;
	for(k=prel+1;k<=prer;k++){
		if(pre[k]==post[postr-1])
			break;
	}
	int numleft=k-prel;
	if(numleft>1){
		root->lch=create(prel+1,k-1,  postl,          postl+numleft-2);//////////
		root->rch=create(k     ,prer, postl+numleft-1,postr-1);///////////
	}else{
		flag=0;
		root->rch=create(k,prer,postl+numleft-1,postr-1);
	}
	return root;
}
int num=0;
void inod(node *root){
	if(root==NULL)
		return;

	inod(root->lch);
	printf("%d",root->data);
	num++;
	if(num<n)
		printf(" ");
	inod(root->rch);
}
int main(){
	freopen("G:\\PATdata\\A1119.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	node* root=create(0,n-1,0,n-1);
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	inod(root);
	printf("\n");//////////////////////////////�������û�֣� 
	return 0;
}
