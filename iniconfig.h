#ifndef INICONFIG_H
#define INICONFIG_H

#include <QObject>
#include <qsettings.h>
class IniConfig : public QObject
{
public:
    IniConfig();
    IniConfig(QString strPath);

    //读配置文件
    QString       readConfig(QString key);
    //写配置文件
    bool       writeConfig(QString key, QString value);

private:

    //配置文件对象
    QSettings  *m_iniConfig;



};

#endif // INICONFIG_H
