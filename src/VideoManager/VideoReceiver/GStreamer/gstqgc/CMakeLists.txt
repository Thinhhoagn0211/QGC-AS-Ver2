add_library(gstqgc
    gstqgc.cc
    gstqgcelement.cc
    gstqgcelements.h
    gstqgcvideosinkbin.cc
    gstqgcvideosinkbin.h
)

target_include_directories(gstqgc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
