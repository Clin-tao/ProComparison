#include "iniconfig.h"
#include <qcoreapplication.h>

IniConfig::IniConfig()
{
    QString Path = QCoreApplication::applicationDirPath()+"/config.ini";
    m_iniConfig = new QSettings(Path ,QSettings::IniFormat);
//    m_iniConfig = new QSettings("D:\\GPSSimulate\\config.ini",QSettings::IniFormat);
    m_iniConfig->setIniCodec("UTF-8");
}

IniConfig::IniConfig(QString strPath)
{
    m_iniConfig = new QSettings(strPath ,QSettings::IniFormat);
//    m_iniConfig = new QSettings("D:\\GPSSimulate\\config.ini",QSettings::IniFormat);
    m_iniConfig->setIniCodec("UTF-8");
}


QString IniConfig::readConfig(QString key)
{
    if(m_iniConfig != nullptr)
    {
        return m_iniConfig->value(key).toString();
    }
    else
    {
        return "";
    }
}

bool IniConfig::writeConfig(QString key, QString value)
{
    if(m_iniConfig != nullptr)
    {
        m_iniConfig->setValue(key, value);
        return true;
    }
    else
    {

    }

    return false;
}
