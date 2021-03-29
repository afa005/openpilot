#include <QApplication>
#include <QTranslator>
#include <QString>

#include "common/swaglog.h"
#include "common/util.h"

#define myApp (dynamic_cast<Application *>(QApplication::instance()))

class Application : public QApplication {
  Q_OBJECT

public:
  Application(int &argc, char **argv);
  void initTranslator(const QString &language);

private:
  QTranslator *translator;
};
