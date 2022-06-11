#include <QApplication>
#include <QRegularExpression>
#include "Calculator.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    Calculator calculator(nullptr);
    Ui::MainWindow calcGUI;
    calcGUI.setupUi(&calculator);

    QString tmpl = "^[\\+|\\-]?\\d*(\\.?\\d*)$";
    QRegularExpression RegExp(tmpl);

    calculator.field_1 = calcGUI.lineEdit_2;
    calculator.field_1->setValidator(new QRegularExpressionValidator(RegExp, calculator.field_1));

    calculator.field_2 = calcGUI.lineEdit;
    calculator.field_2->setValidator(new QRegularExpressionValidator(RegExp, calculator.field_2));

    calculator.chField();

    calculator.field_result = calcGUI.lineEdit_3;
    // инициализация обработчика события "клик мышки левой кнопкой" в GUI
    calcGUI.lineEdit->installEventFilter(&calculator);
    calcGUI.lineEdit_2->installEventFilter(&calculator);
    //---
    calculator.show();
    return QApplication::exec();
}
