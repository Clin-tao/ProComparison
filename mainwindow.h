#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "iniconfig.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbn_start_clicked();

    void on_pushButton_clicked();
    //定时器处理函数
    void Timer10sHandle(void);

    void on_ckb_Lock_stateChanged(int arg1);

    void on_pbn_clear_clicked();

    void on_pbn_save_clicked();

private:
    Ui::MainWindow *ui;

    void GetAllFileFolder(QString dirPath, QVector<QString> &folderList);
    QStringList getFileNames(const QString &path);
    QDateTime GetLastmodifiedTime(QString catalog);
    void readConfig(IniConfig *pIniConfig, bool bUpdateVal = true);
    void writeConfig(IniConfig *pIniConfig, bool bForcos = false, bool bUpdateVal= true);
    bool Judge_ShieldFile(QStringList strSheildlist, QString strFileName);

    QString m_StrIniSavePath;
    QString m_StrIniopenPath;
    QString m_StrSrcPath;
    QString m_StrDestPath;
    QString m_StrShield;
    IniConfig *m_pIniConfig;
    QTimer *m_pTimer10s;


};
#endif // MAINWINDOW_H
