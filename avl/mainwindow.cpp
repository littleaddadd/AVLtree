#include <cstdio>
#include <utility>
#include <QTextStream>
#include <sstream>
#include <cstring>
#include <QString>

#include "mainwindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readnamefile();
    readhobbyfile();
    ui->button_ok->hide();
    ui->textBrowser->hide();
    ui->label1->hide();
    ui->label2->hide();
    ui->label3->hide();
    ui->label4->hide();
    ui->label5->hide();
    ui->input1->hide();
    ui->input2->hide();
    ui->input3->hide();
    ui->comboBox->hide();
    ui->comboBox_1->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//输入函数
template <typename Edit, typename ...Args>
void MainWindow::scan(Edit input, Args&&...args)
{
    auto text = input->text().toStdString();
    input->setText("");
    std::istringstream stream(text);
    int list[] __attribute__((unused))= {(stream >> std::forward<Args>(args), 0)...};
}

//清屏函数
void MainWindow::clear_output()
{
    output = "";
    ui->textBrowser->setText(output);
}

namespace
{
    void append(QString &str, int i)
    {
        str += QString::number(i);
    }
    void append(QString &str, char const* s)
    {
        str += s;
    }
    void append(QString &str, std::string const&s)
    {
        str += s.c_str();
    }
}
template <typename ...Args>
//输出函数
void MainWindow::print(Args&&...args)
{
//    QTextStream stream(&output);
    int list[] __attribute__((unused)) = {(append(output, std::forward<Args>(args)), 0)...};
}
template <typename ...Args>
void MainWindow::print_and_flush(Args&&...args)
{
    print(std::forward<Args>(args)...);
    flush();
}

//更新文本框函数
void MainWindow::flush()
{
    ui->textBrowser->setText(output);
}
//退出按钮函数
void MainWindow::on_button_exit_clicked()
{

}
//确认提交函数
void MainWindow::on_button_ok_clicked()
{
    input_handler();
}

//保存函数
void MainWindow::on_button_save_clicked()
{
    gui_save_applydata();
}



void MainWindow::show_input(std::size_t number_of_edit)
{
    switch(number_of_edit)
    {
    case 3:  //如果参数为3 显示3个输入框 3个提示标签 显示确认按钮 其余隐藏
        ui->input3->show();
        ui->input2->show();
        ui->input1->show();
        ui->label1->show();
        ui->label2->show();
        ui->label3->show();
        ui->button_ok->show();
        break;
    case 2:  //如果参数为2 显示2个输入框 2个提示标签 显示确认按钮 其余隐藏
        ui->input3->hide();
        ui->input2->show();
        ui->input1->show();
        ui->label3->hide();
        ui->label2->show();
        ui->label1->show();
        ui->button_ok->show();
        break;
    case 1: //如果参数为1 显示1个输入框 1个提示标签 显示确认按钮 其余隐藏
        ui->input3->hide();
        ui->input2->hide();
        ui->input1->show();
        ui->label3->hide();
        ui->label2->hide();
        ui->label1->show();
        ui->button_ok->show();
        break;
    case 0:  //如果参数为3 显示3个输入框 3个提示标签 显示确认按钮 其余隐藏
        ui->input3->hide();
        ui->input2->hide();
        ui->input1->hide();
        ui->label3->hide();
        ui->label2->hide();
        ui->label1->hide();
        ui->button_ok->hide();
    }
}

void MainWindow::show_hide()
{
    //隐藏输入框 隐藏标签 隐藏下拉菜单 清空下拉菜单栏
    ui->input3->hide();
    ui->input2->hide();
    ui->input1->hide();
    ui->label3->hide();
    ui->label2->hide();
    ui->label1->hide();
    ui->label4->hide();
    ui->label5->hide();
    ui->button_ok->hide();
    ui->comboBox->hide();
    ui->comboBox_1->hide();

    ui->comboBox->clear();
    ui->comboBox_1->clear();
    flush();
}








/****************************************集合****************************************/
//初始化集合
void MainWindow::on_set_init_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_actionset_init();
}
//摧毁集合
void MainWindow::on_set_destroy_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_actionset_destroy();
}
//插入集合
void MainWindow::on_set_insert_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_insert();
}
//删除集合
void MainWindow::on_set_remove_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_remove();
}

//交运算
void MainWindow::on_set_intersection_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_intersection();
}
//并运算
void MainWindow::on_set_union_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_union();
}
//差运算
void MainWindow::on_set_difference_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_difference();
}
//求个数
void MainWindow::on_set_size_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_size();
}
//查找
void MainWindow::on_set_member_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_member();
}
//子集
void MainWindow::on_set_subset_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_subset();
}
//相等
void MainWindow::on_set_equal_triggered()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    if(t1.exists==false||t2.exists==false)
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_actionset_equal();
}


/****************************************应用****************************************/
/*系统*/
//初始化系统
void MainWindow::on_action_init_triggered()
{
    clear_output();  //清屏
    show_hide();     //隐藏按钮
    ui->textBrowser->show();//重新显示文本框
    gui_set_init();  //调用set_init的gui函数
    gui_read_applydata();
}
//销毁系统
void MainWindow::on_action_destroy_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();  //重新显示文本框
    gui_set_destroy();    //调用set_destroy的gui函数
}

