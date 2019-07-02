#include <QtTest>
#include <QAbstractItemModelTester>
#include "recentprojectsmodel.h"

class TestViewerModel: public QObject
{
    Q_OBJECT
private slots:
    void test();
};

void TestViewerModel::test()
{

    RecentProject pr1("/home/game1");
    RecentProject pr2("/home/igor/bla/blabla/game2");
    RecentProject pr3("/home/igor/Documents/game3");

    QVector<RecentProject> projects{pr1,pr2,pr3};

    ProgramSettings settings{projects};

    auto model = new RecentProjectsModel(settings);

    auto tester = new QAbstractItemModelTester(model,QAbstractItemModelTester::FailureReportingMode::QtTest,this);

}


QTEST_MAIN(TestViewerModel)
#include "tst_projectviewermodel.moc"
