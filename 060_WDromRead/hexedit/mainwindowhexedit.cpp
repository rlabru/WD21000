#include "mainwindowhexedit.h"

#include "QtAwesome.h"
#include "optionsdialog.h"
#include "searchdialog.h"
#include "dialogshowmodulechecksum.h"
#include "rlab.h"

/*****************************************************************************/
/* Public methods */
/*****************************************************************************/
MainWindowHexEdit::MainWindowHexEdit(QWidget *parent):
    QMainWindow(parent)
{
    setAcceptDrops( true );
    init();
    setCurrentFile("");
    this->statusBar()->setSizeGripEnabled(false);
}

/*****************************************************************************/
/* Protected methods */
/*****************************************************************************/

void MainWindowHexEdit::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        event->accept();
        QList<QUrl> urls = event->mimeData()->urls();
        QString str = urls.at(0).toLocalFile();
        statusBar()->showMessage( tr("Drop File: ") + str, 2000);
    }
}

void MainWindowHexEdit::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        QList<QUrl> urls = event->mimeData()->urls();
        QString str = urls.at(0).toLocalFile();
        loadFile(str);
        event->accept();
    }
}

/*****************************************************************************/
/* Private Slots */
/*****************************************************************************/

void MainWindowHexEdit::dataChanged()
{
    setWindowModified(hexEdit->isModified());
}

void MainWindowHexEdit::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,"OPEN",hexCaller.profilePathMisc);
    if (!fileName.isEmpty()) {
        loadFile(fileName);
    }
}

void MainWindowHexEdit::optionsAccepted()
{
    readSettings();
}

void MainWindowHexEdit::findNext()
{
    searchDialog->findNext();
}

bool MainWindowHexEdit::save()
{
    return saveAs();
//    if (isUntitled) {
//        return saveAs();
//    } else {
//        return saveFile(curFile);
//    }
}

bool MainWindowHexEdit::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    hexCaller.profilePathMisc);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void MainWindowHexEdit::saveSelectionToReadableFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save To Readable File"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("QHexEdit"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }

        QApplication::setOverrideCursor(Qt::WaitCursor);
        file.write(hexEdit->selectionToReadableString().toLatin1());
        QApplication::restoreOverrideCursor();

        statusBar()->showMessage(tr("File saved"), 2000);
    }
}

void MainWindowHexEdit::saveToReadableFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save To Readable File"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("QHexEdit"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }

        QApplication::setOverrideCursor(Qt::WaitCursor);
        file.write(hexEdit->toReadableString().toLatin1());
        QApplication::restoreOverrideCursor();

        statusBar()->showMessage(tr("File saved"), 2000);
    }
}

void MainWindowHexEdit::setAddress(qint64 address)
{
    lbAddress->setText(QString("%1").arg(address, 1, 16));
}

void MainWindowHexEdit::setOverwriteMode(bool mode)
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    settings.setValue("OverwriteMode", mode);
    if (mode)
        lbOverwriteMode->setText(tr("Overwrite"));
    else
        lbOverwriteMode->setText(tr("Insert"));
}

void MainWindowHexEdit::setSize(qint64 size)
{
    lbSize->setText(QString("%1").arg(size));
}

void MainWindowHexEdit::showOptionsDialog()
{
    optionsDialog->show();
}

void MainWindowHexEdit::showSearchDialog()
{
    searchDialog->show();
}

void MainWindowHexEdit::slotHome()
{
    emit navigationChanged(hexCaller.datasource, hexCaller.startObj);
}

void MainWindowHexEdit::slotBack()
{
    emit navigationChanged(hexCaller.datasource, (hexCaller.currentObj==hexCaller.startObj)?hexCaller.startObj:hexCaller.currentObj-1 );
}

void MainWindowHexEdit::slotSelect()
{
    // dialog ask a value, use dec/hex view
    bool ok;
    quint64 num=QInputDialog::getInt(this,tr("InputDialog"),tr("Please put a value"),0,0,2147483647,1,&ok);
    if(ok) {
        hexCaller.currentObj=num;
        emit navigationChanged(hexCaller.datasource, hexCaller.currentObj);
    }
}

void MainWindowHexEdit::slotNext()
{
    emit navigationChanged(hexCaller.datasource, (hexCaller.currentObj==hexCaller.endObj)?hexCaller.endObj:hexCaller.currentObj+1 );
}

