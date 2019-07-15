#include <QtTest>
#include <QStandardItemModel>
#include <QSignalSpy>
#include <QPushButton>
#include <QListView>
#include <QKeySequence>

#include "prototypecomponentsnavigatorwindow.h"


class PrototipeViewerWindowTests : public QObject
{
    Q_OBJECT

public:
    PrototipeViewerWindowTests();
    ~PrototipeViewerWindowTests();

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Tests
    void test_openOnePrototipeClicked_signalEmitted();
    void test_openMoreThanOnePrototipe();
    void test_newPrototipeClicked_signalEmitted();
    void test_deleteOnePrototipeClicked_signalEmitted();
    void test_deleteMoreThanOnePrototipe_signalEmitted();

private:
    QStandardItemModel *mModel{nullptr};

};

PrototipeViewerWindowTests::PrototipeViewerWindowTests()
{

}

PrototipeViewerWindowTests::~PrototipeViewerWindowTests()
{

}

void PrototipeViewerWindowTests::initTestCase()
{
    mModel = new QStandardItemModel(this);

    mModel->appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item1"));
    mModel->appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item2"));
    mModel->appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item3"));
}

void PrototipeViewerWindowTests::cleanupTestCase()
{
    delete mModel;
}

void PrototipeViewerWindowTests::test_openOnePrototipeClicked_signalEmitted()
{
    PrototypeComponentsNavigatorWindow w;
    w.setModel(mModel);
    auto pushButtonLoadSelectedComponents = w.findChild<QPushButton *>("pushButtonLoadSelectedComponents");
    QVERIFY2(pushButtonLoadSelectedComponents, "pushButtonLoadSelectedComponents not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(componentOpened(QString)));
    QTest::mouseClick(pushButtonLoadSelectedComponents, Qt::LeftButton);
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
                QTest::mouseClick(pushButtonLoadSelectedComponents, Qt::LeftButton);
                QTest::qWait(1000);
                QCOMPARE(spy.count(), 1);
                spy.clear();
            }
        }

    }
}

void PrototipeViewerWindowTests::test_openMoreThanOnePrototipe()
{
    PrototypeComponentsNavigatorWindow w;
    w.setModel(mModel);
    auto pushButtonLoadSelectedComponents = w.findChild<QPushButton *>("pushButtonLoadSelectedComponents");
    QVERIFY2(pushButtonLoadSelectedComponents, "pushButtonLoadSelectedComponents not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(componentOpened(QString)));
    QTest::mouseClick(pushButtonLoadSelectedComponents, Qt::LeftButton);
    QCOMPARE(spy.count(), 0);

    QListView *listView = w.findChild<QListView *>();
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
                QTest::mouseClick(pushButtonLoadSelectedComponents, Qt::LeftButton);
                int compare = (itemsCount == 1) ? 1 : 0;
                QCOMPARE(spy.count(), compare);
                QTest::qWait(500);
                spy.clear();
            }
        }

    }
}

void PrototipeViewerWindowTests::test_newPrototipeClicked_signalEmitted()
{
    PrototypeComponentsNavigatorWindow w;
    w.setModel(mModel);
    auto pushButtonAddComponentsToPrototipe = w.findChild<QPushButton *>("pushButtonAddComponentsToPrototipe");
    QVERIFY2(pushButtonAddComponentsToPrototipe, "pushButtonAddComponentsToPrototipe not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(newComponentRequested()));
    QTest::mouseClick(pushButtonAddComponentsToPrototipe, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);
}

void PrototipeViewerWindowTests::test_deleteOnePrototipeClicked_signalEmitted()
{
    PrototypeComponentsNavigatorWindow w;
    w.setModel(mModel);
    auto pushButtonDeleteSelectedComponent = w.findChild<QPushButton *>("pushButtonDeleteSelectedComponent");
    QVERIFY2(pushButtonDeleteSelectedComponent, "pushButtonDeleteSelectedComponent not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(componentRemoved(QString)));
    QTest::mouseClick(pushButtonDeleteSelectedComponent, Qt::LeftButton);
    QCOMPARE(spy.count(), 0);

    QListView *listView = w.findChild<QListView *>();
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

                QTest::mouseClick(pushButtonDeleteSelectedComponent, Qt::LeftButton);
                QCOMPARE(spy.count(), 1);
                QTest::qWait(500);
                spy.clear();
            }
        }

    }
}

void PrototipeViewerWindowTests::test_deleteMoreThanOnePrototipe_signalEmitted()
{
    PrototypeComponentsNavigatorWindow w;
    w.setModel(mModel);
    auto pushButtonDeleteSelectedComponent = w.findChild<QPushButton *>("pushButtonDeleteSelectedComponent");
    QVERIFY2(pushButtonDeleteSelectedComponent, "pushButtonDeleteSelectedComponent not found");

    w.show();
    QSignalSpy spy(&w, SIGNAL(componentRemoved(QString)));
    QTest::mouseClick(pushButtonDeleteSelectedComponent, Qt::LeftButton);
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
                QTest::mouseClick(pushButtonDeleteSelectedComponent, Qt::LeftButton);
                QCOMPARE(spy.count(), 1);
                QTest::qWait(500);
                spy.clear();
            }
        }

    }
}

QTEST_MAIN(PrototipeViewerWindowTests)

#include "testprototypecomponentsnavigatorwindow.moc"
