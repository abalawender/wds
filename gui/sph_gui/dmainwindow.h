#ifndef DMAINWINDOW_H
#define DMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class DMainWindow;
}

class DMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DMainWindow(QWidget *parent = 0);
    ~DMainWindow();

private:
    Ui::DMainWindow *ui;
};

#endif // DMAINWINDOW_H
