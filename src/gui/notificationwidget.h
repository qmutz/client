/*
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef NOTIFICATIONWIDGET_H
#define NOTIFICATIONWIDGET_H

#include <QWidget>

#include "activitywidget.h"

#include "ui_notificationwidget.h"

namespace OCC {

class NotificationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NotificationWidget(QWidget *parent = 0);

    void setAccountName( const QString& name );

signals:
    void sendNotificationRequest( const QString&, const QString& link, const QString& verb);

public slots:
     void setActivity(const Activity& activity);
     void slotNotificationRequestFinished(int statusCode);

private slots:
     void slotButtonClicked();

private:
    Ui_NotificationWidget _ui;
    Activity _myActivity;
    QList<QPushButton*> _buttons;
    QString _accountName;
    QProgressIndicator *_progressIndi;
};

}

#endif // NOTIFICATIONWIDGET_H
