#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "mainwindowhexedit.h"

QT_BEGIN_NAMESPACE
class QtAwesome;
class QSerialPort;
class QProgressBar;
QT_END_NAMESPACE

#define arduino_mega2560_vendor  0x2341
#define arduino_mega2560_product 0x0042

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:

public slots:
    void slotReadRom();
    void handleReadyRead();
    void handleTimeout();
private:
    Ui::MainWindow *ui;
    QtAwesome *awesome;
    MainWindowHexEdit *hexEditWidget;
    //
    QAction *selectAction;
    //
    bool arduino_is_available;
    QString arduino_port_name;
    QSerialPort *arduino;
    QTimer m_timer;
    QByteArray m_readData;
    QByteArray m_resultData;
    int addressCounter = 0;
    QProgressBar *progressBar;
};

#endif // MAINWINDOW_H
