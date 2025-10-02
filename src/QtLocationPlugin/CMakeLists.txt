add_subdirectory(Providers)

add_library(QtLocationPlugin
    QGCCacheTile.h
    QGCMapEngine.cpp
    QGCMapEngine.h
    QGCMapEngineManager.cc
    QGCMapEngineManager.h
    QGCMapUrlEngine.cpp
    QGCMapUrlEngine.h
    QGCTile.h
    QGCTileCacheWorker.cpp
    QGCTileCacheWorker.h
    QGCTileSet.h
    QGeoMapReplyQGC.cpp
    QGeoMapReplyQGC.h
    QGeoCodeReplyQGC.cpp
    QGeoCodeReplyQGC.h
	QGeoCodingManagerEngineQGC.cpp
    QGeoCodingManagerEngineQGC.h
    QGeoServiceProviderPluginQGC.cpp
    QGeoServiceProviderPluginQGC.h
    QGeoTiledMappingManagerEngineQGC.cpp
    QGeoTiledMappingManagerEngineQGC.h
    QGeoTileFetcherQGC.cpp
    QGeoTileFetcherQGC.h
    QGCMapEngineData.h
    QGCMapTileSet.cpp
    QGCMapTileSet.h
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
