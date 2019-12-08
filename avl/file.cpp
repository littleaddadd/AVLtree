#include "head.h"
#include "fstream"
#include "sstream"

/*save file*/
/**
 * 函数名称：savefile
 * 函数参数：BSTree T,std::string filename
 * 函数功能：调用savetreeinfo实现存文件的功能
 * 返回值：TRUE FALSE
 * 调用说明：用于实现存储文件的功能
 **/
int savefile(AVLpoint T,std::string filename)
{
    char ach[3]={char(0xEF),char(0xBB),char(0xBF)};  //写入Utf-8 BOM文件头
    FILE *p=fopen(filename.c_str(),"w");
    if(T!=nullptr)
    fwrite(ach,1,sizeof(ach),p);
    fclose(p);

    std::ofstream outFile(filename,std::ios::app);   //写入filename指定文件

    savetreeinfo(T,outFile);

    outFile.close();
    return TRUE;
}
/**
 * 函数名称：savetreeinfo
 * 函数参数：BSTree T,std::ofstream& outFile
 * 函数功能：调用savechiildtreeinfo实现递归写
 * 返回值：TRUE FALSE
 * 调用说明：调用savechiildtreeinfo实现递归写结点
 **/
int savetreeinfo(AVLpoint T,std::ofstream& outFile)
{
      if(T==nullptr) return FALSE;

      savetreeinfo(T->lchild,outFile);

      outFile<<"key,"<<T->data.key<<std::endl;    //写下用户的key
      outFile<<"name,"<<T->data.name<<std::endl;  //写下用户的name

      outFile<<"friend";
      savechildtreeinfo(outFile,T->data.friends);  //调用函数写下用户的朋友树
      outFile<<std::endl;

      outFile<<"follow";
      savechildtreeinfo(outFile,T->data.follow);  //调用函数写下用户的关注树
      outFile<<std::endl;

      outFile<<"follower";
      savechildtreeinfo(outFile,T->data.follower);  //调用函数写下用户的粉丝树
      outFile<<std::endl;

      outFile<<"hobby";
      savechildtreeinfo(outFile,T->data.hobby);   //调用函数写下用户的爱好树
      outFile<<std::endl;

      savetreeinfo(T->rchild,outFile);

      return TRUE;
}
/**
 * 函数名称：savechildtreeinfo
 * 函数参数：std::ofstream &outfile,Treepoint tree
 * 函数功能：写子树信息
 * 返回值：TRUE FALSE
 * 调用说明：用于被调用实现写子树的功能
 **/
int savechildtreeinfo(std::ofstream &outfile,ChildAVLpoint tree)
{
    if(tree==nullptr) return FALSE;
    savechildtreeinfo(outfile,tree->lchild);
    outfile<<","<<"key,"<<tree->data.key<<","<<"名,"<<tree->data.name;  //按照递归写下子树
    savechildtreeinfo(outfile,tree->rchild);
    return TRUE;
}


/*read file*/
/**
 * 函数名称：readfile
 * 函数参数：BSTree *T,std::string filename
 * 函数功能：用于读取数据文件
 * 返回值：TRUE　FALSE
 * 调用说明：读取csv文件
 **/
int readfile(AVLpoint *T,std::string filename)
{
    using std::istringstream;
    bool taller;
    if(*T!=nullptr) return FALSE;   //如果找不到文件 返回FALSE
    std::ifstream infile(filename);
    if(!infile) return FALSE;
    std::string str;
    std::string tmp;
    while(std::getline(infile,str)){ //使用std::getline 控制格式读
        istringstream stream1(str);
        elemnode data;
        std::getline(stream1,tmp,',');   //处理逗号间隔
        std::getline(stream1,tmp);
        data.key = std::stoi(tmp);     //读取key
        std::getline(infile,str);
        istringstream stream2(str);
        while(std::getline(stream2,tmp,',')){  //处理读入名字
           if(tmp=="name") continue;
           strcpy(data.name,tmp.c_str());
        }
        InsertAVL(T,data,&taller);

        AVLpoint p=SearchAVL(*T,data.key);  //找到key对应的结点的指针
        p->data.follow=nullptr;           //置空关注子树
        p->data.follower=nullptr;         //置空粉丝子树
        p->data.friends=nullptr;          //置空朋友子树
        p->data.hobby=nullptr;            //置空爱好子树

        std::getline(infile,str);
        istringstream stream3(str);
        std::getline(stream3,tmp,',');
        while(std::getline(stream3,tmp,',')){  //处理逗号读入朋友
            childelemnode tiny;
            std::getline(stream3,tmp,',');
            tiny.key = std::stoi(tmp);    //读入key
            std::getline(stream3,tmp,',');
            std::getline(stream3,tmp,',');
            strcpy(tiny.name,tmp.c_str());  //读入名
            InsertChildAVL(&p->data.friends,tiny,&taller);  //插入
        }
        std::getline(infile,str);
        istringstream stream4(str);
        std::getline(stream4,tmp,',');
        while(std::getline(stream4,tmp,',')){     //处理逗号读入关注
            childelemnode tiny;
            std::getline(stream4,tmp,',');
            tiny.key = std::stoi(tmp);    //读入key
            std::getline(stream4,tmp,',');
            std::getline(stream4,tmp,',');
            strcpy(tiny.name,tmp.c_str());  //读入名
            InsertChildAVL(&p->data.follow,tiny,&taller);  //插入
        }
        std::getline(infile,str);
        istringstream stream5(str);
        std::getline(stream5,tmp,',');
        while(std::getline(stream5,tmp,',')){   //处理逗号读入粉丝
            childelemnode tiny;
            std::getline(stream5,tmp,',');
            tiny.key = std::stoi(tmp);   //读入key
            std::getline(stream5,tmp,',');
            std::getline(stream5,tmp,',');
            strcpy(tiny.name,tmp.c_str());  //读入名
            InsertChildAVL(&p->data.follower,tiny,&taller);  //插入
        }
        std::getline(infile,str);
        istringstream stream6(str);
        std::getline(stream6,tmp,',');
        while(std::getline(stream6,tmp,',')){  //处理逗号读入爱好
            childelemnode tiny;
            std::getline(stream6,tmp,',');
            tiny.key = std::stoi(tmp);        //读入key
            std::getline(stream6,tmp,',');
            std::getline(stream6,tmp,',');
            strcpy(tiny.name,tmp.c_str());   //读入名
            InsertChildAVL(&p->data.hobby,tiny,&taller);
        }
    }
    infile.close();
    return true;
}
