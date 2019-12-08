#include "head.h"

/*初始化*/
/**
 * 函数名称：set_init
 * 函数参数：结构体指针struct tree *T
 * 函数功能：初始化此应用
 * 返回值：TRUE FALSE
 * 调用说明：用于实现集合初始化功能
 **/
int set_init(struct tree * T)
{
    //调用InitAVL实现初始化集合的操作
    return InitAVL(T);
}

/*摧毁算法*/
/**
 * 函数名称：set_destroy
 * 函数参数：结构体指针struct tree *T
 * 函数功能：摧毁集合
 * 返回值：TRUE FALSE
 * 调用说明：用于实现集合销毁功能
 **/
int set_destroy(struct tree * T)
{
    //调用DestroyAVL函数实现销毁集合操作
    if(T->exists==false) return FALSE;  //如果树不存在 返回FALSE
    T->exists=false; //如果树存在 将exists改为false
    DestroyAVL(&T->tree); //摧毁AVL树
    return TRUE;
}

/*插入*/
/**
 * 函数名称：set_insert
 * 函数参数：BSTree *T，数据结构体指针data，bool变量的指针taller
 * 函数功能：插入结点
 * 返回值：TRUE FALSE
 * 调用说明：用于实现集合插入功能
 **/
int set_insert(AVLpoint *T, elempoint data,bool *taller)
{
    return InsertAVL(T,*data,taller); //调用实现插入功能
}

/*删除*/
/**
 * 函数名称：set_remove
 * 函数参数：BSTree *T，key
 * 函数功能：删除结点
 * 返回值：TRUE FALSE
 * 调用说明：用于实现集合删除功能
 **/
int set_remove(AVLpoint *T,int key)
{
    bool shorter;
    return DeleteAVL(T,key,&shorter); //调用实现删除功能
}




/**
 * 函数名称：set_intersection
 * 函数参数：BSTree T1,BSTree T2,BSTree * intersectiontree
 * 函数功能：用于实现集合交运算
 * 返回值：TRUE FALSE
 * 调用说明：调用实现对两棵树的交
 **/
int set_intersection(AVLpoint T1,AVLpoint T2,AVLpoint *intersectiontree)
{
    if(T2==nullptr) return FALSE;
    bool taller;
    set_intersection(T1,T2->lchild,intersectiontree);
    if(SearchAVL(T1,T2->data.key)!=nullptr)
        InsertAVL(intersectiontree,T2->data,&taller);    //把T1和T2都有的结点插入
    set_intersection(T1,T2->rchild,intersectiontree);
    return TRUE;
}

/**
 * 函数名称：set_union
 * 函数参数：BSTree T1,BSTree T2,BSTree * uniontree
 * 函数功能：用于实现集合并运算
 * 返回值：TRUE FALSE
 * 调用说明：用于实现对两棵树的并
 **/
int set_union(AVLpoint T1,AVLpoint T2,AVLpoint *uniontree)
{
    set_intersection(T1,T1,uniontree);    //T1插入uniontree
    set_intersection(T2,T2,uniontree);    //T2插入uniontree
    return TRUE;
}

/**
 * 函数名称：set_difference
 * 函数参数：BSTree T1,BSTree T2,BSTree *differencetree
 * 函数功能：用于实现集合的差运算
 * 返回值：TRUE FALSE
 * 调用说明：用于实现对两棵树的差运算
 **/
int set_difference(AVLpoint T1,AVLpoint T2,AVLpoint *differencetree)
{
    if(T2==nullptr) return FALSE;
    set_remove(differencetree,T2->data.key);   //把T2中的结点从differencetree移除
    set_difference(T1,T2->lchild,differencetree);
    set_difference(T1,T2->rchild,differencetree);
    return TRUE;
}


/*个数*/
/**
 * 函数名称：set_size
 * 函数参数：BSTree T
 * 函数功能：成员个数
 * 返回值：成员个数
 * 调用说明：用于实现求树结点个数
 **/
int set_size(AVLpoint T)
{   //递归调用求成员个数
    if(T==nullptr) return 0;         //如果结点为空返回0
    return set_size(T->lchild)+set_size(T->rchild)+1;
}



/*查找*/
/**
 * 函数名称：set_member
 * 函数参数：BSTree T，key
 * 函数功能：判断元素是否为集合成员的查找
 * 返回值：TRUE FALSe
 * 调用说明：用于实现集合的查找功能
 **/
AVLpoint set_member(AVLpoint T, int key)
{
    return SearchAVL(T,key);  //调用实现查找功能
}


/**
 * 函数名称：set_subset
 * 函数参数：BSTree T1,BSTree T2,bool *judge
 * 函数功能：判断子集
 * 返回值：void
 * 调用说明：用于判断子集
 **/
void set_subset(AVLpoint T1,AVLpoint T2,bool *judge)
{
    if(T2==nullptr) return ;
    if(SearchAVL(T1,T2->data.key)==nullptr)   //如果存在有集合没有的结点 就不能算子集了
        *judge=false;
    set_subset(T1,T2->lchild,judge);
    set_subset(T1,T2->rchild,judge);
    return;
}

/**
 * 函数名称：set_equal
 * 函数参数：BSTree T1,BSTree T2
 * 函数功能：判断集合相等
 * 返回值：TRUE FALSE
 * 调用说明：用于判断集合相等
 **/
int set_equal(AVLpoint T1,AVLpoint T2)
{
    bool judge=true;
    set_subset(T1,T2,&judge);
    if(judge==false) return FALSE;
    set_subset(T2,T1,&judge);
    if(judge==false) return FALSE;    //T1是T2的子集 而且 T2是T1的子集
    return TRUE;
}



