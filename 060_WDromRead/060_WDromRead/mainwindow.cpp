#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QtAwesome.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000,650);
    this->move(100,100);
    this->setWindowTitle(tr("060_WDromRead 0.%1").arg(SVN_V));
    awesome = new QtAwesome(this);
    awesome->initFontAwesome();
    //
    hexEditWidget = new MainWindowHexEdit();
    setCentralWidget(hexEditWidget);
    //
    progressBar = new QProgressBar();
    ui->toolBar->addWidget(progressBar);
    selectAction = new QAction(awesome->icon(fa::play), tr("select"),this);
    ui->toolBar->addAction(selectAction);
    connect(selectAction,SIGNAL(triggered(bool)),this,SLOT(slotReadRom()));
    //
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::handleReadyRead);
    connect(&m_timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
    //
    foreach (const QSerialPortInfo&serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasVendorIdentifier()&&serialPortInfo.hasProductIdentifier()) {
            if(serialPortInfo.vendorIdentifier()==arduino_mega2560_vendor ) {
                if(serialPortInfo.productIdentifier()==arduino_mega2560_product) {
                    arduino_is_available = true;
                    arduino_port_name = serialPortInfo.portName();
                }
            }
        }
    }
    if(arduino_is_available) {
        // open and configure serial port
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::SoftwareControl);
    } else {
        // if no arduino board put a error message
        QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotReadRom()
{
    if(arduino->isWritable()) {
        addressCounter = 0;
        progressBar->reset();
        progressBar->setRange(0,1024*32-1);
        m_readData.clear();
        arduino->write("r",1); // reset address counter
        arduino->write("d",1); // read first word
        m_timer.start(5000);
    } else {
        QMessageBox::warning(this, "Port error", "Can't send command.");
    }
}

void MainWindow::handleReadyRead()
{
    m_readData.append(arduino->readAll());
    if(m_readData.size() > 5) {
        m_timer.stop();
        char b0 = m_readData[0];
        char b1 = m_readData[1];
        m_readData[0] = m_readData[2];
        m_readData[1] = m_readData[3];
        m_readData[2] = b0;
        m_readData[3] = b1;
        m_resultData.append(QByteArray::fromHex(m_readData));
        m_readData.clear();
        if(addressCounter < 1024*32-1) {
            addressCounter++;
            arduino->write("d",1);
            progressBar->setValue(addressCounter);
        } else {
            hexEditWidget->setData(m_resultData);
            progressBar->reset();
        }
    }
}

void MainWindow::handleTimeout()
{
    if (m_readData.size() < 6) {
        QMessageBox::warning(this, "Port error", "Device not unswer.");
    }
}

