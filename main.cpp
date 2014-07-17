#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "graphwidget.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication a(argc, argv);
    MainWindow window;

    window.show();
    return a.exec();
}
