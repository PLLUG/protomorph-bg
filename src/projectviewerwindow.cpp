#include "projectviewerwindow.h"
#include "ui_projectviewerwindow.h"

#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <QStringListModel>
#include <QItemSelection>
#include <QItemSelectionModel>



ProjectViewerWindow::ProjectViewerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectViewerWindow)
{
    ui->setupUi(this);

    ui->projectsListView->setViewMode(QListView::ViewMode::IconMode);

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
        mSelectionModel = ui->projectsListView->selectionModel();
        qDebug()<<mSelectionModel->currentIndex();
        qDebug()<<"OK";
        connect(mSelectionModel,&QItemSelectionModel::selectionChanged,this,&ProjectViewerWindow::getSelection);
    }
}

void ProjectViewerWindow::onNewProjectButtonClicked()
{
    emit newProjectRequested();
    qDebug()<<"new project button clicked";
}

void ProjectViewerWindow::onOpenProjectButtonClicked()
{
    emit projectOpened("");
}

void ProjectViewerWindow::onRemoveProjectButtonClicked()
{
    emit projectRemoved("");
}

void ProjectViewerWindow::makeRemoveActive()
{
    qDebug()<<mSelectionModel->currentIndex();
}

void ProjectViewerWindow::getSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    for(auto temp : selected)
    {
        qDebug()<<temp;
    }

    for(auto temp : deselected)
    {
        qDebug()<<temp;
    }
}
