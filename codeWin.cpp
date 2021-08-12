#include <codeWin.h>
#include <QTabWidget>

codeWin::codeWin(QString &codeH,QString &codeCPP,QWidget *parent=0):QDialog(parent)
{
    //code
    codeGenere = new QTextEdit();
    codeGenere->setPlainText(codeH);
    codeGenere->setReadOnly(true);
    codeGenere->setFont(QFont("Courier"));
    codeGenere->setLineWrapMode(QTextEdit::NoWrap);
    QTextEdit *text = new QTextEdit();
    text->setPlainText(codeCPP);
    text->setReadOnly(true);
    text->setFont(QFont("Courier"));
    text->setLineWrapMode(QTextEdit::NoWrap);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(codeGenere);

    QVBoxLayout *layoutPrincipal2 = new QVBoxLayout;
    layoutPrincipal2->addWidget(text);

    QGroupBox *tab1 = new QGroupBox;
    tab1->setLayout(layoutPrincipal);
    QGroupBox *tab2 = new QGroupBox;
    tab2->setLayout(layoutPrincipal2);


    QTabWidget *tab_bar = new QTabWidget();
    tab_bar->addTab(tab1,"Header_file");
    tab_bar->addTab(tab2,"CPP_file");

    QVBoxLayout *layoutCPP = new QVBoxLayout;

    quit = new QPushButton("Quit");
    layoutCPP->addWidget(tab_bar);
    layoutCPP->addWidget(quit);
    setLayout(layoutCPP);
   resize(450, 600);

    connect(quit, SIGNAL(clicked()), this, SLOT(accept()));
}
codeWin::codeWin(QString &codeHTML,QWidget *parent=0):QDialog(parent)
{
    codeGenereHTML = new QTextEdit();
    codeGenereHTML->setPlainText(codeHTML);
    codeGenereHTML->setReadOnly(true);
    codeGenereHTML->setFont(QFont("Courier"));
    codeGenereHTML->setLineWrapMode(QTextEdit::NoWrap);

    quit2 = new QPushButton("Quit");
    QVBoxLayout *V_layoutHTML = new QVBoxLayout;
    V_layoutHTML->addWidget(codeGenereHTML);
    V_layoutHTML->addWidget(quit2);
    setLayout(V_layoutHTML);
    resize(450, 350);

    connect(quit2, SIGNAL(clicked()), this, SLOT(accept()));
}


