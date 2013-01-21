// Default empty project template
#ifndef TugOfWar_HPP_
#define TugOfWar_HPP_

#include <QObject>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>

namespace bb {
namespace cascades {
class Application;
}
}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class TugOfWar: public QObject {
Q_OBJECT
public:
	TugOfWar(bb::cascades::Application *app);
	virtual ~TugOfWar() {
	}

Q_SIGNALS:

	void ropePositionUpdated(int newPosition);

public slots:

	void tugA();
	void tugB();

private:

	int ropePosition, teamAPullCount, teamBPullCount;
	bb::cascades::ImageView *ropeImage;
	bb::cascades::Label *teamAPullCountLabel, *teamBPullCountLabel;

	void tug(bool isFromTeamA);
};

#endif /* TugOfWar_HPP_ */
