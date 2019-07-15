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

    void setModel(QAbstractItemModel*);

signals:
    void newComponentRequested();
    void componentOpened(QString id);
    void componentRemoved(QString id);

private slots:
    void componentOpenButtonClicked();
    void componentRemovButtonClicked();
    void handleSelectionChanged();

private:
    Ui::PrototypeComponentsNavigatorWindow *ui;


};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
