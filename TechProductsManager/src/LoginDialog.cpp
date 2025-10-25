#include "LoginDialog.h"
#include "utils/Style.h"
#include <QMessageBox>
#include <QLabel>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

LoginDialog::~LoginDialog()
{
}

void LoginDialog::setupUI()
{
    setWindowTitle("Login - Tech Products Manager");
    setFixedSize(400, 250);
    setStyleSheet(Style::getMainStyle());
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    QLabel *titleLabel = new QLabel("Tech Products Manager", this);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 20px;");
    titleLabel->setAlignment(Qt::AlignCenter);
    
    QLabel *usernameLabel = new QLabel("Username:", this);
    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Enter username");
    
    QLabel *passwordLabel = new QLabel("Password:", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Enter password");
    passwordEdit->setEchoMode(QLineEdit::Password);
    
    loginButton = new QPushButton("Login", this);
    loginButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; font-weight: bold; padding: 10px; }");
    
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(usernameEdit);
    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(passwordEdit);
    mainLayout->addWidget(loginButton);
    mainLayout->addStretch();
    
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::handleLogin);
}

void LoginDialog::handleLogin()
{
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    
    if (validateCredentials(username, password)) {
        accept();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password!");
    }
}

bool LoginDialog::validateCredentials(const QString &username, const QString &password)
{
    // Simple validation: admin/admin or user/user
    return (username == "admin" && password == "admin") || 
           (username == "user" && password == "user");
}