#include "LoginDialog.h"
#include <QIcon>
#include <QFont>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    setupUI();
    setWindowTitle(tr("Login"));
    setMinimumSize(400, 350);
    setMaximumSize(400, 350);
}

void LoginDialog::setupUI() {
    // Create main vertical layout with proper spacing
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 40, 40, 40);
    mainLayout->setSpacing(20);

    // Title Label
    titleLabel = new QLabel(tr("Sistema de Gestão"), this);
    titleLabel->setObjectName("titleLabel");
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont("Segoe UI", 18, QFont::Bold);
    titleLabel->setFont(titleFont);
    mainLayout->addWidget(titleLabel);

    mainLayout->addSpacing(20);

    // Username section
    usernameLabel = new QLabel(tr("Nome de Usuário:"), this);
    usernameLabel->setObjectName("fieldLabel");
    QFont labelFont("Segoe UI", 11);
    usernameLabel->setFont(labelFont);
    mainLayout->addWidget(usernameLabel);

    usernameEdit = new QLineEdit(this);
    usernameEdit->setObjectName("loginField");
    usernameEdit->setPlaceholderText(tr("Digite seu usuário"));
    usernameEdit->setMinimumHeight(40);
    QFont fieldFont("Segoe UI", 11);
    usernameEdit->setFont(fieldFont);
    mainLayout->addWidget(usernameEdit);

    mainLayout->addSpacing(10);

    // Password section
    passwordLabel = new QLabel(tr("Senha:"), this);
    passwordLabel->setObjectName("fieldLabel");
    passwordLabel->setFont(labelFont);
    mainLayout->addWidget(passwordLabel);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setObjectName("loginField");
    passwordEdit->setPlaceholderText(tr("Digite sua senha"));
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setMinimumHeight(40);
    passwordEdit->setFont(fieldFont);
    mainLayout->addWidget(passwordEdit);

    mainLayout->addSpacing(20);

    // Buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(15);

    loginButton = new QPushButton(tr("Entrar"), this);
    loginButton->setObjectName("loginButton");
    loginButton->setIcon(QIcon(":/icons/login.svg"));
    loginButton->setMinimumHeight(45);
    loginButton->setMinimumWidth(150);
    QFont buttonFont("Segoe UI", 11, QFont::Bold);
    loginButton->setFont(buttonFont);
    loginButton->setCursor(Qt::PointingHandCursor);
    connect(loginButton, &QPushButton::clicked, this, &QDialog::accept);

    cancelButton = new QPushButton(tr("Cancelar"), this);
    cancelButton->setObjectName("cancelButton");
    cancelButton->setMinimumHeight(45);
    cancelButton->setMinimumWidth(150);
    cancelButton->setFont(buttonFont);
    cancelButton->setCursor(Qt::PointingHandCursor);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);
    
    // Set focus to username field
    usernameEdit->setFocus();
}

QString LoginDialog::getUsername() const {
    return usernameEdit->text();
}

QString LoginDialog::getPassword() const {
    return passwordEdit->text();
}