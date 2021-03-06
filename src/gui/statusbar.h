// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>

#include <QLabel>

class StatusBar : public QStatusBar {
  Q_OBJECT

  public:
    explicit StatusBar(QWidget* parent = nullptr);
    virtual ~StatusBar();

    void setEncoding(const QString& encoding);
    void setFileType(const QString& file_type);

  protected:
    bool eventFilter(QObject* watched, QEvent* event);

  private:
    QLabel* m_lblEncoding;
    QLabel* m_lblFileType;
};

#endif // STATUSBAR_H
