#include "head.h"
/*初始化算法*/
/**
 * 函数名称：InitAVL
 * 函数参数：struct tree *T
 * 函数功能：初始化
 * 返回值：TRUE FALSE
 * 调用说明：用于初始化系统
 **/
int InitAVL(struct tree * T)
{
    if(T->exists) return FALSE;  //exists表示是否初始化
    T->exists=true;              //true表示已经初始化
    return TRUE;
}


/*摧毁算法*/
/**
 * 函数名称：DestroyAVL
 * 函数参数：BSTree *T
 * 函数功能：摧毁树
 * 返回值：TRUE FALSE
 * 调用说明：用于摧毁二叉树
 **/
int DestroyAVL(AVLpoint *T)
{
    if(*T==nullptr) return FALSE;
    if((*T)->lchild)
        DestroyAVL(&((*T)->lchild));
    if((*T)->rchild)
        DestroyAVL(&((*T)->rchild));
    DestroyChildAVL(&(*T)->data.follow);   //销毁关注子树
    DestroyChildAVL(&(*T)->data.follower); //销毁粉丝子树
    DestroyChildAVL(&(*T)->data.friends);  //销毁朋友子树
    DestroyChildAVL(&(*T)->data.hobby);    //销毁爱好子树
    free(*T);
    *T=NULL;
    return TRUE;
}

/*搜索算法*/
/**
 * 函数名称：searchAVL
 * 函数参数：BSTree T，key
 * 函数功能：搜索key对应的结点的指针
 * 返回值：key对应的结点的指针或者是nullptr
 * 调用说明：用于各项搜索
 **/
AVLpoint SearchAVL(AVLpoint T,int key)
{
    /*递归调用用于求指定key的结点*/
    if(T==nullptr) return nullptr;
    AVLpoint p=T,q;
    if(p)
    {
        if(p->data.key==key) return p;  //相等
        q=SearchAVL(p->lchild,key);  //对左右子树递归
        if(q)
            return q;
        else
            return SearchAVL(p->rchild,key);
    }
    return nullptr;
}

/*插入算法*/
/**
 * 函数名称：InsertAVL
 * 函数参数：BSTree *T,插入结点数据elemnode,用于在递归中判断增高的bool变量指针taller
 * 函数功能：插入结点
 * 返回值：TRUE FALSE
 * 调用说明：用于插入平衡二叉树
 **/
int InsertAVL(AVLpoint *T,elemnode e,bool *taller)
{
    //若在平衡的二叉排序树T中不存在和e有相同关键字的结点,则插入一个数据元素
    //为e的新结点，并返回1否则返回0，若因插入而使二叉排序树失去平衡，则作平衡
    //旋转处理，布尔变量taller反应T长高没有
    //if(T==nullptr) return FALSE;
    if(*T==nullptr){  //插入新结点 树长高 置taller为TRUE
    (*T)=(AVLpoint)malloc(sizeof(AVLtree));
    if(*T==nullptr) return FALSE;
    (*T)->data=e;
    (*T)->lchild=(*T)->rchild=nullptr;
    (*T)->bf=EH;
    *taller=TRUE;
    }
    else{
        if(e.key==(*T)->data.key)     //树中已存在和e有相同关键字的结点
        {
            *taller=FALSE;     //不再插入
            return FALSE;
        }
        if(e.key<(*T)->data.key)      //应继续在*T的左子树中搜索
        {
            if(!InsertAVL(&(*T)->lchild,e,taller)) return FALSE; //未插入
            if(*taller)  //已插入到*T的左子树中且左子树长高
            switch((*T)->bf){  //检查*T的平衡度
            case LH: LeftBalance(T);*taller=FALSE;break;  //原本左子树比右子树高 需要左平衡处理
            case EH: (*T)->bf=LH;*taller=TRUE;break; //原本左右子树等高 现因左子树增高而使树增高
            case RH: (*T)->bf=EH;*taller=FALSE;break; //原本右子树比左子树高，现在等高
            }
        }
        else{                                    //应继续在*T的右子树中进行搜索
            if(!InsertAVL(&(*T)->rchild,e,taller)) return FALSE;   //未插入
            if(*taller)    //已插入到*T的右子树且右子树长高
            switch((*T)->bf){   //检查*T的平衡度
            case LH: (*T)->bf=EH; *taller=FALSE; break;  //原本*T的左子树比右子树高 现在等高
            case EH: (*T)->bf=RH; *taller=TRUE; break;  //原本左右子树等高 现因右子树增高而使树增高
            case RH: RightBalance(T);*taller=FALSE;break; //原本右子树比左子树高 需作右平衡处理
            }
        }
    }
    return TRUE;
}

/*调整算法*/
/**
 * 函数名称：R_Rotate
 * 函数参数：BSTree *p
 * 函数功能：右旋操作
 * 返回值：void
 * 调用说明：用于插入删除时的调整
 **/
