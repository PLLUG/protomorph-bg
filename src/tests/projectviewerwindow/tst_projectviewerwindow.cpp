#include <QtTest>

#include "projectviewerwindow.h"

#include <QStandardItemModel>
#include <QSignalSpy>
#include <QPushButton>
#include <QListView>
#include <QKeySequence>

class ProjectViewerWindowTests : public QObject
{
    Q_OBJECT

public:
    ProjectViewerWindowTests();
    ~ProjectViewerWindowTests();

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Tests
    void test_openOneProjectClicked_signalEmitted();
    void test_openMoreThanOneProject();

    void test_newProjectClicked_signalEmitted();

    void test_deleteOneProjectClicked_signalEmitted();
    void test_deleteMoreThanOneProject_signalEmitted();

private:
    QStandardItemModel *mTestModel{nullptr};

};

ProjectViewerWindowTests::ProjectViewerWindowTests()
{

}

ProjectViewerWindowTests::~ProjectViewerWindowTests()
{

}

void ProjectViewerWindowTests::initTestCase()
{
    mTestModel = new QStandardItemModel(this);

    mTestModel->appendRow(new QStandardItem(QIcon(":/projectviewer/images/projecticon"), "path1"));
    mTestModel->appendRow(new QStandardItem(QIcon(":/projectviewer/images/projecticon"), "looooooooong path"));
    mTestModel->appendRow(new QStandardItem(QIcon(":/projectviewer/images/projecticon"), "path3"));
}

void ProjectViewerWindowTests::cleanupTestCase()
{
    delete mTestModel;
}

void ProjectViewerWindowTests::test_openOneProjectClicked_signalEmitted()
{
    ProjectViewerWindow w;
    w.setModel(mTestModel);
    auto openProjectButton = w.findChild<QPushButton *>("openProjectButton");
    QVERIFY2(openProjectButton, "openProjectButton not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(projectOpened(QString)));
    QTest::mouseClick(openProjectButton, Qt::LeftButton);
    QCOMPARE(spy.count(), 0);
    QListView * listView = w.findChild<QListView *>();
    if(listView)
    {
        for(int r = 0; r < listView->model()->rowCount(); r++)
        {
            QModelIndex idx = listView->model()->index(r,0);
            listView->scrollTo(idx);
            QPoint itemPt = listView->visualRect(idx).center();

            if(!itemPt.isNull())
            {
                QTest::mouseClick(listView->viewport(), Qt::LeftButton, nullptr, itemPt);
                QTest::mouseClick(openProjectButton, Qt::LeftButton);
                QTest::qWait(500);
                QCOMPARE(spy.count(), 1);
                spy.clear();
            }
        }

    }
}

void ProjectViewerWindowTests::test_openMoreThanOneProject()
{
    ProjectViewerWindow w;
    w.setModel(mTestModel);
    auto openProjectButton = w.findChild<QPushButton *>("openProjectButton");
    QVERIFY2(openProjectButton, "openProjectButton not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(projectOpened(QString)));
    QTest::mouseClick(openProjectButton, Qt::LeftButton);
    QCOMPARE(spy.count(), 0);

    QListView * listView = w.findChild<QListView *>();
    if(listView)
    {
        int itemsCount{0};
        for(int r = 0; r < listView->model()->rowCount(); r++)
        {
            itemsCount++;
            QModelIndex idx = listView->model()->index(r,0);
            listView->scrollTo(idx);
            QPoint itemPt = listView->visualRect(idx).center();
            if(!itemPt.isNull())
            {
                QTest::mouseClick(listView->viewport(), Qt::LeftButton, Qt::ControlModifier, itemPt);
                QTest::mouseClick(openProjectButton, Qt::LeftButton);
                int compare = (itemsCount == 1) ? 1 : 0;
                QCOMPARE(spy.count(), compare);
                QTest::qWait(500);
                spy.clear();
            }
        }

    }
}

void ProjectViewerWindowTests::test_newProjectClicked_signalEmitted()
{
    ProjectViewerWindow w;
    w.setModel(mTestModel);
    auto newProjectButton = w.findChild<QPushButton *>("newProjectButton");
    QVERIFY2(newProjectButton, "newProjectButton not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(newProjectRequested()));
    QTest::mouseClick(newProjectButton, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);
}

void ProjectViewerWindowTests::test_deleteOneProjectClicked_signalEmitted()
{
    ProjectViewerWindow w;
    w.setModel(mTestModel);
    auto deleteProjectButton = w.findChild<QPushButton *>("deleteProjectButton");
    QVERIFY2(deleteProjectButton, "deleteProjectButton not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(projectRemoved(QString)));
    QTest::mouseClick(deleteProjectButton, Qt::LeftButton);
    QCOMPARE(spy.count(), 0);

    QListView * listView = w.findChild<QListView *>();
    if(listView)
    {
        for(int r = 0; r < listView->model()->rowCount(); r++)
        {
            QModelIndex idx = listView->model()->index(r,0);
            listView->scrollTo(idx);
            QPoint itemPt = listView->visualRect(idx).center();

            if(!itemPt.isNull())
            {
                QTest::mouseClick(listView->viewport(), Qt::LeftButton, nullptr, itemPt);

                QTest::mouseClick(deleteProjectButton, Qt::LeftButton);
                QCOMPARE(spy.count(), 1);
                 QTest::qWait(500);
                spy.clear();
            }
        }

    }
}

void ProjectViewerWindowTests::test_deleteMoreThanOneProject_signalEmitted()
{
    ProjectViewerWindow w;
    w.setModel(mTestModel);
    auto deleteProjectButton = w.findChild<QPushButton *>("deleteProjectButton");
    QVERIFY2(deleteProjectButton, "deleteProjectButton not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(projectRemoved(QString)));
    QTest::mouseClick(deleteProjectButton, Qt::LeftButton);
    QCOMPARE(spy.count(), 0);

    QListView * listView = w.findChild<QListView *>();
    if(listView)
    {
        int itemsCount{0};
        for(int r = 0; r < listView->model()->rowCount(); r++)
        {
            itemsCount++;
            QModelIndex idx = listView->model()->index(r,0);
            listView->scrollTo(idx);
            QPoint itemPt = listView->visualRect(idx).center();
            QString str = listView->model()->index(r,0).data( Qt::DisplayRole ).toString();

            if(!itemPt.isNull())
            {
                QTest::mouseClick(listView->viewport(), Qt::LeftButton, Qt::ControlModifier, itemPt);
                QTest::mouseClick(deleteProjectButton, Qt::LeftButton);
                QCOMPARE(spy.count(), 1);
                QTest::qWait(500);
                spy.clear();
            }
        }

    }
}

QTEST_MAIN(ProjectViewerWindowTests)

#include "tst_projectviewerwindow.moc"
