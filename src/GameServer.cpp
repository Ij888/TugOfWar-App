#include "GameServer.hpp"

#include <QtNetwork/QTcpSocket>

GameServer::GameServer(QObject *parent, int listenPort) : QTcpServer(parent), listenPort(listenPort) {

}

void GameServer::start() {

	qDebug() << "Starting the Game Server on port " << listenPort;

	bool isListening = listen(QHostAddress::Any, (quint16) listenPort);

	if (isListening) {
		qDebug() << "Started listening";
	} else {
		qDebug() << "Could not start listening" << errorString();
	}
}

void GameServer::incomingConnection(int socketDescriptor) {

	qDebug() << "Got incoming connection";

	QTcpSocket *tcpSocket = new QTcpSocket(this);
	tcpSocket->setSocketDescriptor(socketDescriptor);
	//close the socket immediately
	tcpSocket->abort();
	delete tcpSocket;

	emit tugReceived();
}

GameServer::~GameServer() {

}

