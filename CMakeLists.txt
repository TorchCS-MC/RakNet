cmake_minimum_required(VERSION 3.15)
project(torchcs-raknet VERSION 4.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(RAKNET_ENABLE_DLL "Build DLL/shared library instead of static" OFF)
option(RAKNET_ENABLE_ASAN "Enable Address/UB sanitizers in Debug" OFF)

find_package(Threads REQUIRED)

set(RAKNET_SOURCES_COMMON
    src/Base64Encoder.cpp
    src/BitStream.cpp
    src/CCRakNetSlidingWindow.cpp
    src/CCRakNetUDT.cpp
    src/CheckSum.cpp
    src/CloudClient.cpp
    src/CloudCommon.cpp
    src/CloudServer.cpp
    src/CommandParserInterface.cpp
    src/ConnectionGraph2.cpp
    src/ConsoleServer.cpp
    src/DR_SHA1.cpp
    src/DS_BytePool.cpp
    src/DS_ByteQueue.cpp
    src/DS_HuffmanEncodingTree.cpp
    src/DS_Table.cpp
    src/DataCompressor.cpp
    src/DirectoryDeltaTransfer.cpp
    src/EmailSender.cpp
    src/EpochTimeToString.cpp
    src/FileList.cpp
    src/FileListTransfer.cpp
    src/FileOperations.cpp
    src/FormatString.cpp
    src/FullyConnectedMesh2.cpp
    src/GetTime.cpp
    src/Getche.cpp
    src/Gets.cpp
    src/GridSectorizer.cpp
    src/HTTPConnection.cpp
    src/HTTPConnection2.cpp
    src/IncrementalReadInterface.cpp
    src/Itoa.cpp
    src/LocklessTypes.cpp
    src/LogCommandParser.cpp
    src/MessageFilter.cpp
    src/NatPunchthroughClient.cpp
    src/NatPunchthroughServer.cpp
    src/NatTypeDetectionClient.cpp
    src/NatTypeDetectionCommon.cpp
    src/NatTypeDetectionServer.cpp
    src/NetworkIDManager.cpp
    src/NetworkIDObject.cpp
    src/PacketConsoleLogger.cpp
    src/PacketFileLogger.cpp
    src/PacketLogger.cpp
    src/PacketizedTCP.cpp
    src/PluginInterface2.cpp
    src/RPC4Plugin.cpp
    src/RakMemoryOverride.cpp
    src/RakNetCommandParser.cpp
    src/RakNetStatistics.cpp
    src/RakNetTransport2.cpp
    src/RakNetTypes.cpp
    src/RakPeer.cpp
    src/RakSleep.cpp
    src/RakString.cpp
    src/RakThread.cpp
    src/RakWString.cpp
    src/Rand.cpp
    src/RandSync.cpp
    src/ReadyEvent.cpp
    src/RelayPlugin.cpp
    src/ReliabilityLayer.cpp
    src/ReplicaManager3.cpp
    src/Router2.cpp
    src/SecureHandshake.cpp
    src/SendToThread.cpp
    src/SignaledEvent.cpp
    src/SimpleMutex.cpp
    src/SocketLayer.cpp
    src/StatisticsHistory.cpp
    src/StringCompressor.cpp
    src/StringTable.cpp
    src/SuperFastHash.cpp
    src/TCPInterface.cpp
    src/TableSerializer.cpp
    src/TeamBalancer.cpp
    src/TeamManager.cpp
    src/TelnetTransport.cpp
    src/ThreadsafePacketLogger.cpp
    src/TwoWayAuthentication.cpp
    src/UDPForwarder.cpp
    src/UDPProxyClient.cpp
    src/UDPProxyCoordinator.cpp
    src/UDPProxyServer.cpp
    src/VariableDeltaSerializer.cpp
    src/VariableListDeltaTracker.cpp
    src/VariadicSQLParser.cpp
)

set(RAKNET_SOURCES_PLATFORM "")

if (WIN32)
    list(APPEND RAKNET_SOURCES_PLATFORM
        src/PS4Includes.cpp
        src/RakNetSocket2.cpp
        src/RakNetSocket2_360_720.cpp
        src/RakNetSocket2_NativeClient.cpp
        src/RakNetSocket2_PS3_PS4.cpp
        src/RakNetSocket2_PS4.cpp
        src/RakNetSocket2_Vita.cpp
        src/RakNetSocket2_WindowsStore8.cpp
        src/RakNetSocket2_Windows_Linux.cpp
        src/RakNetSocket2_Windows_Linux_360.cpp
        src/VitaIncludes.cpp
        src/WSAStartupSingleton.cpp
        src/_FindFirst.cpp
    )
else()
    list(APPEND RAKNET_SOURCES_PLATFORM
        src/LinuxStrings.cpp
        src/gettimeofday.cpp
        src/RakNetSocket2.cpp
        src/RakNetSocket2_Berkley.cpp
        src/RakNetSocket2_Berkley_NativeClient.cpp
        src/RakNetSocket2_Windows_Linux.cpp
    )
endif()

set(RAKNET_SOURCES ${RAKNET_SOURCES_COMMON} ${RAKNET_SOURCES_PLATFORM})

if (RAKNET_ENABLE_DLL)
    add_library(torchcs_raknet SHARED ${RAKNET_SOURCES})
    target_compile_definitions(torchcs_raknet PRIVATE _RAKNET_DLL)
else()
    add_library(torchcs_raknet STATIC ${RAKNET_SOURCES})
    target_compile_definitions(torchcs_raknet PRIVATE _RAKNET_LIB)
endif()

add_library(torchcs::RakNet ALIAS torchcs_raknet)

target_include_directories(torchcs_raknet
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/DependentExtensions>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

if (MSVC)
    target_compile_definitions(torchcs_raknet PRIVATE WIN32 _CRT_SECURE_NO_DEPRECATE _CRT_NONSTDC_NO_DEPRECATE WIN32_LEAN_AND_MEAN)
    target_compile_options(torchcs_raknet PRIVATE /W4 /permissive- /Zc:__cplusplus)
else()
    target_compile_definitions(torchcs_raknet PRIVATE _GNU_SOURCE _FILE_OFFSET_BITS=64)
    target_compile_options(torchcs_raknet PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wnon-virtual-dtor -fno-strict-aliasing)
    if (RAKNET_ENABLE_ASAN AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(torchcs_raknet PRIVATE -fsanitize=address,undefined)
        target_link_options(torchcs_raknet PRIVATE -fsanitize=address,undefined)
    endif()
endif()

if (WIN32)
    target_link_libraries(torchcs_raknet PRIVATE ws2_32 bcrypt iphlpapi)
else()
    target_link_libraries(torchcs_raknet PRIVATE Threads::Threads)
endif()
