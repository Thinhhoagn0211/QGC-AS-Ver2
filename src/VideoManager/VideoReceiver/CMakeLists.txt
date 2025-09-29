add_library(VideoReceiver
    VideoReceiver.h
)

target_link_libraries(VideoReceiver
	PUBLIC
		Qt5::Core
		Qt5::Network
		qgc
)

target_include_directories(VideoReceiver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(GStreamer)