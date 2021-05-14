# Install script for directory: /mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release" TYPE EXECUTABLE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build/registerNode")
  if(EXISTS "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode"
         OLD_RPATH "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../../bin/comm.datalayer/linux-gcc-aarch64/release:/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../../bin/zmq/linux-gcc-aarch64/release:/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/registerNode")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib/libcomm_datalayer.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../..//bin/comm.datalayer//linux-gcc-aarch64/release/libcomm_datalayer.so")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib/libzmq.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../..//bin/zmq//linux-gcc-aarch64/release/libzmq.so")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib/libzmq.so.5")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../..//bin/zmq//linux-gcc-aarch64/release/libzmq.so.5")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib/libplctag.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/lib//libplctag.so")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib/libplctag.so.2.3")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/linux-gcc-aarch64/Release/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/lib//libplctag.so.2.3")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build" TYPE EXECUTABLE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build/registerNode")
  if(EXISTS "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode"
         OLD_RPATH "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../../bin/comm.datalayer/linux-gcc-aarch64/release:/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../../bin/zmq/linux-gcc-aarch64/release:/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/registerNode")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib/libcomm_datalayer.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../..//bin/comm.datalayer//linux-gcc-aarch64/release/libcomm_datalayer.so")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib/libzmq.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../..//bin/zmq//linux-gcc-aarch64/release/libzmq.so")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib/libzmq.so.5")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/../..//bin/zmq//linux-gcc-aarch64/release/libzmq.so.5")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib/libplctag.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/lib//libplctag.so")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib/libplctag.so.2.3")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/generated/build/usr/lib" TYPE FILE FILES "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/lib//libplctag.so.2.3")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/e/ctrlX Development/public/samples-cpp/datalayer.register.node/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
