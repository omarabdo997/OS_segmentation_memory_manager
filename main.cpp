#include "mainwindow.h"
#include "segment.h"
#include "process.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   QApplication::setAttribute(Qt::AA_DisableWindowContextHelpButton);
      MainWindow w;
      w.show();
    return a.exec();

}
