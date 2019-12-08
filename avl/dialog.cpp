#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "picosha2.h"
#include "QString"
#include <string>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->passwordinput->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
}

Dialog::~Dialog()
{
    delete ui;
}


template <typename Edit, typename ...Args>
void Dialog::scan(Edit input, Args&&...args)
{
    auto text = input->text().toStdString();
    input->setText("");
    std::istringstream stream(text);
    int list[] __attribute__((unused))= {(stream >> std::forward<Args>(args), 0)...};
}

void Dialog::on_pushButton_clicked()
{
    std::string password="a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3";//123经过sha256加密的结果
    std::string passwordinput;
    std::string checkpassword;

    scan(ui->passwordinput,passwordinput);

    checkpassword=picosha2::hash256_hex_string(passwordinput);  //输入的密码sha256加密

        if(ui->nameinput->text() == tr("admin")&&  //用户名设置
               checkpassword == password) //比较加密后的输入密码和设置的密码加密后的密码
        {
           accept();
        } else {
           QMessageBox::warning(this, tr("Waring"),  //弹框
                                 tr("user name or password error!"),
                                 QMessageBox::Yes);
        }
}

