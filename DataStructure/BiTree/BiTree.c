#include <stdio.h>
#include <malloc.h>

#define ElemType char

typedef struct BiTNode{
    ElemType data;                  // 数据域
    struct BiTNode *lchild, *rchild; // 左、右孩子指针
}BiTNode,*BiTree;

//用递归对树输入
BiTree InputTreeRecursive()
{
    BiTree t;
    char ch;
    scanf("%c",&ch);
    if (ch == '#')
        t = NULL;
    else
    {
        t = (BiTree)malloc(sizeof(BiTNode));
        t->data = ch;
        t->lchild = InputTreeRecursive();
        t->rchild = InputTreeRecursive();
    }
    return t;
}

void visit(BiTree T)
{
    printf("%c",T->data);
}

void preOrder(BiTree T){
    if (T!=NULL)
    {
        visit(T);            // 访问根节点
        preOrder(T->lchild); // 递归遍历左子树
        preOrder(T->rchild); // 递归遍历右子树
    }
}




int main()
{
    BiTree t = InputTreeRecursive();

    preOrder(t);


    return 0;
}








