#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSplitter>
#include "scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Scene *myscene;
    QSplitter *h1Splitter;
    QSplitter *h2Splitter;
};

#endif // MAINWINDOW_H
