#include <queue>
#include "head.h"
#include "mainwindow.h"
/*添加社交关系算法*/
/**
 * 函数名称：childset_insertrelation
 * 函数参数：BSTree *T  用户1和2的key 插入关系的选择
 * 函数功能：添加社交关系
 * 返回值：TRUE FALSE
 * 调用说明：用于调用添加社交关系
 **/
int relation_insert(AVLpoint *T,int key1,int key2,int choice)
{
    switch (choice){
    case 0:   return friend_relation_insert(T,key1,key2);  //让key1用户和key2用户成为朋友
    case 1:   return follow_relation_insert(T,key1,key2);  //让key1用户关注key2用户
    case 2:   return follower_relation_insert(T,key1,key2);  //让key2用户关注key1用户
    }
    return FALSE;
}

/**
 * 函数名称：childset_insertfriend
 * 函数参数：BSTree *T  用户1和2的key
 * 函数功能：添加朋友
 * 返回值：TRUE FALSE
 * 调用说明：用于调用添加朋友关系
 **/
int friend_relation_insert(AVLpoint *T,int key1,int key2)
{
    int judge = relation_search(*T,key1,key2);    //先根据childset_member函数的返回值判断key1 key2的用户是否存在
    if(judge==FALSE) return FALSE;                //不存在或不合法就返回FALSE

    AVLpoint p=SearchAVL(*T,key1);                 //找到key1用户节点的指针
    AVLpoint r=SearchAVL(*T,key2);                 //找到key2用户节点的指针

    bool taller;
    childelemnode data1,data2;

    data1.key=key2;                            //data1表示要给用户1插入的数据结点
    data2.key=key1;                            //data2表示要给用户2插入的数据节点

    strcpy(data1.name,r->data.name);
    strcpy(data2.name,p->data.name);

    InsertChildAVL(&p->data.friends,data1,&taller);      //因为是朋友 所以在这里要插入朋友树，关注树，粉丝树
    InsertChildAVL(&p->data.follow,data1,&taller);
    InsertChildAVL(&p->data.follower,data1,&taller);

    InsertChildAVL(&r->data.friends,data2,&taller);
    InsertChildAVL(&r->data.follow,data2,&taller);
    InsertChildAVL(&r->data.follower,data2,&taller);


    return TRUE;

}
/**
 * 函数名称：childset_insertfollow
 * 函数参数：BSTree *T  用户1和2的key
 * 函数功能：添加关注
 * 返回值：TRUE FALSE
 * 调用说明：用于调用添加关注关系
 **/
int follow_relation_insert(AVLpoint *T,int key1,int key2)
{
    int judge=relation_search(*T,key1,key2);  //先根据childset_member函数的返回值判断key1 key2的用户是否存在
    if(judge==FALSE) return FALSE;            //不存在或不合法就返回FALSE

    AVLpoint p=SearchAVL(*T,key1);             //找到key1用户节点的指针
    AVLpoint r=SearchAVL(*T,key2);             //找到key2用户节点的指针

    bool taller;
    childelemnode data1,data2;

    data1.key=key2;                            //data1表示要给用户1插入的数据结点
    data2.key=key1;                            //data2表示要给用户2插入的数据节点

    strcpy(data1.name,r->data.name);
    strcpy(data2.name,p->data.name);

    if(judge==AVL_FRIEND) return FALSE;   //已经是朋友时 添加关系失败
    if(judge==AVL_USER1_FOLLOW_USER2) return FALSE;   //已经是用户1关注用户2时 添加关系失败
    if(judge==AVL_USER2_FOLLOW_USER1)                //如果用户2关注了用户1 相互关注就成朋友了
    {
        friend_relation_insert(T,key1,key2);
    }
    if(judge==AVL_USER_NO_RELATION)                  //如果没有任何关系 则只需要在用户1的关注树和用户2的粉丝树添加
    {
        InsertChildAVL(&p->data.follow,data1,&taller);
        InsertChildAVL(&r->data.follower,data2,&taller);
    }
    return TRUE;
}

/**
 * 函数名称：childset_insertfollower
 * 函数参数：BSTree *T  用户1和2的key
 * 函数功能：添加粉丝
 * 返回值：TRUE FALSE
 * 调用说明：用于调用添加被关注关系
 **/
int follower_relation_insert(AVLpoint *T,int key1,int key2)
{
    int judge=relation_search(*T,key1,key2);  //先根据childset_member函数的返回值判断key1 key2的用户是否存在
    if(judge==FALSE) return FALSE;           //不存在或不合法就返回FALSE
    AVLpoint p=SearchAVL(*T,key1);             //找到key1用户节点的指针
    AVLpoint r=SearchAVL(*T,key2);             //找到key2用户节点的指针

    bool taller;
    childelemnode data1,data2;

    data1.key=key2;                        //data1表示要给用户1插入的数据结点
    data2.key=key1;                        //data2表示要给用户2插入的数据节点

    strcpy(data1.name,r->data.name);
    strcpy(data2.name,p->data.name);
    if(judge==AVL_FRIEND) return FALSE;  //已经是朋友时 添加关系失败
    if(judge==AVL_USER2_FOLLOW_USER1) return FALSE;  //已经是用户2关注用户1时 添加关系失败
    if(judge==AVL_USER1_FOLLOW_USER2)                //如果用1关注了用户2 相互关注就成朋友了
    {
        friend_relation_insert(T,key1,key2);
    }
    if(judge==AVL_USER_NO_RELATION)             //如果没有任何关系 则只需要在用户1的粉丝树和用户2的关注树添加
    {
        InsertChildAVL(&p->data.follower,data1,&taller);
        InsertChildAVL(&r->data.follow,data2,&taller);
    }
    return TRUE;
}

