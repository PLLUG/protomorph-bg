#include "prototypecomponentsnavigatorwindow.h"
#include "ui_prototypecomponentsnavigatorwindow.h"
#include <QStringListModel>
#include <QItemSelectionModel>

PrototypeComponentsNavigatorWindow::PrototypeComponentsNavigatorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrototypeComponentsNavigatorWindow)
{
    ui->setupUi(this);

    componentPreview = new QStringListModel(this);
    mSelectionModel = new QItemSelectionModel;

    QStringList list;
    list << "Clair de Lune" << "Reverie" << "Prelude";
    componentPreview->setStringList(list);
    ui->listView->setModel(componentPreview);

    mSelectionModel = ui->listView->selectionModel();
    connect(mSelectionModel,&QItemSelectionModel::selectionChanged,this,&PrototypeComponentsNavigatorWindow::setButtonEnabled);
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


