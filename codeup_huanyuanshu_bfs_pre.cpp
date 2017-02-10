//paste.ubuntu.com/10616131/
//
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int in[maxn];    //����

//��ǰ�������Ĳ�������Ϊlayer��������������Ϊ[inL, inR]
//create�������ع������Ķ������ĸ�����ַ
node* create(vector<int> layer, int inL, int inR) {
    if(layer.size() == 0) {
        return NULL;
    }
    node* root = new node;  //�½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����
    root->data = layer[0];  //�½���������Ϊ������ֵ
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == layer[0]) {
            break;
        }
    }
    vector<int> layerLeft;
    vector<int> layerRight;
    for(int i = 1; i < layer.size(); i++) {
        bool isLeft = false;
        for(int j = inL; j < k; j++) {
            if(layer[i] == in[j]) {
                isLeft = true;
                break;
            }
        }
        if(isLeft) {
            layerLeft.push_back(layer[i]);
        } else {
            layerRight.push_back(layer[i]);
        }
    }
    root->lchild = create(layerLeft, inL, k - 1);
    root->rchild = create(layerRight, k + 1, inR);
    return root;  //���ظ�����ַ
}

int num;
void preOrder(node* root,int n) {
    if(root == NULL) {
        return;
    }
    printf("%d", root->data);
    num++;
    if(num < n) printf(" ");
    else printf("\n");
    preOrder(root->lchild, n);
    preOrder(root->rchild, n);
}

void postOrder(node* root,int n) {
    if(root == NULL) {
        return;
    }
    postOrder(root->lchild, n);
    postOrder(root->rchild, n);
    printf("%d", root->data);
    num++;
    if(num < n) printf(" ");
    else printf("\n");
}

int main() {
        vector<int> layer;
        int n, temp;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            layer.push_back(temp);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        node* root = create(layer, 0, n - 1);    //����
        num = 0;
        preOrder(root, n);
        num = 0;
        postOrder(root, n);
    return 0;
}
