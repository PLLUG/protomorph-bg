#include "prototypecomponentsnavigatorwindow.h"
#include "ui_prototypecomponentsnavigatorwindow.h"

PrototypeComponentsNavigatorWindow::PrototypeComponentsNavigatorWindow(QWidget *parent) :
    QWidget(parent)
  ,ui(new Ui::PrototypeComponentsNavigatorWindow)
{
    ui->setupUi(this);

    ui->listView->setIconSize(QSize(100,100));
    ui->listView->setUniformItemSizes(true);

    connect(ui->pushButtonAddComponentsToPrototipe, &QPushButton::clicked, this, &PrototypeComponentsNavigatorWindow::newComponentRequested);
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
        connect(ui->listView->selectionModel(), &QItemSelectionModel::selectionChanged,this,&PrototypeComponentsNavigatorWindow::handleSelectionChanged);
    }
}

void PrototypeComponentsNavigatorWindow::componentOpenButtonClicked()
{
    emit componentOpened("");
}

void PrototypeComponentsNavigatorWindow::componentRemovButtonClicked()
{
    emit componentRemoved("");
}

void PrototypeComponentsNavigatorWindow::handleSelectionChanged()
{
    bool isOnlyOneProjectSelected = ui->listView->selectionModel()->selectedIndexes().size() == 1;
    bool isAnyProjectsSelected = ui->listView->selectionModel()->selectedIndexes().size() > 0;

    ui->pushButtonDeleteSelectedComponent->setEnabled(isAnyProjectsSelected);
    ui->pushButtonLoadSelectedComponents->setEnabled(isOnlyOneProjectSelected);
}