/*用户*/
//添加用户
int MainWindow::on_action_insert_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();  //重新显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    int judge=gui_insert_user();
    if(judge==FALSE) print_and_flush("创建用户模式进入失败\n");
    return TRUE;
}

//删除用户
int MainWindow::on_action_remove_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();  //重新显示文本框
    if(!tree.exists)      //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_removeuser();
    return TRUE;
}
//修改用户
int MainWindow::on_action_modify_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();  //重新显示文本框
    if(!tree.exists)  //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_modifyuser();
    return TRUE;
}
//查找用户
int MainWindow::on_action_member_triggered()
{
    clear_output();  //清屏
    show_hide();     //隐藏按钮
    ui->textBrowser->show();  //重新显示文本框
    if(!tree.exists)  //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_searchuser();
    return TRUE;
}
//当前用户数
int MainWindow::on_action_size_triggered()
{
    clear_output();  //清屏
    show_hide();     //隐藏按钮
    ui->textBrowser->show();  //重新显示文本框
    if(!tree.exists) //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    int judge=set_size(tree.tree);
    print_and_flush("用户个数为：",judge);
    return TRUE;
}
//遍历所有用户
int MainWindow::on_action_traverse_triggered()
{
    clear_output();  //清屏
    show_hide();     //隐藏按钮
    ui->textBrowser->show(); //重新显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_traverseuser();
    return TRUE;
}

/*社交*/
//添加用户的社交
int MainWindow::on_action_relationinsert_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();  //重新显示文本框
    if(!tree.exists)    //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_insertrelation();
    return TRUE;
}
//删除用户的社交
int MainWindow::on_action_relationremove_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();  //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_removerelation();
    return TRUE;
}
//修改用户的社交
int MainWindow::on_action_relationmodify_triggered()
{
    clear_output();     //清屏
    show_hide();        //隐藏按钮
    ui->textBrowser->show();   //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_modifyrelation();
    return TRUE;
}
//查询用户的社交
int MainWindow::on_action_relationmember_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();   //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_searchrelation();
    return TRUE;
}
//遍历用户的社交
int MainWindow::on_action_relationtraverse_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();  //显示文本框
    if(!tree.exists)    //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_traverserelation();
    return TRUE;
}
//清空用户的社交
int MainWindow::on_action_relationreset_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();    //显示文本框
    if(!tree.exists)    //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_resetrelation();
    return TRUE;
}

/*爱好*/
//添加用户的爱好
int MainWindow::on_action_hobbyinsert_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();   //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_inserthobby();
    return TRUE;
}
//删除用户的爱好
int MainWindow::on_action_hobbyremove_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();  //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_removehobby();
    return TRUE;
}
//修改用户的爱好
int MainWindow::on_action_hobbymodify_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();    //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_modifyhobby();
    return TRUE;
}

//查询用户的爱好
int MainWindow::on_action_hobbymember_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();   //显示文本框
    if(!tree.exists)           //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_searchhobby();
    return TRUE;
}
//遍历用户的爱好
int MainWindow::on_action_hobbytraverse_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();   //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_traversehobby();
    return TRUE;
}
//初始化用户的爱好
int MainWindow::on_action_hobbyreset_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();  //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_resethobby();
    return TRUE;
}

/*特殊查询*/
//共同关注查询
int MainWindow::on_bothfollow_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();   //显示文本框
    if(!tree.exists)    //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_tinyset_bothfollow();
    return TRUE;
}
//共同喜好查询
int MainWindow::on_bothhobby_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show();  //显示文本框
    if(!tree.exists)    //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_tinyset_bothhobby();
    return TRUE;
}

//二度好友查询
int MainWindow::on_twodegreefriend_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();  //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_twodegreefriend();
    return TRUE;
}

/*随机生成*/
//随机生成
int MainWindow::on_random_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show(); //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_randomuser();
    return TRUE;
}

/****************************************文件****************************************/
//备份文件读
int MainWindow::on_readapplybackup_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show(); //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_read_applybackupdata();
    return TRUE;
}
//备份文件写
int MainWindow::on_saveapplybackup_triggered()
{
    clear_output();     //清屏
    show_hide();        //隐藏按钮
    ui->textBrowser->show(); //显示文本框
    if(!tree.exists)    //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return FALSE;
    }
    gui_save_applybackupdata();
    return TRUE;
}

//集合保存
void MainWindow::on_saveset_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show();  //显示文本框
    gui_save_setdata();
}

//集合读取
void MainWindow::on_readset_triggered()
{
    clear_output();    //清屏
    show_hide();       //隐藏按钮
    ui->textBrowser->show(); //显示文本框
    if(t1.exists==false||t2.exists==false)  //尚未初始化
    {
        print_and_flush("尚未初始化");
        return ;
    }
    gui_read_setdata();
}
//默认文件写
void MainWindow::on_saveapply_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show(); //显示文本框

    gui_save_applydata();
}
//默认文件读
void MainWindow::on_readapply_triggered()
{
    clear_output();   //清屏
    show_hide();      //隐藏按钮
    ui->textBrowser->show(); //显示文本框
    if(!tree.exists)   //尚未初始化
    {
        print_and_flush("系统尚未初始化");
        return ;
    }
    gui_read_applydata();
}





