#ifndef DIALOGDBCONNECTION_H
#define DIALOGDBCONNECTION_H

#include <QDialog>


#include "cdtdialogs_global.h"
namespace Ui {
class DialogDBConnection;
}

class CDTDIALOGS_EXPORT CDTDatabaseConnInfo
{
public:
    QString dbType;
    QString dbName;
    QString username;
    QString password;
    QString hostName;
    int port;

    bool operator==(const CDTDatabaseConnInfo& rhs) const;
    bool isNull();
};
QDataStream CDTDIALOGS_EXPORT &operator<<(QDataStream &out, const CDTDatabaseConnInfo &dbInfo);
QDataStream CDTDIALOGS_EXPORT &operator>>(QDataStream &in, CDTDatabaseConnInfo &dbInfo);

class CDTDIALOGS_EXPORT DialogDBConnection : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDBConnection(CDTDatabaseConnInfo dbInfo = CDTDatabaseConnInfo(),QWidget *parent = 0);
    ~DialogDBConnection();

    CDTDatabaseConnInfo dbConnectInfo();

private slots:
    void on_toolButton_clicked();
    void on_comboDriver_currentIndexChanged(const QString &arg1);
    void on_pushButtonTest_clicked();

private:
    void initialize();
    void updateConnInfo();

private:
    Ui::DialogDBConnection *ui;
    CDTDatabaseConnInfo dbConnInfo;
};

#endif // DIALOGDBCONNECTION_H