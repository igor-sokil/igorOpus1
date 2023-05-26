
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QWidget;
class QLabel;
class QPushButton;
class QToolButton;
class QGridLayout;
class QTabWidget;
class QLineEdit;
class QCloseEvent;
QT_END_NAMESPACE

class MiniButtonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MiniButtonWidget(QWidget *parent = 0);

    QToolButton *virtualMenuUpButton;
    QToolButton *virtualMenuDownButton;

    QToolButton *virtualMenuCloseButton;
    QToolButton *virtualMenuOpenButton;

    QToolButton *virtualMenuPUpButton;
    QToolButton *virtualMenuPDownButton;

    QToolButton *virtualMenuHomeButton;
    QToolButton *virtualMenuEndButton;

    QToolButton *virtualMenuEnterButton;
    QToolButton *virtualMenuEscButton;

    QToolButton *virtualMenuResetButton;
    QToolButton *virtualMenuLogButton;

    QToolButton *virtualMenuUpdateButton;
    QToolButton *virtualMenuFreeButton;

    QToolButton *createButton(const QString &text, const char *member);

//protected:
  //  void keyPressEvent(QKeyEvent *event);

private slots:
    void digitClicked();

    void freeClicked();
    void downClicked();
    void upClicked();
    void enterClicked();
    void escClicked();
    void rightClicked();
    void leftClicked();
/*
    void pageDownClicked();
    void upClicked();
    void pageUpClicked();
    void homeClicked();
    void endClicked();
    void openClicked();
    void closeClicked();
    void resetClicked();
//    void logClicked();
    void updateClicked();
    void clearClicked();
*/
};

class MiniDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MiniDisplayWidget(QWidget *parent = 0);


    QLabel      *virtualMenu1Label;
    QLabel      *virtualMenu2Label;
    QLabel      *virtualMenu3Label;
    QLabel      *virtualMenu4Label;

    QGridLayout *miniDisplayLayout;

};

class MainWindow : public QWidget//QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MiniButtonWidget    *miniButtonWidget;
    MiniDisplayWidget   *miniDisplayWidget;

public slots:

private slots:

//private:
//    QPushButton *quitButton;


};

#endif
