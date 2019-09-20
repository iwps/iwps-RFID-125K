#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<QtNetwork>
#include<QNetworkAccessManager>
Server::Server(QByteArray cardId)
{
   this->cardId = cardId;
   //QHttpRequestHeader header("192.168.0.1/test.html");
   QNetworkAccessManager m_pNetWorkManager;
   QNetworkRequest request;
   QByteArray line;
   request.setUrl(QUrl("http://192.168.0.101:8080/rfid/sendList"));
   request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

   QByteArray array("{\"cardId\":\""+this->cardId.toHex()+"\"}");

   QNetworkReply *reply = m_pNetWorkManager.post(request, array);

   QEventLoop loop;
   QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
   loop.exec();

   printf("Connection closed.\n");
}
int Server::myServer()
{

}
