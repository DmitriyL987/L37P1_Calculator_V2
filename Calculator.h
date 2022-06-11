//
// Created by LDm on 10.04.2022.
//

#ifndef L37P1_CALCULATOR_V2_CALCULATOR_H
#define L37P1_CALCULATOR_V2_CALCULATOR_H
#include <limits>
#include <iostream>
#include <sstream>
#include <exception>
#include <QWidget>
#include <Qt>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QValidator>
#include <QRegularExpression>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QAbstractNativeEventFilter>
#include <QString>
#include "./ui_Calc.h"

class Calculator : public QMainWindow
{
    Q_OBJECT
public:
    Calculator(QWidget* parent = nullptr){};

public slots:
    void slot0(){currentInputField->setText(currentInputField->text() + '0');}
    void slot1(){currentInputField->setText(currentInputField->text() + '1');}
    void slot2(){currentInputField->setText(currentInputField->text() + '2');}
    void slot3(){currentInputField->setText(currentInputField->text() + '3');}
    void slot4(){currentInputField->setText(currentInputField->text() + '4');}
    void slot5(){currentInputField->setText(currentInputField->text() + '5');}
    void slot6(){currentInputField->setText(currentInputField->text() + '6');}
    void slot7(){currentInputField->setText(currentInputField->text() + '7');}
    void slot8(){currentInputField->setText(currentInputField->text() + '8');}
    void slot9(){currentInputField->setText(currentInputField->text() + '9');}
    void comm();
    void plus();
    void minus();
    void divide();
    void mult();
    void chField();
    void Clear();
    void valide();

private:

    bool dot_field1 = false;
    bool dot_field2 = false;

    QLineEdit* currentInputField = nullptr;
    enum Action{PLUS, MINUS, DIVIDE, MULTIPLEX,} act;

public:

    QLineEdit* field_1 = nullptr;
    QLineEdit* field_2 = nullptr;
    QLineEdit* field_result = nullptr;
    void calculate();
    std::string ld_convert2str(long double);
    bool eventFilter(QObject *object, QEvent *event);
    void change_Delime(QLineEdit* , char old_delime, char new_delime);

};


#endif //L37P1_CALCULATOR_V2_CALCULATOR_H