void R_Rotate(AVLpoint *p)
{
    //对以*为根的二叉排序树作右旋处理，处理之后p指向新的树根结点，即旋转
    //处理之前的左子树的根结点
    AVLpoint lc;
    lc=(*p)->lchild;           //lc指向的*p的左子树根结点
    (*p)->lchild=lc->rchild;  //lc的右子树挂接为*p的左子树
    lc->rchild=(*p);             //p指向新的根节点
    (*p)=lc;
}

/**
 * 函数名称：L_Rotate
 * 函数参数：BSTree *p
 * 函数功能：左旋操作
 * 返回值：void
 * 调用说明：用于插入删除时的调整
 **/
void L_Rotate(AVLpoint *p)
{
    //对以*p为根的二叉排序树作左旋处理，处理之后p指向新的树根结点，即旋转
    //处理之前的右子树的根结点
    AVLpoint rc;
    rc=(*p)->rchild;            //rc指向的*p的右子树根结点
    (*p)->rchild=rc->lchild;   //rc的左子树挂接为*p的右子树
    rc->lchild=(*p);             //p指向新的根节点
    (*p)=rc;
}

/**
 * 函数名称：LeftBalance
 * 函数参数：BSTree *T
 * 函数功能：左平衡函数
 * 返回值：void
 * 调用说明：当左高时需要左平衡时调用
 **/
void LeftBalance(AVLpoint *T)
{
    //对以指针T所指结点为根的二叉树作左平衡旋转处理，本算法结束时，指针T指向
    //新的根结点
    AVLpoint lc,rd;
    lc=(*T)->lchild;   //lc指向*T的左子树根结点
    switch(lc->bf){    //检查*T的左子树的平衡度，并作相应平衡处理
    case LH:           //新结点插入在*T的左孩子的左子树上，要作单右旋处理
        (*T)->bf=lc->bf=EH;
         R_Rotate(T);
         break;
    case RH:           //新结点插入在*T的左孩子的右子树上，要作双旋处理
        rd=lc->rchild; //rd指向*T的左孩子的右子树根
        switch(rd->bf) //修改*T及其左孩子的平衡因子
        {
            case LH:(*T)->bf=RH;  lc->bf=EH;  break;
            case EH:(*T)->bf=lc->bf=EH;       break;
            case RH:(*T)->bf=EH; lc->bf=LH;   break;
        }
        rd->bf=EH;
        L_Rotate(&(*T)->lchild);   //对*T的左子树作左旋平衡处理
        R_Rotate(T);               //对*T作右平衡旋转处理
    }
}

/**
 * 函数名称：RightBalance
 * 函数参数：BSTree *T
 * 函数功能：右平衡函数
 * 返回值：void
 * 调用说明：当右高时需要右平衡时调用
 **/
void RightBalance(AVLpoint *T)
{
    //对以指针T所指结点为根的二叉树作右平衡旋转处理，本算法结束时，指针T指向
    //新的根结点
    AVLpoint rc,ld;
    rc=(*T)->rchild; //rc指向*T的右子树根结点
    switch(rc->bf){  //检查*T的右子树的平衡度，并作相应平衡处理
    case RH:         //新结点插入在*T的右孩子的右子树上，要作单独左旋处理
        (*T)->bf=rc->bf=EH;
        L_Rotate(T);
        break;
    case LH:            //新结点插入在*T的右孩子的左子树上，要作双旋处理
        ld=rc->lchild;  //rd指向*T的右孩子的左子树根
        switch(ld->bf)  //修改*T及其右孩子的平衡因子
        {
            case RH:(*T)->bf=LH; rc->bf=EH; break;
            case EH:(*T)->bf=rc->bf=EH;     break;
            case LH:(*T)->bf=EH; rc->bf=RH; break;
        }
        ld->bf=EH;
        R_Rotate(&(*T)->rchild);  //对*T的右子树作右旋平衡处理
        L_Rotate(T);              //对*T作左平衡旋转处理
    }
}

/*遍历算法*/
/**
 * 函数名称：TraverseAVL
 * 函数参数：T 用于打印的lambda表达式callable 对应选项的choice
 * 函数功能：遍历调用
 * 返回值：void
 * 调用说明：用于控制遍历方式的选择
 **/
void TraverseAVL(AVLpoint T, std::function<void(elemnode)> callable,int choice)
{
    switch (choice){
    case 0:  PreOrderTraverse(T, callable);      break;  //前序遍历
    case 1:  InOrderTraverse(T, callable);       break;  //中序遍历
    case 2:  PostOrderTraverse(T, callable);     break;  //后序遍历
    case 3:  LevelOrderTraverse(T, callable);    break;  //按层遍历
    default : break;
    }
}
/**
 * 函数名称：PreOrderTraverse
 * 函数参数：T 用于打印的lambda表达式callable
 * 函数功能：先序遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于前序遍历
 **/
