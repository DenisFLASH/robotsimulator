#include "PlayingArea.h"
#include "SimulatorEngine.h"
#include <QCoreApplication>
#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PlayingArea* playingArea = new PlayingArea();
    SimulatorEngine* engine = new SimulatorEngine(playingArea);


    return a.exec();
}
