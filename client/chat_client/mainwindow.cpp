#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pLoginDlg = new LoginDialog();
    setCentralWidget(m_pLoginDlg);
    m_pLoginDlg->show();

    m_pRegisterDlg = new RegisterDialog();

    connect(m_pLoginDlg, &LoginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);


}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_pLoginDlg != nullptr) {
        delete m_pLoginDlg;
        m_pLoginDlg = nullptr;
    }
    if(m_pRegisterDlg != nullptr) {
        delete m_pRegisterDlg;
        m_pRegisterDlg = nullptr;
    }
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(m_pRegisterDlg);
    m_pLoginDlg->hide();
    m_pRegisterDlg->show();
}
