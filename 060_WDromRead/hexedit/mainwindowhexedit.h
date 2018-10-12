#ifndef MAINWINDOWHEXEDIT_H
#define MAINWINDOWHEXEDIT_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QStatusBar>
#include <QLabel>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QColorDialog>
#include <QFontDialog>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QInputDialog>

#include "qhexedit.h"

QT_BEGIN_NAMESPACE
class QtAwesome;
class OptionsDialog;
class SearchDialog;
QT_END_NAMESPACE

class MainWindowHexEdit : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowHexEdit(QWidget *parent = 0);
    void setData(QByteArray const &data, QHexCaller const &caller = QHexCaller());
    QByteArray data();
    void setSourceObjectNumber(int objNum);
    int sourceObjectNumber() const;
    void setAlgorithmNumber(int algo);
    int algorithmNumber() const;

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

signals:
    void navigationChanged(const DATASOURCE datasource, const qint64 currentObj);
    void SaveDataToHdd(const DATASOURCE datasource,const qint64 currentObj);
    void ReloadHexEdit(const DATASOURCE datasource,const qint64 currentObj);

private slots:
    void dataChanged();
    void open();
    void optionsAccepted();
    void findNext();
    bool save();
    bool saveAs();
    void saveSelectionToReadableFile();
    void saveToReadableFile();
    void setAddress(qint64 address);
    void setOverwriteMode(bool mode);
    void setSize(qint64 size);
    void showOptionsDialog();
    void showSearchDialog();
    void slotHome();
    void slotBack();
    void slotSelect();
    void slotNext();
    void slotEnd();
    void slotSaveToHdd();
    void slotReload();
    void slotCheckSumShow();
    void slotChangeCheckSum();

private:
    void init();
    void createActions();
    void createMenus();
    void createStatusBar();
    void createToolBars();
    void loadFile(const QString &fileName);
    void readSettings();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QString curFile;
    QFile file;
    bool isUntitled;
    
    QMenu *fileMenu;
    QMenu *editMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QToolBar *homeToolBar;
    QToolBar *CheckToolBar;

    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *saveReadable;
    QAction *closeAct;
    QAction *exitAct;

    QAction *undoAct;
    QAction *redoAct;
    QAction *saveSelectionReadable;

    QAction *optionsAct;
    QAction *findAct;
    QAction *findNextAct;

    QtAwesome *awesome;
    QHexEdit *hexEdit;
    OptionsDialog *optionsDialog;
    SearchDialog *searchDialog;
    QLabel *lbAddress, *lbAddressName;
    QLabel *lbOverwriteMode, *lbOverwriteModeName;
    QLabel *lbSize, *lbSizeName;
    QLabel *lbCurrent,*lbCurrentName;

    QAction *homeAction;
    QAction *backAction;
    QAction *selectAction;
    QAction *nextAction;
    QAction *endAction;
    QAction *SaveToHDD;

    QAction *CheckSumAction;
    QAction *CheckCheckSumAction;

    QAction *ReloadAction;
    QHexCaller hexCaller;
};

#endif
