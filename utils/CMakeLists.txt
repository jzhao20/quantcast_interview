add_library(ProcessFiles ProcessFiles.cxx)
target_include_directories(ProcessFiles
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                            )