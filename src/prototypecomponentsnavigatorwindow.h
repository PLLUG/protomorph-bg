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


private slots:
    void handleCheckedChanged(QStandardItem *);
    void handleSelectionChanged(const QItemSelection &, const QItemSelection &);

};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
