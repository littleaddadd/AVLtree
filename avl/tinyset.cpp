#include <queue>

#include "head.h"
#include "mainwindow.h"

/*添加社交关系算法*/
/**
 * 函数名称：set_insertfriendnode
 * 函数参数：
 * 函数功能：添加朋友
 * 返回值：
 * 调用说明：
 **/
status set_insertfriendnode(BSTree *T,int key1,int key2)
{
    int judge = tinyset_member(*T,key1,key2);
    if(judge==FALSE) return FALSE;

    BSTree p=searchAVL(*T,key1);
    BSTree r=searchAVL(*T,key2);

    bool taller;
    tinyelemnode data1,data2;

    data1.key=key2;
    data2.key=key1;

    strcpy(data1.name,r->data.name);
    strcpy(data2.name,p->data.name);

    InsertAVLnode(&p->data.friends,data1,&taller);
    InsertAVLnode(&p->data.follow,data1,&taller);
    InsertAVLnode(&p->data.follower,data1,&taller);

    InsertAVLnode(&r->data.friends,data2,&taller);
    InsertAVLnode(&r->data.follow,data2,&taller);
    InsertAVLnode(&r->data.follower,data2,&taller);


    return TRUE;

}
/**
 * 函数名称：set_insertfollownode
 * 函数参数：
 * 函数功能：添加关注的人
 * 返回值：
 * 调用说明：
 **/
status set_insertfollownode(BSTree *T,int key1,int key2)
{
    int judge=tinyset_member(*T,key1,key2);
    if(judge==FALSE) return FALSE;

    BSTree p=searchAVL(*T,key1);
    BSTree r=searchAVL(*T,key2);

    bool taller;
    tinyelemnode data1,data2;

    data1.key=key2;
    data2.key=key1;

    strcpy(data1.name,r->data.name);
    strcpy(data2.name,p->data.name);

    if(judge==AVL_USER1_FRIEND_USER2) return FALSE;
    if(judge==AVL_USER1_FOLLOW_USER2) return FALSE;
    if(judge==AVL_USER2_FOLLOW_USER1)
    {
        set_insertfriendnode(T,key1,key2);
        return TRUE;
    }
    if(judge==AVL_USER_NO_RELATION)
    {
        InsertAVLnode(&p->data.follow,data1,&taller);
        InsertAVLnode(&r->data.follower,data2,&taller);
        return TRUE;
    }
}

/**
 * 函数名称：set_insertfollowernode
 * 函数参数：
 * 函数功能：添加粉丝
 * 返回值：
 * 调用说明：
 **/
status set_insertfollowernode(BSTree *T,int key1,int key2)
{
    int judge=tinyset_member(*T,key1,key2);
    if(judge==FALSE) return FALSE;
    BSTree p=searchAVL(*T,key1);
    BSTree r=searchAVL(*T,key2);

    bool taller;
    tinyelemnode data1,data2;

    data1.key=key2;
    data2.key=key1;

    strcpy(data1.name,r->data.name);
    strcpy(data2.name,p->data.name);
    if(judge==AVL_USER1_FRIEND_USER2) return FALSE;
    if(judge==AVL_USER2_FOLLOW_USER1) return FALSE;
    if(judge==AVL_USER1_FOLLOW_USER2)
    {
        set_insertfriendnode(T,key1,key2);
        return TRUE;
    }
    if(judge==AVL_USER_NO_RELATION)
    {
        InsertAVLnode(&p->data.follower,data1,&taller);
        InsertAVLnode(&r->data.follow,data2,&taller);
        return TRUE;
    }
}


