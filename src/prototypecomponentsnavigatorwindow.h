#ifndef PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
#define PROTOTYPECOMPONENTSNAVIGATORWINDOW_H

#include <QWidget>

class QItemSelectionModel;
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
    QItemSelectionModel *mSelectionModel;
    QAbstractItemModel *mPreviewItemModel;

private slots:
    void setButtonEnabled();

};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