/****************************************集合界面****************************************/

//初始化集合
void MainWindow::gui_actionset_init()
{
    print_and_flush("点击按钮完成初始化\n");
    ui->button_ok->show();
    input_handler=[this]
    {
        int judge;
        judge=set_init(&t1);   //调用set_init函数完成对t1的初始化
        if(judge==TRUE) print_and_flush("树1初始化成功\n");
        else print_and_flush("树1初始化失败\n");
        judge=set_init(&t2);   //调用set_init函数完成对t2的初始化
        if(judge==TRUE) print_and_flush("树2初始化成功\n");
        else print_and_flush("树2初始化失败\n");
        show_hide();
    };
}
//销毁集合
void MainWindow::gui_actionset_destroy()
{
    ui->button_ok->show();
    print_and_flush("点击按钮完成销毁\n");
    input_handler=[this]
    {
        int judge;
        judge=set_destroy(&t1);  //调用set_destroy函数完成对t1的销毁
        if(judge==TRUE) print_and_flush("树1摧毁成功\n");
        else print_and_flush("树1摧毁失败\n");
        judge=set_destroy(&t2);  //调用set_destroy函数完成对t2的销毁
        if(judge==TRUE) print_and_flush("树2摧毁成功\n");
        else print_and_flush("树2摧毁失败\n");
        show_hide();
    };
}
//插入集合
int MainWindow::gui_actionset_insert()
{
    elempoint data;
    data=(elempoint)malloc(sizeof(elemnode));        //声明一个结点用来插入
    if(data==nullptr) return FALSE;

    std::string name="";
    strcpy(data->name,name.c_str());

    data->follow=nullptr;                       //关注指针置空
    data->follower=nullptr;                     //粉丝指针置空
    data->friends=nullptr;                      //朋友指针置空
    data->hobby=nullptr;                        //爱好指针置空

    print_and_flush("请输入数字集合\n");
    ui->label1->setText("key");
    show_input(1);

    ui->label4->show();
    ui->label4->setText("选择添加的树");
    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0,"添加到树1");
    ui->comboBox->insertItem(1,"添加到树2");

    input_handler=[this,data]
    {
        bool taller;
        if(ui->input1->text().isEmpty())  //判断输入框是否为空
        {
            print_and_flush("输入为空\n");
            return;
        }

        QString qstr=ui->input1->text();
        ui->input1->setText("");
        std::string str=qstr.toUtf8().constData();  //格式转换

        std::vector<std::string> result_list;  //vector声明完成集合格式输入
        std::string bufstr;  //缓冲

        for(int index = 0,range=str.size();index != range;++index)
        {
            if(str[index]!=','){   //如果不是逗号，加入缓冲
                bufstr.push_back(str[index]);
            }
            else                  //遇到逗号 push_back并清除缓冲
            {
                result_list.push_back(bufstr);
                bufstr.erase();
            }
        }
        result_list.push_back(bufstr);//将最后一个,后的数据加入缓冲
        for(unsigned int index=0;index != result_list.size();++index)
        {
            int judge;
            data->key=std::stoi(result_list[index]);  //转换成int
            if(ui->comboBox->currentIndex()==0)
                     judge=set_insert(&t1.tree,data,&taller);
            if(ui->comboBox->currentIndex()==1)
                     judge=set_insert(&t2.tree,data,&taller);
            if(judge==FALSE)
                  print_and_flush(data->key,"插入失败\n");
            else
                  print_and_flush(data->key,"插入成功\n");
        }
        show_hide();
    };
    return TRUE;
}

//删除集合
void MainWindow::gui_actionset_remove()
{
    print_and_flush("请输入数字集合\n");
    ui->label1->setText("key");
    show_input(1);
    ui->label4->show();
    ui->label4->setText("选择要删除的树");

    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0,"从树1删除");
    ui->comboBox->insertItem(1,"从树2删除");

    input_handler=[this]
    {
        if(ui->input1->text().isEmpty())     //输入框为空
        {
            print_and_flush("输入为空\n");
            return;
        }
        QString qstr=ui->input1->text();
        ui->input1->setText("");
        std::string str=qstr.toUtf8().constData();   //格式转换
        std::vector<std::string> result_list;        //设置vector完成集合形式输入的删除
        std::string bufstr;                          //缓冲区
        for(int index = 0,range=str.size();index != range;++index)
        {
              if(str[index]!=','){ //如果不是逗号
                  bufstr.push_back(str[index]);  //加入缓冲区
              }
              else   //是逗号
              {
                  result_list.push_back(bufstr);  //弹出缓冲区加入vector
                  bufstr.erase();     //清空缓冲区
              }
         }
         result_list.push_back(bufstr);  //将,最后一个输入加入vector
         for(unsigned int index=0;index != result_list.size();++index)
         {
             int judge;
             int key=std::stoi(result_list[index]);  //类型转换
             print_and_flush(key);
             if(ui->comboBox->currentIndex()==0)
                 judge=set_remove(&t1.tree,key);
             if(ui->comboBox->currentIndex()==1)
                 judge=set_remove(&t2.tree,key);
             if(judge==TRUE)
             {
                 print_and_flush("删除成功\n");
             }
             else
             {
                 print_and_flush("删除失败\n");
             }
             input_handler = nullptr;
         }
         show_hide();
    };
}

