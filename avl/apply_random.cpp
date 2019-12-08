#include "head.h"
#include "fstream"
#include "sstream"

std::vector<std::string> names;  //读取姓名库中的人名
std::vector<std::string> hobby;  //读取爱好库中的爱好

/**
 * 函数名称：readnamefile
 * 函数参数：保存姓名的vector容器
 * 函数功能：将name文件读取到容器中
 * 返回值：TRUE FALSE
 * 调用说明：读取name文件到容器中，用于随机
 **/
int readnamefile()
{
    FILE *fp=nullptr;
    if((fp=fopen("name.csv","at+"))==nullptr)   //读入存姓名的文件
        return FALSE;
    char buffer[1024];     //缓冲数组
    while(fscanf(fp,"%s",buffer)!=EOF)   //利用fscanf
    {
        names.push_back(buffer);    //读入vector
    }
    return TRUE;
}

/**
 * 函数名称：readhobbyfile
 * 函数参数：保存爱好的vector容器
 * 函数功能：将hobby文件读取到容器中
 * 返回值：TRUE FALSE
 * 调用说明：读取hobby文件到容器中，用于随机
 **/
int readhobbyfile()
{
    FILE *fp=nullptr;
    if((fp=fopen("hobby.csv","at+"))==nullptr)   //读入存爱好的文件
        return FALSE;
    char buffer[1024];   //缓冲数组
    while(fscanf(fp,"%s",buffer)!=EOF)  //利用fscanf
    {
        hobby.push_back(buffer);   //读入vector
    }
    return TRUE;
}


/**
 * 函数名称：addrandomuser
 * 函数参数：BSTree *T,int usernum,保存姓名的容器
 * 函数功能：随机生成用户
 * 返回值：添加指定规模的用户
 * 调用说明：TRUE FALSE
 **/
int addrandomuser(AVLpoint *T,int usernum)
{
       elempoint data;
       data=(elempoint)malloc(sizeof(elemnode));
       if(data==nullptr) return FALSE;
       bool taller;
       srand((unsigned)time(nullptr));  //时间种子
       int randomnum;
       for(int i=0;i<usernum;i++)  //循环生成指定规模用户
       {
           randomnum=rand()%names.size();  //随机取名字
           data->key=set_size(*T);        //自动赋key
           data->follow=nullptr;          //关注树置空
           data->follower=nullptr;        //粉丝树置空
           data->friends=nullptr;         //朋友树置空
           data->hobby=nullptr;           // 爱好树置空
           std::strcpy(data->name,names[randomnum].c_str());  //赋值名字
           InsertAVL(T,*data,&taller);  //插入
       }
       return TRUE;
}

/**
 * 函数名称：addrandomhobby
 * 函数参数：BSTree *T
 * 函数功能：随机生成用户爱好
 * 返回值：给现存用户添加爱好
 * 调用说明：TRUE　FALSE
 **/
int addrandomhobby(AVLpoint *T)
{
    childelempoint data;
    data=(childelempoint)malloc(sizeof(childelemnode));
    if(data==nullptr) return FALSE;
    srand((unsigned)time(nullptr));  //时间种子
    int usernum=set_size(*T);  //得到用户规模
    for(int i=0;i<usernum;i++)
    {
        int hobbynum=rand()%AVL_RANDOM_HOBBY_NUM;   //爱好上限为20
        for(int j=0;j<hobbynum;j++)
        {
            int number=rand()%hobby.size();  //随机爱好位序
            hobby_insert(T,i,hobby[number]);
        }
    }
    return TRUE;
}

/**
 * 函数名称：addrandomfriend
 * 函数参数：BSTree *T
 * 函数功能：随机生成朋友
 * 返回值：给现存用户添加朋友关系
 * 调用说明：TRUE FALSE
 **/
int addrandomfriend(AVLpoint *T)
{
    int usernum=set_size(*T);
    srand((unsigned)time(nullptr));   //时间种子
    for(int i=0;i<usernum;i++)        //循环添加朋友
    {
        int  friendnum=rand()%usernum;
        friendnum=friendnum/2;
        for(int j=0;j<friendnum;j++)
        {
            friend_relation_insert(T,i,rand()%usernum);  //调用函数添加朋友
        }
    }
    return TRUE;
}

/**
 * 函数名称：addrandomfollow
 * 函数参数：BSTree *T
 * 函数功能：随机生成关注
 * 返回值：给现存用户添加关注关系
 * 调用说明：TRUE FALSE
 **/
int addrandomfollow(AVLpoint *T)
{
    int usernum=set_size(*T);
    srand((unsigned)time(nullptr));  //时间种子
    for(int i=0;i<usernum;i++)
    {
        int follownum=rand()%usernum;
        follownum=follownum/2;

        for(int j=0;j<follownum;j++)
        {
            follow_relation_insert(T,i,rand()%usernum);  //调用函数添加单方面关注
        }
    }
    return TRUE;
}
