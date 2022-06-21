#include <QtTest>
#include "appsettings.h"
// add necessary includes here

class Settings : public QObject
{
Q_OBJECT

public:
    Settings();
    ~Settings();

private slots:
    void test_case1();

};

Settings::Settings()
{

}

Settings::~Settings()
{

}

void Settings::test_case1()
{
    QString path=qApp->applicationDirPath(),
               settingsPath;

       settingsPath=path + "/settings.json";
       AppSettings settings(settingsPath.toStdString());
       QCOMPARE(settings.getFilePath(), "/settings.json");
}

QTEST_APPLESS_MAIN( Settings )

#include "tst_settings.moc"
