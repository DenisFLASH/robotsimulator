#ifndef VIEWGAME_H
#define VIEWGAME_H
#include <QFrame>
#include <QGraphicsView>

class viewGame;
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(viewGame *v) : QGraphicsView(), view(v) { }

private:
    viewGame *view;
};


class viewGame : public QFrame
{
public:
    ~viewGame();
    viewGame(const QString &name, QWidget *parent = 0);
    QGraphicsView *view() const;

private:
    QGraphicsView *graphicsView;
};

#endif // VIEWGAME_H
