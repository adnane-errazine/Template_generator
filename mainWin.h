#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>

#include "codeWin.h"

class mainWin : public QMainWindow
{
  Q_OBJECT

public:
    mainWin();


private slots:
 void generateCodeCPP();
 void generateCodeHTML();
 void about();
void restart();
protected:
    QLineEdit *name;
    QLineEdit *classParent;
    QComboBox *scope;
    QCheckBox *guards;
    QCheckBox *constructor;
    QCheckBox *destructor;
    QCheckBox *virtualDestructor;
    QTextEdit *member_text;
    QCheckBox *getter;
    QCheckBox *setter;
    QGroupBox *comments_group;
    QCheckBox *iosrteam_h;
    QCheckBox *vector_h;
    QCheckBox *string_h;
    QCheckBox *algorithm_h;
    QLineEdit *author;
    QDateEdit *date;
    QTextEdit *description;
    QTextEdit *copyright;
    QPushButton *generate;
    QPushButton *quit_win;

    //-------------------------- html
    QComboBox *scopeHTML;
    QCheckBox *tag_meta;
    QCheckBox *tag_title;
    QCheckBox *tag_body;
    QCheckBox *tag_footer;
    QGroupBox *head_group;
    QPushButton *generateHTML;
    QPushButton *quit_win2;
    QGroupBox *comments_groupHTML;
    QLineEdit *authorHTML;
    QDateEdit *dateHTML;
    QTextEdit *descriptionHTML;
    QTextEdit *copyrightHTML;
};


#endif // MAINWIN_H
