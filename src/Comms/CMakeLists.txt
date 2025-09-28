add_subdirectory(AirLink)

add_library(Comms
	AirLink/AirLinkLink.cc
	AirLink/AirLinkLink.h
	AirLink/AirLinkManager.cc
	AirLink/AirLinkManager.h


	MockLink/MockConfiguration.cc
	MockLink/MockConfiguration.h
	MockLink/MockLink.cc
	MockLink/MockLink.h
	MockLink/MockLinkFTP.cc
	MockLink/MockLinkFTP.h
	MockLink/MockLinkMissionItemHandler.cc
	MockLink/MockLinkMissionItemHandler.h
	MockLink/MockLinkWorker.cc
	MockLink/MockLinkWorker.h

	BluetoothLink.cc
	BluetoothLink.h
	LinkConfiguration.cc
	LinkConfiguration.h
	LinkInterface.cc
	LinkInterface.h
	LinkManager.cc
	LinkManager.h
	LogReplayLink.cc
	LogReplayLink.h
    LogReplayLinkController.cc
    LogReplayLinkController.h
	MAVLinkProtocol.cc
	MAVLinkProtocol.h
	QGCSerialPortInfo.cc
	QGCSerialPortInfo.h
	SerialLink.cc
	SerialLink.h
	TCPLink.cc
	TCPLink.h
	UdpIODevice.cc
	UdpIODevice.h
	UDPLink.cc
	UDPLink.h


	${EXTRA_SRC}
)

target_link_libraries(Comms
	PUBLIC
		qgc
		Qt5::Location
		Qt5::SerialPort
		Qt5::Test
		Qt5::TextToSpeech
		Qt5::Widgets
		qmdnsengine
)

target_include_directories(Comms INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

qt_add_resources(${CMAKE_PROJECT_NAME} json_mavlink_camera
    PREFIX "/json"
    FILES USBBoardInfo.json
)