/**
 * 函数名称：tinyset_insertnode
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status tinyset_insertnode(BSTree *T,int key1,int key2,int choice)
{

    switch (choice){
    case 0:   return set_insertfriendnode(T,key1,key2);
    case 1:   return set_insertfollownode(T,key1,key2);
    case 2:   return set_insertfollowernode(T,key1,key2);
    }
}




status tinyset_inserthobby(BSTree *T,int key,std::string hobbyname)
{
    BSTree p=searchAVL(*T,key);
    if(p==NULL) return FALSE;
    Treepoint q=tinysearchhobbyAVL(p->data.hobby,hobbyname);
    if(q!=NULL) return FALSE;
    tinyelemnode hobbynode;
    hobbynode.key=tinyset_size(p->data.hobby);
    strcpy(hobbynode.name,hobbyname.c_str());
    bool taller;
    return InsertAVLnode(&p->data.hobby,hobbynode,&taller);
}

status tinyset_removehobby(BSTree *T,int key,std::string hobbyname)
{
    BSTree p=searchAVL(*T,key);
    if(p==NULL) return FALSE;

    Treepoint q=tinysearchhobbyAVL(p->data.hobby,hobbyname);
    if(q==NULL) return FALSE;
    bool shorter;

    return tinyDeleteAVL(&p->data.hobby,q->data.key,&shorter);
}

status tinyset_modifyhobby(BSTree *T,int key,std::string oldhobbyname,std::string newhobbyname)
{
    BSTree p=searchAVL(*T,key);
    if(p==NULL) return FALSE;

    Treepoint q=tinysearchhobbyAVL(p->data.hobby,oldhobbyname);
    if(q==NULL) return FALSE;
    strcpy(q->data.name,newhobbyname.c_str());
    return TRUE;
}











/*删除算法*/
/**
 * 函数名称：tinyset_removefriend
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/

status tinyset_removefriend(BSTree *T,int key1,int key2)
{
    int judge=tinyset_member(*T,key1,key2);
    if(judge==FALSE) return FALSE;

    BSTree p;
    BSTree r;
    p=searchAVL(*T,key1);
    r=searchAVL(*T,key2);
    bool shorter;

    tinyDeleteAVL(&p->data.friends,key2,&shorter);
    tinyDeleteAVL(&r->data.friends,key1,&shorter);
    tinyDeleteAVL(&p->data.follow,key2,&shorter);
    tinyDeleteAVL(&r->data.follow,key1,&shorter);
    tinyDeleteAVL(&p->data.follower,key2,&shorter);
    tinyDeleteAVL(&r->data.follower,key1,&shorter);

    return TRUE;
}

/**
 * 函数名称：tinyset_removefollow
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status tinyset_removefollow(BSTree *T,int key1,int key2)
{
    BSTree p;
    BSTree r;
    p=searchAVL(*T,key1);
    r=searchAVL(*T,key2);
    bool shorter;

    int judge=tinyset_member(*T,key1,key2);
    if(judge==FALSE) return FALSE;
    if(judge==AVL_USER_NO_RELATION) return FALSE;
    if(judge==AVL_USER2_FOLLOW_USER1) return FALSE;
    if(judge==AVL_USER1_FOLLOW_USER2)
    {
        tinyDeleteAVL(&p->data.follow,key2,&shorter);
        tinyDeleteAVL(&r->data.follower,key1,&shorter);
    }
    if(judge==AVL_USER1_FRIEND_USER2)
    {
        tinyDeleteAVL(&p->data.friends,key2,&shorter);
        tinyDeleteAVL(&r->data.friends,key1,&shorter);
        tinyDeleteAVL(&p->data.follow,key2,&shorter);
        tinyDeleteAVL(&r->data.follower,key1,&shorter);
    }
    return TRUE;
}
/**
 * 函数名称：tinyset_remove
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status tinyset_remove(BSTree *T,int key1,int key2,int choice)
{

    //删除好友 取消关注
    switch (choice){
    case 0:   return tinyset_removefollow(T,key1,key2); //取消关注
    case 1:   return tinyset_removefriend(T,key1,key2); //删除好友
    }
//    BSTree p;
//    BSTree r;

//    p=searchAVL(*T,key1);
//    if(p==NULL) return FALSE;
//    r=searchAVL(*T,key2);
//    if(r==NULL) return FALSE;
//    int judge;
//    judge=tinyset_member(*T,key1,key2);
//    if(judge==1) tinyset_removefriend(T,key1,key2);
//    if(judge==2) tinyset_removefollow(T,key1,key2);
//    if(judge==3) tinyset_removefollower(T,key1,key2);
//    if(judge==FALSE) return FALSE;
//    return TRUE;
}

/*修改社交关系算法*/
/**
 * 函数名称：tinyset_modify
 * 函数参数：
 * 函数功能：修改社交关系
 * 返回值：
 * 调用说明：
 **/
int tinyset_modify(BSTree *T,int key1,int key2,int choice)
{
    int judge=tinyset_member(*T,key1,key2);
    if(judge==FALSE) return FALSE;
    tinyset_removefriend(T,key1,key2);
    return tinyset_insertnode(T,key1,key2,choice);
}



