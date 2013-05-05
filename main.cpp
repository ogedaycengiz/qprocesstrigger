#include <QCoreApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess process;
    QString shPath = "/home/linaro/agrcv/respawn.sh";
    while (process.execute(QString("sh %1").arg(shPath)) != QProcess::Running);
    return a.exec();
}
