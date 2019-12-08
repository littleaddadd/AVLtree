#include <queue>
#include "head.h"
#include "mainwindow.h"

/*添加用户爱好算法*/
/**
 * 函数名称：childset_size
 * 函数参数：Treepoint T
 * 函数功能：求子树结点的个数
 * 返回值：子树结点的个数
 * 调用说明：用于求爱好树的结点个数
 **/
int hobby_size(ChildAVLpoint T)
{
    if(T==nullptr) return 0;
    return hobby_size(T->lchild)+hobby_size(T->rchild)+1;  //递归函数 求子树结点的个数
}


/**
 * 函数名称：childset_inserthobby
 * 函数参数：BSTree *T,int key,std::string hobbyname
 * 函数功能：添加爱好
 * 返回值：TRUE　FALSE
 * 调用说明：用于添加爱好树
 **/
int hobby_insert(AVLpoint *T,int key,std::string hobbyname)
{
    AVLpoint p=SearchAVL(*T,key);
    if(p==nullptr) return FALSE;                                 // 如果找不到key指定的用户 返回FALSE
    ChildAVLpoint q=SearchHobbyAVLbyname(p->data.hobby,hobbyname);   //按name找爱好
    if(q!=nullptr) return FALSE;                                 //已经有此爱好 不能重复添加

    childelemnode hobbynode;
    hobbynode.key=hobby_size(p->data.hobby);                  //key指定为当前爱好数量
    strcpy(hobbynode.name,hobbyname.c_str());
    bool taller;
    return InsertChildAVL(&p->data.hobby,hobbynode,&taller);     //添加hobby
}

/*删除爱好算法*/
/**
 * 函数名称：childset_removehobby
 * 函数参数：BSTree *T,int key,std::string hobbyname
 * 函数功能：删除爱好
 * 返回值：TRUE　FALSE
 * 调用说明：用于删除爱好树
 **/
int hobby_remove(AVLpoint *T,int key,std::string hobbyname)
{
    AVLpoint p=SearchAVL(*T,key);
    if(p==nullptr) return FALSE;                                 // 如果找不到key指定的用户 返回FALSE

    ChildAVLpoint q=SearchHobbyAVLbyname(p->data.hobby,hobbyname);   //找爱好
    if(q==nullptr) return FALSE;                                 //如果找不到爱好 返回FALSE
    bool shorter;

    return DeleteChildAVL(&p->data.hobby,q->data.key,&shorter);
}

/*修改爱好算法*/
/**
 * 函数名称：childset_modifyhobby
 * 函数参数：BSTree *T,int key,std::string oldhobbyname,std::string newhobbyname
 * 函数功能：修改爱好
 * 返回值：TRUE　FALSE
 * 调用说明：用于修改爱好树
 **/
int hobby_modify(AVLpoint *T,int key,std::string oldhobbyname,std::string newhobbyname)
{
    AVLpoint p=SearchAVL(*T,key);
    if(p==nullptr) return FALSE;                              // 如果找不到key指定的用户 返回FALSE

    ChildAVLpoint q=SearchHobbyAVLbyname(p->data.hobby,oldhobbyname);
    if(q==nullptr) return FALSE;                              //如果找不到爱好 返回FALSE
    strcpy(q->data.name,newhobbyname.c_str());                //找到爱好 修改名字
    return TRUE;
}

/*查询爱好算法*/
/**
 * 函数名称：childset_memberhobby
 * 函数参数：BSTree T,std::string hobby,std::function<void(elemnode)> callable
 * 函数功能：查询子树
 * 返回值：TRUE FALSE
 * 调用说明：用于查询爱好
 **/
int hobby_search(AVLpoint T,std::string hobby,std::function<void(elemnode)> callable)
{
    if(T==nullptr) return FALSE;
    if(SearchHobbyAVLbyname(T->data.hobby,hobby)!=nullptr)     //在此函数递归查找爱好
          callable(T->data);
    hobby_search(T->lchild,hobby,callable);            //左子树
    hobby_search(T->rchild,hobby,callable);            //右子树
    return TRUE;
}

/*遍历爱好算法*/
/**
 * 函数名称：childset_traversehobby
 * 函数参数：BSTree T,int key,int choicemanner,std::function<void(tinyelemnode)> callable
 * 函数功能：遍历爱好
 * 返回值：TRUE FALSE
 * 调用说明：用于遍历爱好
 **/
int hobby_traverse(AVLpoint T,int key,int choicemanner,std::function<void(childelemnode)> callable)
{
    AVLpoint p=nullptr;
    p=SearchAVL(T,key);
    if(p==nullptr) return FALSE;                             //如果找不到用户 返回FALSE
    TraverseChildAVL(p->data.hobby,choicemanner,callable);   //遍历爱好树
    return TRUE;
}

/*重置爱好算法*/
/**
 * 函数名称：childset_inithobby
 * 函数参数：BSTree *T,int key
 * 函数功能：初始化爱好
 * 返回值：TRUE FALSE
 * 调用说明：用于初始化爱好
 **/
int hobby_reset(AVLpoint *T,int key)
{
    AVLpoint p=SearchAVL(*T,key);
    if(p==nullptr) return FALSE;
    DestroyChildAVL(&(p->data.hobby));                      //摧毁爱好树完成初始化
    return TRUE;
}


