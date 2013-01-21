// Default empty project template
#include "TugOfWar.hpp"
#include "GameServer.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

using namespace bb::cascades;

TugOfWar::TugOfWar(bb::cascades::Application *app) :
		QObject(app) {
	// create scene document from main.qml asset
	// set parent to created document to ensure it exists for the whole application lifetime
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
	qml->setContextProperty("game", this);

	// create root object for the UI
	AbstractPane *root = qml->createRootObject<AbstractPane>();
	// set created root object as a scene
	app->setScene(root);

	//initialize the rope position and pull counts
	ropePosition = 0;
	teamAPullCount = 0;
	teamBPullCount = 0;

	//Get the rope ImageView
	ropeImage = root->findChild<ImageView*>("rope");
	teamAPullCountLabel = root->findChild<Label*>("teamAPullCount");
	teamBPullCountLabel = root->findChild<Label*>("teamBPullCount");

	//Set up the input server
	GameServer *teamAServer = new GameServer(this, 8080);
	GameServer *teamBServer = new GameServer(this, 8081);

	//bind the pull signal to our pull slot
	connect(teamAServer, SIGNAL(tugReceived()), this, SLOT(tugA()));
	connect(teamBServer, SIGNAL(tugReceived()), this, SLOT(tugB()));
	teamAServer->start();
	teamBServer->start();
}

void TugOfWar::tugA(){
	tug(true);
}

void TugOfWar::tugB(){
	tug(false);
}

void TugOfWar::tug(bool isFromTeamA) {

	if (isFromTeamA) {
		ropePosition--;
		teamAPullCount++;
		teamAPullCountLabel->setText(QString::number(teamAPullCount));

	} else {
		ropePosition++;
		teamBPullCount++;
		teamBPullCountLabel->setText(QString::number(teamBPullCount));
	}

	qDebug() << "Got pull from team: " << ((isFromTeamA) ?
			"A" : "B") << " Rope position: " << ropePosition;

	//Update the rope position in the UI
	ropeImage->setTranslationX(ropePosition*10);
}

