cmake_minimum_required(VERSION 3.5)
project(room_emulator)


set(PROJECT_SRCS
)

set(PROJECT_INCS
)


add_library(${PROJECT_NAME} SHARED ${PROJECT_SRCS} ${PROJECT_INCS})

target_include_directories(${PROJECT_NAME} PUBLIC
                          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                          $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}Targets
        ARCHIVE DESTINATION lib COMPONENT install-app
        LIBRARY DESTINATION lib COMPONENT install-app
        RUNTIME DESTINATION bin COMPONENT install-app)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/Room/Emulator
        DESTINATION include/Room/Emulator
        FILES_MATCHING PATTERN "*.h")

export(TARGETS ${PROJECT_NAME} NAMESPACE room::
      APPEND FILE ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Targets.cmake)

file(APPEND
    ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
"set(ROOM_RGBDSLAM_LIBRARIES \${ROOM_RGBDSLAM_LIBRARIES} ${PROJECT_NAME})\n")
