#include "app.hpp"

Application::Application(int &argc, char **argv) : QApplication(argc, argv) {
  std::string sys_locale = util::read_file("/data/property/persist.sys.locale");
  QString lang = QLocale(sys_locale.c_str()).name();
  LOGW("system_language:%s", lang.toStdString().c_str());
  initTranslator(lang);
}

void Application::initTranslator(const QString &language) {
  translator = new QTranslator(this);
  QString translationFile = QString("qt/translations/offroad_%1").arg(language);
  if (translator->load(translationFile)) {
    installTranslator(translator);
  }
}


