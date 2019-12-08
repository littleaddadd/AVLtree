#include "head.h"

/*二度好友算法*/
/**
 * 函数名称：twodegreefriend
 * 函数参数：BSTree T,int key,std::function<void(tinyelemnode)> callable
 * 函数功能：实现二度好友功能
 * 返回值：TRUE FALSE
 * 调用说明：
 **/
int twodegreefriend(AVLpoint T,int key,std::function<void(childelemnode)> callable)
{
    AVLpoint p=nullptr;
    ChildAVLpoint twodegreetree=nullptr;
    bool shorter;

    p=SearchAVL(T,key);
    if(p==nullptr) return FALSE;
    if(p->data.friends==nullptr) return FALSE;

    addfriendtree(&twodegreetree,p->data.friends,T,p->data.friends);  //调用函数求二度好友

    DeleteChildAVL(&twodegreetree,p->data.key,&shorter);  //删除自己结点

    TraverseChildAVL(twodegreetree,1,callable);  //遍历
    return TRUE;
}
/**
 * 函数名称： addfriendtree
 * 函数参数：Treepoint *twodegreetree,Treepoint T,BSTree T1,Treepoint T2
 * 函数功能： 添加朋友树
 * 返回值：TRUE FALSE
 * 调用说明：
 **/
int addfriendtree(ChildAVLpoint *twodegreetree,ChildAVLpoint T,AVLpoint T1,ChildAVLpoint T2)
{
    if(T==nullptr) return FALSE;
//    bool taller;
//    InsertAVLnode(twodegreetree,T->data,&taller);

    AVLpoint p=SearchAVL(T1,T->data.key);

    addtreefriend(twodegreetree,p->data.friends,T2);   //调用函数添加树上朋友
    addfriendtree(twodegreetree,T->lchild,T1,T2);      //递归左子树
    addfriendtree(twodegreetree,T->rchild,T1,T2);      //递归右子树
    return TRUE;
}
/**
 * 函数名称：addtreefriend
 * 函数参数：Treepoint *twodegreetree,Treepoint T,Treepoint T2
 * 函数功能：添加朋友树上的朋友
 * 返回值：TRUE FALSE
 * 调用说明：
 **/
int addtreefriend(ChildAVLpoint *twodegreetree,ChildAVLpoint T,ChildAVLpoint T2)
{
    bool taller;
    if(T==nullptr) return FALSE;
    addtreefriend(twodegreetree,T->lchild,T2);          //递归左子树
    if(SearchChildAVLbykey(T2,T->data.key)==nullptr)   //如果不是用户的一度好友就加入
              InsertChildAVL(twodegreetree,T->data,&taller);
    addtreefriend(twodegreetree,T->rchild,T2);         //递归右子树
    return TRUE;
}

/*共同关注算法*/

/**
 * 函数名称：childset_intersectionkey
 * 函数参数：交
 * 函数功能：以key来交运算
 * 返回值：TRUE FALSE
 * 调用说明：用于实现共同关注等功能
 **/
int childset_intersectionkey(ChildAVLpoint T1,ChildAVLpoint T2,ChildAVLpoint * bothtree)
{
    if(T2==nullptr) return FALSE;
    bool taller;
    childset_intersectionkey(T1,T2->lchild,bothtree);
    if(SearchChildAVLbykey(T1,T2->data.key)!=nullptr) InsertChildAVL(bothtree,T2->data,&taller);  //如果在T1中找到T2的结点 插入bothtree
    childset_intersectionkey(T1,T2->rchild,bothtree);
    return TRUE;
}

/**
 * 函数名称：bothfollow
 * 函数参数：实现共同关注功能
 * 函数功能：BSTree T,int key1,int key2,std::function<void(tinyelemnode)> callable
 * 返回值：TRUE FALSE
 * 调用说明：
 **/
int bothfollow(AVLpoint T,int key1,int key2,std::function<void(childelemnode)> callable)
{
    AVLpoint p=nullptr;
    AVLpoint q=nullptr;
    ChildAVLpoint bothtree=nullptr;
    p=SearchAVL(T,key1);
    if(p==nullptr) return FALSE;

    q=SearchAVL(T,key2);
    if(q==nullptr) return FALSE;

    if(p->data.follow==nullptr) return FALSE;     //关注树为空
    if(q->data.follow==nullptr) return FALSE;     //关注树为空
    childset_intersectionkey(p->data.follow,q->data.follow,&bothtree);  //调用函数求共同关注
    TraverseChildAVL(bothtree,1,callable);
    return TRUE;
}
/*共同爱好算法*/
/**
 * 函数名称：childset_intersectionname
 * 函数参数：交
 * 函数功能：以name来交运算
 * 返回值：TRUE FALSE
 * 调用说明：用于实现共同爱好功能
 **/
int childset_intersectionname(ChildAVLpoint T1, ChildAVLpoint T2, ChildAVLpoint *bothtree)
{
    if(T2==nullptr) return FALSE;
    bool taller;
    childset_intersectionname(T1,T2->lchild,bothtree);
    if(SearchHobbyAVLbyname(T1,T2->data.name)!=nullptr)                        //如果在T1中找到T2中name对应的结点 插入bothtree
        InsertChildAVL(bothtree,T2->data,&taller);
    childset_intersectionname(T1,T2->rchild,bothtree);
    return TRUE;
}

/**
 * 函数名称：bothhobby
 * 函数参数：实现共同爱好功能
 * 函数功能：BSTree T,int key1,int key2,std::function<void(tinyelemnode)> callable
 * 返回值：TRUE FALSE
 * 调用说明：
 **/
int bothhobby(AVLpoint T,int key1,int key2,std::function<void(childelemnode)> callable)
{
    AVLpoint p=nullptr;
    AVLpoint q=nullptr;
    ChildAVLpoint bothtree=nullptr;
    p=SearchAVL(T,key1);
    if(p==nullptr) return FALSE;
    q=SearchAVL(T,key2);
    if(q==nullptr) return FALSE;

    if(p->data.hobby==nullptr) return FALSE;  //爱好树为空
    if(q->data.hobby==nullptr) return FALSE;  //爱好树为空
    childset_intersectionname(p->data.hobby,q->data.hobby,&bothtree);  //调用函数求共同爱好

    TraverseChildAVL(bothtree,1,callable);
    return TRUE;
}
