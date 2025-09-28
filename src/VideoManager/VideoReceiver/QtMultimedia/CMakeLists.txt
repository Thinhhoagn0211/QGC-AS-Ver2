add_library(QtMultimedia
    QtMultimediaReceiver.cc
    QtMultimediaReceiver.h
    UVCReceiver.cc
    UVCReceiver.h
)

target_link_libraries(QtMultimedia
	PUBLIC
		Qt5::Core
		Qt5::Network
		qgc
)

target_include_directories(QtMultimedia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(QGC_ENABLE_QT_VIDEOSTREAMING)
    target_compile_definitions(QtMultimedia PUBLIC QGC_QT_STREAMING)
endif()

if(NOT QGC_ENABLE_UVC)
    target_compile_definitions(QtMultimedia PUBLIC QGC_DISABLE_UVC)
endif()
