#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
class mainwindow;
}

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();


private slots:
    void actualizar();
    void actualizar2();
    void actualizar3();
    void actualizar4();
    void actualizar5();

    void on_tabWidget_currentChanged();//int index);

    void on_mainwindow_signalActualizar();

    //void on_tabWidget_currentChanged();//int index);

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
