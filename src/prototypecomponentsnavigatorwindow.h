#ifndef PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
#define PROTOTYPECOMPONENTSNAVIGATORWINDOW_H

#include <QDialog>
class QStandardItemModel;
class QItemSelectionModel;

namespace Ui {
class PrototypeComponentsNavigatorWindow;
}

class PrototypeComponentsNavigatorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PrototypeComponentsNavigatorWindow(QWidget *parent = nullptr);
    ~PrototypeComponentsNavigatorWindow();

private:
    Ui::PrototypeComponentsNavigatorWindow *ui;
    QStandardItemModel *componentPreview;
    QItemSelectionModel *mSelectionModel;

private slots:
    void setButtonEnabled();

};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
