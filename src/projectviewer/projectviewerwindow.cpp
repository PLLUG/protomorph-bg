#include "projectviewerwindow.h"
#include "ui_projectviewerwindow.h"


ProjectViewerWindow::ProjectViewerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectViewerWindow)
{
    ui->setupUi(this);

    ui->projectsListView->setViewMode(QListView::ViewMode::IconMode);
    ui->projectsListView->setIconSize(QSize(100,100));
    ui->projectsListView->setUniformItemSizes(true);

    connect(ui->newProjectButton, &QPushButton::clicked, this, &ProjectViewerWindow::onNewProjectButtonClicked);
    connect(ui->openProjectButton, &QPushButton::clicked, this, &ProjectViewerWindow::onOpenProjectButtonClicked);
    connect(ui->deleteProjectButton, &QPushButton::clicked, this, &ProjectViewerWindow::onRemoveProjectButtonClicked);

}

ProjectViewerWindow::~ProjectViewerWindow()
{
    delete ui;
}

void ProjectViewerWindow::setModel(QAbstractItemModel *model)
{
    if(model)
    {
        ui->projectsListView->setModel(model);
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
    bool isOnlyOneProjectSelected = ui->projectsListView->selectionModel()->selectedIndexes().size() == 1;
    bool isAnyProjectsSelected = ui->projectsListView->selectionModel()->selectedIndexes().size() > 0;

    ui->deleteProjectButton->setEnabled(isAnyProjectsSelected);
    ui->openProjectButton->setEnabled(isOnlyOneProjectSelected);
}
