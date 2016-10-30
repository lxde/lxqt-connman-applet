/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * lxqt-connman-applet - a gui frontend for connman
 *
 * Copyright: 2014-2015 Christian Surlykke
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef AGENT_H
#define AGENT_H

#include <QDebug>
#include <QDBusContext>
#include <QDBusObjectPath>
#include "connmannobject.h"

class Agent : public QObject, public QDBusContext
{
    Q_OBJECT

public:
    explicit Agent();
    void setEntityName(const QString& path, const QString& name);

    void Release();
    void Cancel();
    void ReportError(QDBusObjectPath serviceName, QString errorMessage);
    void ReportPeerError(QDBusObjectPath peerName, QString errorMessage);
    void RequestBrowser(QDBusObjectPath serviceName, QString url);
    QVariantMap RequestInput(QDBusObjectPath serviceName, QVariantMap fields);
    QVariantMap RequestPeerAuthorization(QDBusObjectPath peerName, QVariantMap fields);

signals:
    void operationCanceled();

private:
    QString entityName(QDBusObjectPath entityPath);
    QMap<QString, QString> entityNames;

};

#endif // AGENT_H
