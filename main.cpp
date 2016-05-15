#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // ================= Setting Windows Size =================
    QDesktopWidget wid;
    int screenW = 1000;
    int screenH = 563;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);
    // ================= Setting Windows Title and Icon =================
    w.setWindowTitle("Taiko Drum Master");
    w.setWindowIcon(QIcon(":/image/img/icon.jpg"));
    w.setFixedSize(screenW , screenH);
    w.show();
    return a.exec();
}