/*搜索算法*/
/**
 * 函数名称：tinyset_member
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
int tinyset_member(BSTree T,int key1,int key2)
{
    BSTree p=NULL;
    BSTree q=NULL;
    if(key1==key2) return FALSE;

    p=searchAVL(T,key1);
    if(p==NULL) return FALSE;
    q=searchAVL(T,key2);
    if(q==NULL) return FALSE;

    int judge1=tinyset_friend(p,q);
    int judge2=tinyset_follow(p,q);
    int judge3=tinyset_follow(q,p);
    if(judge1==TRUE) return AVL_USER1_FRIEND_USER2;
    else if(judge2==TRUE) return AVL_USER1_FOLLOW_USER2;
    else if(judge3==TRUE) return AVL_USER2_FOLLOW_USER1;
    else return AVL_USER_NO_RELATION;
}

int tinyset_follow(BSTree user1,BSTree user2)
{
    Treepoint judge=tinysearchAVL(user1->data.follow,user2->data.key);
    if(judge!=NULL) return TRUE;
    else return FALSE;

}
int tinyset_friend(BSTree user1,BSTree user2)
{
    Treepoint judge=tinysearchAVL(user1->data.friends,user2->data.key);
    if(judge!=NULL) return TRUE;
    else return FALSE;
}

int tinyset_memberhobby(BSTree T,std::string hobby,std::function<void(elemnode)> callable)
{
    if(T==NULL) return FALSE;
    tinyset_memberhobby(T->lchild,hobby,callable);
    if(tinysearchhobbyAVL(T->data.hobby,hobby)!=NULL)
          callable(T->data);
    tinyset_memberhobby(T->rchild,hobby,callable);
    return TRUE;
}



/*遍历算法*/
/**
 * 函数名称：tinyPreOrderTraverse
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status tinyPreOrderTraverse(Treepoint T,std::function<void(tinyelemnode)> callable)
{
    if(T==NULL) return FALSE;
    else
    {
        callable(T->data);
        tinyPreOrderTraverse(T->lchild,callable);
        tinyPreOrderTraverse(T->rchild,callable);
    }
    return TRUE;
}


/**
 * 函数名称：tinyInOrderTraverse
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status tinyInOrderTraverse(Treepoint T,std::function<void(tinyelemnode)> callable)
{
    if(T==NULL) return FALSE;
    else
    {
        tinyInOrderTraverse(T->lchild,callable);
        callable(T->data);
        tinyInOrderTraverse(T->rchild,callable);
    }
    return TRUE;
}


/**
 * 函数名称：tinyPostOrderTraverse
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status tinyPostOrderTraverse(Treepoint T,std::function<void(tinyelemnode)> callable)
{
    if(T==NULL) return FALSE;
    else
    {
        tinyPostOrderTraverse(T->lchild,callable);
        tinyPostOrderTraverse(T->rchild,callable);
        callable(T->data);
    }
    return TRUE;
}

status tinyLevelOrderTraverse(Treepoint T,std::function<void(tinyelemnode)> callable)
{
    if(T==NULL) return FALSE;
    Treepoint p;
    std::queue<Treepoint> queue;
    queue.push(T);
    while(!queue.empty())
    {
        Treepoint p = queue.front();
        queue.pop();
        callable(p->data);
        if (p->lchild != nullptr)
            queue.push(p->lchild);
        if (p->rchild != nullptr)
            queue.push(p->rchild);
    }
    return TRUE;
}


/**
 * 函数名称：tinyset_traversenode
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
int tinyset_traversenode(Treepoint T,int choice,std::function<void(tinyelemnode)> callable)
{
    //int choice;
    switch (choice){
    case 0:  tinyPreOrderTraverse(T,callable); break;
    case 1:  tinyInOrderTraverse(T,callable); break;
    case 2:  tinyPostOrderTraverse(T,callable); break;
    case 3:  tinyLevelOrderTraverse(T,callable); break;
    default : break;
    }
    return TRUE;
}

/**
 * 函数名称：tinyset_traverse
 * 函数参数：
 * 函数功能：遍历
 * 返回值：
 * 调用说明：
 **/
int tinyset_traverse(BSTree T,int key,int choicekind,int choicemanner,std::function<void(tinyelemnode)> callable)
{

    BSTree p=NULL;
    p=searchAVL(T,key);
    if(p==NULL) return FALSE;

    switch (choicekind)
    {
          case 0:  tinyset_traversenode(p->data.friends,choicemanner,callable);  break;
          case 1:  tinyset_traversenode(p->data.follow,choicemanner,callable);   break;
          case 2:  tinyset_traversenode(p->data.follower,choicemanner,callable); break;
          case 3:  tinyset_traversenode(p->data.hobby,choicemanner,callable);   break;
    }
    return TRUE;
}

int tinyset_traversehobby(BSTree T,int key,int choicemanner,std::function<void(tinyelemnode)> callable)
{
    BSTree p=NULL;
    p=searchAVL(T,key);
    if(p==NULL) return FALSE;
    tinyset_traversenode(p->data.hobby,choicemanner,callable);
    return TRUE;
}








