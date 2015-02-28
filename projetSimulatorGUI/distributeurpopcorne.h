#ifndef DISTRIBUTEURPOPCORNE_H
#define DISTRIBUTEURPOPCORNE_H

#include <QGraphicsRectItem>

class DistributeurPopCorne: public QGraphicsRectItem
{
public:
    DistributeurPopCorne();
    ~DistributeurPopCorne();
   private:
   std::string m_text;
};

#endif // DISTRIBUTEURPOPCORNE_H
