
add_library(Terrain
    Providers/TerrainQueryCopernicus.cc
    Providers/TerrainQueryCopernicus.h
    Providers/TerrainTileCopernicus.cc
    Providers/TerrainTileCopernicus.h
    TerrainQuery.cc
    TerrainQuery.h
    TerrainQueryInterface.cc
    TerrainQueryInterface.h
    TerrainTile.cc
    TerrainTile.h
    TerrainTileManager.cc
    TerrainTileManager.h
)

target_link_libraries(Terrain
	PUBLIC
		Qt5::Core
		Qt5::Network
		qgc
)

target_include_directories(Terrain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

