cmake_minimum_required(VERSION 3.16)

project(torchcs-raknet VERSION 4.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(RAKNET_ENABLE_SAMPLES "Build example programs" ON)
option(RAKNET_ENABLE_DLL "Build DLL instead of static library" OFF)

set(RAKNET_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RAKNET_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes/raknet)

if(WIN32)
    set(RAKNET_SYSTEM_LIBS ws2_32)
else()
    set(RAKNET_SYSTEM_LIBS pthread)
endif()

set(RAKNET_SOURCES
    ${RAKNET_SOURCE_DIR}/Base64Encoder.cpp
    ${RAKNET_SOURCE_DIR}/BitStream.cpp
    ${RAKNET_SOURCE_DIR}/CCRakNetSlidingWindow.cpp
    ${RAKNET_SOURCE_DIR}/CCRakNetUDT.cpp
    ${RAKNET_SOURCE_DIR}/CheckSum.cpp
    ${RAKNET_SOURCE_DIR}/CloudClient.cpp
    ${RAKNET_SOURCE_DIR}/CloudCommon.cpp
    ${RAKNET_SOURCE_DIR}/CloudServer.cpp
    ${RAKNET_SOURCE_DIR}/CommandParserInterface.cpp
    ${RAKNET_SOURCE_DIR}/ConnectionGraph2.cpp
    ${RAKNET_SOURCE_DIR}/ConsoleServer.cpp
    ${RAKNET_SOURCE_DIR}/DR_SHA1.cpp
    ${RAKNET_SOURCE_DIR}/DS_BytePool.cpp
    ${RAKNET_SOURCE_DIR}/DS_ByteQueue.cpp
    ${RAKNET_SOURCE_DIR}/DS_HuffmanEncodingTree.cpp
    ${RAKNET_SOURCE_DIR}/DS_Table.cpp
    ${RAKNET_SOURCE_DIR}/DataCompressor.cpp
    ${RAKNET_SOURCE_DIR}/DirectoryDeltaTransfer.cpp
    ${RAKNET_SOURCE_DIR}/DynDNS.cpp
    ${RAKNET_SOURCE_DIR}/EmailSender.cpp
    ${RAKNET_SOURCE_DIR}/EpochTimeToString.cpp
    ${RAKNET_SOURCE_DIR}/FileList.cpp
    ${RAKNET_SOURCE_DIR}/FileListTransfer.cpp
    ${RAKNET_SOURCE_DIR}/FileOperations.cpp
    ${RAKNET_SOURCE_DIR}/FormatString.cpp
    ${RAKNET_SOURCE_DIR}/FullyConnectedMesh2.cpp
    ${RAKNET_SOURCE_DIR}/GetTime.cpp
    ${RAKNET_SOURCE_DIR}/Getche.cpp
    ${RAKNET_SOURCE_DIR}/Gets.cpp
    ${RAKNET_SOURCE_DIR}/GridSectorizer.cpp
    ${RAKNET_SOURCE_DIR}/HTTPConnection.cpp
    ${RAKNET_SOURCE_DIR}/HTTPConnection2.cpp
    ${RAKNET_SOURCE_DIR}/IncrementalReadInterface.cpp
    ${RAKNET_SOURCE_DIR}/Itoa.cpp
    ${RAKNET_SOURCE_DIR}/LinuxStrings.cpp
    ${RAKNET_SOURCE_DIR}/LocklessTypes.cpp
    ${RAKNET_SOURCE_DIR}/LogCommandParser.cpp
    ${RAKNET_SOURCE_DIR}/MessageFilter.cpp
    ${RAKNET_SOURCE_DIR}/NatPunchthroughClient.cpp
    ${RAKNET_SOURCE_DIR}/NatPunchthroughServer.cpp
    ${RAKNET_SOURCE_DIR}/NatTypeDetectionClient.cpp
    ${RAKNET_SOURCE_DIR}/NatTypeDetectionCommon.cpp
    ${RAKNET_SOURCE_DIR}/NatTypeDetectionServer.cpp
    ${RAKNET_SOURCE_DIR}/NetworkIDManager.cpp
    ${RAKNET_SOURCE_DIR}/NetworkIDObject.cpp
    ${RAKNET_SOURCE_DIR}/PS4Includes.cpp
    ${RAKNET_SOURCE_DIR}/PacketConsoleLogger.cpp
    ${RAKNET_SOURCE_DIR}/PacketFileLogger.cpp
    ${RAKNET_SOURCE_DIR}/PacketLogger.cpp
    ${RAKNET_SOURCE_DIR}/PacketOutputWindowLogger.cpp
    ${RAKNET_SOURCE_DIR}/PacketizedTCP.cpp
    ${RAKNET_SOURCE_DIR}/PluginInterface2.cpp
    ${RAKNET_SOURCE_DIR}/RPC4Plugin.cpp
    ${RAKNET_SOURCE_DIR}/Rackspace.cpp
    ${RAKNET_SOURCE_DIR}/RakMemoryOverride.cpp
    ${RAKNET_SOURCE_DIR}/RakNetCommandParser.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_360_720.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_Berkley.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_Berkley_NativeClient.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_NativeClient.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_PS3_PS4.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_PS4.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_Vita.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_WindowsStore8.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_Windows_Linux.cpp
    ${RAKNET_SOURCE_DIR}/RakNetSocket2_Windows_Linux_360.cpp
    ${RAKNET_SOURCE_DIR}/RakNetStatistics.cpp
    ${RAKNET_SOURCE_DIR}/RakNetTransport2.cpp
    ${RAKNET_SOURCE_DIR}/RakNetTypes.cpp
    ${RAKNET_SOURCE_DIR}/RakPeer.cpp
    ${RAKNET_SOURCE_DIR}/RakSleep.cpp
    ${RAKNET_SOURCE_DIR}/RakString.cpp
    ${RAKNET_SOURCE_DIR}/RakThread.cpp
    ${RAKNET_SOURCE_DIR}/RakWString.cpp
    ${RAKNET_SOURCE_DIR}/Rand.cpp
    ${RAKNET_SOURCE_DIR}/RandSync.cpp
    ${RAKNET_SOURCE_DIR}/ReadyEvent.cpp
    ${RAKNET_SOURCE_DIR}/RelayPlugin.cpp
    ${RAKNET_SOURCE_DIR}/ReliabilityLayer.cpp
    ${RAKNET_SOURCE_DIR}/ReplicaManager3.cpp
    ${RAKNET_SOURCE_DIR}/Router2.cpp
    ${RAKNET_SOURCE_DIR}/SecureHandshake.cpp
    ${RAKNET_SOURCE_DIR}/SendToThread.cpp
    ${RAKNET_SOURCE_DIR}/SignaledEvent.cpp
    ${RAKNET_SOURCE_DIR}/SimpleMutex.cpp
    ${RAKNET_SOURCE_DIR}/SocketLayer.cpp
    ${RAKNET_SOURCE_DIR}/StatisticsHistory.cpp
    ${RAKNET_SOURCE_DIR}/StringCompressor.cpp
    ${RAKNET_SOURCE_DIR}/StringTable.cpp
    ${RAKNET_SOURCE_DIR}/SuperFastHash.cpp
    ${RAKNET_SOURCE_DIR}/TCPInterface.cpp
    ${RAKNET_SOURCE_DIR}/TableSerializer.cpp
    ${RAKNET_SOURCE_DIR}/TeamBalancer.cpp
    ${RAKNET_SOURCE_DIR}/TeamManager.cpp
    ${RAKNET_SOURCE_DIR}/TelnetTransport.cpp
    ${RAKNET_SOURCE_DIR}/ThreadsafePacketLogger.cpp
    ${RAKNET_SOURCE_DIR}/TwoWayAuthentication.cpp
    ${RAKNET_SOURCE_DIR}/UDPForwarder.cpp
    ${RAKNET_SOURCE_DIR}/UDPProxyClient.cpp
    ${RAKNET_SOURCE_DIR}/UDPProxyCoordinator.cpp
    ${RAKNET_SOURCE_DIR}/UDPProxyServer.cpp
    ${RAKNET_SOURCE_DIR}/VariableDeltaSerializer.cpp
    ${RAKNET_SOURCE_DIR}/VariableListDeltaTracker.cpp
    ${RAKNET_SOURCE_DIR}/VariadicSQLParser.cpp
    ${RAKNET_SOURCE_DIR}/VitaIncludes.cpp
    ${RAKNET_SOURCE_DIR}/WSAStartupSingleton.cpp
    ${RAKNET_SOURCE_DIR}/_FindFirst.cpp
    ${RAKNET_SOURCE_DIR}/gettimeofday.cpp
)

if(RAKNET_ENABLE_DLL)
    add_library(torchcs_raknet SHARED ${RAKNET_SOURCES})
    target_compile_definitions(torchcs_raknet PRIVATE _RAKNET_DLL)
else()
    add_library(torchcs_raknet STATIC ${RAKNET_SOURCES})
    target_compile_definitions(torchcs_raknet PRIVATE _RAKNET_LIB)
endif()

target_include_directories(torchcs_raknet PUBLIC
    ${RAKNET_INCLUDE_DIR}
)

if(WIN32)
    target_compile_definitions(torchcs_raknet PRIVATE
        WIN32
        _CRT_SECURE_NO_DEPRECATE
        _CRT_NONSTDC_NO_DEPRECATE
    )
    target_compile_options(torchcs_raknet PRIVATE /W3 /GR- /GS-)
endif()

target_link_libraries(torchcs_raknet PRIVATE ${RAKNET_SYSTEM_LIBS})

if(RAKNET_ENABLE_SAMPLES AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/samples/CMakeLists.txt")
    add_subdirectory(samples)
endif()