//交运算
void MainWindow::gui_actionset_intersection()
{
    ui->button_ok->show();
    print_and_flush("点击按钮完成交运算\n");
    input_handler=[this]
    {
        AVLpoint intersectiontree=nullptr;    //声明一棵树用于交
        set_intersection(t1.tree,t2.tree,&intersectiontree);  //交运算

        auto visit = [this](elemnode data)
        {
            print(data.key,"\n");
        };
        user_traverse(intersectiontree,visit,1);  //传lambda表达式完成打印

        input_handler = nullptr;
        show_hide();
    };
}

//并运算
void MainWindow::gui_actionset_union()
{
    ui->button_ok->show();
    print_and_flush("点击按钮完成并运算\n");
    input_handler=[this]
    {
        AVLpoint uniontree=nullptr;          //声明一棵树用于并
        set_union(t1.tree,t2.tree,&uniontree);   //并运算
        auto visit = [this](elemnode data)
        {
                print(data.key,"\n");
        };
        user_traverse(uniontree,visit,1);    //传lambda表达式完成打印
        input_handler = nullptr;
        show_hide();
    };
}

//差运算
void MainWindow::gui_actionset_difference()
{
    ui->button_ok->show();
    print_and_flush("点击按钮完成差运算\n");
    input_handler=[this]
    {
        AVLpoint differencetree=nullptr;      //声明一棵树用于差
         set_intersection(t1.tree,t1.tree,&differencetree);   //首先将t1.tree的值给differencetree
        set_difference(t1.tree,t2.tree,&differencetree);     //完成
        auto visit = [this](elemnode data)
        {
            print(data.key,"\n");
        };
        user_traverse(differencetree,visit,1);  //传lambda表达式完成打印
        input_handler=nullptr;
        show_hide();
    };
}

//查看集合元素个数
void MainWindow::gui_actionset_size()
{
    ui->button_ok->show();
    print_and_flush("选择查看的树\n");
    ui->label4->show();
    ui->label4->setText("请选择树");
    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0,"树1");
    ui->comboBox->insertItem(1,"树2");

    input_handler=[this]
    {
        int choice=ui->comboBox->currentIndex();  //获取下拉选项
        int judge;
        if(choice==0)
            judge=set_size(t1.tree);    //求t1.tree结点个数
        else
            judge=set_size(t2.tree);    //求t2.tree结点个数
        print_and_flush("树",choice+1,"结点的个数为",judge);
        show_hide();
    };
}

//查找集合
void MainWindow::gui_actionset_member()
{
    print_and_flush("选择查找的树\n");
    show_input(1);
    ui->label1->setText("输入key");
    ui->label4->show();
    ui->label4->setText("请选择树");
    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0,"树1");
    ui->comboBox->insertItem(1,"树2");

    input_handler=[this]
    {
        int choice=ui->comboBox->currentIndex();    //获取下拉选项
        AVLpoint judge;
        int key;
        scan(ui->input1,key);
        if(choice==0)
            judge=set_member(t1.tree,key);    //在t1.tree中查找
        else
            judge=set_member(t2.tree,key);    //在t2.tree中查找
        if(judge!=nullptr) print_and_flush("查找成功\n");
                   else print_and_flush("查找失败\n");
         show_hide();
    };
}

//判断子集
void MainWindow::gui_actionset_subset()
{
    print_and_flush("请选择要判断的类型\n");
    ui->label4->show();
    ui->label4->setText("请选择");
    ui->button_ok->show();
    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0,"判断树2是树1的子集");
    ui->comboBox->insertItem(1,"判断树1是树2的子集");
    input_handler=[this]
    {
        int choice=ui->comboBox->currentIndex();     //获取下拉选项
        bool judgeset=true;
        if(choice==0)
        set_subset(t1.tree,t2.tree,&judgeset);       //判断t2.tree是t1.tree的子集
        if(choice==1)
        set_subset(t2.tree,t1.tree,&judgeset);       //判断t1.tree是t2.tree的子集
        if(judgeset==true) print_and_flush("是子集\n");
        else print_and_flush("不是子集\n");
        show_hide();
    };
}

//判断集合是否相等
void MainWindow::gui_actionset_equal()
{
    ui->button_ok->show();
    print_and_flush("请按确定按钮判断相等\n");
    input_handler=[this]
    {
        int judge=set_equal(t1.tree,t2.tree);
        if(judge==TRUE) print_and_flush("集合相等\n");
        else print_and_flush("集合不相等\n");
        show_hide();
    };
}

/****************************************应用界面****************************************/
/*系统界面*/
//初始化界面
void MainWindow::gui_set_init()
{
    int judge=set_init(&tree);
    if(judge==TRUE) print_and_flush("该系统初始化成功\n");
        else print_and_flush("该系统初始化失败\n");
    show_hide();
}

