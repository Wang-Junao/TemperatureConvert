#ifndef TEMPWINDOW_H
#define TEMPWINDOW_H

#include <QMainWindow>

namespace Ui {
class TempWindow;
}

class TempWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TempWindow(QWidget *parent = nullptr);
    ~TempWindow();

private:
    Ui::TempWindow *ui;

public :
    static void Exiter();

    void ClearAll();

    void ConvertTemp();

    void ReadValue();

    void TheNew();

    static void AboutThis();

    static void UpdateLog();

    static void Explain();

    bool TooBigNumber(const double&, const QString&);
};

#endif // TEMPWINDOW_H
