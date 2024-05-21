#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
char data;
struct TreeNode *left, *right;
}TreeNode;

TreeNode n1 ={'I',NULL,NULL}; //i
TreeNode n2 ={'J',NULL,NULL};  //j
TreeNode n3 ={'D',&n1,&n2};   //d
TreeNode n4 ={'F',NULL,NULL};  //f
TreeNode n5 ={'B',&n3,&n4};  //b
TreeNode n6 ={'K',NULL,NULL}; //k
TreeNode n7 ={'G',NULL,&n6};  //G
TreeNode n8 ={'H',NULL,NULL};   //H
TreeNode n9 ={'C',&n7,&n8};    //c
TreeNode n10 ={'A',&n5,&n9}; //A
TreeNode *root =&n10;

int get_node_count(TreeNode *node)
{
    int count=0;
    if(node !=NULL)
        count=1+get_node_count(node->left)+get_node_count(node->right);
    return count;
}

int get_leaf_count(TreeNode *node)
{
    int count=0;
    if(node!=NULL)
    {
        if(node->left==NULL &&node->right==NULL)
            return 1;
        else
            count=get_leaf_count(node->left)+get_leaf_count(node->right);
    }
    return count;
}

int get_height(TreeNode *node)
{
    int height=-1;
    if(node!=NULL)
        height=1+max(get_height(node->left),get_height(node->right));
    return height;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int an,fn,h;
    an=get_node_count(root);
    fn=get_leaf_count(root);
    h=get_height(root);
    printf("1)전체 노드 수 :%d \n",an);
    printf("2)단말 노드 수 :%d \n",fn);
    printf("3)트리의 높이 :%d \n",h);
    return 0;
}
