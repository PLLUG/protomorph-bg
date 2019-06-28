#ifndef PROJECTVIEWERWINDOW_H
#define PROJECTVIEWERWINDOW_H

#include <QWidget>

namespace Ui {
class ProjectViewerWindow;
}

class QString;

class ProjectViewerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectViewerWindow(QWidget *parent = nullptr);
    ~ProjectViewerWindow();

signals:
    void newProjectRequested();
    void projectOpened(QString fullProjectPath);
    void projectRemoved(QString fullProjectPath);

private:
    Ui::ProjectViewerWindow *ui;
};

#endif // PROJECTVIEWERWINDOW_H