/*删除社交关系算法*/
/**
 * 函数名称：childset_removerelation
 * 函数参数：BSTree *T  用户1和2的key 删除种类选项choice
 * 函数功能：删除社交关系
 * 返回值：TRUE FALSE
 * 调用说明：用于删除社交关系
 **/
int relation_remove(AVLpoint *T,int key1,int key2,int choice)
{
    //删除好友 取消关注
    switch (choice){
    case 0:   return follow_relation_remove(T,key1,key2); //取消关注
    case 1:   return friend_relation_remove(T,key1,key2); //删除好友
    }
    return FALSE;
}

/**
 * 函数名称：childset_removefriend
 * 函数参数：BSTree *T  用户1和2的key
 * 函数功能：删除朋友关系
 * 返回值：TRUE FALSE
 * 调用说明：用于删除朋友关系
 **/

int friend_relation_remove(AVLpoint *T,int key1,int key2)
{
    int judge=relation_search(*T,key1,key2);         //首先找key是否合法
    if(judge==FALSE) return FALSE;

    AVLpoint p;
    AVLpoint r;
    p=SearchAVL(*T,key1);                           //找到用户1和2的结点指针
    r=SearchAVL(*T,key2);
    bool shorter;

    DeleteChildAVL(&p->data.friends,key2,&shorter);   //在用户1的朋友树 关注树 粉丝树 用户2的朋友树 关注树 粉丝树 删除
    DeleteChildAVL(&r->data.friends,key1,&shorter);
    DeleteChildAVL(&p->data.follow,key2,&shorter);
    DeleteChildAVL(&r->data.follow,key1,&shorter);
    DeleteChildAVL(&p->data.follower,key2,&shorter);
    DeleteChildAVL(&r->data.follower,key1,&shorter);

    return TRUE;
}

/**
 * 函数名称：childset_removefollow
 * 函数参数：BSTree *T  用户1和2的key
 * 函数功能：删除关注关系
 * 返回值：TRUE FALSE
 * 调用说明：用于删除关注关系
 **/
int follow_relation_remove(AVLpoint *T,int key1,int key2)
{
    AVLpoint p;
    AVLpoint r;
    p=SearchAVL(*T,key1);                     //找到用户1和2的结点的指针
    r=SearchAVL(*T,key2);
    bool shorter;

    int judge=relation_search(*T,key1,key2);       //查找用户1和2的社交关系
    if(judge==FALSE) return FALSE;                 //表示输入的key不合法 返回FALSE
    if(judge==AVL_USER_NO_RELATION) return FALSE;  //表示用户1和2没有关系 返回FALSE
    if(judge==AVL_USER2_FOLLOW_USER1) return FALSE;  //表示是用户2关注用户1 用户1没有关注用户2 返回FALSE
    if(judge==AVL_USER1_FOLLOW_USER2)                //用户1关注用户2
    {
        DeleteChildAVL(&p->data.follow,key2,&shorter);  //在用户1的关注树删除
        DeleteChildAVL(&r->data.follower,key1,&shorter);  //在用户2的粉丝树删除
    }
    if(judge==AVL_FRIEND)                //两者是朋友 单方面取消关注后 需要删除朋友树 用户1的关注树  用户2的粉丝树
    {
        DeleteChildAVL(&p->data.friends,key2,&shorter);
        DeleteChildAVL(&r->data.friends,key1,&shorter);
        DeleteChildAVL(&p->data.follow,key2,&shorter);
        DeleteChildAVL(&r->data.follower,key1,&shorter);
    }
    return TRUE;
}

/*修改关系算法*/
/**
 * 函数名称：childset_modify
 * 函数参数：BSTree *T  用户1和2的key 修改种类选项choice
 * 函数功能：修改社交关系
 * 返回值：TRUE FALSE
 * 调用说明：用于修改社交关系
 **/
int relation_modify(AVLpoint *T,int key1,int key2,int choice)
{
    int judge=relation_search(*T,key1,key2);         //修改算法是先删除 后添加
    if(judge==FALSE) return FALSE;
    friend_relation_remove(T,key1,key2);              //先解除两人的任何关系
    return relation_insert(T,key1,key2,choice);  //然后根据修改选项添加对应关系
}


/*查询关系算法*/

/**
 * 函数名称：childset_member
 * 函数参数：BSTree *T  用户1和2的key
 * 函数功能：查询社交关系
 * 返回值：TRUE FALSE
 * 调用说明：用于查询两个用户的社交关系
 **/
