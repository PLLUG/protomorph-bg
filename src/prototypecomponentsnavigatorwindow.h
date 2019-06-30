#ifndef PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
#define PROTOTYPECOMPONENTSNAVIGATORWINDOW_H

#include <QWidget>
class QStandardItemModel;
class QItemSelectionModel;

namespace Ui {
class PrototypeComponentsNavigatorWindow;
}

class PrototypeComponentsNavigatorWindow : public QWidget
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
