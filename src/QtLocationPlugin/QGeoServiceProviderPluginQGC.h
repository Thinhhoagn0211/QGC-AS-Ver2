/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtCore/QObject>
#include <QtLocation/QGeoServiceProviderFactory>
#include <QtPlugin>

class QGeoServiceProviderFactoryQGC: public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)
    Q_PLUGIN_METADATA(IID "org.qt-project.qt.geoservice.serviceproviderfactory/5.0" FILE "qgc_maps_plugin.json")

public:
    QGeoCodingManagerEngine*    createGeocodingManagerEngine    (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    QGeoMappingManagerEngine*   createMappingManagerEngine      (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    QGeoRoutingManagerEngine*   createRoutingManagerEngine      (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    QPlaceManagerEngine*        createPlaceManagerEngine        (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
};