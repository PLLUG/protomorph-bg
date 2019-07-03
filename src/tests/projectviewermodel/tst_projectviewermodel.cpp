#include <QtTest>
#include <QAbstractItemModelTester>
#include "recentprojectsmodel.h"

class ViewerModelTests: public QObject
{
    Q_OBJECT
private slots:
    void test();
};

void ViewerModelTests::test()
{

    RecentProject pr1("/home/game1");
    RecentProject pr2("/home/igor/bla/blabla/game2");
    RecentProject pr3("/home/igor/Documents/game3");

    QVector<RecentProject> projects{pr1,pr2,pr3};

    ProgramSettings settings{projects};

    RecentProjectsModel model(settings);

    QAbstractItemModelTester tester(&model,QAbstractItemModelTester::FailureReportingMode::QtTest,this);

}


QTEST_MAIN(ViewerModelTests)
#include "tst_projectviewermodel.moc"
