
add_library(QtLocationPlugin
    QGCCachedTileSet.cpp
    QGCMapEngine.cpp
    QGCMapEngineManager.cc
    QGCMapUrlEngine.cpp
    QGCTileCacheWorker.cpp
    QGeoFileTileCacheQGC.cpp
    QGeoMapReplyQGC.cpp
    QGeoServiceProviderPluginQGC.cpp
    QGeoTiledMappingManagerEngineQGC.cpp
    QGeoTiledMapQGC.cpp
    QGeoTileFetcherQGC.cpp

    Providers/BingMapProvider.cpp
    Providers/ElevationMapProvider.cpp
    Providers/EsriMapProvider.cpp
    Providers/GenericMapProvider.cpp
    Providers/GoogleMapProvider.cpp
    Providers/MapboxMapProvider.cpp
    Providers/MapProvider.cpp
)

target_link_libraries(QtLocationPlugin
	PUBLIC
		Qt5::Location
		Qt5::Sql

		qgc
)

target_include_directories(QtLocationPlugin
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
		QMLControl
)
