#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QIntValidator>
#include <QDate>
#include <QCheckBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_StrIniSavePath(""),m_StrIniopenPath(""),m_StrSrcPath(""),m_StrDestPath(""),m_StrShield(""),
      m_pIniConfig(nullptr),m_pTimer10s(nullptr)
{
    ui->setupUi(this);

    ui->Ledit_src->setEnabled(false);
    ui->Ledit_dest->setEnabled(false);
    ui->ckb_Lock->setCheckState(Qt::Checked);
    ui->ledit_shield->setEnabled(false);

    m_pIniConfig = new IniConfig();
    readConfig(m_pIniConfig);


    m_pTimer10s = new QTimer();
    connect(m_pTimer10s, SIGNAL(timeout()), this, SLOT(Timer10sHandle()));
    m_pTimer10s->start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::Judge_ShieldFile(QStringList strSheildlist, QString strFileName)
{
    bool bSheild = false;
    if(strFileName != "")
    {
        for(int i = 0; i < strSheildlist.size(); i++)
        {
            if(strSheildlist.at(i) != "")
            {
                if(strFileName.contains(strSheildlist.at(i)))//查找包含，子文件也屏蔽
                {
                    bSheild = true;
                    break;
                }
            }
        }
    }
    else
    {
       bSheild = true;
    }

    return bSheild;
}


void MainWindow::on_pbn_start_clicked()
{

    bool bIscopy = false;
    QString strSrc = ui->Ledit_src->text();
    QString strDest = ui->Ledit_dest->text();
    QString strSheild = ui->ledit_shield->text();
    QStringList strSheildlist = strSheild.split(",");
    QVector<QString> vecAllDir;
    int numfile= 0, numdir = 0;

    QStringList strDirList;
    strDirList.clear();



    if((strSrc.isEmpty()) || (strDest.isEmpty()))
    {
        ui->tbo_show->append("源目录或者目标目录为空!!!");
        return;
    }
    QDir dirSrc(strSrc);
    QDir dirDest(strDest);
    if(!dirSrc.exists() || ! dirDest.exists())
    {
        ui->tbo_show->append("源目录或者目标目录不存在!!!");
        return;
    }

    GetAllFileFolder(strSrc, vecAllDir);//递归获取文件夹下所有子文件夹

    QString strtempDir;
    QString strFolder;
    QDir dirtemp;
    int templen = 0;
    if(strSrc.at(strSrc.size() - 1) != "\\")
    {
        templen = 1;
    }
    numdir = vecAllDir.size();
    for(int i = 0; i < numdir; i++)
    {
        strFolder = vecAllDir.at(i).mid(strSrc.size() + templen, vecAllDir.at(i).size());
        if(!Judge_ShieldFile(strSheildlist, strFolder))
        {
            strtempDir = "";
            if(strDest.at(strDest.size() - 1) != "\\")
            {
                strtempDir = strDest + "\\";
            }
            //ui->tbo_show->append(vecAllDir.at(i));
            strtempDir = strtempDir + vecAllDir.at(i).mid(strSrc.size() + templen, vecAllDir.at(i).size());
            //ui->tbo_show->append(strtempDir);
            if(!dirtemp.exists(strtempDir))
            {
                dirtemp.mkdir(strtempDir);
                ui->tbo_show->append("创建的文件夹:" + strtempDir);
            }
        }
    }

    QStringList strFileNameList;
    QDateTime srcDateTime, destDateTime;
    QString strtempDirDest, strtempDirSrc;
    QString strtempFileDest, strtempFileSrc;
    QFile qFiletemp;

    //获取第一目录下所有文件
    strFileNameList = getFileNames(strSrc);
    numfile = strFileNameList.size();
    for(int i = 0; i < numfile; i++)
    {
        if(!Judge_ShieldFile(strSheildlist, strFileNameList.at(i)))
        {
            strtempDirDest = "";
            strtempDirSrc = "";
            strtempFileDest = "";
            strtempFileSrc = "";


            if(strSrc.at(strSrc.size() - 1) != "\\")
            {
                strtempDirSrc = strSrc + "\\";
            }
            strtempFileSrc = strtempDirSrc + strFileNameList.at(i);


            if(strDest.at(strDest.size() - 1) != "\\")
            {
                strtempDirDest = strDest + "\\";
            }
            strtempFileDest = strtempDirDest + strFileNameList.at(i);
            if(!qFiletemp.exists(strtempFileDest))
            {//文件不存在直接复制
                QFile::copy(strtempFileSrc, strtempFileDest);
                ui->tbo_show->append("复制文件:" + strtempFileSrc + "->" + strtempFileDest);
                bIscopy = true;
            }
            else
            {//获取时间进行对比
                srcDateTime = GetLastmodifiedTime(strtempFileSrc);
                destDateTime = GetLastmodifiedTime(strtempFileDest);
                if(srcDateTime != destDateTime)
                {
                   QFile::remove(strtempFileDest);
                   QFile::copy(strtempFileSrc, strtempFileDest);
                   ui->tbo_show->append("复制文件:" + strtempFileSrc + "->" + strtempFileDest);
                   bIscopy = true;
                }
            }
        }
    }

    //获取子目录下所有文件

   for(int j = 0; j < numdir; j++)
   {
       strFileNameList = getFileNames(vecAllDir.at(j));
       numfile = strFileNameList.size();
       for(int i = 0; i < numfile; i++)
       {
           strtempDirDest = "";
           strtempDirSrc = "";
           strtempFileDest = "";
           strtempFileSrc = "";

           strtempDirSrc = vecAllDir.at(j);
           QString strFileName = strtempDirSrc.mid(strSrc.size() + templen, strtempDirSrc.size());

           if(!Judge_ShieldFile(strSheildlist, strFileName))
           {
               if(strDest.at(strDest.size() - 1) != "\\")
               {
                   strtempDirDest = strDest + "\\";
               }
               strtempDirDest = strtempDirDest + strFileName;


               if(strtempDirSrc.at(strtempDirSrc.size() - 1) != "\\")
               {
                   strtempDirSrc = strtempDirSrc + "\\";
               }
               strtempFileSrc = strtempDirSrc + strFileNameList.at(i);


               if(strtempDirDest.at(strtempDirDest.size() - 1) != "\\")
               {
                   strtempDirDest = strtempDirDest + "\\";
               }
               strtempFileDest = strtempDirDest + strFileNameList.at(i);
               if(!qFiletemp.exists(strtempFileDest))
               {//文件不存在直接复制
                   QFile::copy(strtempFileSrc, strtempFileDest);
                   ui->tbo_show->append("复制文件:" + strtempFileSrc + "->" + strtempFileDest);
                   bIscopy = true;
               }
               else
               {//获取时间进行对比
                   srcDateTime = GetLastmodifiedTime(strtempFileSrc);
                   destDateTime = GetLastmodifiedTime(strtempFileDest);
                   if(srcDateTime != destDateTime)
                   {
                      QFile::remove(strtempFileDest);
                      QFile::copy(strtempFileSrc, strtempFileDest);
                      ui->tbo_show->append("复制文件:" + strtempFileSrc + "->" + strtempFileDest);
                      bIscopy = true;
                   }
               }

           }
           }

   }

   QDateTime curDateTime = QDateTime::currentDateTime();
   QString strcurDateTime = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
   if(!bIscopy)
   {
        ui->tbo_show->append(strcurDateTime + "--文件检测已是最新，不需要复制或者修改!");
   }
   else
   {
       ui->tbo_show->append(strcurDateTime + "--完成复制或者修改!");
   }

}

void MainWindow::on_pushButton_clicked()
{
    QString file_name, file_path, FilePath;
    QFileInfo fi;
    bool bUpdate = false;
    if(m_StrIniopenPath == "")
    {
       m_StrIniopenPath = QCoreApplication::applicationDirPath();
    }
    FilePath = QFileDialog::getOpenFileName(this, tr("Open Ini Config"), m_StrIniopenPath, tr("*.ini"));
    if(FilePath != "")
    {
        m_StrIniopenPath = FilePath;
        fi = QFileInfo(m_StrIniopenPath);
        file_name = fi.fileName();
        file_path = fi.absolutePath() + "\\" + file_name;
        if(file_name.compare("config.ini") == 0)
        {
            bUpdate = true;
        }
        IniConfig *pIniFile = new IniConfig(file_path);
        readConfig(pIniFile, bUpdate);
        if(pIniFile != nullptr)
        {
            delete pIniFile;
            pIniFile = nullptr;
        }

        ui->tbo_show->clear();//清除
        ui->tbo_show->append("打开配置文件:" + file_path);


    }
    else
    {
        ui->tbo_show->append("请选中ini文件");
    }

}

//定时器处理函数
void MainWindow::Timer10sHandle(void)
{
    writeConfig(m_pIniConfig);
}

void MainWindow::readConfig(IniConfig *pIniConfig, bool bUpdate)
{
   QString str;
   str = pIniConfig->readConfig("strSrc");
   if(bUpdate)
   {
       m_StrSrcPath = str;
   }

   ui->Ledit_src->setText(str);

   str = pIniConfig->readConfig("strDest");
   if(bUpdate)
   {
       m_StrDestPath = str;
   }

   ui->Ledit_dest->setText(str);

   str = pIniConfig->readConfig("strShield");
   if(bUpdate)
   {
        m_StrShield = str;
   }

   ui->ledit_shield->setText(str);


}

void MainWindow::writeConfig(IniConfig *pIniConfig, bool bForcos, bool bUpdateVal)
{

   QString str;
   str = ui->Ledit_dest->text();
   if((bForcos) || (m_StrDestPath != str))
   {
       if(bUpdateVal)
       {
           m_StrDestPath = str;
       }

       pIniConfig->writeConfig("strDest", str);
   }
   str = ui->Ledit_src->text();
   if((bForcos) || (m_StrSrcPath != str))
   {
       if(bUpdateVal)
       {
           m_StrSrcPath = str;
       }
       pIniConfig->writeConfig("strSrc", str);
   }
   str = ui->ledit_shield->text();
   if((bForcos) || (m_StrShield != str))
   {
       if(bUpdateVal)
       {
           m_StrShield = str;
       }
       pIniConfig->writeConfig("strShield", str);
   }
}

void MainWindow::GetAllFileFolder(QString dirPath, QVector<QString> &folderList)
{
    QDir dir(dirPath);
    dir.setFilter(QDir::Dirs);
    foreach(QFileInfo fullDir, dir.entryInfoList())
    {

        if(fullDir.fileName() == "." || fullDir.fileName() == "..") continue;
        folderList.push_back(fullDir.absoluteFilePath());
        GetAllFileFolder(fullDir.absoluteFilePath(), folderList);
    }
    return ;
}

QStringList MainWindow::getFileNames(const QString &path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}

//获取文件夹里所有文件的最终修改时间
QDateTime MainWindow::GetLastmodifiedTime(QString path)
{
    QDateTime lastModifiedTime(QDate(0, 0, 0));
    QFileInfo Fileinfo(path);
    //该目录下的具体文件的时间
    if(Fileinfo.exists())
    {
        lastModifiedTime = Fileinfo.lastModified().toLocalTime();
    }

    return lastModifiedTime;
}



void MainWindow::on_ckb_Lock_stateChanged(int arg1)
{
    if(ui->ckb_Lock->isChecked())
    {
        ui->Ledit_src->setEnabled(false);
        ui->Ledit_dest->setEnabled(false);
        ui->ledit_shield->setEnabled(false);
    }
    else
    {
        ui->Ledit_src->setEnabled(true);
        ui->Ledit_dest->setEnabled(true);
        ui->ledit_shield->setEnabled(true);
    }
}

void MainWindow::on_pbn_clear_clicked()
{
    ui->tbo_show->clear();
}

void MainWindow::on_pbn_save_clicked()
{
    static QString s_FilePathsrc="";

    QString file_name, file_path, FilePath;
    QFileInfo fi;
    if(m_StrIniSavePath == "")
    {
       m_StrIniSavePath = QCoreApplication::applicationDirPath();
    }

    if(s_FilePathsrc == "")
    {
        s_FilePathsrc = QCoreApplication::applicationDirPath() + +"/config.ini";
    }

    FilePath = QFileDialog::getSaveFileName(this, tr("Save Ini Config"), m_StrIniSavePath, tr("*.ini"));
    if(FilePath != "")
    {
        m_StrIniSavePath = FilePath;
        fi = QFileInfo(m_StrIniSavePath);
        file_name = fi.fileName();
        file_path = fi.absolutePath() + "\\" + file_name;
        if(QFile::exists(file_path))
        {
            //QFile::remove(file_path);
        }
        else
        {
           QFile::copy(s_FilePathsrc, file_path);
        }

        bool bUpdate = false;
        if(s_FilePathsrc.compare(file_path) == 0)
        {
            bUpdate = true;
        }

        ui->tbo_show->append("保存配置文件：" + file_path);
        IniConfig *pIniFile = new IniConfig(file_path);
        writeConfig(pIniFile, true, bUpdate);

        if(pIniFile != nullptr)
        {
            delete pIniFile;
            pIniFile = nullptr;
        }



    }
    else
    {
        ui->tbo_show->append("请输入需要保存的ini文件名");
    }



}
