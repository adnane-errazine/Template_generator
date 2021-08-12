#include "mainWin.h"

mainWin::mainWin()
{

    //Class definition

    name =new QLineEdit;
    classParent =new QLineEdit;
    scope = new QComboBox;
    scope->addItem("public");
    scope->addItem("protected");
    scope->addItem("private");
    QFormLayout *form_definition=new QFormLayout;
    form_definition->addRow("Class name :", name);
    form_definition->addRow("Class parent :", classParent);
    form_definition->addRow("Class parent scope :", scope);
    QGroupBox *definition_group= new QGroupBox("Class definition");
    definition_group->setLayout(form_definition);

    //Class options


    constructor = new QCheckBox("Constructor");
    destructor = new QCheckBox("Destrutor");
    virtualDestructor = new QCheckBox("Virtual destructor");
    QVBoxLayout *list_option= new QVBoxLayout();
    list_option->addWidget(constructor);
    list_option->addWidget(destructor);
    list_option->addWidget(virtualDestructor);
    QGroupBox *option_group = new QGroupBox("Options");
    option_group->setLayout(list_option);

    //Members section

   QLabel *label = new QLabel("Format : dataType variable_name ;  ");
    member_text= new QTextEdit;
   QVBoxLayout *list_members = new QVBoxLayout();
   list_members->addWidget(label);
   list_members->addWidget(member_text);
   QGroupBox *members_group = new QGroupBox("Memebers");
   members_group->setLayout(list_members);

    // header section
   guards = new QCheckBox("Header guards");
   iosrteam_h= new QCheckBox("Add <iostream> header file");
   vector_h= new QCheckBox("Add <vector> ");
   string_h= new QCheckBox("Add <string>");
   algorithm_h= new QCheckBox("Add <algorithm>");
   QVBoxLayout *list_headers = new QVBoxLayout();
   list_headers->addWidget(guards);
   list_headers->addWidget(iosrteam_h);
   list_headers->addWidget(vector_h);
   list_headers->addWidget(string_h);
   list_headers->addWidget(algorithm_h);
   QGroupBox *header_group = new QGroupBox("Header");
   header_group->setLayout(list_headers);

    //comment section

    author = new QLineEdit();
    date = new QDateEdit();
    date->setDate(QDate::currentDate());
    description = new QTextEdit();
    copyright = new QTextEdit();
    QFormLayout *form_Comment = new QFormLayout;
    form_Comment->addRow("Author :",author);
    form_Comment->addRow("Date",date);
    form_Comment->addRow("Copyright :",copyright);
    form_Comment->addRow("Class description :",description);
    comments_group = new QGroupBox("Add comments");
    comments_group->setCheckable(true);
    comments_group->setChecked(false);
    comments_group->setLayout(form_Comment);


    //buttons

    generate = new QPushButton("&Generate code");
    quit_win = new QPushButton("&Quit");
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setAlignment(Qt::AlignRight);
    buttonLayout->addWidget(generate);
    buttonLayout->addWidget(quit_win);


    // main layout C++ class

    QGridLayout *mainLayout_cppClass = new QGridLayout;
    mainLayout_cppClass->addWidget(definition_group);
    mainLayout_cppClass->addWidget(option_group,0,1);
    mainLayout_cppClass->addWidget(members_group);
    mainLayout_cppClass->addWidget(header_group);
    mainLayout_cppClass->addWidget(comments_group);
    mainLayout_cppClass->addLayout(buttonLayout,4,1);


    //menuBar ----------------------------

    QMenu *menuFile = menuBar()->addMenu("&File");
    QMenu *menuHelp= menuBar()->addMenu("&Help");

    QAction *actionNew = new QAction("&New", this);
    menuFile->addAction(actionNew);
    QAction *actionExit = new QAction("&Exit", this);
    menuFile->addAction(actionExit);
    QAction *actionAbout = new QAction("&About", this);
    menuHelp->addAction(actionAbout);


    connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(actionNew, SIGNAL(triggered()), this, SLOT(restart()));
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    //signal/slots

    connect(generate,SIGNAL(clicked()),this,SLOT(generateCodeCPP()));
    connect(quit_win,SIGNAL(clicked()),qApp,SLOT(quit()));



    // container CPP

    QGroupBox *all_cpp= new QGroupBox;
    all_cpp->setLayout(mainLayout_cppClass);
    //----------------------------------------------------------------------------------------------------------- HTML

    //class tags

    scopeHTML = new QComboBox;
    scopeHTML->addItem("HTML 5");
    scopeHTML->addItem("HTML 4.01");
    scopeHTML->addItem("XHTML 1.1");
    QVBoxLayout *HTMLversion_layout = new QVBoxLayout;
    HTMLversion_layout->addWidget(scopeHTML);

    tag_meta = new QCheckBox("Meta");
    tag_title = new QCheckBox("Title");
    QVBoxLayout *head_layout = new QVBoxLayout;
    head_layout->addWidget(tag_meta);
    head_layout->addWidget(tag_title);
    head_group = new QGroupBox("Head Tag");
    head_group->setCheckable(true);
    head_group->setChecked(false);
    head_group->setLayout(head_layout);
    head_group->setAlignment(Qt::AlignTop);


    tag_body = new QCheckBox("Add body tag");
    tag_footer = new QCheckBox("Add footer tag");
    QVBoxLayout *body_layout = new QVBoxLayout;
    body_layout->addWidget(tag_body);
    body_layout->addWidget(tag_footer);

    // buttons HTML

    generateHTML = new QPushButton("&Generate code");
    quit_win2 = new QPushButton("Quit");
    QHBoxLayout *buttonLayoutHTML = new QHBoxLayout;
    buttonLayoutHTML->setAlignment(Qt::AlignRight);
    buttonLayoutHTML->addWidget(generateHTML);
    buttonLayoutHTML->addWidget(quit_win2);

    //comment HTML

    authorHTML = new QLineEdit();
    dateHTML = new QDateEdit();
    dateHTML->setDate(QDate::currentDate());
    descriptionHTML = new QTextEdit();
    copyrightHTML = new QTextEdit();
    QFormLayout *form_CommentHTML = new QFormLayout;
    form_CommentHTML->addRow("Author :",authorHTML);
    form_CommentHTML->addRow("Date",dateHTML);
    form_CommentHTML->addRow("Copyright :",copyrightHTML);
    form_CommentHTML->addRow("Class description :",descriptionHTML);
    comments_groupHTML = new QGroupBox("Add comments");
    comments_groupHTML->setCheckable(true);
    comments_groupHTML->setChecked(false);
    comments_groupHTML->setLayout(form_CommentHTML);

    // main layout html

    QGridLayout *mainLayout_HTML = new QGridLayout ;
    mainLayout_HTML->addLayout(HTMLversion_layout,0,0,1,2);
    mainLayout_HTML->addWidget(head_group,1,0);
    mainLayout_HTML->addLayout(body_layout,1,1);
    mainLayout_HTML->addWidget(comments_groupHTML);
    mainLayout_HTML->addLayout(buttonLayoutHTML,3,1);
    QGroupBox *all_HTML= new QGroupBox;
    all_HTML->setLayout(mainLayout_HTML);

    // SIGNALS AND SLOTS FOR HTML
    connect(generateHTML,SIGNAL(clicked()),this,SLOT(generateCodeHTML()));
    connect(quit_win2,SIGNAL(clicked()),qApp,SLOT(quit()));
    // -----------------------------------------------------------------------------------------final

    QTabWidget *tab = new QTabWidget;
    tab->addTab(all_cpp,QIcon("cpplogo.png"),"C++ Class");
    tab->addTab(all_HTML,QIcon("htmllogo.png"),"HTML");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(tab);
    setCentralWidget(tab);
    setWindowIcon(QIcon("icon.png"));
    setWindowTitle("Code Generator");
}
void mainWin::generateCodeCPP()
{
       if (name->text().isEmpty())
       {
           QMessageBox::critical(this, "ERROR", "You need to fill the class name.");
           return;
       }

       // code .h file

       QString codeH;

       if (comments_group->isChecked())
       {
           codeH += "/*\nAuthor : " + author->text() + "\n";
           codeH += "Creation date : " + date->date().toString() + "\n";
           codeH += "Copyright : " + copyright->toPlainText() + "\n";
           codeH += "Description :\n   " + description->toPlainText() + "\n*/\n\n\n";
       }

       if (guards->isChecked())
       {
           codeH += "#ifndef HEADER_" + name->text().toUpper() + "\n";
           codeH += "#define HEADER_" + name->text().toUpper() + "\n\n\n";
       }

       if(iosrteam_h->isChecked())
       {
           codeH +="#include <iostream>\n";
       }

       if(vector_h->isChecked())
       {
           codeH +="#include <vector>\n";
       }

       if(string_h->isChecked())
       {
           codeH +="#include <string>\n";
       }
       if(algorithm_h->isChecked())
       {
           codeH +="#include <algorithm>\n";
       }
       codeH += "class " + name->text();

       if (!classParent->text().isEmpty())
       {

           codeH += " : "+ scope->itemText(scope->currentIndex())+" " + classParent->text();
       }

       codeH += "\n{\n    public:\n";
       if (constructor->isChecked())
       {
           codeH += "        " + name->text() + "();\n";
       }
       if (destructor->isChecked() || virtualDestructor->isChecked() )
       {
           if (virtualDestructor->isChecked())
           {
              codeH += "virtual ~" + name->text() + "();\n";
           }
           else
           {
              codeH += "        ~" + name->text() + "();\n";
           }
       }
      QString text_members=member_text->toPlainText();
       codeH += "\n\n    protected:\n\n"+text_members;
       codeH += "\n\n    private:\n\n" ;//-----------------------------------------------------------------------------------
       codeH += "};\n\n";

       if (guards->isChecked())
       {
           codeH += "#endif\n";
       }

              // code .cpp file


       QString codeCPP;

           codeCPP+="#include \""+name->text()+"\"\n\n";
           codeCPP+=name->text()+"::"+name->text()+"()";
           codeCPP+="\n  {\n\n\n\n  }\n";
           if (destructor->isChecked() || virtualDestructor->isChecked() )
           {
               if (virtualDestructor->isChecked())
               {
                  codeCPP += "\nvirtual "+name->text()+"::~"+name->text()+"()";
               }
               else
               {
                  codeCPP += name->text()+"::~"+name->text()+"()";
               }
               codeCPP+="\n  {\n\n  }";
           }

       codeWin *win = new codeWin(codeH,codeCPP, this);
       win->exec();

}
void mainWin::about()
{
    QMessageBox::information(this,"About","contact me : \nhttps://twitter.com/adnane_errazine\nhttps://www.linkedin.com/in/adnane-errazine/");
}
void mainWin::restart()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
void mainWin::generateCodeHTML()
{
   QString code;
   if (comments_groupHTML->isChecked())
   {
       code += "/*\nAuthor : " + authorHTML->text() + "\n";
       code += "Creation date : " + dateHTML->date().toString() + "\n";
       code += "Copyright : " + copyrightHTML->toPlainText() + "\n";
       code += "Description :\n    " + descriptionHTML->toPlainText() + "\n*/\n\n\n";
   }

   if(scopeHTML->currentIndex()==0)
   {
       code+="<!DOCTYPE html>\n";
   }
   if(scopeHTML->currentIndex()==1)
   {
       code+="<!DOCTYPE HTML PUBLIC \" -// //DTD HTML 4.01\" \" \"\n";
   }
   if(scopeHTML->currentIndex()==2)
   {
       code+="<!DOCTYPE html PUBLIC \"-// //DTD XHTML 1.1 \" \"\n";
   }
   code+="<html>\n";
   if (head_group->isChecked())
   {
       code+="   <head>\n";
   }
   if (tag_meta->isChecked())
   {
       code+="     <meta content=\"\" >\n";
   }
   if (tag_title->isChecked())
   {
       code+="     <title>  </title>\n";
   }
   if (head_group->isChecked())
   {
       code+="   </head>\n";
   }
   if (tag_body->isChecked())
   {
       code+="   <body>\n\n\n\n   </body>\n";
   }
   if (tag_footer->isChecked())
   {
       code+="   <footer>\n  \n  \n   </footer>\n";
   }
    code+="</html>";
    codeWin *winHTML = new codeWin(code, this);
    winHTML->exec();
}
