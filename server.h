#include "Widget.h"
#include "ui_Widget.h"

#ifndef SERVER_H
#define SERVER_H

class Server
{
public:
    Server(QByteArray cardId);
    int myServer();
private:
    QByteArray cardId;
};

#endif // SERVER_H
