#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>  //添加头文件

#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <dialog.h>

int main(int argc, char *argv[])
{
       QApplication a(argc, argv);
       MainWindow w;
       Dialog dlg;
       if (dlg.exec() == QDialog::Accepted)
       {
          w.show();
          return a.exec();
       }
       else return 0;
}
