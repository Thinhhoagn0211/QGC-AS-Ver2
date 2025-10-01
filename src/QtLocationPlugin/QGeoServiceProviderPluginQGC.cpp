/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "QGeoServiceProviderPluginQGC.h"
#include "QGeoTiledMappingManagerEngineQGC.h"
#include "QGeoCodingManagerEngineQGC.h"

#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

Q_EXTERN_C Q_DECL_EXPORT const char *qt_plugin_query_metadata();
Q_EXTERN_C Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance();

//-----------------------------------------------------------------------------
const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_QGeoServiceProviderFactoryQGC()
{
    QT_PREPEND_NAMESPACE(QStaticPlugin) plugin = { qt_plugin_instance, qt_plugin_query_metadata};
    return plugin;
}

//-----------------------------------------------------------------------------
QGeoCodingManagerEngine*
QGeoServiceProviderFactoryQGC::createGeocodingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return new QGeoCodingManagerEngineQGC(parameters, error, errorString);
}

//-----------------------------------------------------------------------------
QGeoMappingManagerEngine*
QGeoServiceProviderFactoryQGC::createMappingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return new QGeoTiledMappingManagerEngineQGC(parameters, error, errorString);
}

//-----------------------------------------------------------------------------
QGeoRoutingManagerEngine*
QGeoServiceProviderFactoryQGC::createRoutingManagerEngine(
    const QVariantMap &, QGeoServiceProvider::Error *, QString *) const
{
    // Not implemented for QGC
    return nullptr;
}

//-----------------------------------------------------------------------------
QPlaceManagerEngine*
QGeoServiceProviderFactoryQGC::createPlaceManagerEngine(
    const QVariantMap &, QGeoServiceProvider::Error *, QString *) const
{
    // Not implemented for QGC
    return nullptr;
}
