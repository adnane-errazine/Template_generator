#ifndef CODEWIN_H
#define CODEWIN_H
#include <QtWidgets>
#include <QtGui>
#include <QClipboard>
class codeWin : public QDialog
{
    Q_OBJECT

public:
    codeWin(QString &codeH,QString &codeCPP,QWidget *parent);
    codeWin(QString &codeHTML,QWidget *parent);

protected:
    QTextEdit *codeGenere;
    QPushButton *quit;
    QTextEdit *codeGenereHTML;
    QPushButton *quit2;
    QPushButton *saveButton;
};



#endif // CODEWIN_H