//摧毁界面
void MainWindow::gui_set_destroy()
{
    int judge=set_destroy(&tree);
    if(judge==TRUE) print_and_flush("系统已经成功摧毁\n");
    else print_and_flush("系统摧毁失败\n");
    show_hide();
}

/*用户界面*/
//插入界面
int MainWindow::gui_insert_user()
{
    elempoint data;
    data=(elempoint)malloc(sizeof(elemnode));
    if(data==nullptr) return FALSE;               //申请失败

    data->follow=nullptr;     //关注树指针置空
    data->follower=nullptr;   //粉丝数指针置空
    data->friends=nullptr;    //朋友树指针置空
    data->hobby=nullptr;      //爱好树指针置空

    print_and_flush("请输入用户名 最多20个字符\n");
    ui->label1->setText("用户名");
    show_input(1);

    input_handler = [this, data]
    {
         std::string  name;
         if(ui->input1->text().isEmpty())   //如果输入框为空时点击确认按钮
         {
                print_and_flush("输入为空\n");
                return;
         }
         scan(ui->input1, name);
         data->key = set_size(tree.tree);  //key等于当前用户数
         std::strcpy(data->name, name.c_str());
         bool taller;
         int JudgeReturn=set_insert(&tree.tree,data,&taller);
         if(JudgeReturn==FALSE) print_and_flush("此用户插入失败！\n");
         print_and_flush("当前已有", set_size(tree.tree), "位用户\n");
         input_handler = nullptr;
         show_hide();
    };
    return TRUE;
}

//查询界面
void MainWindow::gui_searchuser()
{
    print_and_flush("请输入要查询的key\n");
    ui->label1->setText("key");
    flush();
    show_input(1);
    input_handler=[this]
    {
        AVLpoint judge=nullptr;
        int key;
        if(ui->input1->text().isEmpty())  //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key);
        judge=set_member(tree.tree,key);
        if(judge==nullptr) print_and_flush("找不到用户\n");
        else
        {
            print_and_flush("该用户名为：",judge->data.name,"  key为：",judge->data.key,"\n");
        }
        input_handler = nullptr;  //表达式置空
        show_hide();
    };
}

//删除界面
void MainWindow::gui_removeuser()
{
    print_and_flush("请输入要删除用户的key\n");
    flush();
    ui->label1->setText("key");
    show_input(1);
    input_handler=[this]
    {
        int key;
        int judge;
        if(ui->input1->text().isEmpty())   //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key);
        judge=set_remove(&tree.tree,key);   //删除结点
        if(judge==TRUE)
        {
            print_and_flush("删除成功\n");
        }
        else
        {
            print_and_flush("删除失败\n");
        }
        input_handler = nullptr;
        show_hide();
    };
}

//修改界面
void MainWindow::gui_modifyuser()
{
    print_and_flush("请输入要修改的成员的key\n");
    print_and_flush("请选择要修改的成员的name\n");
    flush();
    show_input(2);
    ui->label1->setText("用户的key");
    ui->label2->setText("用户的name");
    input_handler=[this]
    {
        int key;
        std::string name;
        int judge;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())  //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }

        scan(ui->input1,key);
        scan(ui->input2,name);

        judge=user_modify(&tree.tree,key,name);   //修改

        if(judge==TRUE) print_and_flush("修改成功");
        else print_and_flush("修改失败");
        input_handler = nullptr;
        show_hide();
       };
}

//遍历界面
void MainWindow::gui_traverseuser()
{
    print_and_flush("请选择遍历的方式\n");
    ui->button_ok->show();
    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0, "前序遍历");
    ui->comboBox->insertItem(1, "中序遍历");
    ui->comboBox->insertItem(2, "后序遍历");
    ui->comboBox->insertItem(3, "按层遍历");
    ui->label4->show();
    ui->label4->setText("输入数字选择遍历方式");

    input_handler=[this]
    {
        auto visit = [this](elemnode data)
        {
            print("key为 ",data.key, "名字为 " ,data.name,"\n");
        };
        user_traverse(tree.tree,visit,ui->comboBox->currentIndex());   //遍历
        print("遍历完毕");
        input_handler = nullptr;
        show_hide();
    };
}

