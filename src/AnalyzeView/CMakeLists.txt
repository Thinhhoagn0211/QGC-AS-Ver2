add_library(AnalyzeView
	ExifParser.cc
	ExifParser.h
	GeoTagController.cc
	GeoTagController.h
	GeoTagWorker.cc
	GeoTagWorker.h
	LogDownloadController.cc
	LogDownloadController.h
	LogEntry.cc
	LogEntry.h
	MAVLinkChartController.cc
	MAVLinkChartController.h
	MAVLinkConsoleController.cc
	MAVLinkConsoleController.h
	MAVLinkInspectorController.cc
	MAVLinkInspectorController.h
	MAVLinkMessage.cc
	MAVLinkMessage.h
	MAVLinkMessageField.cc
	MAVLinkMessageField.h
	MAVLinkSystem.cc
	MAVLinkSystem.h
	PX4LogParser.cc
	PX4LogParser.h
	ULogParser.cc
	ULogParser.h

	${EXTRA_SRC}
)

add_custom_target(AnalyzeViewQml
	SOURCES
        AnalyzeView.qml
        GeoTagPage.qml
        LogDownloadPage.qml
        MAVLinkConsolePage.qml
        MAVLinkInspectorPage.qml
        VibrationPage.qml
)

target_link_libraries(AnalyzeView
	PRIVATE
		qgc

	PUBLIC
		Qt5::Charts
		Qt5::Location
		Qt5::SerialPort
		Qt5::TextToSpeech
		Qt5::Widgets
)

target_include_directories(AnalyzeView INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

