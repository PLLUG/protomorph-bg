#include "projectviewerwindow.h"
#include "ui_projectviewerwindow.h"

#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <QStringListModel>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QStandardItemModel>



ProjectViewerWindow::ProjectViewerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectViewerWindow)
{
    ui->setupUi(this);

    ui->projectsListView->setViewMode(QListView::ViewMode::IconMode);
    ui->projectsListView->setIconSize(QSize(100,100));
    ui->projectsListView->setUniformItemSizes(true);

    connect(ui->newProjectButton,&QPushButton::clicked,this,&ProjectViewerWindow::onNewProjectButtonClicked);
    connect(ui->openProjectButton,&QPushButton::clicked,this,&ProjectViewerWindow::onOpenProjectButtonClicked);
    connect(ui->deleteProjectButton,&QPushButton::clicked,this,&ProjectViewerWindow::onRemoveProjectButtonClicked);

}
ProjectViewerWindow::~ProjectViewerWindow()
{
    delete ui;
}

void ProjectViewerWindow::setModel(QAbstractItemModel *model)
{
    if(model)
    {
        mProjectsViewModel = model;
        ui->projectsListView->setModel(mProjectsViewModel);
        connect(ui->projectsListView->selectionModel(),&QItemSelectionModel::selectionChanged,this,&ProjectViewerWindow::makeButtonsEnabled);
    }
}

void ProjectViewerWindow::onNewProjectButtonClicked()
{
    emit newProjectRequested();
}

void ProjectViewerWindow::onOpenProjectButtonClicked()
{
    emit projectOpened("");
}

void ProjectViewerWindow::onRemoveProjectButtonClicked()
{
    emit projectRemoved("");
}

void ProjectViewerWindow::makeButtonsEnabled()
{
    bool isEqualToOne = ui->projectsListView->selectionModel()->selectedIndexes().size() == 1;
    bool isMoreThanZero = ui->projectsListView->selectionModel()->selectedIndexes().size() > 0;

    ui->deleteProjectButton->setEnabled(isMoreThanZero);
    ui->openProjectButton->setEnabled(isEqualToOne);
}
