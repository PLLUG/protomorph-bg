#include "prototypecomponentsnavigatorwindow.h"
#include "ui_prototypecomponentsnavigatorwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>

PrototypeComponentsNavigatorWindow::PrototypeComponentsNavigatorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrototypeComponentsNavigatorWindow)
{
    ui->setupUi(this);

    componentPreview = new QStandardItemModel(this);
    mSelectionModel = new QItemSelectionModel;

    componentPreview->appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item1"));
    componentPreview->appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item2"));
    componentPreview->appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item3"));

    ui->listView->setModel(componentPreview);
    ui->listView->setIconSize(QSize(100,100));
    ui->listView->setUniformItemSizes(true);
    ui->listView->setSelectionMode(QAbstractItemView::MultiSelection);

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


