#include "prototypecomponentsnavigatorwindow.h"
#include "ui_prototypecomponentsnavigatorwindow.h"
#include <QItemSelectionModel>
#include <QAbstractItemModel>
#include <QStandardItem>

PrototypeComponentsNavigatorWindow::PrototypeComponentsNavigatorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrototypeComponentsNavigatorWindow)
{
    ui->setupUi(this);


    mSelectionModel = new QItemSelectionModel;

    ui->listView->setIconSize(QSize(100,100));
    ui->listView->setUniformItemSizes(true);
    ui->listView->setSelectionMode(QAbstractItemView::MultiSelection);

    connect(ui->pushButtonAddComponentsToPrototipe, &QPushButton::clicked, this, &PrototypeComponentsNavigatorWindow::newComponentButtonClicked);
    connect(ui->pushButtonLoadSelectedComponents, &QPushButton::clicked, this, &PrototypeComponentsNavigatorWindow::componentOpenButtonClicked);
    connect(ui->pushButtonDeleteSelectedComponent, &QPushButton::clicked, this, &PrototypeComponentsNavigatorWindow::componentRemovButtonClicked);

}

PrototypeComponentsNavigatorWindow::~PrototypeComponentsNavigatorWindow()
{
    delete ui;
}

void PrototypeComponentsNavigatorWindow::setModel(QAbstractItemModel *model)
{
    if(model)
    {
        ui->listView->setModel(model);
        mSelectionModel = ui->listView->selectionModel();
        connect(model, SIGNAL(itemChanged(QStandardItem *)), this, SLOT(handleCheckedChanged(QStandardItem *)));
        connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(handleSelectionChanged(QItemSelection, QItemSelection)));
    }
}

void PrototypeComponentsNavigatorWindow::newComponentButtonClicked()
{
    emit newComponentRequested();
}

void PrototypeComponentsNavigatorWindow::componentOpenButtonClicked()
{
    emit componentOpened("");
}

void PrototypeComponentsNavigatorWindow::componentRemovButtonClicked()
{
    emit componentRemoved("");
}


void PrototypeComponentsNavigatorWindow::handleCheckedChanged(QStandardItem *item)
{
    mSelectionModel = ui->listView->selectionModel();
    mSelectionModel->select(QItemSelection(item->model()->indexFromItem(item), item->model()->indexFromItem(item)), item->checkState() == Qt::Checked ? QItemSelectionModel::Select : QItemSelectionModel::Deselect);
}

void PrototypeComponentsNavigatorWindow::handleSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    foreach (const QModelIndex &index, selected.indexes())
    {
        ui->pushButtonLoadSelectedComponents->setEnabled(true);
        ui->pushButtonDeleteSelectedComponent->setEnabled(true);
    }
    foreach (const QModelIndex &index, deselected.indexes())
    {
        ui->pushButtonLoadSelectedComponents->setEnabled(false);
        ui->pushButtonDeleteSelectedComponent->setEnabled(false);
    }
}

