#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <functional>
#include "head.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    template <typename Edit, typename ...Args>
    void scan(Edit input, Args&&...args);
    void clear_output();
    template <typename ...Args>
    void print(Args&&...args);
    template <typename ...Args>
    void print_and_flush(Args&&...args);
    void flush();
    Ui::MainWindow *ui;



private slots:

    void on_button_exit_clicked();

    void on_button_ok_clicked();

    void on_action_init_triggered();

    void on_action_destroy_triggered();

    int on_action_insert_triggered();

    int on_action_remove_triggered();

    int on_action_modify_triggered();

    int on_action_member_triggered();

    int on_action_size_triggered();

    int on_action_traverse_triggered();

    int on_action_relationinsert_triggered();

    int on_action_relationremove_triggered();

    int on_action_relationmodify_triggered();

    int on_action_relationmember_triggered();

    int on_action_relationtraverse_triggered();

    int on_action_relationreset_triggered();

    int on_action_hobbyinsert_triggered();

    int on_action_hobbyremove_triggered();

    int on_action_hobbymodify_triggered();

    int on_action_hobbymember_triggered();

    int on_action_hobbytraverse_triggered();

    int on_action_hobbyreset_triggered();

    int on_bothfollow_triggered();

    int on_bothhobby_triggered();


    int on_twodegreefriend_triggered();

    int on_random_triggered();

    int on_readapplybackup_triggered();

    int on_saveapplybackup_triggered();

    void on_actionhigh_triggered();

    void on_button_save_clicked();

    void on_set_init_triggered();

    void on_set_destroy_triggered();

    void on_set_insert_triggered();

    void on_set_remove_triggered();

    void on_set_intersection_triggered();

    void on_set_union_triggered();

    void on_set_difference_triggered();

    void on_set_size_triggered();

    void on_set_member_triggered();

    void on_set_subset_triggered();

    void on_set_equal_triggered();

    void on_saveset_triggered();

    void on_readset_triggered();

    void on_readapply_triggered();

    void on_saveapply_triggered();

    void on_input1_cursorPositionChanged(int arg1, int arg2);

private:
    std::function<void()> input_handler;

    QString output;
//    BSTree tree = nullptr;
    struct tree tree;

    struct tree t1;
    struct tree t2;

    void show_input(std::size_t number_of_edit);
    //插入算法
    int gui_insert_user();
    //删除算法


//    status gui_set_member();



    void gui_searchuser();
    void gui_removeuser();
    void gui_modifyuser();
    void gui_traverseuser();
    void show_hide();

    void gui_insertrelation();
    void gui_removerelation();
    void gui_modifyrelation();
    void gui_traverserelation();
    void gui_searchrelation();
    void gui_resetrelation();
    void gui_inserthobby();
    void gui_removehobby();
    void gui_modifyhobby();
    void gui_traversehobby();
    void gui_resethobby();
    void gui_searchhobby();
    void gui_save_applybackupdata();
    void gui_tinyset_bothfollow();
    void gui_read_applybackupdata();
    void gui_tinyset_bothhobby();
    void gui_twodegreefriend();
    void gui_randomuser();
    void gui_set_init();
    void printtree();
    int treeheight(AVLpoint T);
    void gui_set_destroy();
    void gui_read_applydata();
    void gui_save_applydata();

    void gui_actionset_init();
    void gui_actionset_destroy();
    int gui_actionset_insert();
    void gui_actionset_remove();
    void gui_actionset_intersection();
    void gui_actionset_union();
    void gui_actionset_difference();
    void gui_actionset_size();
    void gui_actionset_member();
    void gui_actionset_subset();
    void gui_actionset_equal();
    void gui_read_setdata();
    void gui_save_setdata();
};

#endif // MAINWINDOW_H
