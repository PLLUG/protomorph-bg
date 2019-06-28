#include "prototypecomponentsnavigatorwindow.h"
#include "ui_prototypecomponentsnavigatorwindow.h"
#include <QStringListModel>

PrototypeComponentsNavigatorWindow::PrototypeComponentsNavigatorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrototypeComponentsNavigatorWindow)
{
    ui->setupUi(this);

    componentPreview = new QStringListModel(this);

    QStringList list;
    list << "Clair de Lune" << "Reverie" << "Prelude";
    componentPreview->setStringList(list);
    ui->listView->setModel(componentPreview);
//    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed |
//                                  QAbstractItemView::DoubleClicked);

    connect( componentPreview, SIGNAL(clicked), this, SLOT(setButtonEnabled));
}

PrototypeComponentsNavigatorWindow::~PrototypeComponentsNavigatorWindow()
{
    delete ui;
}

void PrototypeComponentsNavigatorWindow::setButtonEnabled()
{
    ui->pushButtonLoadSelectedComponents->setEnabled(true);
    ui->pushButtonDeleteSelectedComponent->setEnabled(true);
}


