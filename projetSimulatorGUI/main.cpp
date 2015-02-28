//#include "mainwindow.h"
#include <QApplication>
#include <qgraphicsview.h>
#include <QtGui>
#include "scene.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    Scene *scene = new Scene();
    QGraphicsView *view = new QGraphicsView(scene);
    //view->setFixedSize(900,600);
   // view.setRenderHint(QPainter::Antialiasing);
    //view.setBackgroundBrush(QPixmap(":/images/cheese.jpg"));
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    //view.setFixedWidth(1000);
    //view.setFixedHeight(900);
    //view.setBackgroundBrush(Qt::white);
    //view.show();
    /*MainWindow window;
    window.show()*/;
    //#if defined(Q_WS_S60) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    //#else
        view->show();
    //#endif

        QTimer timer;
       QObject::connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
        timer.start(1000 / 33);

        return app.exec();
}
