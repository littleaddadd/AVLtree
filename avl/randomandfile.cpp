#include "head.h"
#include "fstream"
#include "sstream"

///**
// * 函数名称：readnode
// * 函数参数：
// * 函数功能：
// * 返回值：
// * 调用说明：
// **/
//status readnode(BSTree *T)
//{
//    ////if(T==NULL) return ERROR;
//   // if(*T==NULL) return ERROR;
//    FILE *fp=NULL;
//    char *line,*record;
//    char buffer[1024];
//    if((fp=fopen("hobby.csv","at+"))!=NULL)
//    {
//        fseek(fp,11L,SEEK_SET);  //定位到
//        char delims[]=",";
//        char *result=NULL;
//        int j=0;
//        while((line=fgets(buffer,sizeof(buffer),fp))!=NULL)  //当没有读取到文件尾时循环继续
//        {
//             record = strtok(line,",");
//             while(record != NULL)  //读取每一行的数据
//             {
//                 printf("%s",record);      //将读取到的每一个数据打印出来
//                 //if(j==10)  //只需读取前9列
//                 //   break;
//                 record = strtok(NULL,",");

//                 //j++;
//             }
//            // printf("\n");
//             //j=0;
//        }
//        fclose(fp);

//    }
//   return TRUE;
//}

////读边
///**
// * 函数名称：readedge
// * 函数参数：
// * 函数功能：
// * 返回值：
// * 调用说明：
// **/
//status readedge(BSTree *T)
//{
//  return TRUE;
//}

/**
 * 函数名称：randomdata
 * 函数参数：
 * 函数功能：随机添加一定规模的用户
 * 返回值：
 * 调用说明：
 **/
status randomdata(BSTree *T,int usernum)
{
       FILE *fp=NULL;
       char * line;

       char buffer[1024];
       elempoint data;
       data=(elempoint)malloc(sizeof(elemnode));
       if(data==NULL) return FALSE;
       int i;
       int key;
       int count;
       bool taller;
       count=set_size(*T)+1;
       if((fp=fopen("name.csv","at+"))==NULL)
           return FALSE;
       int j;
       srand((unsigned)time(NULL));
       int num;
       for(i=0;i<usernum;i++)
       {
            fseek(fp,0L,SEEK_SET);
            num=rand()%10000;
            for(j=0;j<num;j++)
            {
                line=fgets(buffer,sizeof(buffer),fp);
            }
            char * record=strtok(line,",");
            strcpy(data->name,record);
            data->key=count+i;
            data->follow=NULL;
            data->follower=NULL;
            data->friends=NULL;
            data->hobby=NULL;
            InsertAVL(T,*data,&taller);
       }
       return TRUE;
}











/**
 * 函数名称：randomrelation
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status randomrelation(BSTree *T)
{
    //friend
    //follow
    //follower

    randomrelation(&((*T)->lchild));
    randomrelation(&((*T)->rchild));
    return TRUE;
}

/**
 * 函数名称：random
 * 函数参数：
 * 函数功能：
 * 返回值：
 * 调用说明：
 **/
status random(BSTree *T1,Treepoint *T)
{
    srand((unsigned)time(NULL));
    int size=set_size(*T1);
    BSTree p=NULL;
    bool taller;
    tinyelemnode data;

    int relationnum=rand()%size;
    for(int k=1;k<relationnum;k++)
    {
        int key=rand()%size;
//        if(key!=k&&tinyset_member(*T1,k,key)==FALSE)
//        {
//            set_insertfriendnode(T1,k,key);


//        }
    }
    return TRUE;
}


/**
 * 函数名称：randomhobby
 * 函数参数：
 * 函数功能：随机爱好
 * 返回值：
 * 调用说明：
 **/
status randomhobby(BSTree *T)
{
    int num=set_size(*T);
    srand((unsigned)time(NULL));
    int hobbynum;
    int i;
    BSTree p;
    bool taller;
    FILE *fp=NULL;
    char *line,*record;
    tinyelemnode data;
    char buffer[1024];
    if((fp=fopen("hobby.csv","at+"))==NULL)
        return FALSE;
    printf("打开成功\n");
    printf("1");
    fseek(fp,0L,SEEK_SET);

    line=fgets(buffer,sizeof(buffer),fp);
    record=strtok(line,",");
    printf("%s",record);

    while(record!=NULL)
    {
         printf("%s",record);
         record=strtok(NULL,",");
    }
    for(int n=0;n<1;n++)
    {

      for(int l=0;record!=NULL&&l<5;)
      {
          record=strtok(NULL,",");
          printf("3%s\n",record);
          if(record!=NULL) l++;
      }
    }
    for(i=1;i<=num;i++)
    {
        hobbynum=rand()%4+1;
        p=searchAVL(*T,i);
        for(int j=0;j<hobbynum;j++)
        {
            fseek(fp,0L,SEEK_SET);
            line=fgets(buffer,sizeof(buffer),fp);
            record=strtok(line,",");
            int number=rand()%100;
            //for(int k=0;k<number;k++)
              printf("%s",data.name);
              record=strtok(NULL,",");
             // printf("%s",data.name);
              //record=strtok(NULL,",");
           // strcpy(data.name,record);
            //printf("%s",data.name);
            //InsertAVLnode(&p->data.hobby,data,&taller);
        }
    }
    return TRUE;
}


