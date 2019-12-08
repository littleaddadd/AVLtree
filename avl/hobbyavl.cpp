#include "head.h"
/*初始化算法*/
/*搜索算法*/
Treepoint tinysearchhobbyAVL(Treepoint T,std::string hobby)
{
    if(T==NULL) return NULL;
    Treepoint p=T,q;
    if(p)
    {
        if(strcmp(p->data.name,hobby.c_str())==0)
            return p;
        q=tinysearchhobbyAVL(p->lchild,hobby);
        if(q)
            return q;
        else
            return tinysearchhobbyAVL(p->rchild,hobby);
    }
    return NULL;
}

int tinyset_size(Treepoint T)
{
    if(T==NULL) return 0;
    return tinyset_size(T->lchild)+tinyset_size(T->rchild)+1;
}

status DestroyhobbyAVL(Treepoint *T)
{
    if(T==NULL) return FALSE;
    if(*T==NULL) return FALSE;
    if((*T)->lchild)
        DestroyhobbyAVL(&((*T)->lchild));
    if((*T)->rchild)
        DestroyhobbyAVL(&((*T)->rchild));
    free(*T);
    *T=NULL;
    return TRUE;
}
