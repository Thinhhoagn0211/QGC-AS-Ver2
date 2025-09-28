include_directories(Drivers/src)

add_library(GPS
	Drivers/src/ashtech.cpp
	Drivers/src/gps_helper.cpp
	Drivers/src/mtk.cpp
	Drivers/src/rtcm.cpp
	Drivers/src/sbf.cpp
	Drivers/src/ubx.cpp
	GPSManager.cc
	GPSProvider.cc
	RTCMMavlink.cc
)

target_link_libraries(GPS
	Qt5::Core
	Qt5::Location
	Qt5::SerialPort
	Qt5::Svg
	Qt5::TextToSpeech
	Vehicle
	MAVLink
	qgc
)

target_include_directories(GPS INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

