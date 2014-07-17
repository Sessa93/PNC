#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QActionGroup>
#include <QList>
#include "graphwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow();
    protected:
        //void closeEvent(QCloseEvent *event);
    private slots:
        void newFile();
        void connectionModeClicked(bool state);
        void placeModeClicked();
        void transModeClicked();
        void tabClose(int tab);
        //TODO: AGGIUNGERE SLOT PER SALVATAGGIO/APERTURA
    private:
         void createActions();
         void createMenus();
         void createToolBars();
         void createStatusBar();
         void readSettings();
         void writeSettings();
         bool maybeSave();
         void loadFile(const QString &fileName);
         bool saveFile(const QString &fileName);
         void setCurrentFile(const QString &fileName);
         QString strippedName(const QString &fullFileName);
         void addSheet(GraphWidget *);

         QMenu *fileMenu;
         QMenu *editMenu;
         QMenu *helpMenu;
         QToolBar *fileToolBar;
         QToolBar *editToolBar;
         QAction *newAct;
         QAction *openAct;
         QAction *saveAct;
         QAction *saveAsAct;
         QAction *exitAct;
         QAction *cutAct;
         QAction *copyAct;
         QAction *pasteAct;
         QAction *aboutAct;
         QAction *aboutQtAct;
         QAction *connAct;
         QAction *placeAct;
         QAction *transAct;

         QTabWidget *tabber;
         QActionGroup *group;

         QList<GraphWidget *> sheetList;
};

#endif
