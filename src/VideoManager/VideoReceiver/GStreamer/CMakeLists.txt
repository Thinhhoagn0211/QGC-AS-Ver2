set(EXTRA_SOURCES)
set(EXTRA_LIBRARIES)

if (GST_FOUND)
    set(EXTRA_SOURCES
    	gstqgc/gstqgc.cc
        gstqgc/gstqgcelement.cc
    	gstqgc/gstqgcelements.h
    	gstqgc/gstqgcvideosinkbin.cc
        gstqgc/gstqgcvideosinkbin.h
    	GStreamer.cc
    	GStreamer.h
        GStreamerHelpers.cc
        GStreamerHelpers.h
    	GstVideoReceiver.cc
    	GstVideoReceiver.h
        VideoItemStub.h
    )
   
    set(EXTRA_LIBRARIES qmlglsink ${GST_LINK_LIBRARIES})
endif()

add_library(GStreamer
    ${EXTRA_SOURCES}
)

target_link_libraries(GStreamer
    PUBLIC
        Qt5::Multimedia
        Qt5::OpenGL
        Qt5::Quick
        ${EXTRA_LIBRARIES}
        Settings
)

target_include_directories(GStreamer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
if (GST_FOUND)
    target_include_directories(GStreamer PUBLIC ${GST_INCLUDE_DIRS})
endif()
