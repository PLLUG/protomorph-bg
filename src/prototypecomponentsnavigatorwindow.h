#ifndef PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
#define PROTOTYPECOMPONENTSNAVIGATORWINDOW_H

#include <QDialog>
class QStringListModel;

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
    QStringListModel *componentPreview;

private slots:
    void setButtonEnabled();

};

#endif // PROTOTYPECOMPONENTSNAVIGATORWINDOW_H
