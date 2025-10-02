/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "QGCMapEngine.h"
#include "QGeoTileFetcherQGC.h"
#include "QGeoMapReplyQGC.h"

#include <QtCore/QLocale>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>

//-----------------------------------------------------------------------------
QGeoTileFetcherQGC::QGeoTileFetcherQGC(QGeoTiledMappingManagerEngine *parent)
    : QGeoTileFetcher(parent)
    , _networkManager(new QNetworkAccessManager(this))
{
    //-- Check internet status every 30 seconds or so
    connect(&_timer, &QTimer::timeout, this, &QGeoTileFetcherQGC::timeout);
    _timer.setSingleShot(false);
    _timer.start(30000);
}

//-----------------------------------------------------------------------------
QGeoTileFetcherQGC::~QGeoTileFetcherQGC()
{

}

//-----------------------------------------------------------------------------
QGeoTiledMapReply*
QGeoTileFetcherQGC::getTileImage(const QGeoTileSpec &spec)
{
    //-- Build URL
    QNetworkRequest request = getQGCMapEngine()->urlFactory()->getTileURL(spec.mapId(), spec.x(), spec.y(), spec.zoom(), _networkManager);
    if ( ! request.url().isEmpty() ) {
        return new QGeoTiledMapReplyQGC(_networkManager, request, spec);
    }
    else {
        return nullptr;
    }
}

//-----------------------------------------------------------------------------
void
QGeoTileFetcherQGC::timeout()
{
    getQGCMapEngine()->testInternet();
}