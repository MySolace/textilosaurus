// For license of this file, see <project-root-folder>/LICENSE.md.

#include "gui/dialogs/formabout.h"

#include "definitions/definitions.h"
#include "exceptions/applicationexception.h"
#include "gui/guiutilities.h"
#include "miscellaneous/iconfactory.h"
#include "miscellaneous/settingsproperties.h"
#include "miscellaneous/textfactory.h"

#include <QFile>
#include <QTextStream>

FormAbout::FormAbout(QWidget* parent) : QDialog(parent) {
  m_ui.setupUi(this);
  m_ui.m_lblIcon->setPixmap(QPixmap(APP_ICON_PATH));
  GuiUtilities::applyDialogProperties(*this, qApp->icons()->fromTheme(QSL("help-about")), tr("About %1").arg(APP_NAME));
  loadLicenseAndInformation();
  loadSettingsAndPaths();
}

FormAbout::~FormAbout() {
  qDebug("Destroying FormAbout instance.");
}

void FormAbout::loadSettingsAndPaths() {
  if (qApp->settings()->type() == SettingsProperties::Portable) {
    m_ui.m_txtPathsSettingsType->setText(tr("FULLY portable"));
  }
  else {
    m_ui.m_txtPathsSettingsType->setText(tr("NOT portable"));
  }

  m_ui.m_txtPathsSettingsFile->setText(QDir::toNativeSeparators(qApp->settings()->fileName()));
}

void FormAbout::loadLicenseAndInformation() {
  try {
    m_ui.m_txtLicenseGnu->setText(IOFactory::readFile(APP_INFO_PATH + QL1S("/COPYING_GNU_GPL_HTML")));
  }
  catch (...) {
    m_ui.m_txtLicenseGnu->setText(tr("License not found."));
  }

  try {
    m_ui.m_txtLicenseMpl->setText(IOFactory::readFile(APP_INFO_PATH + QL1S("/COPYING_MPL")));
  }
  catch (...) {
    m_ui.m_txtLicenseMpl->setText(tr("License not found."));
  }

  try {
    m_ui.m_txtChangelog->setText(IOFactory::readFile(APP_INFO_PATH + QL1S("/CHANGELOG")));
  }
  catch (...) {
    m_ui.m_txtChangelog->setText(tr("Changelog not found."));
  }

  // Set other informative texts.
  m_ui.m_lblDesc->setText(tr("<b>%8</b><br>" "<b>Version:</b> %1 (built on %2/%3)<br>" "<b>Revision:</b> %4<br>" "<b>Build date:</b> %5<br>"
                                                                                                                 "<b>Qt:</b> %6 (compiled against %7)<br>").arg(
                            qApp->applicationVersion(), APP_SYSTEM_NAME, APP_SYSTEM_VERSION, APP_REVISION,
                            TextFactory::parseDateTime(QString("%1 %2").arg(__DATE__,
                                                                            __TIME__)).toString(Qt::DefaultLocaleShortDate),
                            qVersion(), QT_VERSION_STR,
                            APP_NAME));
  m_ui.m_txtInfo->setText(tr("<body>%5 is simple cross-platform text editor based on Qt and QScintilla."
                             "<br><br>This software is distributed under the terms of GNU General Public License, version 3."
                             "<br><br>Contacts:"
                             "<ul><li><a href=\"mailto://%1\">%1</a> ~e-mail</li>"
                             "<li><a href=\"%2\">%2</a> ~website</li></ul>"
                             "You can obtain source code for %5 from its website."
                             "<br><br><br>Copyright (C) 2017-%3 %4</body>").arg(APP_EMAIL, APP_URL,
                                                                                QString::number(QDateTime::currentDateTime()
                                                                                                .date()
                                                                                                .year()),
                                                                                APP_AUTHOR, APP_NAME));
}
