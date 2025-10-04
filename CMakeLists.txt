cmake_minimum_required(VERSION 3.15)

project(torchcs-raknet VERSION 4.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(RAKNET_ENABLE_DLL "Build DLL instead of static library" OFF)

if(WIN32)
    set(RAKNET_SYSTEM_LIBS ws2_32)
else()
    set(RAKNET_SYSTEM_LIBS pthread)
endif()

set(RAKNET_SOURCES
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
    src/DynDNS.cpp
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
    src/LinuxStrings.cpp
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
    src/PS4Includes.cpp
    src/PacketConsoleLogger.cpp
    src/PacketFileLogger.cpp
    src/PacketLogger.cpp
    src/PacketOutputWindowLogger.cpp
    src/PacketizedTCP.cpp
    src/PluginInterface2.cpp
    src/RPC4Plugin.cpp
    src/Rackspace.cpp
    src/RakMemoryOverride.cpp
    src/RakNetCommandParser.cpp
    src/RakNetSocket.cpp
    src/RakNetSocket2.cpp
    src/RakNetSocket2_360_720.cpp
    src/RakNetSocket2_Berkley.cpp
    src/RakNetSocket2_Berkley_NativeClient.cpp
    src/RakNetSocket2_NativeClient.cpp
    src/RakNetSocket2_PS3_PS4.cpp
    src/RakNetSocket2_PS4.cpp
    src/RakNetSocket2_Vita.cpp
    src/RakNetSocket2_WindowsStore8.cpp
    src/RakNetSocket2_Windows_Linux.cpp
    src/RakNetSocket2_Windows_Linux_360.cpp
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
    src/VitaIncludes.cpp
    src/WSAStartupSingleton.cpp
    src/_FindFirst.cpp
    src/gettimeofday.cpp
)

if(RAKNET_ENABLE_DLL)
    add_library(torchcs_raknet SHARED ${RAKNET_SOURCES})
    target_compile_definitions(torchcs_raknet PRIVATE _RAKNET_DLL)
else()
    add_library(torchcs_raknet STATIC ${RAKNET_SOURCES})
    target_compile_definitions(torchcs_raknet PRIVATE _RAKNET_LIB)
endif()

add_library(RakNet::RakNet ALIAS torchcs_raknet)

target_include_directories(torchcs_raknet PUBLIC include)

if(WIN32)
    target_compile_definitions(torchcs_raknet PRIVATE WIN32 _CRT_SECURE_NO_DEPRECATE _CRT_NONSTDC_NO_DEPRECATE)
    target_compile_options(torchcs_raknet PRIVATE /W3 /GR- /GS-)
endif()

target_link_libraries(torchcs_raknet PRIVATE ${RAKNET_SYSTEM_LIBS})