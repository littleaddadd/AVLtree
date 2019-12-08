#ifndef AVL_COURSE_DESIGN_HEAD_H_ICNLUDED
#define AVL_COURSE_DESIGN_HEAD_H_ICNLUDED
#include <string>
#include <functional>
#include <cstring>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define TRUE	1
#define FALSE	0

#define LH 1  //左高
#define EH 0  //等高
#define RH -1  //右高
#define AVL_COURSE_DESIGN_QUEUE_LENGTH 100
#define AVL_FRIEND 2
#define AVL_USER1_FOLLOW_USER2 3
#define AVL_USER2_FOLLOW_USER1 4
#define AVL_USER_NO_RELATION   5
#define AVL_RANDOM_HOBBY_NUM 20

//enum class relationtype{friends,a_follow_b,b_follow_a,none};
/*主树的信息结点*/
typedef struct AVLdata{
int key;                   //key
char name[20];             //名
struct ChildAVLtree *friends;  //用户的好友树
struct ChildAVLtree *follow;   //用户的关注树
struct ChildAVLtree *follower; //用户的粉丝树
struct ChildAVLtree *hobby;    //用户的喜好树
}*elempoint,elemnode;

/*主树的结点*/
typedef struct AVLtree{
elemnode data;             //主树结点的数据域
int bf;                    //结点的平衡因子
struct AVLtree *lchild,*rchild; //左右孩子指针
}AVLtree, *AVLpoint;

/*子树的信息结点*/
typedef struct ChildAVLdata
{
    int key;               //key
    char name[20];         //名
}childelemnode,*childelempoint;

/*子树的结点*/
typedef struct ChildAVLtree
{
  childelemnode data;     //子树结点的数据域
  int bf;                 //结点的平衡因子
  struct ChildAVLtree *lchild,* rchild;  //左右孩子指针
}ChildAVLtree,*ChildAVLpoint;

/*树结构*/
struct tree{
    bool exists=false;   //树存在状态记录
    AVLpoint tree = nullptr;
};



/*AVL_cpp*/
/*初始化算法*/
int InitAVL(tree *T);                  //初始化
/*摧毁算法*/
int DestroyAVL(AVLpoint *T);             //摧毁
/*搜索算法*/
AVLpoint SearchAVL(AVLpoint T, int key);   //搜索
/*插入算法*/
int InsertAVL(AVLpoint *T,elemnode e,bool *taller); //插入
/*调整算法*/
void R_Rotate(AVLpoint *p);      //右旋转
void L_Rotate(AVLpoint *p);      //左旋转
void LeftBalance(AVLpoint *T);   //左平衡
void RightBalance(AVLpoint *T);  //右平衡
/*遍历算法*/
void TraverseAVL(AVLpoint T, std::function<void(elemnode)> callable, int choice);//遍历
int PreOrderTraverse(AVLpoint T,std::function<void(elemnode)> callable);         //前序遍历
int InOrderTraverse(AVLpoint T,std::function<void(elemnode)> callable);          //中序遍历
int PostOrderTraverse(AVLpoint T,std::function<void(elemnode)> callable);        //后序遍历
int LevelOrderTraverse(AVLpoint T, std::function<void(elemnode)> callable);      //按层遍历
/*删除算法*/
int DeleteAVL(AVLpoint *T,int e,bool *shorter);            //删除



/*ChildAVL_cpp*/
/*摧毁算法*/
int DestroyChildAVL(ChildAVLpoint *T);                       //摧毁
/*搜索算法*/
ChildAVLpoint SearchChildAVLbykey(ChildAVLpoint T,int e);         //key搜索
ChildAVLpoint SearchHobbyAVLbyname(ChildAVLpoint T,std::string hobby); //name搜索
/*插入算法*/
int InsertChildAVL(ChildAVLpoint *T,childelemnode e,bool *taller);   //插入
/*调整算法*/
void ChildR_Rotate(ChildAVLpoint *p);        //右旋转
void ChildL_Rotate(ChildAVLpoint *p);        //左旋转
void ChildLeftBalance(ChildAVLpoint *T);     //左平衡
void ChildRightBalance(ChildAVLpoint *T);    //右平衡
/*遍历算法*/
int TraverseChildAVL(ChildAVLpoint T,int choice,std::function<void(childelemnode)> callable);  //遍历函数
int ChildPreOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable);        //前序遍历
int ChildInOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable);         //中序遍历
int ChildPostOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable);       //后序遍历
int ChildLevelOrderTraverse(ChildAVLpoint T,std::function<void(childelemnode)> callable);      //按层遍历
/*删除算法*/
int DeleteChildAVL(ChildAVLpoint *T,int e,bool * shorter);           //删除


/*set_cpp*/
int set_init(struct tree * T);          //初始化
int set_destroy(struct tree * T);       //摧毁
int set_insert(AVLpoint *T, elempoint data,bool *taller);  //插入
int set_remove(AVLpoint *T,int key);                   //删除
int set_intersection(AVLpoint T1,AVLpoint T2,AVLpoint *intersectiontree); //交
int set_union(AVLpoint T1,AVLpoint T2,AVLpoint *uniontree); //并
int set_difference(AVLpoint T1,AVLpoint T2,AVLpoint *differencetree); //差
int set_size(AVLpoint T);                   //个数
AVLpoint set_member(AVLpoint T, int key);     //查找
void set_subset(AVLpoint T1,AVLpoint T2,bool *judge);  //判断子集
int set_equal(AVLpoint T1,AVLpoint T2);       //判断相等

