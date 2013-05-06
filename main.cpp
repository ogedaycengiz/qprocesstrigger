#include <QCoreApplication>
#include <QProcess>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

static string getSdCardCid();
static string getSdCardSerial();
static string getOEMID();

const char *CID = {"744a455344432020102402247f00cc00"};
const char *SERIAL = {"0x2402247f"};
const char *OEM_ID = {"0x4a45"};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess process;
    QString shPath = "/home/linaro/respawn.sh";

    bool cidOk = false;
    bool serialOk = false;
    bool oemOk = false;
    if (getSdCardCid().compare(0, getSdCardCid().length(), CID) == 0)
        cidOk = true;
    else
        cidOk = false;

    if (getSdCardSerial().compare(0, getSdCardSerial().length(), SERIAL) == 0)
        serialOk = true;
    else
        serialOk = false;

    if (getOEMID().compare(0, getOEMID().length(), OEM_ID) == 0)
        oemOk = true;
    else
        oemOk = false;

    if (cidOk)
        process.execute(QString("sh %1").arg(shPath));
    return a.exec();
}


#define SD_CARD_CID "/sys/block/mmcblk0/device/cid"
#define SD_CARD_SERIAL "/sys/block/mmcblk0/device/serial"
#define SD_CARD_OEM_ID "/sys/block/mmcblk0/device/oemid"


static string getSdCardCid()
{
    string cid;
    ifstream file;
    file.open(SD_CARD_CID);
    file >> cid;
    file.close();
    return cid;
}

static string getSdCardSerial()
{
    string serial;
    ifstream file;
    file.open(SD_CARD_SERIAL);
    file >> serial;
    file.close();
    return serial;
}

static string getOEMID()
{
    string oemid;
    ifstream file;
    file.open(SD_CARD_OEM_ID);
    file.open(SD_CARD_OEM_ID);
    file >> oemid;
    file.close();
    return oemid;
}
