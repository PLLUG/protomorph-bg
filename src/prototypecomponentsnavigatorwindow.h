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
    QItemSelectionModel *mSelectionModel;
    QAbstractItemModel *mPreviewItemModel;

signals:
    void newComponentRequested();
    void componentOpened(QString id);
    void componentRemoved(QString id);


private slots:
    void newComponentButtonClicked();
    void componentOpenButtonClicked();
    void componentRemovButtonClicked();
    void handleCheckedChanged(QStandardItem *);
    void handleSelectionChanged(const QItemSelection &, const QItemSelection &);

};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