/*社交界面*/
//插入社交关系
void MainWindow::gui_insertrelation()
{
    print("请输入用户1\n");
    print("请输入用户2\n");
    print_and_flush("请选择要添加的社交关系\n");
    show_input(2);
    ui->label1->setText("用户1的key");
    ui->label2->setText("用户2的key");
    ui->label4->show();
    ui->label4->setText("选择添加的关系");
    /*下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0, "用户1和2是朋友");
    ui->comboBox->insertItem(1, "用户1关注用户2");
    ui->comboBox->insertItem(2, "用户1被用户2关注");

    input_handler=[this]
    {
        int key1,key2;
        int judge;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())   //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key1);
        scan(ui->input2,key2);
        judge=relation_insert(&tree.tree,key1,key2,ui->comboBox->currentIndex());   //加入社交关系
        if(judge==FALSE) print_and_flush("添加失败");
        else print_and_flush("添加成功");

        input_handler = nullptr;
        show_hide();
    };
}

//删除社交关系
void MainWindow::gui_removerelation()
{
    print("请输入用户1的key\n");
    print_and_flush("请输入用户2的key\n");
    flush();
    show_input(2);
    ui->label1->setText("用户1的key");
    ui->label2->setText("用户2的key");
    ui->label4->show();
    ui->label4->setText("选择删除类别");
    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0, "用户1取消关注用户2");
    ui->comboBox->insertItem(1, "删除好友");

    input_handler=[this]
    {
        int key1,key2;
        int judge;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())   //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key1);
        scan(ui->input2,key2);

        int choice=ui->comboBox->currentIndex();

        judge=relation_remove(&tree.tree,key1,key2,choice); //完成删除

        if(judge==TRUE) print_and_flush("删除关系成功");
        else print_and_flush("删除关系失败");
        input_handler = nullptr;
        show_hide();
    };
}

//修改社交关系
void MainWindow::gui_modifyrelation()
{
    print_and_flush("请输入用户1\n");
    print_and_flush("请输入用户2\n");
    flush();
    show_input(2);
    ui->label1->setText("用户1的key");
    ui->label2->setText("用户2的key");
    ui->label4->show();
    ui->label4->setText("选择修改的关系");
    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0, "朋友");
    ui->comboBox->insertItem(1, "用户1关注用户2");
    ui->comboBox->insertItem(2, "用户1被用户2关注");
    input_handler=[this]
    {
        int key1,key2;
        int judge;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())    //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key1);
        scan(ui->input2,key2);
        judge=relation_modify(&tree.tree,key1,key2,ui->comboBox->currentIndex());//完成修改
        if(judge==TRUE) print_and_flush("修改关系成功");
        else print_and_flush("修改关系失败");
        input_handler = nullptr;
        show_hide();
    };
}

//查询社交关系
void MainWindow::gui_searchrelation()
{
    print_and_flush("请输入要查询关系的两个用户的key\n");
    flush();
    show_input(2);
    ui->label1->setText("用户1的key");
    ui->label2->setText("用户2的key");
    input_handler=[this]
    {
        int key1,key2;
        int judge;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())     //如果输入框为空时点击确认按钮
        {

            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key1);
        scan(ui->input2,key2);
        judge=relation_search(tree.tree,key1,key2);
        if(judge==AVL_FRIEND) print_and_flush("用户1和2是朋友关系");
        if(judge==AVL_USER1_FOLLOW_USER2) print_and_flush("用户1关注用户2");
        if(judge==AVL_USER2_FOLLOW_USER1) print_and_flush("用户2关注用户1");
        if(judge==AVL_USER_NO_RELATION) print_and_flush("用户1和2没有社交关系");
        if(judge==FALSE) print_and_flush("查找失败");
        input_handler = nullptr;
        show_hide();
    };
}
//遍历社交关系
void MainWindow::gui_traverserelation()
{
    print_and_flush("请输入要遍历的用户的key\n");
    flush();
    show_input(1);
    ui->label1->setText("用户的key");
    ui->label4->show();
    ui->label4->setText("选择遍历类别");
    ui->label5->show();
    ui->label5->setText("选择遍历方式");
    /*设置两个下拉菜单*/
    ui->comboBox->show();
    ui->comboBox_1->show();

    ui->comboBox->insertItem(0, "好友");
    ui->comboBox->insertItem(1, "关注的人");
    ui->comboBox->insertItem(2, "粉丝");

    ui->comboBox_1->insertItem(0, "前序遍历");
    ui->comboBox_1->insertItem(1, "中序遍历");
    ui->comboBox_1->insertItem(2, "后序遍历");
    ui->comboBox_1->insertItem(3, "按层遍历");

    input_handler=[this]
    {
        int key;
        if(ui->input1->text().isEmpty())         //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key);
        auto visit = [this](childelemnode data)
        {
            print("key为 ",data.key);
            print("名字为 \n",data.name);
        };
        relation_traverse(tree.tree,key,ui->comboBox->currentIndex(),ui->comboBox_1->currentIndex(),visit);  //传入lambda表达式和下拉选项完成遍历
        print_and_flush("遍历完毕");

        input_handler = nullptr;
        show_hide();
    };
}
//重置社交关系
void MainWindow::gui_resetrelation()
{
    print_and_flush("请输入要重置关系的用户的key\n");
    show_input(1);
    ui->label1->setText("用户的key");
    ui->label4->show();
    ui->label4->setText("选择重置的类别");

    //设置下拉菜单
    ui->comboBox->show();
    ui->comboBox->insertItem(0, "好友集");
    ui->comboBox->insertItem(1, "关注集");
    ui->comboBox->insertItem(2, "粉丝集");

    //调用删除函数实现初始化功能
    input_handler=[this]
    {
        int key;
        int judge;
        if(ui->input1->text().isEmpty())          //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key);
        judge=relation_reset(&tree.tree,key,ui->comboBox->currentIndex());  //完成重置
        if(judge==TRUE) print_and_flush("初始化成功");
        else print_and_flush("初始化失败");
        input_handler = nullptr;
        show_hide();
    };

}

