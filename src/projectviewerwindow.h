#ifndef PROJECTVIEWERWINDOW_H
#define PROJECTVIEWERWINDOW_H

#include <QWidget>

namespace Ui {
class ProjectViewerWindow;
}

class QString;
class QStringListModel;
class QAbstractItemModel;
class QItemSelectionModel;
class QItemSelection;

class ProjectViewerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectViewerWindow(QWidget *parent = nullptr);
    ~ProjectViewerWindow();

    void setModel(QAbstractItemModel*);
signals:
    void newProjectRequested();
    void projectOpened(QString fullProjectPath);
    void projectRemoved(QString fullProjectPath);

private slots:
    void onNewProjectButtonClicked();
    void onOpenProjectButtonClicked();
    void onRemoveProjectButtonClicked();

    void makeButtonsEnabled();

private:
    Ui::ProjectViewerWindow *ui;
    QAbstractItemModel *mProjectsViewModel;
    QItemSelectionModel *mSelectionModel;
};

#endif // PROJECTVIEWERWINDOW_H
