#ifndef STYLE_H
#define STYLE_H

#include <QString>

class Style
{
public:
    static QString getMainStyle()
    {
        return R"(
            QMainWindow, QDialog {
                background-color: #f5f5f5;
            }
            
            QPushButton {
                background-color: #2196F3;
                color: white;
                border: none;
                padding: 8px 16px;
                border-radius: 4px;
                font-weight: bold;
            }
            
            QPushButton:hover {
                background-color: #1976D2;
            }
            
            QPushButton:pressed {
                background-color: #0D47A1;
            }
            
            QTableWidget {
                background-color: white;
                border: 1px solid #ddd;
                gridline-color: #ddd;
            }
            
            QTableWidget::item:selected {
                background-color: #2196F3;
                color: white;
            }
            
            QLineEdit, QTextEdit, QComboBox {
                border: 1px solid #ddd;
                padding: 5px;
                border-radius: 3px;
                background-color: white;
            }
            
            QLineEdit:focus, QTextEdit:focus, QComboBox:focus {
                border: 2px solid #2196F3;
            }
            
            QLabel {
                color: #333;
                font-size: 12px;
            }
        )";
    }
};

#endif // STYLE_H