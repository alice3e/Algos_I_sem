project(SortingAlgos_lib)

set(HEADER_FILES
        Radix_MSD_VS_std_sort.h
)

set(SOURCE_FILES
        Radix_MSD_VS_std_sort.cpp
        Radix_MSD_VS_std_sort.cpp
)

add_library(SortingAlgos_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})