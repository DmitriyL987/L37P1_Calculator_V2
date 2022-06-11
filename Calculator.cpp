//
// Created by LDm on 10.04.2022.
//

#include "Calculator.h"


void Calculator::comm() {
    if(!currentInputField->text().contains('.')) currentInputField->setText(currentInputField->text() + '.');
}

void Calculator::plus() {
    act = PLUS;
    calculate();
}

void Calculator::minus() {
    act = MINUS;
    calculate();
}

void Calculator::divide() {
    act = DIVIDE;
    calculate();
}

void Calculator::mult() {
    act = MULTIPLEX;
    calculate();
}

void Calculator::Clear() {
    field_1->setText("");
    field_2->setText("");
    field_result->setText("");
}

void Calculator::calculate() {
    QString a , b;
    a = field_1->text();
    b = field_2->text();

    long double n1, n2, result;
    try {
        n1 = std::stold(a.toStdString());
        n2 = std::stold(b.toStdString());
        // проверка ввода
        //std::cout << n1 << "  " << n2 << std::endl;

        if (act == DIVIDE && n2 == 0) { throw std::invalid_argument("Try divide of the 0");
        } else if (act == DIVIDE) { result = n1 / n2;
        } else if (act == PLUS) { result = n1 + n2;
        } else if (act == MINUS) { result = n1 - n2;
        } else if (act == MULTIPLEX) result = n1 * n2;
        QString str = ld_convert2str(result).c_str();
        field_result->setText(str);
        // проверка результата
        //std::cout << "Result " << result << "  " << str.toStdString() << std::endl;

    }
    catch (...)
    {
        currentInputField = field_1;
        field_1->setText("");
        field_2->setText("");
        field_result->setText("Error");
    }
}
//если пользователь ввел ',' меняем на '.'
void Calculator::change_Delime(QLineEdit* line, char old_d, char new_d) {
    std::string num="";
    num = line->text().toStdString();
    int ind = num.find(old_d);
    if(ind != num.npos){
       num[ind] = new_d;
       line->setText(num.c_str());
    }
}

void Calculator::valide() {
    change_Delime(currentInputField, ',', '.');
}
//------------------------------------------
void Calculator::chField() {
    if(currentInputField != field_1) currentInputField = field_1;
    else currentInputField = field_2;
}
//------------------------------------------
// обработчик события "клик мышки левой кнопкой" на полях ввода для корректной смены фокуса
//
bool Calculator::eventFilter(QObject *object, QEvent *event) {
    if(object == field_1 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
        if(mouseEvent != 0 && mouseEvent->button() == Qt::LeftButton)
        {
            currentInputField = field_1;
            currentInputField->setFocus();
        }
    } else if(object == field_2 && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent *>(event);
        if (mouseEvent != 0 && mouseEvent->button() == Qt::LeftButton)
        {
            currentInputField = field_2;
            currentInputField->setFocus();
        }
    }
    return QMainWindow::eventFilter(object, event);
}
//----------------------------------------------
std::string Calculator::ld_convert2str(long double val) {
    std::stringstream sstr("");
    sstr << val;
    std::string str;
    sstr >> str;
    return str;
}
