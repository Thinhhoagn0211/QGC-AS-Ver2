/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtNetwork/QNetworkReply>
#include <QtLocation/private/qgeotiledmapreply_p.h>
#include <QTimer>

#include "QGCMapEngineData.h"

class QGeoTiledMapReplyQGC : public QGeoTiledMapReply
{
    Q_OBJECT
public:
    QGeoTiledMapReplyQGC(QNetworkAccessManager*  networkManager, const QNetworkRequest& request, const QGeoTileSpec &spec, QObject *parent = 0);
    ~QGeoTiledMapReplyQGC();
    void abort();

signals:
    void terrainDone            (QByteArray responseBytes, QNetworkReply::NetworkError error);

private slots:
    void networkReplyFinished   ();
    void networkReplyError      (QNetworkReply::NetworkError error);
    void cacheReply             (QGCCacheTile* tile);
    void cacheError             (QGCMapTask::TaskType type, QString errorString);
    void timeout                ();

private:
    void _clearReply            ();
    void setIgnoreSSLErrorsIfNeeded(QNetworkReply& networkReply);

private:
    QNetworkReply*          _reply;
    QNetworkRequest         _request;
    QNetworkAccessManager*  _networkManager;
    QByteArray              _badMapbox;
    QByteArray              _badTile;
    QTimer                  _timer;
    static QByteArray       _bingNoTileImage;
    static int              _requestCount;
};