/*apply_user_cpp*/
//调用set_insert添加用户
//调用set_remove删除用户
int user_modify(AVLpoint *T,int key,std::string name);                    //修改用户
//调用set_member查找用户
//调用set_size当前用户数
void user_traverse(AVLpoint T, std::function<void(elemnode)> callable,int choice);//遍历所有用户


/*apply_relation_cpp*/
//添加社交关系
int relation_insert(AVLpoint *T,int key1,int key2,int choice);  //添加社交关系主函数
int friend_relation_insert(AVLpoint *T,int key1,int key2);               //添加朋友关系
int follow_relation_insert(AVLpoint *T,int key1,int key2);               //添加关注关系
int follower_relation_insert(AVLpoint *T,int key1,int key2);             //添加粉丝关系
//删除社交关系
int relation_remove(AVLpoint *T,int key1,int key2,int choice);  //删除社交关系主函数
int friend_relation_remove(AVLpoint *T,int key1,int key2);               //删除朋友关系
int follow_relation_remove(AVLpoint *T,int key1,int key2);               //删除关注关系和粉丝关系
//修改社交关系
int relation_modify(AVLpoint *T,int key1,int key2,int choice);          //修改社交关系
//查询社交关系
int relation_search(AVLpoint T,int key1,int key2);                      //查询社交关系
int follow_relation_search(AVLpoint user1,AVLpoint user2);                 //查询关注
int friend_relation_search(AVLpoint user1,AVLpoint user2);                 //查询朋友
//遍历社交关系
int relation_traverse(AVLpoint T,int key,int choicekind,int choicemanner,std::function<void(childelemnode)> callable);  //遍历社交关系
//清空社交关系
int relation_reset(AVLpoint *T,int key,int choice);                      //清空社交关系
int friend_relation_reset(AVLpoint *T,ChildAVLpoint T1,int key);              //清空朋友
int follow_relation_reset(AVLpoint *T,ChildAVLpoint T1,int key);              //清空关注和粉丝


/*apply_hobby_cpp*/
//添加用户爱好
int hobby_insert(AVLpoint *T,int key,std::string hobbyname);    //添加用户爱好
int hobby_size(ChildAVLpoint T);                                       //求当前爱好个数并赋给key
//删除用户爱好
int hobby_remove(AVLpoint *T,int key,std::string hobbyname);    //删除用户爱好
//修改用户爱好
int hobby_modify(AVLpoint *T,int key,std::string oldhobbyname,std::string newhobbyname);                //修改用户爱好
//查询用户爱好
int hobby_search(AVLpoint T,std::string hobby,std::function<void(elemnode)> callable);                  //查询用户爱好
//遍历用户爱好
int hobby_traverse(AVLpoint T,int key,int choicemanner,std::function<void(childelemnode)> callable);    //遍历用户爱好
//初始化用户爱好
int hobby_reset(AVLpoint *T,int key);                            //清空用户爱好

/*apply_specialfunction*/
//共同关注查询
int bothfollow(AVLpoint T,int key1,int key2,std::function<void(childelemnode)> callable);            //共同关注
int childset_intersectionkey(ChildAVLpoint T1,ChildAVLpoint T2,ChildAVLpoint * bothtree);                      //按key对子树交运算
//共同aihao查询
int bothhobby(AVLpoint T,int key1,int key2,std::function<void(childelemnode)> callable);             //共同爱好
int childset_intersectionname(ChildAVLpoint T1, ChildAVLpoint T2, ChildAVLpoint *bothtree);                    //按名对子树交运算
//二度好友查询
int twodegreefriend(AVLpoint T,int key,std::function<void(childelemnode)> callable);                 //二度好友
int addfriendtree(ChildAVLpoint *twodegreetree,ChildAVLpoint T,AVLpoint T1,ChildAVLpoint T2);                    //添加朋友树
int addtreefriend(ChildAVLpoint *twodegreetree,ChildAVLpoint T,ChildAVLpoint T2);                              //添加朋友树的朋友

/*apply_random_cpp*/
int readnamefile();                                                  //预读取随机姓名库到程序中
int readhobbyfile();                                                 //预读取随机爱好库到程序中
int addrandomuser(AVLpoint *T,int usernum);                            //添加指定规模随机用户
int addrandomhobby(AVLpoint *T);                                       //随机添加爱好
int addrandomfriend(AVLpoint *T);                                      //随机添加朋友
int addrandomfollow(AVLpoint *T);                                      //随机添加关注粉丝

/*file*/
int savefile(AVLpoint T,std::string filename);                         //保存文件
int savetreeinfo(AVLpoint T,std::ofstream& outFile);                   //保存主树
int savechildtreeinfo(std::ofstream &outfile,ChildAVLpoint tree);        //保存子树
int readfile(AVLpoint *T,std::string filename);                        //读取文件
#endif
