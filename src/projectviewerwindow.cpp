#include "projectviewerwindow.h"
#include "ui_projectviewerwindow.h"

ProjectViewerWindow::ProjectViewerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectViewerWindow)
{
    ui->setupUi(this);
}

ProjectViewerWindow::~ProjectViewerWindow()
{
    delete ui;
}
