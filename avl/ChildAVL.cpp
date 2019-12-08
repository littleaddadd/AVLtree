#include "head.h"
#include "queue"

/*摧毁算法*/
/**
 * 函数名称：DestroyChildAVL
 * 函数参数：Treepoint *T
 * 函数功能：摧毁子树
 * 返回值：TRUE FALSE
 * 调用说明：摧毁子树
 **/
int DestroyChildAVL(ChildAVLpoint *T)
{
    //递归实现对树的销毁释放
    if(T==nullptr) return FALSE;
    if(*T==nullptr) return FALSE;
    if((*T)->lchild)
        DestroyChildAVL(&((*T)->lchild));
    if((*T)->rchild)
        DestroyChildAVL(&((*T)->rchild));
    free(*T);   //释放*T指向的空间
    *T=nullptr;
    return TRUE;
}

/*搜索算法*/
/**
 * 函数名称：SearchChildAVLbykey
 * 函数参数：Treepoint T,int e
 * 函数功能：按照key查找结点
 * 返回值：返回对应结点的指针或者是nullptr
 * 调用说明：用于按照key查找结点
 **/
ChildAVLpoint SearchChildAVLbykey(ChildAVLpoint T,int e)
{
    //递归调用用于求指定key的子树结点
    if(T==nullptr) return nullptr;
    ChildAVLpoint p=T,q;
    if(p)
    {
        if(p->data.key==e) return p;
        q=SearchChildAVLbykey(p->lchild,e);
        if(q)
            return q;
        else
            return SearchChildAVLbykey(p->rchild,e);
    }
    return nullptr;
}

/**
 * 函数名称：SearchHobbyAVLbyname
 * 函数参数：Treepoint T,std::string hobby
 * 函数功能：按照name查找结点
 * 返回值：返回对应结点的指针或者是nullptr
 * 调用说明：用于查找hobby
 **/
ChildAVLpoint SearchHobbyAVLbyname(ChildAVLpoint T,std::string hobby)
{
    //递归调用用于求指定name的子树结点
    if(T==nullptr) return nullptr;
    ChildAVLpoint p=T,q;
    if(p)
    {
        if(strcmp(p->data.name,hobby.c_str())==0)
            return p;
        q=SearchHobbyAVLbyname(p->lchild,hobby);
        if(q)
            return q;
        else
            return SearchHobbyAVLbyname(p->rchild,hobby);
    }
    return nullptr;
}

/*插入算法*/
/**
 * 函数名称：InsertChildAVL
 * 函数参数：Treepoint *T，子树数据结点e，用于判断是否增高的bool变量的指针
 * 函数功能：插入子树的结点
 * 返回值：TRUE FALSE
 * 调用说明：用于插入子树
 **/
