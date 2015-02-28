#include "SupportGUI.h"
#include "Scene.h"
#include <QGraphicsView>
#include <iostream>
using namespace std;

SupportGUI::SupportGUI()
{
    cout << "SupportGUI created..." << endl;
}

SupportGUI::~SupportGUI()
{
    cout << "...SupportGUI destroyed." << endl;
}

void SupportGUI::bindPlayingArea(PlayingArea *area)
{
    p_playingArea = area;
}

PlayingArea* SupportGUI::getPlayingArea()
{
    return p_playingArea;
}

void SupportGUI::run()
{
    cout << "\n\n\t\t!!!!!!  THREAD SupportGUI STARTED RUNNING..." << endl;
    Scene scene(p_playingArea);
    QGraphicsView view(&scene);
    //QTimer timer;
    //QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    view.show();
    //timer.start(10);
}
