#ifndef PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
#define PROTOTYPECOMPONENTSNAVIGATORWINDOW_H

#include <QWidget>

class QItemSelectionModel;
class QAbstractItemModel;
class QStandardItem;
class QItemSelection;


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
    void handleSelectionChanged(const QItemSelection &, const QItemSelection &);

};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
