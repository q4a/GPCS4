cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
cmake_policy(VERSION 3.2)

project(GPCS4 LANGUAGES CXX C)

include(${PROJECT_SOURCE_DIR}/cmake/utils.cmake)

add_subdirectory(3rdParty/Zydis)
add_subdirectory(3rdParty/rtaudio)

add_definitions(-DGPCS4_DEBUG -DGPCS4_LINUX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

list(APPEND DIRS_GPCS4
	"GPCS4"
	"GPCS4/Algorithm"
	"GPCS4/Common"
	"GPCS4/Emulator"
	"GPCS4/Graphic"
	"GPCS4/Graphic/Gnm"
	"GPCS4/Graphic/Gnm/GpuAddress"
	"GPCS4/Graphic/Pssl"
	"GPCS4/Graphic/Pssl/GCNParser"
	"GPCS4/Graphic/Sce"
	"GPCS4/Graphic/SpirV"
	"GPCS4/Graphic/Violet"
	"GPCS4/Loader"
	"GPCS4/Platform"
	"GPCS4/SceModules"
	"GPCS4/SceModules/SceAjm"
	"GPCS4/SceModules/SceAppContentUtil"
	"GPCS4/SceModules/SceAudio3d"
	"GPCS4/SceModules/SceAudioOut"
	"GPCS4/SceModules/SceCommonDialog"
	"GPCS4/SceModules/SceErrorDialog"
	"GPCS4/SceModules/SceFiber"
	"GPCS4/SceModules/SceFios2"
	"GPCS4/SceModules/SceGameLiveStreaming"
	"GPCS4/SceModules/SceGnmDriver"
	"GPCS4/SceModules/SceHttp"
	"GPCS4/SceModules/SceIme"
	"GPCS4/SceModules/SceInvitationDialog"
	"GPCS4/SceModules/SceJobManager"
	"GPCS4/SceModules/SceJson"
	"GPCS4/SceModules/SceLibc"
	"GPCS4/SceModules/SceLibkernel"
	"GPCS4/SceModules/SceMouse"
	"GPCS4/SceModules/SceMsgDialog"
	"GPCS4/SceModules/SceNet"
	"GPCS4/SceModules/SceNetCtl"
	"GPCS4/SceModules/SceNpCommerce"
	"GPCS4/SceModules/SceNpCommon"
	"GPCS4/SceModules/SceNpManager"
	"GPCS4/SceModules/SceNpMatching2"
	"GPCS4/SceModules/SceNpProfileDialog"
	"GPCS4/SceModules/SceNpScore"
	"GPCS4/SceModules/SceNpSignaling"
	"GPCS4/SceModules/SceNpTrophy"
	"GPCS4/SceModules/SceNpTus"
	"GPCS4/SceModules/SceNpWebApi"
	"GPCS4/SceModules/ScePad"
	"GPCS4/SceModules/ScePlayGo"
	"GPCS4/SceModules/ScePlayGoDialog"
	"GPCS4/SceModules/SceRtc"
	"GPCS4/SceModules/SceRudp"
	"GPCS4/SceModules/SceSaveData"
	"GPCS4/SceModules/SceSaveDataDialog"
	"GPCS4/SceModules/SceScreenShot"
	"GPCS4/SceModules/SceSsl"
	"GPCS4/SceModules/SceSysmodule"
	"GPCS4/SceModules/SceSystemService"
	"GPCS4/SceModules/SceUserService"
	"GPCS4/SceModules/SceVideoOut"
	"GPCS4/SceModules/SceVideoRecording"
	"GPCS4/Util"
	)
add_dir("${DIRS_GPCS4}" "GPCS4")

add_executable(GPCS4 ${GPCS4_SOURCE} ${GPCS4_INLINE} ${GPCS4_HEADER})
target_link_libraries(GPCS4 rtaudio Zydis glfw vulkan pthread)

include_directories(${INCLUDE_DIRECTORIES}
	${PROJECT_SOURCE_DIR}/3rdParty
	${PROJECT_SOURCE_DIR}/GPCS4
	${PROJECT_SOURCE_DIR}/GPCS4/Common
	${PROJECT_SOURCE_DIR}/GPCS4/SceModules
	${PROJECT_SOURCE_DIR}/GPCS4/Util
	)