/*save file*/
status savepeople(BSTree T,std::string filename)
{
    char ach[3]={char(0xEF),char(0xBB),char(0xBF)};
    FILE *p=fopen(filename.c_str(),"w");
    fwrite(ach,1,sizeof(ach),p);
    fclose(p);
    std::ofstream outFile(filename,std::ios::app);
    savefile(T,outFile);
    outFile.close();
}

status savefile(BSTree T,std::ofstream& outFile)
{
      if(T==nullptr) return FALSE;

      savefile(T->lchild,outFile);

      outFile<<"key,"<<T->data.key<<std::endl;
      outFile<<"name,"<<T->data.name<<std::endl;

      outFile<<"friend";
      save(outFile,T->data.friends);
      outFile<<std::endl;

      outFile<<"follow";
      save(outFile,T->data.follow);
      outFile<<std::endl;

      outFile<<"follower";
      save(outFile,T->data.follower);
      outFile<<std::endl;

      outFile<<"hobby";
      save(outFile,T->data.hobby);
      outFile<<std::endl;

      savefile(T->rchild,outFile);

      return TRUE;
}
status save(std::ofstream &outfile,Treepoint tree)
{
    if(tree==NULL) return FALSE;
    save(outfile,tree->lchild);
    outfile<<","<<"key,"<<tree->data.key<<","<<"名,"<<tree->data.name;
    save(outfile,tree->rchild);
    return TRUE;
}


//status randomdata(BSTree *T, int usernum)
//{
//    using std::istringstream;
//    bool taller;
//    if(*T!=NULL) return FALSE;
//    std::ifstream infile("name.csv");
//    if(!infile) return FALSE;

//    std::string str;
//    std::string tmp;
//    while(std::getline(infile,s)) {
















//    }

//}














/*read file*/
status readpeople(BSTree *T,std::string filename)
{
    using std::istringstream;
    bool taller;
    if(*T!=NULL) return FALSE;
    std::ifstream infile(filename);
    if(!infile) return FALSE;
    std::string str;
    std::string tmp;
    while(std::getline(infile,str)){
        istringstream stream1(str);
        elemnode data;
        std::getline(stream1,tmp,',');
        std::getline(stream1,tmp);
        data.key = std::stoi(tmp);
        std::getline(infile,str);
        istringstream stream2(str);
        while(std::getline(stream2,tmp,',')){
           if(tmp=="name") continue;
           strcpy(data.name,tmp.c_str());
        }
        InsertAVL(T,data,&taller);

        BSTree p=searchAVL(*T,data.key);
        p->data.follow=NULL;
        p->data.follower=NULL;
        p->data.friends=NULL;
        p->data.hobby=NULL;

        std::getline(infile,str);
        istringstream stream3(str);
        std::getline(stream3,tmp,',');
        while(std::getline(stream3,tmp,',')){
            tinyelemnode tiny;
            std::getline(stream3,tmp,',');
            tiny.key = std::stoi(tmp);
            std::getline(stream3,tmp,',');
            std::getline(stream3,tmp,',');
            strcpy(tiny.name,tmp.c_str());
            InsertAVLnode(&p->data.friends,tiny,&taller);
        }
        std::getline(infile,str);
        istringstream stream4(str);
        std::getline(stream4,tmp,',');
        while(std::getline(stream4,tmp,',')){
            tinyelemnode tiny;
            std::getline(stream4,tmp,',');
            tiny.key = std::stoi(tmp);
            std::getline(stream4,tmp,',');
            std::getline(stream4,tmp,',');
            strcpy(tiny.name,tmp.c_str());
            InsertAVLnode(&p->data.follow,tiny,&taller);
        }
        std::getline(infile,str);
        istringstream stream5(str);
        std::getline(stream5,tmp,',');
        while(std::getline(stream5,tmp,',')){
            tinyelemnode tiny;
            std::getline(stream5,tmp,',');
            tiny.key = std::stoi(tmp);
            std::getline(stream5,tmp,',');
            std::getline(stream5,tmp,',');
            strcpy(tiny.name,tmp.c_str());
            InsertAVLnode(&p->data.follower,tiny,&taller);
        }
        std::getline(infile,str);
        istringstream stream6(str);
        std::getline(stream6,tmp,',');
        while(std::getline(stream6,tmp,',')){
            tinyelemnode tiny;
            std::getline(stream6,tmp,',');
            tiny.key = std::stoi(tmp);
            std::getline(stream6,tmp,',');
            std::getline(stream6,tmp,',');
            strcpy(tiny.name,tmp.c_str());
            InsertAVLnode(&p->data.hobby,tiny,&taller);
        }
    }
    infile.close();
    return true;
}