int InsertChildAVL(ChildAVLpoint *T,childelemnode e,bool *taller)
{
    //若在平衡的二叉排序树T中不存在和e有相同关键字的结点则插入一个数据元素
    //为e的新节点，并返回TRUE否则返回FALSE，若因插入而使二叉排序树失去平衡，则作平衡
    //旋转处理，布尔变量taller反映T长高没有
    //
    if(*T==nullptr)     //插入新节点 树长高 置taller为TRUE
    {
        (*T)=(ChildAVLpoint)malloc(sizeof(ChildAVLtree));
        if(*T==nullptr) return FALSE;
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=nullptr;
        (*T)->bf=EH;
        *taller=TRUE;
    }
    else
    {
        if(e.key==(*T)->data.key)     //树中已存在和e有相同关键字的结点
        {
            *taller=FALSE;  //不再插入
            return FALSE;
        }
        if(e.key<(*T)->data.key)  //应继续在*T的左子树中搜索
        {
            if(!InsertChildAVL(&((*T)->lchild),e,taller)) return FALSE;  //未插入
            if(*taller)  //已插入到*T的左子树中且左子树长高
            switch((*T)->bf)  //检查*T的平衡度
            {
                case LH: ChildLeftBalance(T); *taller=FALSE; break;//原本左子树比右子树高 需要左平衡处理
                case EH: (*T)->bf=LH; *taller=TRUE; break;//原本左右子树等高 现因左子树增高而使树增高
                case RH: (*T)->bf=EH; *taller=FALSE; break;//原本右子树比左子树高，现在等高
            }
        }
        else
            {                           //应继续在*T的右子树中进行搜索
                if(!InsertChildAVL(&((*T)->rchild),e,taller))  return FALSE;// 未插入
                if(*taller)  //已插入到*T的右子树且右子树长高
                switch((*T)->bf){ //检查*T的平衡度
                case LH: (*T)->bf=EH; *taller=FALSE; break;  //原本*T的左子树比右子树高 现在等高
                case EH: (*T)->bf=RH; *taller=TRUE; break;  //原本左右子树等高 现因右子树增高而使树增高
                case RH: ChildRightBalance(T); *taller=FALSE; break;  //原本右子树比左子树高 需作右平衡处理
                }
            }
    }
    return TRUE;
}

/*调整算法*/
/**
 * 函数名称：ChildR_Rotate
 * 函数参数：Treepoint *p
 * 函数功能：右旋操作
 * 返回值：void
 * 调用说明：用于插入删除时的调整
 **/
void ChildR_Rotate(ChildAVLpoint *p)
{
    //对以*为根的二叉排序树作右旋处理，处理之后p指向新的树根结点，即旋转
    //处理之前的左子树根结点
    ChildAVLpoint lc;
    lc=(*p)->lchild;   //lc指向的*p的左子树根结点
    (*p)->lchild=lc->rchild;  //lc的右子树挂接为*p的左子树
    lc->rchild=(*p);   //p指向新的根节点
    (*p)=lc;
}

/**
 * 函数名称：ChildL_Rotate
 * 函数参数：Treepoint *p
 * 函数功能：左旋操作
 * 返回值：void
 * 调用说明：用于插入删除时的调整
 **/
void ChildL_Rotate(ChildAVLpoint *p)
{
    //对以*p为根的二叉排序树作左旋处理，处理之后p指向新的树根结点，即旋转
    //处理之前的右子树的根结点
    ChildAVLpoint rc;
    rc=(*p)->rchild;     //rc指向的*p的右子树根结点
    (*p)->rchild=rc->lchild;    //rc的左子树挂接为*p的右子树
    rc->lchild=(*p);    //p指向新的根节点
    (*p)=rc;
}

/**
 * 函数名称：ChildLeftBalance
 * 函数参数：Treepoint *T
 * 函数功能：左平衡函数
 * 返回值：void
 * 调用说明：当左高时需要左平衡时调用
 **/
void ChildLeftBalance(ChildAVLpoint *T)
{
    //对以指针T所指结点为根的二叉树作左平衡旋转处理，本算法结束时，指针T指向
    //新的根结点
    ChildAVLpoint lc,rd;
    lc=(*T)->lchild;    //lc指向*T的左子树根结点
    switch(lc->bf){     //检查*T的左子树的平衡度，并作相应平衡处理
    case LH:             //新结点插入在*T的左孩子的左子树上，要作单右旋处理
        (*T)->bf=lc->bf=EH;
         ChildR_Rotate(T);
         break;
    case RH:           //新结点插入在*T的左孩子的右子树上，要作双旋处理
        rd=lc->rchild; //rd指向*T的左孩子的右子树根
        switch(rd->bf) //修改*T及其左孩子的平衡因子
        {
            case LH: (*T)->bf=RH;   lc->bf=EH; break;
            case EH: (*T)->bf=lc->bf=EH;       break;
            case RH: (*T)->bf=EH; lc->bf=LH;   break;
        }
        rd->bf=EH;
        ChildL_Rotate(&(*T)->lchild); //对*T的左子树作左旋平衡处理
        ChildR_Rotate(T);  //对*T作右平衡旋转处理
    }
}