/*初始化算法*/
int tinyset_init(BSTree *T,int key,int choice)
{
    BSTree p=searchAVL(*T,key);
    if(p==NULL) return FALSE;
    switch (choice)
    {
         case 0:   tinyset_initfriend(T,p->data.friends,key);   break;
         case 1:   tinyset_initfollow(T,p->data.follow,key);    break;
         case 2:   tinyset_initfollow(T,p->data.follower,key);  break;
    }
    return TRUE;
}

int tinyset_initfriend(BSTree *T,Treepoint T1,int key)
{
    if(T1==NULL) return FALSE;
    tinyset_initfriend(T,((T1)->lchild),key);
    tinyset_removefriend(T,(T1)->data.key,key);
    tinyset_initfriend(T,((T1)->rchild),key);
}

tinyset_initfollow(BSTree *T,Treepoint T1,int key)
{
    if(T1==NULL) return FALSE;
    tinyset_initfriend(T,((T1)->lchild),key);
    tinyset_removefollow(T,(T1)->data.key,key);
    tinyset_initfriend(T,((T1)->rchild),key);
}

int tinyset_hobbyinit(BSTree *T,int key)
{
    BSTree p=searchAVL(*T,key);
    if(p==NULL) return FALSE;
    DestroyhobbyAVL(&(p->data.hobby));
    return TRUE;
}






/*二度好友算法*/
/**
 * 函数名称：twodegreefriend
 * 函数参数：
 * 函数功能：实现二度好友功能
 * 返回值：
 * 调用说明：
 **/

status twodegreefriend(BSTree T,int key,std::function<void(tinyelemnode)> callable)
{
    BSTree p=NULL;
    Treepoint twodegreetree=NULL;
    bool shorter;

    p=searchAVL(T,key);
    if(p==NULL) return FALSE;
    if(p->data.friends==NULL) return FALSE;

    addfriendtree(&twodegreetree,p->data.friends,T,p->data.friends);
    tinyDeleteAVL(&twodegreetree,p->data.key,&shorter);

    tinyset_traversenode(twodegreetree,0,callable);
    return TRUE;

}
/**
 * 函数名称： addfriendtree
 * 函数参数：
 * 函数功能： 添加朋友树
 * 返回值：
 * 调用说明：
 **/
status addfriendtree(Treepoint *twodegreetree,Treepoint T,BSTree T1,Treepoint T2)
{  
    if(T==NULL) return FALSE;
    bool taller;
//    InsertAVLnode(twodegreetree,T->data,&taller);

    BSTree p=searchAVL(T1,T->data.key);

    addtreefriend(twodegreetree,p->data.friends,T2);

    addfriendtree(twodegreetree,T->lchild,T1,T2);
    addfriendtree(twodegreetree,T->rchild,T1,T2);
}
/**
 * 函数名称：addtreefriend
 * 函数参数：
 * 函数功能：添加朋友树上的朋友
 * 返回值：
 * 调用说明：
 **/
status addtreefriend(Treepoint *twodegreetree,Treepoint T,Treepoint T2)
{
    bool taller;
    if(T==NULL) return FALSE;    
    addtreefriend(twodegreetree,T->lchild,T2);
    if(tinysearchAVL(T2,T->data.key)==NULL)
              InsertAVLnode(twodegreetree,T->data,&taller);
    addtreefriend(twodegreetree,T->rchild,T2);
}




/*共同关注算法*/
/**
 * 函数名称：bothfollow
 * 函数参数：实现共同关注功能
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status bothfollow(BSTree T,int key1,int key2,std::function<void(tinyelemnode)> callable)
{
    BSTree p=NULL;
    BSTree q=NULL;
    Treepoint bothtree=NULL;
    p=searchAVL(T,key1);
    if(p==NULL) return FALSE;

    q=searchAVL(T,key2);
    if(q==NULL) return FALSE;

    if(p->data.follow==NULL) return FALSE;

    if(q->data.follow==NULL) return FALSE;

    set_intersection(p->data.follow,q->data.follow,&bothtree);

    tinyset_traversenode(bothtree,0,callable);
}
/*共同爱好算法*/
/**
 * 函数名称：bothhobby
 * 函数参数：实现共同爱好功能
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status bothhobby(BSTree T,int key1,int key2,std::function<void(tinyelemnode)> callable)
{
    BSTree p=NULL;
    BSTree q=NULL;
    Treepoint bothtree=NULL;
    p=searchAVL(T,key1);
    if(p==NULL) return FALSE;
    q=searchAVL(T,key2);
    if(q==NULL) return FALSE;

    if(p->data.hobby==NULL) return FALSE;
    if(q->data.hobby==NULL) return FALSE;

    set_intersection(p->data.hobby,q->data.hobby,&bothtree);

    tinyset_traversenode(bothtree,0,callable);
}


