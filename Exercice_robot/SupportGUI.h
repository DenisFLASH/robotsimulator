#ifndef SUPPORTGUI_H
#define SUPPORTGUI_H

#include "PlayingArea.h"
#include <QtCore>

class SupportGUI : public QThread
{
private:
    PlayingArea* p_playingArea;
public:
    SupportGUI();
    ~SupportGUI();
    void bindPlayingArea(PlayingArea* area);
    PlayingArea* getPlayingArea();
    void run();
};

#endif // SUPPORTGUI_H