/**
 * 函数名称：ChildRightBalance
 * 函数参数：Treepoint *T
 * 函数功能：右平衡函数
 * 返回值：void
 * 调用说明：当右高时需要右平衡时调用
 **/
void ChildRightBalance(ChildAVLpoint *T)
{
    //对以指针T所指结点为根的二叉树作右平衡旋转处理，本算法结束时，指针T指向
    //新的根结点
    ChildAVLpoint rc,ld;
    rc=(*T)->rchild;  //lc指向*T的右子树根结点
    switch(rc->bf){   //检查*T的右子树的平衡度，并作相应平衡处理
    case RH:           //新结点插入在*T的右孩子的右子树上，要作单独左旋处理
         (*T)->bf=rc->bf=EH;
         ChildL_Rotate(T);
         break;
    case LH:         //新结点插入在*T的右孩子的左子树上，要作双旋处理
         ld=rc->lchild;   //rd指向*T的右孩子的左子树根
         switch(ld->bf)    //修改*T及其右孩子的平衡因子
         {
             case RH:(*T)->bf=LH; rc->bf=EH; break;
             case EH:(*T)->bf=rc->bf=EH;     break;
             case LH:(*T)->bf=EH; rc->bf=RH; break;
         }
         ld->bf=EH;
         ChildR_Rotate(&(*T)->rchild); //对*T的右子树作右旋平衡处理
         ChildL_Rotate(T);         //对*T作左平衡旋转处理
    }
}

/*遍历算法*/
/**
 * 函数名称：TraverseChildAVL
 * 函数参数：T 用于打印的lambda表达式callable 对应选项的choice
 * 函数功能：子树遍历调用
 * 返回值：int
 * 调用说明：用于控制遍历方式的选择
 **/
int TraverseChildAVL(ChildAVLpoint T,int choice,std::function<void(childelemnode)> callable)
{
    switch (choice){
    case 0:  ChildPreOrderTraverse(T,callable); break;  //前序遍历
    case 1:  ChildInOrderTraverse(T,callable); break;   //中序遍历
    case 2:  ChildPostOrderTraverse(T,callable); break; //后序遍历
    case 3:  ChildLevelOrderTraverse(T,callable); break; //按层遍历
    default : break;
    }
    return TRUE;
}


/*遍历算法*/
/**
 * 函数名称：ChildPreOrderTraverse
 * 函数参数：T  用于打印的lambda表达式callable
 * 函数功能：先序遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于先序遍历
 **/
int ChildPreOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable)
{
    //先打印再左右递归实现前序遍历
    if(T==nullptr) return FALSE;
    else
    {
        callable(T->data);   //先打印根再依次访问左右子树
        ChildPreOrderTraverse(T->lchild,callable);
        ChildPreOrderTraverse(T->rchild,callable);
    }
    return TRUE;
}


/**
 * 函数名称： ChildInOrderTraverse
 * 函数参数： T  用于打印的lambda表达式callable
 * 函数功能： 中序遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于中序遍历
 **/
int ChildInOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable)
{
    //先对左右子树递归再打印再对右子树递归实现中序遍历
    if(T==nullptr) return FALSE;
    else
    {
        ChildInOrderTraverse(T->lchild,callable);  //先访问左子树再访问根再访问右子树
        callable(T->data);
        ChildInOrderTraverse(T->rchild,callable);
    }
    return TRUE;
}


/**
 * 函数名称：ChildPostOrderTraverse
 * 函数参数：T  用于打印的lambda表达式callable
 * 函数功能：后序遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于后序遍历
 **/
int ChildPostOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable)
{
    //先对左右子树递归再打印实现后序遍历
    if(T==nullptr) return FALSE;
    else
    {
        ChildPostOrderTraverse(T->lchild,callable);  //先访问左右子树再访问根
        ChildPostOrderTraverse(T->rchild,callable);
        callable(T->data);
    }
    return TRUE;
}

/**
 * 函数名称：ChildLevelOrderTraverse
 * 函数参数：T  用于打印的lambda表达式callable
 * 函数功能：按层遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于按层遍历
 **/
int ChildLevelOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable)
{
    if(T==nullptr) return FALSE;
    std::queue<ChildAVLpoint> queue;
    queue.push(T);
    while(!queue.empty())  //队列不为空进入循环
    {
        ChildAVLpoint p = queue.front();
        queue.pop();  //出队列
        callable(p->data);
        if (p->lchild != nullptr) //若该结点的左子树不为空就将该结点的左孩子存入队列中
            queue.push(p->lchild);
        if (p->rchild != nullptr)//若该结点的左子树不为空就将该结点的左孩子存入队列中
            queue.push(p->rchild);
    }
    return TRUE;
}

/*删除算法*/
/**
 * 函数名称：DeleteChildAVL
 * 函数参数：Treepoint *T，删除结点的key 表示树是否变短的bool变量的指针shorter
 * 函数功能：删除平衡二叉树
 * 返回值：TRUE FALSE
 * 调用说明：用于删除结点
 **/
int DeleteChildAVL(ChildAVLpoint *T,int e,bool * shorter)
{
    //若在平衡的二叉排序树T中存在和*e有相同关键字的结点，则删除这个元素
    //并返回TRUE否则返回FALSE，若因删除而使二叉排序树失去平衡，则作平衡处理
    //布尔变量shorter反映变矮与否
    if(T==nullptr) return FALSE;
    if(*T==nullptr) return FALSE;
    if((*T)->data.key==e)   //找到元素结点
    {
        ChildAVLtree *q=nullptr;
        if((*T)->lchild==nullptr)  //左子树为空或者左右子树为空
        {
            q=*T;
            *T=(*T)->rchild;
            free(q);
            *shorter=TRUE;
        }
        else if((*T)->rchild==nullptr)  //右子树为空
        {
            q=*T;
            *T=(*T)->lchild;
            free(q);
            *shorter=TRUE;
        }
        else         //左右子树都存在
        {
            q=(*T)->lchild;
            while(q->rchild)
                q=q->rchild;
            (*T)->data=q->data;
            DeleteChildAVL(&((*T)->lchild),q->data.key,shorter); //在左子树中递归删除前驱结点
        }
    }
    else if(e<(*T)->data.key)  //在左子树中继续查找
    {
        if(!DeleteChildAVL(&((*T)->lchild),e,shorter))
        {
            return FALSE;
        }
        if(*shorter)
        {
            switch((*T)->bf)
            {
               case LH:
                    (*T)->bf=EH;
                    *shorter=TRUE;
                    break;
               case EH:
                    (*T)->bf=RH;
                    *shorter=FALSE;
                    break;
               case RH:
                    ChildRightBalance(T);  //右平衡处理
                    if((*T)->rchild->bf==EH)
                        *shorter=FALSE;
                    else
                        *shorter=TRUE;
                    break;
            }
        }
    }
    else           //右子树中继续查找
    {
        if(!DeleteChildAVL(&((*T)->rchild),e,shorter))
        {
            return FALSE;
        }
        if(*shorter)
        {
            switch((*T)->bf)
            {
                case LH:
                    ChildLeftBalance(T);   //左平衡处理
                    if((*T)->lchild->bf==EH)
                        *shorter=FALSE;
                    else
                        *shorter=TRUE;
                    break;
                case EH:
                    (*T)->bf=LH;
                    *shorter=FALSE;
                    break;
                case RH:
                    (*T)->bf=EH;
                    *shorter=TRUE;
                    break;
            }
        }
    }
    return TRUE;
}