/*爱好界面*/
//插入爱好
void MainWindow::gui_inserthobby()
{
    print_and_flush("请输入要添加爱好的用户的key和爱好\n");
    flush();
    show_input(2);
    ui->label1->setText("用户的key");
    ui->label2->setText("爱好");
    input_handler=[this]
    {
        std::string  hobbyname;
        int key;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())  //如果输入框为空时点击确认按钮
        {
               print_and_flush("输入为空\n");
               return;
        }
        scan(ui->input1, key);
        scan(ui->input2, hobbyname);
        int judge=hobby_insert(&tree.tree,key,hobbyname);  //调用函数添加爱好
        if(judge==TRUE) print_and_flush("添加爱好成功");
        else print_and_flush("添加爱好失败");
        input_handler = nullptr;
        show_hide();
    };
}
//删除爱好
void MainWindow::gui_removehobby()
{
    print_and_flush("请输入要删除爱好的用户的key和爱好\n");
    show_input(2);
    ui->label1->setText("用户的key");
    ui->label2->setText("爱好");
    input_handler=[this]
    {
        std::string  hobbyname;
        int key;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())   //如果输入框为空时点击确认按钮
        {
               print_and_flush("输入为空\n");
               return;
        }
        scan(ui->input1, key);
        scan(ui->input2, hobbyname);
        int judge=hobby_remove(&tree.tree,key,hobbyname);   //调用函数删除爱好
        if(judge==TRUE) print_and_flush("删除爱好成功");
        else print_and_flush("删除爱好失败");
        input_handler = nullptr;
        show_hide();
    };
}
//修改爱好
void MainWindow::gui_modifyhobby()
{
    print_and_flush("请依次输入用户的key 原爱好 现在的爱好\n");
    show_input(3);
    ui->label1->setText("用户的key");
    ui->label2->setText("原爱好");
    ui->label3->setText("现爱好");
    input_handler=[this]
    {
        std::string oldhobbyname;
        std::string newhobbyname;
        int key;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty()||ui->input3->text().isEmpty()) //如果输入框为空时点击确认按钮
        {
               print_and_flush("输入为空\n");
               return;
        }
        scan(ui->input1,key);
        scan(ui->input2,oldhobbyname);
        scan(ui->input3,newhobbyname);
        int judge=hobby_modify(&tree.tree,key,oldhobbyname,newhobbyname); //调用函数修改爱好
        if(judge==TRUE) print_and_flush("修改爱好成功");
        else print_and_flush("修改爱好失败");
        input_handler = nullptr;
        show_hide();
    };
}
//遍历爱好
void MainWindow::gui_traversehobby()
{
    print_and_flush("请输入要遍历的用户的key和遍历的方式\n");
    flush();
    show_input(1);
    ui->label1->setText("用户的key");
    ui->label4->show();
    ui->label4->setText("遍历的方式");

    /*设置下拉菜单*/
    ui->comboBox->show();
    ui->comboBox->insertItem(0, "前序遍历");
    ui->comboBox->insertItem(1, "中序遍历");
    ui->comboBox->insertItem(2, "后序遍历");
    ui->comboBox->insertItem(3, "按层遍历");

    input_handler=[this]
    {
        int key;
        if(ui->input1->text().isEmpty())      //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key);
        auto visit = [this](childelemnode data)
        {
            print("爱好:",data.name,"\n");
        };
        int judge=hobby_traverse(tree.tree,key,ui->comboBox->currentIndex(),visit); //传入lambda表达式完成遍历
        if(judge==TRUE) print_and_flush("遍历完毕");
        else print_and_flush("遍历失败");
        input_handler = nullptr;
        show_hide();
    };
}

//重置爱好
void MainWindow::gui_resethobby()
{
    print_and_flush("请输入要初始化爱好的用户的key\n");
    flush();
    show_input(1);
    ui->label1->setText("用户的key");
    input_handler=[this]
    {
        int key;
        if(ui->input1->text().isEmpty())       //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key);
        int judge=hobby_reset(&tree.tree,key);  //完成对爱好的重置
        if(judge==TRUE) print_and_flush("初始化成功");
        else print_and_flush("初始化失败");
        input_handler = nullptr;
        show_hide();
    };
}

//查询爱好
void MainWindow::gui_searchhobby()
{
    print_and_flush("输入查询的爱好\n");
    show_input(1);
    ui->label1->setText("查询的爱好");
    input_handler=[this]
    {
        std::string hobby;
        if(ui->input1->text().isEmpty())         //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,hobby);
        print_and_flush("爱好",hobby,"的有\n");
        auto visit = [this](elemnode data)
        {
            print("key:",data.key," 用户名:",data.name,"\n");
        };
        int judge=hobby_search(tree.tree,hobby,visit);  //传入lambda表达式完成遍历
        if(judge==TRUE) print_and_flush("遍历完毕");
        else print_and_flush("遍历失败");
        input_handler = nullptr;
        show_hide();
    };
}

/*特殊查询界面*/
//共同关注
void MainWindow::gui_tinyset_bothfollow()
{
    print_and_flush("请输入用户1和2的key\n");
    show_input(2);
    ui->label1->setText("用户1的key");
    ui->label2->setText("用户2的key");
    input_handler=[this]
    {
        int key1,key2;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())       //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key1);
        scan(ui->input2,key2);
        auto visit = [this](childelemnode data)
        {
            print("key:",data.key," 用户名:",data.name,"\n");
        };
        int judge=bothfollow(tree.tree,key1,key2,visit);     //传入lambda表达式打印共同关注
        if(judge==TRUE) print_and_flush("查询成功");
        else print_and_flush("查询失败");
        show_hide();

    };
}

