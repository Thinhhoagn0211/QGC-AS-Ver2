/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/private/qgeotiledmap_p.h>
#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

class QGeoTiledMapQGC : public QGeoTiledMap
{
    Q_OBJECT
public:
    QGeoTiledMapQGC(QGeoTiledMappingManagerEngine *engine, QObject *parent = 0);
};

class QGeoTileFetcherQGC;

class QGeoTiledMappingManagerEngineQGC : public QGeoTiledMappingManagerEngine
{
    Q_OBJECT
public:
    QGeoTiledMappingManagerEngineQGC(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString);
    ~QGeoTiledMappingManagerEngineQGC();
    QGeoMap *createMap();

private:
    void _setCache(const QVariantMap &parameters);
};