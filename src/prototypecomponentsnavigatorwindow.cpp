#include "prototypecomponentsnavigatorwindow.h"
#include "ui_prototypecomponentsnavigatorwindow.h"
#include <QItemSelectionModel>
#include <QAbstractItemModel>

PrototypeComponentsNavigatorWindow::PrototypeComponentsNavigatorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrototypeComponentsNavigatorWindow)
{
    ui->setupUi(this);


    mSelectionModel = new QItemSelectionModel;

    ui->listView->setIconSize(QSize(100,100));
    ui->listView->setUniformItemSizes(true);
    ui->listView->setSelectionMode(QAbstractItemView::MultiSelection);

    mSelectionModel = ui->listView->selectionModel();
}

PrototypeComponentsNavigatorWindow::~PrototypeComponentsNavigatorWindow()
{
    delete ui;
}

void PrototypeComponentsNavigatorWindow::setModel(QAbstractItemModel *model)
{
    if(model)
    {
        mPreviewItemModel = model;
        ui->listView->setModel(mPreviewItemModel);
        connect(mSelectionModel,&QItemSelectionModel::selectionChanged,this,&PrototypeComponentsNavigatorWindow::setButtonEnabled);
    }
}

void PrototypeComponentsNavigatorWindow::setButtonEnabled()
{
    ui->pushButtonLoadSelectedComponents->setEnabled(true);
    ui->pushButtonDeleteSelectedComponent->setEnabled(true);
}


