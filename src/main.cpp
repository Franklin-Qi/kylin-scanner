/*
* Copyright (C) 2020, KylinSoft Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/
#include "widget.h"
#include "singleApplication.h"
#include <QApplication>
#include <QLabel>
#include <QTranslator>
#include <QLockFile>
#include <QDesktopWidget>
#include <X11/Xlib.h> // ought to put this file last

int getScreenWidth() 
{
    Display *disp = XOpenDisplay(NULL);
    Screen *scrn = DefaultScreenOfDisplay(disp);
    if (NULL == scrn) {
        return 0;
    }
    int width = scrn->width;

    if (NULL != disp) {
        XCloseDisplay(disp);
    }
    return width;
}

int main(int argc, char *argv[])
{
    if (getScreenWidth() > 2560) {
        #if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
                QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
                QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
        #endif
    }

    SingleApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon::fromTheme("kylin-scanner", QIcon(":/icon/icon/scanner.png")));

    // For translations with different language environments
    QTranslator translator;
    QString locale = "/usr/share/kylin-scanner/translations/kylin-scanner." + QLocale::system().name();
    MYLOG << locale ;

    translator.load(locale);
    a.installTranslator(&translator);

    if (!a.isRunning()){
        MYLOG << "isRunning = false.";
        Widget w;
        a.w = &w;
        w.show();
        return a.exec();
    }
    return 0;
}
