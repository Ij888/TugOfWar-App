#ifndef TugOfWar_HPP_
#define TugOfWar_HPP_

#include <QObject>

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
};

#endif /* TugOfWar_HPP_ */
