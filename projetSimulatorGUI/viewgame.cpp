#include "scene.h"
#include "viewgame.h"
#include <QGraphicsView>
#include <QFrame>
class QLabel;
class QSlider;
class QToolButton;

viewGame::viewGame(const QString &name, QWidget *parent)
: QFrame(parent)
{
    graphicsView = new QGraphicsView();
    graphicsView->setFixedSize(1000,200);
}

viewGame::~viewGame()
{
}

QGraphicsView *viewGame::view() const
{
    return static_cast<QGraphicsView *>(graphicsView);
}