int relation_search(AVLpoint T,int key1,int key2)
{
    AVLpoint p=nullptr;
    AVLpoint q=nullptr;
    if(key1==key2) return FALSE;

    p=SearchAVL(T,key1);
    if(p==nullptr) return FALSE;            //找到用户1结点的指针
    q=SearchAVL(T,key2);
    if(q==nullptr) return FALSE;            //找到用户2结点的指针

    int judge1=friend_relation_search(p,q);  //查询用户1是否和用户2为朋友
    int judge2=follow_relation_search(p,q);  //查询用户1是否关注用户2
    int judge3=follow_relation_search(q,p);  //查询用户2是否关注用户1
    if(judge1==TRUE) return AVL_FRIEND;  //返回朋友关系
    else if(judge2==TRUE) return AVL_USER1_FOLLOW_USER2; //返回用户1关注用户2的关系
    else if(judge3==TRUE) return AVL_USER2_FOLLOW_USER1;  //返回用户2关注用户1的关系
    else return AVL_USER_NO_RELATION;     //返回没有关系
}

/**
 * 函数名称：childset_memberfollow
 * 函数参数：BSTree user1，BSTree user2
 * 函数功能：查找关注
 * 返回值：TRUE FALSE
 * 调用说明：查找两个人是否存在关注
 **/
int follow_relation_search(AVLpoint user1,AVLpoint user2)
{
    ChildAVLpoint judge=SearchChildAVLbykey(user1->data.follow,user2->data.key);  //查询用户1的关注树是否有用户2
    if(judge!=nullptr) return TRUE;
    else return FALSE;

}

/**
 * 函数名称：childset_memberfriend
 * 函数参数：BSTree user1，BSTree user2
 * 函数功能：查找朋友
 * 返回值：TRUE　FALSE
 * 调用说明：查找两个人是否是朋友关系
 **/
int friend_relation_search(AVLpoint user1,AVLpoint user2)
{
    ChildAVLpoint judge=SearchChildAVLbykey(user1->data.friends,user2->data.key); //查询用户1的朋友树是否有用户2
    if(judge!=nullptr) return TRUE;
    else return FALSE;
}

/*遍历关系*/

/**
 * 函数名称：childset_traversererelation
 * 函数参数：BSTree T，用于打印的lambda表达式callable 选择遍历方式的choicemanner  选择遍历种类的choicekind
 * 函数功能：遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于遍历关系
 **/
int relation_traverse(AVLpoint T,int key,int choicekind,int choicemanner,std::function<void(childelemnode)> callable)
{

    AVLpoint p=nullptr;
    p=SearchAVL(T,key);
    if(p==nullptr) return FALSE;   //找不到用户返回FALSE

    switch (choicekind)
    {
          case 0:  TraverseChildAVL(p->data.friends,choicemanner,callable);  break;  //遍历朋友树
          case 1:  TraverseChildAVL(p->data.follow,choicemanner,callable);   break;  //遍历关注树
          case 2:  TraverseChildAVL(p->data.follower,choicemanner,callable); break;  //遍历粉丝数
    }
    return TRUE;
}


/*重置关系*/
/**
 * 函数名称： childset_init
 * 函数参数：BSTree *T,int key,int choice
 * 函数功能：初始化子树
 * 返回值：TRUE FALSE
 * 调用说明：用于初始化关系
 **/
int relation_reset(AVLpoint *T,int key,int choice)
{
    AVLpoint p=SearchAVL(*T,key);
    if(p==nullptr) return FALSE;
    switch (choice)
    {
         case 0:   friend_relation_reset(T,p->data.friends,key);   break;        //初始化朋友树
         case 1:   follow_relation_reset(T,p->data.follow,key);    break;        //初始化关注树
         case 2:   follow_relation_reset(T,p->data.follower,key);  break;        //初始化粉丝树
    }
    return TRUE;
}

/**
 * 函数名称：childset_initfriend
 * 函数参数：BSTree *T,Treepoint T1,int key
 * 函数功能：初始化子树
 * 返回值：TRUE　FALSE
 * 调用说明：用于初始化朋友树
 **/
int friend_relation_reset(AVLpoint *T,ChildAVLpoint T1,int key)
{
    if(T1==nullptr) return FALSE;
    friend_relation_reset(T,((T1)->lchild),key);                                 //递归进行初始化
    friend_relation_remove(T,(T1)->data.key,key);
    friend_relation_reset(T,((T1)->rchild),key);
    return TRUE;
}

/**
 * 函数名称：childset_initfollow
 * 函数参数：BSTree *T,Treepoint T1,int key
 * 函数功能：初始化子树
 * 返回值：TRUE　FALSE
 * 调用说明：用于初始化关注树
 **/
int follow_relation_reset(AVLpoint *T,ChildAVLpoint T1,int key)
{
    if(T1==nullptr) return FALSE;
    follow_relation_reset(T,((T1)->lchild),key);                                //递归进行初始化
    follow_relation_remove(T,key,(T1)->data.key);
    follow_relation_reset(T,((T1)->rchild),key);
    return TRUE;
}