int PreOrderTraverse(AVLpoint T,std::function<void(elemnode)> callable)
{
    //先打印再左右递归实现前序遍历
    if(T==nullptr) return FALSE;
    else
    {
        callable(T->data);  //先打印根再依次访问左右子树
        PreOrderTraverse(T->lchild,callable);
        PreOrderTraverse(T->rchild,callable);
    }
    return TRUE;
}
/**
 * 函数名称：InOrderTraverse
 * 函数参数：T 用于打印的lambda表达式callable
 * 函数功能：中序遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于中序遍历
 **/
int InOrderTraverse(AVLpoint T,std::function<void(elemnode)> callable)
{
    //先对左子树递归再打印再对右子树递归实现中序遍历
    if(T==nullptr) return FALSE;
    else
    {
        InOrderTraverse(T->lchild,callable);    //先访问左子树再访问根再访问右子树
        callable(T->data);
        InOrderTraverse(T->rchild,callable);
    }
    return TRUE;
}

/**
 * 函数名称：PostOrderTraverse
 * 函数参数：T 用于打印的lambda表达式callable
 * 函数功能：后序遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于后序遍历
 **/
int PostOrderTraverse(AVLpoint T,std::function<void(elemnode)> callable)
{
    //先对左右子树递归再打印实现后序遍历
    if(T==nullptr) return FALSE;
    else
    {
        PostOrderTraverse(T->lchild,callable);   //先访问左右子树再访问根
        PostOrderTraverse(T->rchild,callable);
        callable(T->data);
    }
    return TRUE;
}
/**
 * 函数名称：LevelOrderTraverse
 * 函数参数：T 用于打印的lambda表达式callable
 * 函数功能：按层遍历
 * 返回值：TRUE FALSE
 * 调用说明：用于按层遍历
 **/
int LevelOrderTraverse(AVLpoint T, std::function<void(elemnode)> callable)
{
    if(T==nullptr)   return FALSE;
    AVLpoint p;
    AVLpoint queue[AVL_COURSE_DESIGN_QUEUE_LENGTH]; //指针数组存数据
    int front,rear;
    front=rear=-1;
    rear++;
    queue[rear]=T;
    while(front!=rear) //队列不为空进入循环
    {
        front=(front+1)%AVL_COURSE_DESIGN_QUEUE_LENGTH; //循环队列front前进一格
        p=queue[front];  //记录当前front所指指针
        callable(p->data);  //打印结点
        if(p->lchild!=nullptr)//若该结点的左子树不为空就将该结点的左孩子存入队列中
        {
            rear=(rear+1)%AVL_COURSE_DESIGN_QUEUE_LENGTH;
            queue[rear]=p->lchild;
        }
        if(p->rchild!=nullptr)//若该结点的左子树不为空就将该结点的左孩子存入队列中
        {
            rear=(rear+1)%AVL_COURSE_DESIGN_QUEUE_LENGTH;
            queue[rear]=p->rchild;
        }
    }
    return TRUE;
}

/*删除算法*/
/**
 * 函数名称：DeleteAVL
 * 函数参数：BSTree *T 删除结点的key 表示树是否变短的bool变量的指针shorter
 * 函数功能：删除平衡二叉树
 * 返回值：TRUE FALSE
 * 调用说明：用于删除结点
 **/
int DeleteAVL(AVLpoint *T,int e,bool *shorter)
{
    //若在平衡的二叉排序树T中存在和*e有相同关键字的结点，则删除这个元素
    //并返回TRUE否则返回FALSE，若因删除而使二叉排序树失去平衡，则作平衡处理
    //布尔变量shorter反映变矮与否
    if(T==nullptr) return FALSE;
    if(*T==nullptr) return FALSE;
    if((*T)->data.key==e)   //找到元素结点
    {
        AVLtree *q=nullptr;
        if((*T)->lchild==nullptr)   //左子树为空或者左右子树为空
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
        else                      //左右子树都存在
        {
            q=(*T)->lchild;
            while(q->rchild)
                q=q->rchild;
           (*T)->data=q->data;
            DeleteAVL(&((*T)->lchild),q->data.key,shorter);   //在左子树中递归删除前驱结点

        }
    }
    else if(e<(*T)->data.key)     //在左子树中继续查找
    {
        if(!DeleteAVL(&((*T)->lchild),e,shorter))
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
                    RightBalance(T);  //右平衡处理
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
        if(!DeleteAVL(&((*T)->rchild),e,shorter))
        {
            return FALSE;
        }
        if(*shorter)
        {
            switch((*T)->bf)
            {
                case LH:
                    LeftBalance(T);   //左平衡处理
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
