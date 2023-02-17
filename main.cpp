#include "mainwindow.h"
#include "tempwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    qputenv("QT_SCALE_FACTOR_ROUNDING_POLICY","");
    QApplication a(argc, argv);
    TempWindow w;
    w.setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    w.show();
    return a.exec();
}
