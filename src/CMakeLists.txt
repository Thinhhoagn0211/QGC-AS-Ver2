add_library(QGroundControlModule STATIC)

set_source_files_properties(UI/MainWindow.qml PROPERTIES QT_RESOURCE_ALIAS MainWindow.qml)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	${Qt5Location_PRIVATE_INCLUDE_DIRS}
	VideoManager
)

set(EXTRA_SRC)

add_library(qgc

	${EXTRA_SRC}

	main.cc
	QGCApplication.cc
	QGCApplication.h
	RunGuard.cc
    RunGuard.cc
)

set_source_files_properties(QGCApplication.cc PROPERTIES COMPILE_DEFINITIONS APP_VERSION_STR="${APP_VERSION_STR}")

add_subdirectory(ADSB)
add_subdirectory(AnalyzeView)
add_subdirectory(Android)
add_subdirectory(API)
add_subdirectory(AutoPilotPlugins)
add_subdirectory(Camera)
add_subdirectory(Comms)
add_subdirectory(FactSystem)
add_subdirectory(FirmwarePlugin)
add_subdirectory(FlightDisplay)
add_subdirectory(FlightMap)
add_subdirectory(FollowMe)
add_subdirectory(Gimbal)
add_subdirectory(GPS)
add_subdirectory(Joystick)
add_subdirectory(MAVLink)
add_subdirectory(MissionManager)
add_subdirectory(PositionManager)
add_subdirectory(QmlControls)
add_subdirectory(QtLocationPlugin)
add_subdirectory(Settings)
add_subdirectory(Terrain)
add_subdirectory(UI)
add_subdirectory(Utilities)
add_subdirectory(Vehicle)
add_subdirectory(VideoManager)
add_subdirectory(Viewer3D)

target_link_libraries(qgc
	PRIVATE
		shp
		Qt5::QuickControls2

	PUBLIC
		Qt5::QuickWidgets
		Qt5::Widgets

		ADSB
		AnalyzeView
		Android
        API
		AutoPilotPlugins
        Camera
		Comms
		FactSystem
        FirmwarePlugin
        FlightDisplay
        FlightMap
        FollowMe
        Gimbal
        GPS
		MAVLink
        Joystick
        MissionManager
        PositionManager
        QmlControls
        QtLocationPlugin
        Settings
        Terrain
        UI
        Utilities
		Geo
		LibEvents
		FactGroups
        Vehicle
        VideoManager
        Viewer3D
		z # zlib
)

