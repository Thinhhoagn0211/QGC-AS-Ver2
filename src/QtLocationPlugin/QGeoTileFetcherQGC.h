/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QTimer>
#include "QGCMapUrlEngine.h"

class QGeoTiledMappingManagerEngine;
class QNetworkAccessManager;

class QGeoTileFetcherQGC : public QGeoTileFetcher
{
    Q_OBJECT
public:
    explicit QGeoTileFetcherQGC             (QGeoTiledMappingManagerEngine *parent = 0);
    ~QGeoTileFetcherQGC();
public slots:
    void                    timeout         ();
private:
    QGeoTiledMapReply*      getTileImage    (const QGeoTileSpec &spec);
private:
    QNetworkAccessManager*  _networkManager;
    QTimer                  _timer;
};
