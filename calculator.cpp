 #include <QGridLayout>
#include <QWidget>
#include <QApplication>
#include <QMessageBox>

#include "calculator.h"

Calculator::Calculator() : QWidget()
{
    lbTitre = new QLabel("Special Calculator");
    lbTitre->setStyleSheet("color : navy");
    lbTitre->setFont(QFont("Comic Sans Ms", 20));

    lbN1 = new QLabel("First Number : ");
    lbN2 = new QLabel("Last Number : ");
    lbR = new QLabel("Result : ");
    lbC = new QLabel("Copyright : MR AKAKPO (c)2023 juin");
    lbC->setStyleSheet("color :red");

    edN1 = new QLineEdit;
    edN2 = new QLineEdit;

    edR = new QLineEdit;
    edR->setReadOnly(true);
    edR->setStyleSheet("background-color :Blue; color :Yellow");

    cbOper = new QComboBox();
    cbOper->addItem("+");
    cbOper->addItem("-");
    cbOper->addItem("/");
    cbOper->addItem("*");

    btExecuter = new QPushButton("Executer");
    btTerminer = new QPushButton("Terminer");

    btExecuter->setCursor(Qt::PointingHandCursor);
    btTerminer->setCursor(Qt::PointingHandCursor);

    QGridLayout *fond = new QGridLayout;

    fond->addWidget(lbTitre, 0, 0, 1, 4, Qt::AlignCenter);
    fond->addWidget(lbN1, 1, 0);
    fond->addWidget(lbN2, 2, 0);
    fond->addWidget(lbR, 3, 0);
    fond->addWidget(lbC, 4, 0, 1, 3, Qt::AlignCenter);

    fond->addWidget(edN1, 1, 1);
    fond->addWidget(edN2, 2, 1);
    fond->addWidget(edR, 3, 1);

    fond->addWidget(cbOper, 1, 2);
    fond->addWidget(btExecuter, 2, 2);
    fond->addWidget(btTerminer, 3, 2);

    connect(btTerminer, SIGNAL(clicked()), this, SLOT(terminer()));
    connect(btExecuter, SIGNAL(clicked()), this, SLOT(executer()));
    setLayout(fond);
}

Calculator::~Calculator()
{
}

void Calculator::terminer()
{
    int reponse = QMessageBox::question(this,"Question",
                                        "voulez-vous reellement quitter ?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(reponse == QMessageBox::Yes)
    {
        qApp->quit();
    }
    else{
        QMessageBox::information(this,"Information",
                                  "Bonne reprise");
    }

}

void Calculator::executer()
{
    float n1 = edN1->text().toFloat();
    float n2 = edN2->text().toFloat();
    QString oper = cbOper->currentText();

    float r;

    if(oper == "+"){
        r = n1+n2;
    }
    else if(oper == "-"){
       r = n1 - n2;
    }
    else if(oper == "*")
    {
        r = n1* n2;
    }
    else if(oper == "/")
    {
        r = n1 / n2;
    }

    edR->setText(QString::number(r));
}
