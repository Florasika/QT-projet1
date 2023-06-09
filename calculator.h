#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCombobox>
#include <QPushButton>

class Calculator : public QWidget
{
    Q_OBJECT
public :
    Calculator();//Constructeur
    virtual ~ Calculator(); //Destructeur

private :
    QLabel *lbTitre ;
    QLabel *lbN1 ;
    QLabel *lbN2 ;
    QLabel *lbR ;
    QLabel *lbC;
    QLineEdit *edN1 ;
    QLineEdit *edN2 ;
    QLineEdit *edR ;
    QComboBox *cbOper ;
    QPushButton *btExecuter ;
    QPushButton *btTerminer ;

public slots :
    void terminer();
    void executer();

};

#endif // CALCULATOR_H
