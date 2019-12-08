#include "head.h"

/*修改*/
/**
 * 函数名称：set_modify
 * 函数参数：BSTree *T，key，name
 * 函数功能：修改结点
 * 返回值：TRUE FALSE
 * 调用说明：用于实现集合修改功能
 **/
int user_modify(AVLpoint *T,int key,std::string name)
{
    AVLpoint judge;
    judge=SearchAVL(*T,key);        //调用实现修改功能
    if(judge==nullptr) {return FALSE; }
    strcpy(judge->data.name, name.c_str());   //修改名字
    return TRUE;
}

/*遍历*/
/**
 * 函数名称：set_traverse
 * 函数参数：BSTree T，用于打印的lambda表达式callable 选择遍历方式的choice
 * 函数功能：成员遍历
 * 返回值：void
 * 调用说明：用于实现集合的遍历
 **/
void user_traverse(AVLpoint T, std::function<void(elemnode)> callable,int choice)
{
    //调用TraverseAVL函数实现遍历功能
    TraverseAVL(T, callable,choice);
}



