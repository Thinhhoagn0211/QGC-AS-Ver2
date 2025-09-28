
add_library(Geo
    GeoJsonHelper.cc
    GeoJsonHelper.h
    KMLDomDocument.cc
    KMLDomDocument.h
    KMLHelper.cc
    KMLHelper.h
    QGCGeo.cc
    QGCGeo.h
    ShapeFileHelper.cc
    ShapeFileHelper.h
    SHPFileHelper.cc
    SHPFileHelper.h
)

target_link_libraries(Geo
	PUBLIC
		qgc
)

target_include_directories(Geo
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)

