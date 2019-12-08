#include "head.h"
/*初始化算法*/
/**
 * 函数名称：tinyInitAVL
 * 函数参数：初始化子树
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
int tinyInitAVL(Treepoint *T)
{
    *T=(Treepoint)malloc(sizeof(Treenode));
    if(*T==NULL) return FALSE;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
    (*T)->bf=0;
    return TRUE;
}
/*搜索算法*/
/**
 * 函数名称：tinysearchAVL
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
Treepoint tinysearchAVL(Treepoint T,int e)
{
    if(T==NULL) return NULL;
    Treepoint p=T,q;
    if(p)
    {
        if(p->data.key==e) return p;
        q=tinysearchAVL(p->lchild,e);
        if(q)
            return q;
        else
            return tinysearchAVL(p->rchild,e);
    }
    return NULL;
}
/*插入算法*/
/**
 * 函数名称：InsertAVLnode
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status InsertAVLnode(Treepoint *T,tinyelemnode e,bool *taller)
{

    if(*T==NULL)
    {
        (*T)=(Treepoint)malloc(sizeof(Treenode));
        if(*T==NULL) return FALSE;
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->bf=EH;
        *taller=TRUE;
    }
    else
    {
        if(e.key==(*T)->data.key)     //树中已存在和e有相同关键字的结点
        {
            *taller=FALSE;
            return FALSE;
        }
        if(e.key<(*T)->data.key)
        {
            if(!InsertAVLnode(&((*T)->lchild),e,taller))       return FALSE;
            if(*taller)
            switch((*T)->bf)
            {
                case LH: tinyLeftBalance(T); *taller=FALSE; break;
                case EH: (*T)->bf=LH; *taller=TRUE; break;
                case RH: (*T)->bf=EH; *taller=FALSE; break;
            }
        }
        else
            {
                if(!InsertAVLnode(&((*T)->rchild),e,taller))  return FALSE;
                if(*taller)
                switch((*T)->bf){
                case LH: (*T)->bf=EH; *taller=FALSE; break;
                case EH: (*T)->bf=RH; *taller=TRUE; break;
                case RH: tinyRightBalance(T); *taller=FALSE; break;
                }
            }
    }
    return TRUE;
}

/*插入删除相关*/
/**
 * 函数名称：tinyR_Rotate
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
void tinyR_Rotate(Treepoint *p)
{
    Treepoint lc;
    lc=(*p)->lchild;
    (*p)->lchild=lc->rchild;
    lc->rchild=(*p);
    (*p)=lc;
}

/**
 * 函数名称：tinyL_Rotate
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
void tinyL_Rotate(Treepoint *p)
{
    Treepoint rc;
    rc=(*p)->rchild;
    (*p)->rchild=rc->lchild;
    rc->lchild=(*p);
    (*p)=rc;
}

/**
 * 函数名称：tinyLeftBalance
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
void tinyLeftBalance(Treepoint *T)
{
    Treepoint lc,rd;
    lc=(*T)->lchild;
    switch(lc->bf){
    case LH:
        (*T)->bf=lc->bf=EH;
         tinyR_Rotate(T);
         break;
    case RH:
        rd=lc->rchild;
        switch(rd->bf)
        {
            case LH: (*T)->bf=RH;   lc->bf=EH; break;
            case EH: (*T)->bf=lc->bf=EH;       break;
            case RH: (*T)->bf=EH; lc->bf=LH;   break;
        }
        rd->bf=EH;
        tinyL_Rotate(&(*T)->lchild);
        tinyR_Rotate(T);
    }
}

/**
 * 函数名称：tinyRightBalance
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
void tinyRightBalance(Treepoint *T)
{
    Treepoint rc,ld;
    rc=(*T)->rchild;
    switch(rc->bf){
    case RH:
         (*T)->bf=rc->bf=EH;
         tinyL_Rotate(T);
         break;
    case LH:
         ld=rc->lchild;
         switch(ld->bf)
         {
             case RH:(*T)->bf=LH; rc->bf=EH; break;
             case EH:(*T)->bf=rc->bf=EH;     break;
             case LH:(*T)->bf=EH; rc->bf=RH; break;
         }
         ld->bf=EH;
         tinyR_Rotate(&(*T)->rchild);
         tinyL_Rotate(T);
    }
}

/*删除算法*/
/**
 * 函数名称：tinyDeleteAVL
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
int tinyDeleteAVL(Treepoint *T,int e,bool * shorter)
{
    if(T==NULL) return FALSE;
    if(*T==NULL) return FALSE;
    if((*T)->data.key==e)
    {
        Treenode *q=NULL;
        if((*T)->lchild==NULL)
        {
            q=*T;
            *T=(*T)->rchild;
            free(q);
            *shorter=TRUE;
        }
        else if((*T)->rchild==NULL)
        {
            q=*T;
            *T=(*T)->lchild;
            free(q);
            *shorter=TRUE;
        }
        else
        {
            q=(*T)->lchild;
            while(q->rchild)
                q=q->rchild;
            (*T)->data=q->data;
            tinyDeleteAVL(&((*T)->lchild),q->data.key,shorter);
        }
    }
    else if(e<(*T)->data.key)
    {
        if(!tinyDeleteAVL(&((*T)->lchild),e,shorter))
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
                    tinyRightBalance(T);
                    if((*T)->rchild->bf==EH)
                        *shorter=FALSE;
                    else
                        *shorter=TRUE;
                    break;
            }
        }
    }
    else
    {
        if(!tinyDeleteAVL(&((*T)->rchild),e,shorter))
        {
            return FALSE;
        }
        if(*shorter)
        {
            switch((*T)->bf)
            {
                case LH:
                    tinyLeftBalance(T);
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