//共同爱好
void MainWindow::gui_tinyset_bothhobby()
{
    print_and_flush("请输入用户1和2的key\n");
    flush();
    show_input(2);
    ui->label1->setText("用户1的key");
    ui->label2->setText("用户2的key");
    input_handler=[this]
    {
        int key1,key2;
        if(ui->input1->text().isEmpty()||ui->input2->text().isEmpty())        //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,key1);
        scan(ui->input2,key2);
        auto visit = [this](childelemnode data)
        {
            print("爱好:",data.name,"\n");
        };
        int judge=bothhobby(tree.tree,key1,key2,visit);     //传入lambda表达式打印共同爱好
        if(judge==TRUE) print_and_flush("查询成功");
        else print_and_flush("查询失败");
        show_hide();
    };
};


//二度好友
void MainWindow::gui_twodegreefriend()
{
    print_and_flush("请输入要查询的用户的key\n");
    flush();
    show_input(1);
    ui->label1->setText("用户的key");
    input_handler=[this]
    {
        int key;
        scan(ui->input1,key);
        auto visit = [this](childelemnode data)
        {
            print("key:",data.key,"用户名:",data.name,"\n");
        };
        int judge=twodegreefriend(tree.tree,key,visit);   //传入lambda表达式打印二度好友
        if(judge==TRUE) print_and_flush("查询成功");
        else print_and_flush("查询失败");
        show_hide();
    };
}


/*随机界面*/
//随机数据
void MainWindow::gui_randomuser()
{
    print_and_flush("请输入要生成的用户的规模\n");
    show_input(1);
    ui->label1->setText("生成的用户数");
    input_handler=[this]
    {
        int usernum;
        if(ui->input1->text().isEmpty())         //如果输入框为空时点击确认按钮
        {
            print_and_flush("输入为空\n");
            return;
        }
        scan(ui->input1,usernum);

        addrandomuser(&tree.tree,usernum);     //添加制定规模的随机用户
        addrandomhobby(&tree.tree);            //为每个用户添加数量随机的爱好
        addrandomfriend(&tree.tree);           //添加随机朋友
        addrandomfollow(&tree.tree);           //添加随机的关注和粉丝关系
        print_and_flush("生成结束");
        show_hide();
    };
}

/****************************************文件界面****************************************/
//保存备份文件
void MainWindow::gui_save_applybackupdata()
{
    print_and_flush("按确认按钮完成存文件功能\n");
    flush();
    show_input(1);
    ui->label1->setText("指定文件名");
    input_handler=[this]
    {
        std::string filename;
        scan(ui->input1,filename);
        filename=filename+".csv";

        savefile(tree.tree,filename);
        show_hide();
    };
}
//读取备份文件
void MainWindow::gui_read_applybackupdata()
{
    print_and_flush("按确认按钮完成读文件功能\n");
    flush();
    show_input(1);
    ui->label1->setText("指定文件名");
    input_handler=[this]
    {
        std::string filename;
        scan(ui->input1,filename);
        filename=filename+".csv";

        int judge=readfile(&tree.tree,filename);
        if(judge==TRUE) print_and_flush("读取成功");
        else print_and_flush("读取失败");
        show_hide();
    };
}

//读取库文件
void MainWindow::gui_read_applydata()
{
    std::string filename="data.csv";
    readfile(&tree.tree,filename);
    ui->textBrowser->show();
    print_and_flush("\n成功读取",set_size(tree.tree),"条数据");
}

//写入库文件
void MainWindow::gui_save_applydata()
{
    std::string filename="data.csv";
    savefile(tree.tree,filename);
    ui->textBrowser->show();
    print_and_flush("成功保存",set_size(tree.tree),"条数据\n");
}

//读取树
void MainWindow::gui_read_setdata()
{
    std::string tree1="tree1.csv";
    std::string tree2="tree2.csv";
    readfile(&t1.tree,tree1);
    readfile(&t2.tree,tree2);
    ui->textBrowser->show();
    print_and_flush("成功读取数据\n");
}

//写入树
void MainWindow::gui_save_setdata()
{
    std::string tree1="tree1.csv";
    std::string tree2="tree2.csv";
    savefile(t1.tree,tree1);
    savefile(t2.tree,tree2);
    ui->textBrowser->show();
    print_and_flush("成功保存\n");
}

















//for test AVL
void MainWindow::printtree()
{
    print_and_flush(treeheight(tree.tree));
}

int MainWindow::treeheight(AVLpoint T)
{
    if(T==nullptr) return FALSE;
    int left= treeheight((T)->lchild);
    int right=treeheight((T)->rchild);
    if(left>right) return left+1;
    else return right+1;
}


//检查高度
void MainWindow::on_actionhigh_triggered()
{
    printtree();
}








void MainWindow::on_input1_cursorPositionChanged(int arg1, int arg2)
{

}
