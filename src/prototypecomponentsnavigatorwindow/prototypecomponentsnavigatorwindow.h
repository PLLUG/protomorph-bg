#ifndef PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
#define PROTOTYPECOMPONENTSNAVIGATORWINDOW_H

#include <QWidget>

class QAbstractItemModel;

namespace Ui {
class PrototypeComponentsNavigatorWindow;
}

class PrototypeComponentsNavigatorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PrototypeComponentsNavigatorWindow(QWidget *parent = nullptr);
    ~PrototypeComponentsNavigatorWindow();

public:
    void setModel(QAbstractItemModel*);

private:
    Ui::PrototypeComponentsNavigatorWindow *ui;

signals:
    void newComponentRequested();
    void componentOpened(QString id);
    void componentRemoved(QString id);

private slots:
    void componentOpenButtonClicked();
    void componentRemovButtonClicked();
    void handleSelectionChanged();

};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