void MainWindowHexEdit::slotEnd()
{
    emit navigationChanged(hexCaller.datasource, hexCaller.endObj);
}

/*****************************************************************************/
/* Private Methods */
/*****************************************************************************/
void MainWindowHexEdit::init()
{
    setAttribute(Qt::WA_DeleteOnClose);
    optionsDialog = new OptionsDialog(this);
    connect(optionsDialog, SIGNAL(accepted()), this, SLOT(optionsAccepted()));
    isUntitled = true;

    hexEdit = new QHexEdit;
    setCentralWidget(hexEdit);
    connect(hexEdit, SIGNAL(overwriteModeChanged(bool)), this, SLOT(setOverwriteMode(bool)));
    connect(hexEdit, SIGNAL(dataChanged()), this, SLOT(dataChanged()));
    searchDialog = new SearchDialog(hexEdit, this);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    readSettings();

    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindowHexEdit::createActions()
{
    awesome = new QtAwesome(this);
    awesome->initFontAwesome();
    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    saveReadable = new QAction(tr("Save &Readable..."), this);
    saveReadable->setStatusTip(tr("Save document in readable form"));
    connect(saveReadable, SIGNAL(triggered()), this, SLOT(saveToReadableFile()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    undoAct = new QAction(QIcon(":/images/undo.png"), tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    connect(undoAct, SIGNAL(triggered()), hexEdit, SLOT(undo()));

    redoAct = new QAction(QIcon(":/images/redo.png"), tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    connect(redoAct, SIGNAL(triggered()), hexEdit, SLOT(redo()));

    saveSelectionReadable = new QAction(tr("&Save Selection Readable..."), this);
    saveSelectionReadable->setStatusTip(tr("Save selection in readable form"));
    connect(saveSelectionReadable, SIGNAL(triggered()), this, SLOT(saveSelectionToReadableFile()));

    findAct = new QAction(QIcon(":/images/find.png"), tr("&Find/Replace"), this);
    findAct->setShortcuts(QKeySequence::Find);
    findAct->setStatusTip(tr("Show the Dialog for finding and replacing"));
    connect(findAct, SIGNAL(triggered()), this, SLOT(showSearchDialog()));

    findNextAct = new QAction(tr("Find &next"), this);
    findNextAct->setShortcuts(QKeySequence::FindNext);
    findNextAct->setStatusTip(tr("Find next occurrence of the searched pattern"));
    connect(findNextAct, SIGNAL(triggered()), this, SLOT(findNext()));

    optionsAct = new QAction(tr("&Options"), this);
    optionsAct->setStatusTip(tr("Show the Dialog to select applications options"));
    connect(optionsAct, SIGNAL(triggered()), this, SLOT(showOptionsDialog()));

    homeAction = new QAction(awesome->icon(fa::stepbackward), tr("home"),this);
    connect(homeAction, SIGNAL(triggered()), this, SLOT(slotHome()));

    backAction = new QAction(awesome->icon(fa::backward), tr("backward"),this);
    connect(backAction, SIGNAL(triggered()), this, SLOT(slotBack()));

    selectAction = new QAction(awesome->icon(fa::th), tr("select"),this);
    connect(selectAction, SIGNAL(triggered()), this, SLOT(slotSelect()));

    nextAction = new QAction(awesome->icon(fa::forward), tr("forward"),this);
    connect(nextAction, SIGNAL(triggered()), this, SLOT(slotNext()));

    endAction = new QAction(awesome->icon(fa::stepforward), tr("end"),this);
    connect(endAction, SIGNAL(triggered()), this, SLOT(slotEnd()));

    ReloadAction = new QAction(awesome->icon(fa::refresh), tr("Reload"),this);
    connect(ReloadAction, SIGNAL(triggered()), this, SLOT(slotReload()));

    SaveToHDD = new QAction(awesome->icon(fa::pencilsquare), tr("SaveToHdd"),this);
    connect(SaveToHDD, SIGNAL(triggered()), this, SLOT(slotSaveToHdd()));

    CheckSumAction = new QAction(awesome->icon(fa::checkcircleo), tr("CheckSumView"),this);
    connect(CheckSumAction, SIGNAL(triggered()), this, SLOT(slotCheckSumShow()));

    CheckCheckSumAction = new QAction(awesome->icon(fa::check), tr("ChangeCheckSum"),this);
    connect(CheckCheckSumAction, SIGNAL(triggered()), this, SLOT(slotChangeCheckSum()));

    homeAction->setDisabled(true);
    backAction->setDisabled(true);
    selectAction->setDisabled(true);
    nextAction->setDisabled(true);
    endAction->setDisabled(true);
    CheckSumAction->setDisabled(true);
    CheckCheckSumAction->setDisabled(true);
}

void MainWindowHexEdit::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(saveReadable);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addAction(saveSelectionReadable);
    editMenu->addSeparator();
    editMenu->addAction(findAct);
    editMenu->addAction(findNextAct);
    editMenu->addSeparator();
    editMenu->addAction(optionsAct);
}

void MainWindowHexEdit::createStatusBar()
{
    //Current
    lbCurrentName = new QLabel(this);
    statusBar()->addPermanentWidget(lbCurrentName);
    lbCurrent = new QLabel(this);
    lbCurrent->setFrameShape(QFrame::Panel);
    lbCurrent->setFrameShadow(QFrame::Sunken);
    lbCurrent->setMinimumWidth(70);
    statusBar()->addPermanentWidget(lbCurrent);

    // Address Label
    lbAddressName = new QLabel();
    lbAddressName->setText(tr("Address:"));
    statusBar()->addPermanentWidget(lbAddressName);
    lbAddress = new QLabel();
    lbAddress->setFrameShape(QFrame::Panel);
    lbAddress->setFrameShadow(QFrame::Sunken);
    lbAddress->setMinimumWidth(70);
    statusBar()->addPermanentWidget(lbAddress);
    connect(hexEdit, SIGNAL(currentAddressChanged(qint64)), this, SLOT(setAddress(qint64)));

    // Size Label
    lbSizeName = new QLabel();
    lbSizeName->setText(tr("Size:"));
    statusBar()->addPermanentWidget(lbSizeName);
    lbSize = new QLabel();
    lbSize->setFrameShape(QFrame::Panel);
    lbSize->setFrameShadow(QFrame::Sunken);
    lbSize->setMinimumWidth(70);
    statusBar()->addPermanentWidget(lbSize);
    connect(hexEdit, SIGNAL(currentSizeChanged(qint64)), this, SLOT(setSize(qint64)));

    // Overwrite Mode Label
    lbOverwriteModeName = new QLabel();
    lbOverwriteModeName->setText(tr("Mode:"));
    statusBar()->addPermanentWidget(lbOverwriteModeName);
    lbOverwriteMode = new QLabel();
    lbOverwriteMode->setFrameShape(QFrame::Panel);
    lbOverwriteMode->setFrameShadow(QFrame::Sunken);
    lbOverwriteMode->setMinimumWidth(70);
    statusBar()->addPermanentWidget(lbOverwriteMode);
    setOverwriteMode(hexEdit->overwriteMode());

    statusBar()->showMessage(tr("Ready"), 2000);
}

void MainWindowHexEdit::createToolBars()
{
    homeToolBar = addToolBar(tr("home"));
    homeToolBar->addAction(homeAction);
    homeToolBar->addAction(backAction);
    homeToolBar->addAction(selectAction);
    homeToolBar->addAction(nextAction);
    homeToolBar->addAction(endAction);
    homeToolBar->addAction(SaveToHDD);
    homeToolBar->addAction(ReloadAction);

    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(undoAct);
    editToolBar->addAction(redoAct);
    editToolBar->addAction(findAct);

    CheckToolBar = addToolBar(tr("Check"));
    CheckToolBar->addAction(CheckSumAction);
    CheckToolBar->addAction(CheckCheckSumAction);
}

void MainWindowHexEdit::loadFile(const QString &fileName)
{
    file.setFileName(fileName);
    if (!hexEdit->setData(file)) {
        QMessageBox::warning(this, tr("QHexEdit"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

void MainWindowHexEdit::readSettings()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    hexEdit->setAddressArea(settings.value("AddressArea").toBool());
    hexEdit->setAsciiArea(settings.value("AsciiArea").toBool());
    hexEdit->setHighlighting(settings.value("Highlighting").toBool());
    hexEdit->setOverwriteMode(settings.value("OverwriteMode").toBool());
    hexEdit->setReadOnly(settings.value("ReadOnly").toBool());

    hexEdit->setHighlightingColor(settings.value("HighlightingColor").value<QColor>());
    hexEdit->setAddressAreaColor(settings.value("AddressAreaColor").value<QColor>());
    hexEdit->setSelectionColor(settings.value("SelectionColor").value<QColor>());
    hexEdit->setFont(settings.value("WidgetFont").value<QFont>());

    hexEdit->setAddressWidth(settings.value("AddressAreaWidth").toInt());
}

bool MainWindowHexEdit::saveFile(const QString &fileName)
{
    QString tmpFileName = fileName + ".~tmp";

    QApplication::setOverrideCursor(Qt::WaitCursor);
    QFile file(tmpFileName);
    bool ok = hexEdit->write(file);
    if (QFile::exists(fileName))
        ok = QFile::remove(fileName);
    if (ok)
    {
        file.setFileName(tmpFileName);
        ok = file.copy(fileName);
        if (ok)
            ok = QFile::remove(tmpFileName);
    }
    QApplication::restoreOverrideCursor();

    if (!ok) {
        QMessageBox::warning(this, tr("QHexEdit"),
                             tr("Cannot write file %1.")
                             .arg(fileName));
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindowHexEdit::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = fileName.isEmpty();
    setWindowModified(false);
    if (fileName.isEmpty())
        setWindowFilePath("QHexEdit");
    else
        setWindowFilePath(curFile + " - QHexEdit");
}

QString MainWindowHexEdit::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindowHexEdit::setData(QByteArray const &data, QHexCaller const &caller)
{
    hexCaller = caller;
    //
    switch (hexCaller.datasource) {
    case dsTrack:
        homeAction->setDisabled(false);
        backAction->setDisabled(false);
        selectAction->setDisabled(false);
        nextAction->setDisabled(false);
        endAction->setDisabled(false);
        break;
    case dsRLBA:
    case dsLBA:
        homeAction->setDisabled(false);
        backAction->setDisabled(false);
        selectAction->setDisabled(false);
        nextAction->setDisabled(false);
        endAction->setDisabled(false);
        break;
    case dsModules:
        homeAction->setDisabled(true);
        backAction->setDisabled(true);
        selectAction->setDisabled(true);
        nextAction->setDisabled(true);
        endAction->setDisabled(true);
        CheckSumAction->setDisabled(false);
        CheckCheckSumAction->setDisabled(false);
        break;
    default:
        homeAction->setDisabled(true);
        backAction->setDisabled(true);
        selectAction->setDisabled(true);
        nextAction->setDisabled(true);
        endAction->setDisabled(true);
        CheckSumAction->setDisabled(true);
        CheckCheckSumAction->setDisabled(true);
        break;
    }
    lbCurrentName->setText(caller.objName);
    lbCurrent->setText(QString("%1").arg(caller.currentObj));
    hexEdit->setData(data);
}

QByteArray MainWindowHexEdit::data()
{
    return hexEdit->data();
}

void MainWindowHexEdit::setSourceObjectNumber(int objNum)
{
    hexCaller.sourceObjectNumber = objNum;
}

int MainWindowHexEdit::sourceObjectNumber() const
{
    return hexCaller.sourceObjectNumber;
}

void MainWindowHexEdit::setAlgorithmNumber(int algo)
{
    hexCaller.algoNumber = algo;
}

int MainWindowHexEdit::algorithmNumber() const
{
    return hexCaller.algoNumber;
}

void MainWindowHexEdit::slotSaveToHdd()
{
    emit SaveDataToHdd(hexCaller.datasource,hexCaller.currentObj);
}

void MainWindowHexEdit::slotReload()
{
    emit ReloadHexEdit(hexCaller.datasource,hexCaller.currentObj);
}

void MainWindowHexEdit::slotCheckSumShow()
{
//    quint32 CheckSumResult = WD_functions::calculateCheckSumDW(hexEdit->data(),hexEdit->data().size());
//    QByteArray data = hexEdit->dataAt(12,4);
//    DialogShowModuleCheckSum *resultdialog = new DialogShowModuleCheckSum(CheckSumResult,data,this);
//    resultdialog->show();
}

void MainWindowHexEdit::slotChangeCheckSum()
{
//    quint32 CheckSumResult = WD_functions::calculateCheckSumDW(hexEdit->data(),hexEdit->data().size());
//    char sum0 = CheckSumResult;
//    char sum1 = CheckSumResult>>8;
//    char sum2 = CheckSumResult>>16;
//    char sum3 = CheckSumResult>>24;
//    hexEdit->replace(12,sum0);
//    hexEdit->replace(13,sum1);
//    hexEdit->replace(14,sum2);
//    hexEdit->replace(15,sum3);
}
