#include <windows.h>
#include <Shlwapi.h>
#include<vector>
#include <time.h>
#include <iostream>
using namespace std;

#pragma comment( lib, "Shlwapi.lib")

#pragma comment(linker, "/EXPORT:Noname2=_new_Unnamed2,@2,NONAME")
#pragma comment(linker, "/EXPORT:CloseDriver=_new_CloseDriver,@3")
#pragma comment(linker, "/EXPORT:DefDriverProc=_new_DefDriverProc,@4")
#pragma comment(linker, "/EXPORT:DriverCallback=_new_DriverCallback,@5")
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=_new_DrvGetModuleHandle,@6")
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=_new_GetDriverModuleHandle,@7")
#pragma comment(linker, "/EXPORT:MigrateAllDrivers=_new_MigrateAllDrivers,@8")
#pragma comment(linker, "/EXPORT:MigrateSoundEvents=_new_MigrateSoundEvents,@9")
#pragma comment(linker, "/EXPORT:NotifyCallbackData=_new_NotifyCallbackData,@10")
#pragma comment(linker, "/EXPORT:OpenDriver=_new_OpenDriver,@11")
#pragma comment(linker, "/EXPORT:PlaySound=_new_PlaySound,@12")
#pragma comment(linker, "/EXPORT:PlaySoundA=_new_PlaySoundA,@13")
#pragma comment(linker, "/EXPORT:PlaySoundW=_new_PlaySoundW,@14")
#pragma comment(linker, "/EXPORT:SendDriverMessage=_new_SendDriverMessage,@15")
#pragma comment(linker, "/EXPORT:WOW32DriverCallback=_new_WOW32DriverCallback,@16")
#pragma comment(linker, "/EXPORT:WOW32ResolveMultiMediaHandle=_new_WOW32ResolveMultiMediaHandle,@17")
#pragma comment(linker, "/EXPORT:WOWAppExit=_new_WOWAppExit,@18")
#pragma comment(linker, "/EXPORT:WinmmLogoff=_new_WinmmLogoff,@19")
#pragma comment(linker, "/EXPORT:WinmmLogon=_new_WinmmLogon,@20")
#pragma comment(linker, "/EXPORT:aux32Message=_new_aux32Message,@21")
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=_new_auxGetDevCapsA,@22")
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=_new_auxGetDevCapsW,@23")
#pragma comment(linker, "/EXPORT:auxGetNumDevs=_new_auxGetNumDevs,@24")
#pragma comment(linker, "/EXPORT:auxGetVolume=_new_auxGetVolume,@25")
#pragma comment(linker, "/EXPORT:auxOutMessage=_new_auxOutMessage,@26")
#pragma comment(linker, "/EXPORT:auxSetVolume=_new_auxSetVolume,@27")
#pragma comment(linker, "/EXPORT:gfxAddGfx=_new_gfxAddGfx,@28")
#pragma comment(linker, "/EXPORT:gfxBatchChange=_new_gfxBatchChange,@29")
#pragma comment(linker, "/EXPORT:gfxCreateGfxFactoriesList=_new_gfxCreateGfxFactoriesList,@30")
#pragma comment(linker, "/EXPORT:gfxCreateZoneFactoriesList=_new_gfxCreateZoneFactoriesList,@31")
#pragma comment(linker, "/EXPORT:gfxDestroyDeviceInterfaceList=_new_gfxDestroyDeviceInterfaceList,@32")
#pragma comment(linker, "/EXPORT:gfxEnumerateGfxs=_new_gfxEnumerateGfxs,@33")
#pragma comment(linker, "/EXPORT:_gfxLogoff=_new_gfxLogoff,@34")
#pragma comment(linker, "/EXPORT:_gfxLogon=_new_gfxLogon,@35")
#pragma comment(linker, "/EXPORT:gfxModifyGfx=_new_gfxModifyGfx,@36")
#pragma comment(linker, "/EXPORT:gfxOpenGfx=_new_gfxOpenGfx,@37")
#pragma comment(linker, "/EXPORT:gfxRemoveGfx=_new_gfxRemoveGfx,@38")
#pragma comment(linker, "/EXPORT:joy32Message=_new_joy32Message,@39")
#pragma comment(linker, "/EXPORT:joyConfigChanged=_new_joyConfigChanged,@40")
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=_new_joyGetDevCapsA,@41")
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=_new_joyGetDevCapsW,@42")
#pragma comment(linker, "/EXPORT:joyGetNumDevs=_new_joyGetNumDevs,@43")
#pragma comment(linker, "/EXPORT:joyGetPos=_new_joyGetPos,@44")
#pragma comment(linker, "/EXPORT:joyGetPosEx=_new_joyGetPosEx,@45")
#pragma comment(linker, "/EXPORT:joyGetThreshold=_new_joyGetThreshold,@46")
#pragma comment(linker, "/EXPORT:joyReleaseCapture=_new_joyReleaseCapture,@47")
#pragma comment(linker, "/EXPORT:joySetCapture=_new_joySetCapture,@48")
#pragma comment(linker, "/EXPORT:joySetThreshold=_new_joySetThreshold,@49")
#pragma comment(linker, "/EXPORT:mci32Message=_new_mci32Message,@50")
#pragma comment(linker, "/EXPORT:mciDriverNotify=_new_mciDriverNotify,@51")
#pragma comment(linker, "/EXPORT:mciDriverYield=_new_mciDriverYield,@52")
#pragma comment(linker, "/EXPORT:mciExecute=_new_mciExecute,@53")
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=_new_mciFreeCommandResource,@54")
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=_new_mciGetCreatorTask,@55")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=_new_mciGetDeviceIDA,@56")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=_new_mciGetDeviceIDFromElementIDA,@57")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=_new_mciGetDeviceIDFromElementIDW,@58")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=_new_mciGetDeviceIDW,@59")
#pragma comment(linker, "/EXPORT:mciGetDriverData=_new_mciGetDriverData,@60")
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=_new_mciGetErrorStringA,@61")
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=_new_mciGetErrorStringW,@62")
#pragma comment(linker, "/EXPORT:mciGetYieldProc=_new_mciGetYieldProc,@63")
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=_new_mciLoadCommandResource,@64")
#pragma comment(linker, "/EXPORT:mciSendCommandA=_new_mciSendCommandA,@65")
#pragma comment(linker, "/EXPORT:mciSendCommandW=_new_mciSendCommandW,@66")
#pragma comment(linker, "/EXPORT:mciSendStringA=_new_mciSendStringA,@67")
#pragma comment(linker, "/EXPORT:mciSendStringW=_new_mciSendStringW,@68")
#pragma comment(linker, "/EXPORT:mciSetDriverData=_new_mciSetDriverData,@69")
#pragma comment(linker, "/EXPORT:mciSetYieldProc=_new_mciSetYieldProc,@70")
#pragma comment(linker, "/EXPORT:mid32Message=_new_mid32Message,@71")
#pragma comment(linker, "/EXPORT:midiConnect=_new_midiConnect,@72")
#pragma comment(linker, "/EXPORT:midiDisconnect=_new_midiDisconnect,@73")
#pragma comment(linker, "/EXPORT:midiInAddBuffer=_new_midiInAddBuffer,@74")
#pragma comment(linker, "/EXPORT:midiInClose=_new_midiInClose,@75")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=_new_midiInGetDevCapsA,@76")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=_new_midiInGetDevCapsW,@77")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=_new_midiInGetErrorTextA,@78")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=_new_midiInGetErrorTextW,@79")
#pragma comment(linker, "/EXPORT:midiInGetID=_new_midiInGetID,@80")
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=_new_midiInGetNumDevs,@81")
#pragma comment(linker, "/EXPORT:midiInMessage=_new_midiInMessage,@82")
#pragma comment(linker, "/EXPORT:midiInOpen=_new_midiInOpen,@83")
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=_new_midiInPrepareHeader,@84")
#pragma comment(linker, "/EXPORT:midiInReset=_new_midiInReset,@85")
#pragma comment(linker, "/EXPORT:midiInStart=_new_midiInStart,@86")
#pragma comment(linker, "/EXPORT:midiInStop=_new_midiInStop,@87")
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=_new_midiInUnprepareHeader,@88")
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=_new_midiOutCacheDrumPatches,@89")
#pragma comment(linker, "/EXPORT:midiOutCachePatches=_new_midiOutCachePatches,@90")
#pragma comment(linker, "/EXPORT:midiOutClose=_new_midiOutClose,@91")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=_new_midiOutGetDevCapsA,@92")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=_new_midiOutGetDevCapsW,@93")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=_new_midiOutGetErrorTextA,@94")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=_new_midiOutGetErrorTextW,@95")
#pragma comment(linker, "/EXPORT:midiOutGetID=_new_midiOutGetID,@96")
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=_new_midiOutGetNumDevs,@97")
#pragma comment(linker, "/EXPORT:midiOutGetVolume=_new_midiOutGetVolume,@98")
#pragma comment(linker, "/EXPORT:midiOutLongMsg=_new_midiOutLongMsg,@99")
#pragma comment(linker, "/EXPORT:midiOutMessage=_new_midiOutMessage,@100")
#pragma comment(linker, "/EXPORT:midiOutOpen=_new_midiOutOpen,@101")
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=_new_midiOutPrepareHeader,@102")
#pragma comment(linker, "/EXPORT:midiOutReset=_new_midiOutReset,@103")
#pragma comment(linker, "/EXPORT:midiOutSetVolume=_new_midiOutSetVolume,@104")
#pragma comment(linker, "/EXPORT:midiOutShortMsg=_new_midiOutShortMsg,@105")
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=_new_midiOutUnprepareHeader,@106")
#pragma comment(linker, "/EXPORT:midiStreamClose=_new_midiStreamClose,@107")
#pragma comment(linker, "/EXPORT:midiStreamOpen=_new_midiStreamOpen,@108")
#pragma comment(linker, "/EXPORT:midiStreamOut=_new_midiStreamOut,@109")
#pragma comment(linker, "/EXPORT:midiStreamPause=_new_midiStreamPause,@110")
#pragma comment(linker, "/EXPORT:midiStreamPosition=_new_midiStreamPosition,@111")
#pragma comment(linker, "/EXPORT:midiStreamProperty=_new_midiStreamProperty,@112")
#pragma comment(linker, "/EXPORT:midiStreamRestart=_new_midiStreamRestart,@113")
#pragma comment(linker, "/EXPORT:midiStreamStop=_new_midiStreamStop,@114")
#pragma comment(linker, "/EXPORT:mixerClose=_new_mixerClose,@115")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=_new_mixerGetControlDetailsA,@116")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=_new_mixerGetControlDetailsW,@117")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=_new_mixerGetDevCapsA,@118")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=_new_mixerGetDevCapsW,@119")
#pragma comment(linker, "/EXPORT:mixerGetID=_new_mixerGetID,@120")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=_new_mixerGetLineControlsA,@121")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=_new_mixerGetLineControlsW,@122")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=_new_mixerGetLineInfoA,@123")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=_new_mixerGetLineInfoW,@124")
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=_new_mixerGetNumDevs,@125")
#pragma comment(linker, "/EXPORT:mixerMessage=_new_mixerMessage,@126")
#pragma comment(linker, "/EXPORT:mixerOpen=_new_mixerOpen,@127")
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=_new_mixerSetControlDetails,@128")
#pragma comment(linker, "/EXPORT:mmDrvInstall=_new_mmDrvInstall,@129")
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=_new_mmGetCurrentTask,@130")
#pragma comment(linker, "/EXPORT:mmTaskBlock=_new_mmTaskBlock,@131")
#pragma comment(linker, "/EXPORT:mmTaskCreate=_new_mmTaskCreate,@132")
#pragma comment(linker, "/EXPORT:mmTaskSignal=_new_mmTaskSignal,@133")
#pragma comment(linker, "/EXPORT:mmTaskYield=_new_mmTaskYield,@134")
#pragma comment(linker, "/EXPORT:mmioAdvance=_new_mmioAdvance,@135")
#pragma comment(linker, "/EXPORT:mmioAscend=_new_mmioAscend,@136")
#pragma comment(linker, "/EXPORT:mmioClose=_new_mmioClose,@137")
#pragma comment(linker, "/EXPORT:mmioCreateChunk=_new_mmioCreateChunk,@138")
#pragma comment(linker, "/EXPORT:mmioDescend=_new_mmioDescend,@139")
#pragma comment(linker, "/EXPORT:mmioFlush=_new_mmioFlush,@140")
#pragma comment(linker, "/EXPORT:mmioGetInfo=_new_mmioGetInfo,@141")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=_new_mmioInstallIOProcA,@142")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=_new_mmioInstallIOProcW,@143")
#pragma comment(linker, "/EXPORT:mmioOpenA=_new_mmioOpenA,@144")
#pragma comment(linker, "/EXPORT:mmioOpenW=_new_mmioOpenW,@145")
#pragma comment(linker, "/EXPORT:mmioRead=_new_mmioRead,@146")
#pragma comment(linker, "/EXPORT:mmioRenameA=_new_mmioRenameA,@147")
#pragma comment(linker, "/EXPORT:mmioRenameW=_new_mmioRenameW,@148")
#pragma comment(linker, "/EXPORT:mmioSeek=_new_mmioSeek,@149")
#pragma comment(linker, "/EXPORT:mmioSendMessage=_new_mmioSendMessage,@150")
#pragma comment(linker, "/EXPORT:mmioSetBuffer=_new_mmioSetBuffer,@151")
#pragma comment(linker, "/EXPORT:mmioSetInfo=_new_mmioSetInfo,@152")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=_new_mmioStringToFOURCCA,@153")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=_new_mmioStringToFOURCCW,@154")
#pragma comment(linker, "/EXPORT:mmioWrite=_new_mmioWrite,@155")
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=_new_mmsystemGetVersion,@156")
#pragma comment(linker, "/EXPORT:mod32Message=_new_mod32Message,@157")
#pragma comment(linker, "/EXPORT:mxd32Message=_new_mxd32Message,@158")
#pragma comment(linker, "/EXPORT:sndPlaySoundA=_new_sndPlaySoundA,@159")
#pragma comment(linker, "/EXPORT:sndPlaySoundW=_new_sndPlaySoundW,@160")
#pragma comment(linker, "/EXPORT:tid32Message=_new_tid32Message,@161")
#pragma comment(linker, "/EXPORT:timeBeginPeriod=_new_timeBeginPeriod,@162")
#pragma comment(linker, "/EXPORT:timeEndPeriod=_new_timeEndPeriod,@163")
#pragma comment(linker, "/EXPORT:timeGetDevCaps=_new_timeGetDevCaps,@164")
#pragma comment(linker, "/EXPORT:timeGetSystemTime=_new_timeGetSystemTime,@165")
#pragma comment(linker, "/EXPORT:timeGetTime=_new_timeGetTime,@166")
#pragma comment(linker, "/EXPORT:timeKillEvent=_new_timeKillEvent,@167")
#pragma comment(linker, "/EXPORT:timeSetEvent=_new_timeSetEvent,@168")
#pragma comment(linker, "/EXPORT:waveInAddBuffer=_new_waveInAddBuffer,@169")
#pragma comment(linker, "/EXPORT:waveInClose=_new_waveInClose,@170")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=_new_waveInGetDevCapsA,@171")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=_new_waveInGetDevCapsW,@172")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=_new_waveInGetErrorTextA,@173")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=_new_waveInGetErrorTextW,@174")
#pragma comment(linker, "/EXPORT:waveInGetID=_new_waveInGetID,@175")
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=_new_waveInGetNumDevs,@176")
#pragma comment(linker, "/EXPORT:waveInGetPosition=_new_waveInGetPosition,@177")
#pragma comment(linker, "/EXPORT:waveInMessage=_new_waveInMessage,@178")
#pragma comment(linker, "/EXPORT:waveInOpen=_new_waveInOpen,@179")
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=_new_waveInPrepareHeader,@180")
#pragma comment(linker, "/EXPORT:waveInReset=_new_waveInReset,@181")
#pragma comment(linker, "/EXPORT:waveInStart=_new_waveInStart,@182")
#pragma comment(linker, "/EXPORT:waveInStop=_new_waveInStop,@183")
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=_new_waveInUnprepareHeader,@184")
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=_new_waveOutBreakLoop,@185")
#pragma comment(linker, "/EXPORT:waveOutClose=_new_waveOutClose,@186")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=_new_waveOutGetDevCapsA,@187")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=_new_waveOutGetDevCapsW,@188")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=_new_waveOutGetErrorTextA,@189")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=_new_waveOutGetErrorTextW,@190")
#pragma comment(linker, "/EXPORT:waveOutGetID=_new_waveOutGetID,@191")
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=_new_waveOutGetNumDevs,@192")
#pragma comment(linker, "/EXPORT:waveOutGetPitch=_new_waveOutGetPitch,@193")
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=_new_waveOutGetPlaybackRate,@194")
#pragma comment(linker, "/EXPORT:waveOutGetPosition=_new_waveOutGetPosition,@195")
#pragma comment(linker, "/EXPORT:waveOutGetVolume=_new_waveOutGetVolume,@196")
#pragma comment(linker, "/EXPORT:waveOutMessage=_new_waveOutMessage,@197")
#pragma comment(linker, "/EXPORT:waveOutOpen=_new_waveOutOpen,@198")
#pragma comment(linker, "/EXPORT:waveOutPause=_new_waveOutPause,@199")
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=_new_waveOutPrepareHeader,@200")
#pragma comment(linker, "/EXPORT:waveOutReset=_new_waveOutReset,@201")
#pragma comment(linker, "/EXPORT:waveOutRestart=_new_waveOutRestart,@202")
#pragma comment(linker, "/EXPORT:waveOutSetPitch=_new_waveOutSetPitch,@203")
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=_new_waveOutSetPlaybackRate,@204")
#pragma comment(linker, "/EXPORT:waveOutSetVolume=_new_waveOutSetVolume,@205")
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=_new_waveOutUnprepareHeader,@206")
#pragma comment(linker, "/EXPORT:waveOutWrite=_new_waveOutWrite,@207")
#pragma comment(linker, "/EXPORT:wid32Message=_new_wid32Message,@208")
#pragma comment(linker, "/EXPORT:winmmDbgOut=_new_winmmDbgOut,@209")
#pragma comment(linker, "/EXPORT:winmmSetDebugLevel=_new_winmmSetDebugLevel,@210")
#pragma comment(linker, "/EXPORT:wod32Message=_new_wod32Message,@211")


PVOID pfnnew_Unnamed2;
PVOID pfnnew_CloseDriver;
PVOID pfnnew_DefDriverProc;
PVOID pfnnew_DriverCallback;
PVOID pfnnew_DrvGetModuleHandle;
PVOID pfnnew_GetDriverModuleHandle;
PVOID pfnnew_MigrateAllDrivers;
PVOID pfnnew_MigrateSoundEvents;
PVOID pfnnew_NotifyCallbackData;
PVOID pfnnew_OpenDriver;
PVOID pfnnew_PlaySound;
PVOID pfnnew_PlaySoundA;
PVOID pfnnew_PlaySoundW;
PVOID pfnnew_SendDriverMessage;
PVOID pfnnew_WOW32DriverCallback;
PVOID pfnnew_WOW32ResolveMultiMediaHandle;
PVOID pfnnew_WOWAppExit;
PVOID pfnnew_WinmmLogoff;
PVOID pfnnew_WinmmLogon;
PVOID pfnnew_aux32Message;
PVOID pfnnew_auxGetDevCapsA;
PVOID pfnnew_auxGetDevCapsW;
PVOID pfnnew_auxGetNumDevs;
PVOID pfnnew_auxGetVolume;
PVOID pfnnew_auxOutMessage;
PVOID pfnnew_auxSetVolume;
PVOID pfnnew_gfxAddGfx;
PVOID pfnnew_gfxBatchChange;
PVOID pfnnew_gfxCreateGfxFactoriesList;
PVOID pfnnew_gfxCreateZoneFactoriesList;
PVOID pfnnew_gfxDestroyDeviceInterfaceList;
PVOID pfnnew_gfxEnumerateGfxs;
PVOID pfnnew_gfxLogoff;
PVOID pfnnew_gfxLogon;
PVOID pfnnew_gfxModifyGfx;
PVOID pfnnew_gfxOpenGfx;
PVOID pfnnew_gfxRemoveGfx;
PVOID pfnnew_joy32Message;
PVOID pfnnew_joyConfigChanged;
PVOID pfnnew_joyGetDevCapsA;
PVOID pfnnew_joyGetDevCapsW;
PVOID pfnnew_joyGetNumDevs;
PVOID pfnnew_joyGetPos;
PVOID pfnnew_joyGetPosEx;
PVOID pfnnew_joyGetThreshold;
PVOID pfnnew_joyReleaseCapture;
PVOID pfnnew_joySetCapture;
PVOID pfnnew_joySetThreshold;
PVOID pfnnew_mci32Message;
PVOID pfnnew_mciDriverNotify;
PVOID pfnnew_mciDriverYield;
PVOID pfnnew_mciExecute;
PVOID pfnnew_mciFreeCommandResource;
PVOID pfnnew_mciGetCreatorTask;
PVOID pfnnew_mciGetDeviceIDA;
PVOID pfnnew_mciGetDeviceIDFromElementIDA;
PVOID pfnnew_mciGetDeviceIDFromElementIDW;
PVOID pfnnew_mciGetDeviceIDW;
PVOID pfnnew_mciGetDriverData;
PVOID pfnnew_mciGetErrorStringA;
PVOID pfnnew_mciGetErrorStringW;
PVOID pfnnew_mciGetYieldProc;
PVOID pfnnew_mciLoadCommandResource;
PVOID pfnnew_mciSendCommandA;
PVOID pfnnew_mciSendCommandW;
PVOID pfnnew_mciSendStringA;
PVOID pfnnew_mciSendStringW;
PVOID pfnnew_mciSetDriverData;
PVOID pfnnew_mciSetYieldProc;
PVOID pfnnew_mid32Message;
PVOID pfnnew_midiConnect;
PVOID pfnnew_midiDisconnect;
PVOID pfnnew_midiInAddBuffer;
PVOID pfnnew_midiInClose;
PVOID pfnnew_midiInGetDevCapsA;
PVOID pfnnew_midiInGetDevCapsW;
PVOID pfnnew_midiInGetErrorTextA;
PVOID pfnnew_midiInGetErrorTextW;
PVOID pfnnew_midiInGetID;
PVOID pfnnew_midiInGetNumDevs;
PVOID pfnnew_midiInMessage;
PVOID pfnnew_midiInOpen;
PVOID pfnnew_midiInPrepareHeader;
PVOID pfnnew_midiInReset;
PVOID pfnnew_midiInStart;
PVOID pfnnew_midiInStop;
PVOID pfnnew_midiInUnprepareHeader;
PVOID pfnnew_midiOutCacheDrumPatches;
PVOID pfnnew_midiOutCachePatches;
PVOID pfnnew_midiOutClose;
PVOID pfnnew_midiOutGetDevCapsA;
PVOID pfnnew_midiOutGetDevCapsW;
PVOID pfnnew_midiOutGetErrorTextA;
PVOID pfnnew_midiOutGetErrorTextW;
PVOID pfnnew_midiOutGetID;
PVOID pfnnew_midiOutGetNumDevs;
PVOID pfnnew_midiOutGetVolume;
PVOID pfnnew_midiOutLongMsg;
PVOID pfnnew_midiOutMessage;
PVOID pfnnew_midiOutOpen;
PVOID pfnnew_midiOutPrepareHeader;
PVOID pfnnew_midiOutReset;
PVOID pfnnew_midiOutSetVolume;
PVOID pfnnew_midiOutShortMsg;
PVOID pfnnew_midiOutUnprepareHeader;
PVOID pfnnew_midiStreamClose;
PVOID pfnnew_midiStreamOpen;
PVOID pfnnew_midiStreamOut;
PVOID pfnnew_midiStreamPause;
PVOID pfnnew_midiStreamPosition;
PVOID pfnnew_midiStreamProperty;
PVOID pfnnew_midiStreamRestart;
PVOID pfnnew_midiStreamStop;
PVOID pfnnew_mixerClose;
PVOID pfnnew_mixerGetControlDetailsA;
PVOID pfnnew_mixerGetControlDetailsW;
PVOID pfnnew_mixerGetDevCapsA;
PVOID pfnnew_mixerGetDevCapsW;
PVOID pfnnew_mixerGetID;
PVOID pfnnew_mixerGetLineControlsA;
PVOID pfnnew_mixerGetLineControlsW;
PVOID pfnnew_mixerGetLineInfoA;
PVOID pfnnew_mixerGetLineInfoW;
PVOID pfnnew_mixerGetNumDevs;
PVOID pfnnew_mixerMessage;
PVOID pfnnew_mixerOpen;
PVOID pfnnew_mixerSetControlDetails;
PVOID pfnnew_mmDrvInstall;
PVOID pfnnew_mmGetCurrentTask;
PVOID pfnnew_mmTaskBlock;
PVOID pfnnew_mmTaskCreate;
PVOID pfnnew_mmTaskSignal;
PVOID pfnnew_mmTaskYield;
PVOID pfnnew_mmioAdvance;
PVOID pfnnew_mmioAscend;
PVOID pfnnew_mmioClose;
PVOID pfnnew_mmioCreateChunk;
PVOID pfnnew_mmioDescend;
PVOID pfnnew_mmioFlush;
PVOID pfnnew_mmioGetInfo;
PVOID pfnnew_mmioInstallIOProcA;
PVOID pfnnew_mmioInstallIOProcW;
PVOID pfnnew_mmioOpenA;
PVOID pfnnew_mmioOpenW;
PVOID pfnnew_mmioRead;
PVOID pfnnew_mmioRenameA;
PVOID pfnnew_mmioRenameW;
PVOID pfnnew_mmioSeek;
PVOID pfnnew_mmioSendMessage;
PVOID pfnnew_mmioSetBuffer;
PVOID pfnnew_mmioSetInfo;
PVOID pfnnew_mmioStringToFOURCCA;
PVOID pfnnew_mmioStringToFOURCCW;
PVOID pfnnew_mmioWrite;
PVOID pfnnew_mmsystemGetVersion;
PVOID pfnnew_mod32Message;
PVOID pfnnew_mxd32Message;
PVOID pfnnew_sndPlaySoundA;
PVOID pfnnew_sndPlaySoundW;
PVOID pfnnew_tid32Message;
PVOID pfnnew_timeBeginPeriod;
PVOID pfnnew_timeEndPeriod;
PVOID pfnnew_timeGetDevCaps;
PVOID pfnnew_timeGetSystemTime;
PVOID pfnnew_timeGetTime;
PVOID pfnnew_timeKillEvent;
PVOID pfnnew_timeSetEvent;
PVOID pfnnew_waveInAddBuffer;
PVOID pfnnew_waveInClose;
PVOID pfnnew_waveInGetDevCapsA;
PVOID pfnnew_waveInGetDevCapsW;
PVOID pfnnew_waveInGetErrorTextA;
PVOID pfnnew_waveInGetErrorTextW;
PVOID pfnnew_waveInGetID;
PVOID pfnnew_waveInGetNumDevs;
PVOID pfnnew_waveInGetPosition;
PVOID pfnnew_waveInMessage;
PVOID pfnnew_waveInOpen;
PVOID pfnnew_waveInPrepareHeader;
PVOID pfnnew_waveInReset;
PVOID pfnnew_waveInStart;
PVOID pfnnew_waveInStop;
PVOID pfnnew_waveInUnprepareHeader;
PVOID pfnnew_waveOutBreakLoop;
PVOID pfnnew_waveOutClose;
PVOID pfnnew_waveOutGetDevCapsA;
PVOID pfnnew_waveOutGetDevCapsW;
PVOID pfnnew_waveOutGetErrorTextA;
PVOID pfnnew_waveOutGetErrorTextW;
PVOID pfnnew_waveOutGetID;
PVOID pfnnew_waveOutGetNumDevs;
PVOID pfnnew_waveOutGetPitch;
PVOID pfnnew_waveOutGetPlaybackRate;
PVOID pfnnew_waveOutGetPosition;
PVOID pfnnew_waveOutGetVolume;
PVOID pfnnew_waveOutMessage;
PVOID pfnnew_waveOutOpen;
PVOID pfnnew_waveOutPause;
PVOID pfnnew_waveOutPrepareHeader;
PVOID pfnnew_waveOutReset;
PVOID pfnnew_waveOutRestart;
PVOID pfnnew_waveOutSetPitch;
PVOID pfnnew_waveOutSetPlaybackRate;
PVOID pfnnew_waveOutSetVolume;
PVOID pfnnew_waveOutUnprepareHeader;
PVOID pfnnew_waveOutWrite;
PVOID pfnnew_wid32Message;
PVOID pfnnew_winmmDbgOut;
PVOID pfnnew_winmmSetDebugLevel;
PVOID pfnnew_wod32Message;


static
HMODULE g_OldModule = NULL;



bool FHexCharValid(char c)
{
	if (c >= '0' && c <= '9' ||
		c >= 'A' && c <= 'F' ||
		c >= 'a' && c <= 'f' ||
		c == '?')
		return true;
	else
		return false;
}

bool FHexDecoder(char* Dec, char* Src)
{
	char HighC, LowC;
	DWORD dwSrcLen = strlen(Src) / 2;
	int i;
	for (i = 0; i < dwSrcLen; i++) {
		HighC = Src[i * 2], LowC = Src[i * 2 + 1];
		if (!FHexCharValid(LowC) || !FHexCharValid(HighC))
			return false;
		HighC -= '0';
		if (HighC > 9) HighC -= 7;
		if (HighC > 0xf) HighC -= 0x20;
		LowC -= '0';
		if (LowC > 9) LowC -= 7;
		if (LowC > 0xf) LowC -= 0x20;
		Dec[i] = (HighC << 4) | LowC;
	}
	return true;
}

namespace AobScan {
	//private: 注意，永远不要手动调用下面的函数
	std::vector <DWORD> FindSigX32(DWORD dwPid, const char* Value, ULONG64 Start = 0, ULONG64 End = 0);
	bool __SundayHexInit__(char* Sub, unsigned long*p, char* HexSub, unsigned long dwSubLen);
	ULONG64 __SundayHex__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen);
	ULONG64 __SundayHexV__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen, int v);
	std::vector<ULONG64> SundayHexV(char* Src, unsigned long dwSrcLen, char* Sub);
} // namespace AobScan

bool __SundayHexInit__(char* Sub, DWORD*p, char* HexSub, unsigned long dwSubLen)
{
	if (!FHexDecoder(HexSub, Sub)) {
		return false;
	}
	ULONG64 i;

	for (i = 0; i < 0x100; i++) {
		p[i] = -1;
	}

	int WildAddr = 0;
	for (i = 0; i < dwSubLen; i++) {
		if (Sub[i * 2] == '?')
			WildAddr = i;
	}

	for (i = WildAddr + 1; i < dwSubLen; i++) {                     //扫描Sub，初始化 P 表
		p[(BYTE)HexSub[i]] = dwSubLen - i;
	}

	for (i = 0; i < 0x100; i++) {
		if (p[i] == -1)
			p[i] = dwSubLen - WildAddr;
	}
	return true;
}

ULONG64 __SundayHex__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen)
{
	//开始配对字符串
	//j为 Sub位置指标， k为 当前匹配位置
	ULONG64 j, k;
	j = dwSubLen - 1;                                   //初始化位置为 dwSubLen - 1,匹配顺序为从右到左

	bool bContinue = true;
	bool bSuccess;
	while (bContinue) {
		bSuccess = true;
		for (k = 0; k < dwSubLen; k++) {
			if (Sub[(dwSubLen - k - 1) * 2] != '?' && Src[j - k] != HexSub[dwSubLen - k - 1]) {
				bSuccess = false;
				break;
			}
		}
		if (bSuccess)
			bContinue = false;
		else {                                          //移动j指针
			if (j < dwSrcLen - 1)                                                        //防止j+1 >= dwSrcLen造成溢出
				j += p[(BYTE)Src[j + 1]];
			else j++;
		}
		if (j >= dwSrcLen)
			break;
	}
	if (j < dwSrcLen)
		return j - dwSubLen + 1;
	else
		return -1;
}

ULONG64 __SundayHexV__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen, int v)
{
	//开始配对字符串
	//j为 Sub位置指标， k为 当前匹配位置
	ULONG64 j, k;
	j = dwSubLen - 1 + v;                                   //初始化位置为 dwSubLen - 1,匹配顺序为从右到左

	bool bContinue = true;
	bool bSuccess;
	while (bContinue) {
		bSuccess = true;
		for (k = 0; k < dwSubLen; k++) {
			if (Sub[(dwSubLen - k - 1) * 2] != '?' && Src[j - k] != HexSub[dwSubLen - k - 1]) {
				bSuccess = false;
				break;
			}
		}
		if (bSuccess)
			bContinue = false;
		else {                                          //移动j指针
			if (j < dwSrcLen - 1)                                                        //防止j+1 >= dwSrcLen造成溢出
				j += p[(BYTE)Src[j + 1]];
			else j++;
		}
		if (j >= dwSrcLen)
			break;
	}
	if (j < dwSrcLen)
		return j - dwSubLen + 1;
	else
		return -1;

}
int SundayHex(char* Src, unsigned long dwSrcLen, char* Sub)
{
	DWORD dwSubLen = strlen(Sub);
	if (dwSubLen % 2)                    //长度必须为2的倍数
		return -1;
	dwSubLen /= 2;

	char* HexSub = new char[dwSubLen + 1];
	DWORD* p = new DWORD[0x100];        //table P,标志距离
	int i = -1;

	if (__SundayHexInit__(Sub, p, HexSub, dwSubLen)) {
		i = __SundayHex__(Src, dwSrcLen, Sub, p, HexSub, dwSubLen);
	}

	delete[]p;
	delete[]HexSub;
	return i;
}

vector<ULONG64> SundayHexV(char* Src, unsigned long dwSrcLen, char* Sub)
{
	vector<ULONG64> v;
	DWORD dwSubLen = strlen(Sub);

	if (dwSubLen % 2)                    //长度必须为2的倍数
		return v;
	dwSubLen /= 2;

	char* HexSub = new char[dwSubLen + 1];
	DWORD* p = new DWORD[0x100];        //table P,标志距离
	int i = -1;

	if (__SundayHexInit__(Sub, p, HexSub, dwSubLen))
	{
		i = __SundayHexV__(Src, dwSrcLen, Sub, p, HexSub, dwSubLen, 0);
		while (i != -1)
		{
			v.push_back(i);
			i = __SundayHexV__(Src, dwSrcLen, Sub, p, HexSub, dwSubLen, i + dwSubLen);
		}
	}
	delete[]p;
	delete[]HexSub;
	return v;
}

#define  RESERVED_ADDRESS_X32  0x00327000
#define  SYSTEM_MEMORY_ADDRESS_X32 0x70000000
#define  SYSTEM_MEMORY_ADDRESS_X32_MAX 0x7FFFFFFF

// 定义区段上限,一般的区段大小不会超过
#define SECTION_SIZE_X32_MAX  0x0f000000

std::vector <DWORD> FindSigX32(DWORD dwPid, const char* Value, ULONG64 Start, ULONG64 End)
{
	std::vector <DWORD> vFindResult;
	if (dwPid == 0)
		return vFindResult;
	if (Start < RESERVED_ADDRESS_X32)
		Start = RESERVED_ADDRESS_X32;
	if (End < 0)
		End = SYSTEM_MEMORY_ADDRESS_X32;
	if (Start >= End)
		return vFindResult;

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPid);

	if (hProcess == NULL)
		return vFindResult;

	DWORD dwSectionSize = 0;
	MEMORY_BASIC_INFORMATION mem_info;
	while (VirtualQueryEx(hProcess, (LPCVOID)Start, &mem_info, sizeof(MEMORY_BASIC_INFORMATION)))
	{
		if (mem_info.Protect != 16 && mem_info.RegionSize != 1 && mem_info.Protect != 512)
		{
			dwSectionSize = (DWORD)mem_info.BaseAddress + mem_info.RegionSize - Start;
			if (dwSectionSize > SECTION_SIZE_X32_MAX)
				break;
			char* buf = new char[dwSectionSize + 1];
			if (buf == NULL)
				break;
			if (ReadProcessMemory(hProcess, (LPCVOID)Start, buf, dwSectionSize, NULL))
			{
				vector<ULONG64>  dwValue = SundayHexV(buf, dwSectionSize, (char*)Value);
				for (size_t i = 0; i < dwValue.size(); i++)
				{
					vFindResult.push_back(Start + dwValue[i]);
				}
			}
			delete[]buf;
		}
		if (End == 0)
			break;
		Start += mem_info.RegionSize;
		if (Start > SYSTEM_MEMORY_ADDRESS_X32)
			break;
		if (Start > End)
			break;
	}
	CloseHandle(hProcess);
	return vFindResult;
}




VOID WINAPI Free()
{
	if (g_OldModule)
	{
		FreeLibrary(g_OldModule);
	}
}


BOOL WINAPI Load()
{
	TCHAR tzPath[MAX_PATH];
	TCHAR tzTemp[MAX_PATH * 2];

	//
	// 这里是否从系统目录或当前目录加载原始DLL
	//
	//GetModuleFileName(NULL,tzPath,MAX_PATH); //获取本目录下的
	//PathRemoveFileSpec(tzPath);

	GetSystemDirectory(tzPath, MAX_PATH); //默认获取系统目录的

	lstrcat(tzPath, TEXT("\\winmm.dll"));

	g_OldModule = LoadLibrary(tzPath);
	if (g_OldModule == NULL)
	{
		wsprintf(tzTemp, TEXT("无法找到模块 %s,程序无法正常运行"), tzPath);
		MessageBox(NULL, tzTemp, TEXT("new"), MB_ICONSTOP);
	}

	return (g_OldModule != NULL);

}


FARPROC WINAPI GetAddress(PCSTR pszProcName)
{
	FARPROC fpAddress;
	CHAR szProcName[64];
	TCHAR tzTemp[MAX_PATH];

	fpAddress = GetProcAddress(g_OldModule, pszProcName);
	if (fpAddress == NULL)
	{
		if (HIWORD(pszProcName) == 0)
		{
			wsprintfA(szProcName, "#%d", pszProcName);
			pszProcName = szProcName;
		}

		wsprintf(tzTemp, TEXT("无法找到函数 %hs,程序无法正常运行"), pszProcName);
		//MessageBox(NULL, tzTemp, TEXT("new"), MB_ICONSTOP);
		//ExitProcess(-2);
	}
	return fpAddress;
}

BOOL WINAPI Init()
{
	pfnnew_Unnamed2 = GetAddress(MAKEINTRESOURCEA(2));
	pfnnew_CloseDriver = GetAddress("CloseDriver");
	pfnnew_DefDriverProc = GetAddress("DefDriverProc");
	pfnnew_DriverCallback = GetAddress("DriverCallback");
	pfnnew_DrvGetModuleHandle = GetAddress("DrvGetModuleHandle");
	pfnnew_GetDriverModuleHandle = GetAddress("GetDriverModuleHandle");
	pfnnew_MigrateAllDrivers = GetAddress("MigrateAllDrivers");
	pfnnew_MigrateSoundEvents = GetAddress("MigrateSoundEvents");
	pfnnew_NotifyCallbackData = GetAddress("NotifyCallbackData");
	pfnnew_OpenDriver = GetAddress("OpenDriver");
	pfnnew_PlaySound = GetAddress("PlaySound");
	pfnnew_PlaySoundA = GetAddress("PlaySoundA");
	pfnnew_PlaySoundW = GetAddress("PlaySoundW");
	pfnnew_SendDriverMessage = GetAddress("SendDriverMessage");
	pfnnew_WOW32DriverCallback = GetAddress("WOW32DriverCallback");
	pfnnew_WOW32ResolveMultiMediaHandle = GetAddress("WOW32ResolveMultiMediaHandle");
	pfnnew_WOWAppExit = GetAddress("WOWAppExit");
	pfnnew_WinmmLogoff = GetAddress("WinmmLogoff");
	pfnnew_WinmmLogon = GetAddress("WinmmLogon");
	pfnnew_aux32Message = GetAddress("aux32Message");
	pfnnew_auxGetDevCapsA = GetAddress("auxGetDevCapsA");
	pfnnew_auxGetDevCapsW = GetAddress("auxGetDevCapsW");
	pfnnew_auxGetNumDevs = GetAddress("auxGetNumDevs");
	pfnnew_auxGetVolume = GetAddress("auxGetVolume");
	pfnnew_auxOutMessage = GetAddress("auxOutMessage");
	pfnnew_auxSetVolume = GetAddress("auxSetVolume");
	pfnnew_gfxAddGfx = GetAddress("gfxAddGfx");
	pfnnew_gfxBatchChange = GetAddress("gfxBatchChange");
	pfnnew_gfxCreateGfxFactoriesList = GetAddress("gfxCreateGfxFactoriesList");
	pfnnew_gfxCreateZoneFactoriesList = GetAddress("gfxCreateZoneFactoriesList");
	pfnnew_gfxDestroyDeviceInterfaceList = GetAddress("gfxDestroyDeviceInterfaceList");
	pfnnew_gfxEnumerateGfxs = GetAddress("gfxEnumerateGfxs");
	pfnnew_gfxLogoff = GetAddress("_gfxLogoff");
	pfnnew_gfxLogon = GetAddress("_gfxLogon");
	pfnnew_gfxModifyGfx = GetAddress("gfxModifyGfx");
	pfnnew_gfxOpenGfx = GetAddress("gfxOpenGfx");
	pfnnew_gfxRemoveGfx = GetAddress("gfxRemoveGfx");
	pfnnew_joy32Message = GetAddress("joy32Message");
	pfnnew_joyConfigChanged = GetAddress("joyConfigChanged");
	pfnnew_joyGetDevCapsA = GetAddress("joyGetDevCapsA");
	pfnnew_joyGetDevCapsW = GetAddress("joyGetDevCapsW");
	pfnnew_joyGetNumDevs = GetAddress("joyGetNumDevs");
	pfnnew_joyGetPos = GetAddress("joyGetPos");
	pfnnew_joyGetPosEx = GetAddress("joyGetPosEx");
	pfnnew_joyGetThreshold = GetAddress("joyGetThreshold");
	pfnnew_joyReleaseCapture = GetAddress("joyReleaseCapture");
	pfnnew_joySetCapture = GetAddress("joySetCapture");
	pfnnew_joySetThreshold = GetAddress("joySetThreshold");
	pfnnew_mci32Message = GetAddress("mci32Message");
	pfnnew_mciDriverNotify = GetAddress("mciDriverNotify");
	pfnnew_mciDriverYield = GetAddress("mciDriverYield");
	pfnnew_mciExecute = GetAddress("mciExecute");
	pfnnew_mciFreeCommandResource = GetAddress("mciFreeCommandResource");
	pfnnew_mciGetCreatorTask = GetAddress("mciGetCreatorTask");
	pfnnew_mciGetDeviceIDA = GetAddress("mciGetDeviceIDA");
	pfnnew_mciGetDeviceIDFromElementIDA = GetAddress("mciGetDeviceIDFromElementIDA");
	pfnnew_mciGetDeviceIDFromElementIDW = GetAddress("mciGetDeviceIDFromElementIDW");
	pfnnew_mciGetDeviceIDW = GetAddress("mciGetDeviceIDW");
	pfnnew_mciGetDriverData = GetAddress("mciGetDriverData");
	pfnnew_mciGetErrorStringA = GetAddress("mciGetErrorStringA");
	pfnnew_mciGetErrorStringW = GetAddress("mciGetErrorStringW");
	pfnnew_mciGetYieldProc = GetAddress("mciGetYieldProc");
	pfnnew_mciLoadCommandResource = GetAddress("mciLoadCommandResource");
	pfnnew_mciSendCommandA = GetAddress("mciSendCommandA");
	pfnnew_mciSendCommandW = GetAddress("mciSendCommandW");
	pfnnew_mciSendStringA = GetAddress("mciSendStringA");
	pfnnew_mciSendStringW = GetAddress("mciSendStringW");
	pfnnew_mciSetDriverData = GetAddress("mciSetDriverData");
	pfnnew_mciSetYieldProc = GetAddress("mciSetYieldProc");
	pfnnew_mid32Message = GetAddress("mid32Message");
	pfnnew_midiConnect = GetAddress("midiConnect");
	pfnnew_midiDisconnect = GetAddress("midiDisconnect");
	pfnnew_midiInAddBuffer = GetAddress("midiInAddBuffer");
	pfnnew_midiInClose = GetAddress("midiInClose");
	pfnnew_midiInGetDevCapsA = GetAddress("midiInGetDevCapsA");
	pfnnew_midiInGetDevCapsW = GetAddress("midiInGetDevCapsW");
	pfnnew_midiInGetErrorTextA = GetAddress("midiInGetErrorTextA");
	pfnnew_midiInGetErrorTextW = GetAddress("midiInGetErrorTextW");
	pfnnew_midiInGetID = GetAddress("midiInGetID");
	pfnnew_midiInGetNumDevs = GetAddress("midiInGetNumDevs");
	pfnnew_midiInMessage = GetAddress("midiInMessage");
	pfnnew_midiInOpen = GetAddress("midiInOpen");
	pfnnew_midiInPrepareHeader = GetAddress("midiInPrepareHeader");
	pfnnew_midiInReset = GetAddress("midiInReset");
	pfnnew_midiInStart = GetAddress("midiInStart");
	pfnnew_midiInStop = GetAddress("midiInStop");
	pfnnew_midiInUnprepareHeader = GetAddress("midiInUnprepareHeader");
	pfnnew_midiOutCacheDrumPatches = GetAddress("midiOutCacheDrumPatches");
	pfnnew_midiOutCachePatches = GetAddress("midiOutCachePatches");
	pfnnew_midiOutClose = GetAddress("midiOutClose");
	pfnnew_midiOutGetDevCapsA = GetAddress("midiOutGetDevCapsA");
	pfnnew_midiOutGetDevCapsW = GetAddress("midiOutGetDevCapsW");
	pfnnew_midiOutGetErrorTextA = GetAddress("midiOutGetErrorTextA");
	pfnnew_midiOutGetErrorTextW = GetAddress("midiOutGetErrorTextW");
	pfnnew_midiOutGetID = GetAddress("midiOutGetID");
	pfnnew_midiOutGetNumDevs = GetAddress("midiOutGetNumDevs");
	pfnnew_midiOutGetVolume = GetAddress("midiOutGetVolume");
	pfnnew_midiOutLongMsg = GetAddress("midiOutLongMsg");
	pfnnew_midiOutMessage = GetAddress("midiOutMessage");
	pfnnew_midiOutOpen = GetAddress("midiOutOpen");
	pfnnew_midiOutPrepareHeader = GetAddress("midiOutPrepareHeader");
	pfnnew_midiOutReset = GetAddress("midiOutReset");
	pfnnew_midiOutSetVolume = GetAddress("midiOutSetVolume");
	pfnnew_midiOutShortMsg = GetAddress("midiOutShortMsg");
	pfnnew_midiOutUnprepareHeader = GetAddress("midiOutUnprepareHeader");
	pfnnew_midiStreamClose = GetAddress("midiStreamClose");
	pfnnew_midiStreamOpen = GetAddress("midiStreamOpen");
	pfnnew_midiStreamOut = GetAddress("midiStreamOut");
	pfnnew_midiStreamPause = GetAddress("midiStreamPause");
	pfnnew_midiStreamPosition = GetAddress("midiStreamPosition");
	pfnnew_midiStreamProperty = GetAddress("midiStreamProperty");
	pfnnew_midiStreamRestart = GetAddress("midiStreamRestart");
	pfnnew_midiStreamStop = GetAddress("midiStreamStop");
	pfnnew_mixerClose = GetAddress("mixerClose");
	pfnnew_mixerGetControlDetailsA = GetAddress("mixerGetControlDetailsA");
	pfnnew_mixerGetControlDetailsW = GetAddress("mixerGetControlDetailsW");
	pfnnew_mixerGetDevCapsA = GetAddress("mixerGetDevCapsA");
	pfnnew_mixerGetDevCapsW = GetAddress("mixerGetDevCapsW");
	pfnnew_mixerGetID = GetAddress("mixerGetID");
	pfnnew_mixerGetLineControlsA = GetAddress("mixerGetLineControlsA");
	pfnnew_mixerGetLineControlsW = GetAddress("mixerGetLineControlsW");
	pfnnew_mixerGetLineInfoA = GetAddress("mixerGetLineInfoA");
	pfnnew_mixerGetLineInfoW = GetAddress("mixerGetLineInfoW");
	pfnnew_mixerGetNumDevs = GetAddress("mixerGetNumDevs");
	pfnnew_mixerMessage = GetAddress("mixerMessage");
	pfnnew_mixerOpen = GetAddress("mixerOpen");
	pfnnew_mixerSetControlDetails = GetAddress("mixerSetControlDetails");
	pfnnew_mmDrvInstall = GetAddress("mmDrvInstall");
	pfnnew_mmGetCurrentTask = GetAddress("mmGetCurrentTask");
	pfnnew_mmTaskBlock = GetAddress("mmTaskBlock");
	pfnnew_mmTaskCreate = GetAddress("mmTaskCreate");
	pfnnew_mmTaskSignal = GetAddress("mmTaskSignal");
	pfnnew_mmTaskYield = GetAddress("mmTaskYield");
	pfnnew_mmioAdvance = GetAddress("mmioAdvance");
	pfnnew_mmioAscend = GetAddress("mmioAscend");
	pfnnew_mmioClose = GetAddress("mmioClose");
	pfnnew_mmioCreateChunk = GetAddress("mmioCreateChunk");
	pfnnew_mmioDescend = GetAddress("mmioDescend");
	pfnnew_mmioFlush = GetAddress("mmioFlush");
	pfnnew_mmioGetInfo = GetAddress("mmioGetInfo");
	pfnnew_mmioInstallIOProcA = GetAddress("mmioInstallIOProcA");
	pfnnew_mmioInstallIOProcW = GetAddress("mmioInstallIOProcW");
	pfnnew_mmioOpenA = GetAddress("mmioOpenA");
	pfnnew_mmioOpenW = GetAddress("mmioOpenW");
	pfnnew_mmioRead = GetAddress("mmioRead");
	pfnnew_mmioRenameA = GetAddress("mmioRenameA");
	pfnnew_mmioRenameW = GetAddress("mmioRenameW");
	pfnnew_mmioSeek = GetAddress("mmioSeek");
	pfnnew_mmioSendMessage = GetAddress("mmioSendMessage");
	pfnnew_mmioSetBuffer = GetAddress("mmioSetBuffer");
	pfnnew_mmioSetInfo = GetAddress("mmioSetInfo");
	pfnnew_mmioStringToFOURCCA = GetAddress("mmioStringToFOURCCA");
	pfnnew_mmioStringToFOURCCW = GetAddress("mmioStringToFOURCCW");
	pfnnew_mmioWrite = GetAddress("mmioWrite");
	pfnnew_mmsystemGetVersion = GetAddress("mmsystemGetVersion");
	pfnnew_mod32Message = GetAddress("mod32Message");
	pfnnew_mxd32Message = GetAddress("mxd32Message");
	pfnnew_sndPlaySoundA = GetAddress("sndPlaySoundA");
	pfnnew_sndPlaySoundW = GetAddress("sndPlaySoundW");
	pfnnew_tid32Message = GetAddress("tid32Message");
	pfnnew_timeBeginPeriod = GetAddress("timeBeginPeriod");
	pfnnew_timeEndPeriod = GetAddress("timeEndPeriod");
	pfnnew_timeGetDevCaps = GetAddress("timeGetDevCaps");
	pfnnew_timeGetSystemTime = GetAddress("timeGetSystemTime");
	pfnnew_timeGetTime = GetAddress("timeGetTime");
	pfnnew_timeKillEvent = GetAddress("timeKillEvent");
	pfnnew_timeSetEvent = GetAddress("timeSetEvent");
	pfnnew_waveInAddBuffer = GetAddress("waveInAddBuffer");
	pfnnew_waveInClose = GetAddress("waveInClose");
	pfnnew_waveInGetDevCapsA = GetAddress("waveInGetDevCapsA");
	pfnnew_waveInGetDevCapsW = GetAddress("waveInGetDevCapsW");
	pfnnew_waveInGetErrorTextA = GetAddress("waveInGetErrorTextA");
	pfnnew_waveInGetErrorTextW = GetAddress("waveInGetErrorTextW");
	pfnnew_waveInGetID = GetAddress("waveInGetID");
	pfnnew_waveInGetNumDevs = GetAddress("waveInGetNumDevs");
	pfnnew_waveInGetPosition = GetAddress("waveInGetPosition");
	pfnnew_waveInMessage = GetAddress("waveInMessage");
	pfnnew_waveInOpen = GetAddress("waveInOpen");
	pfnnew_waveInPrepareHeader = GetAddress("waveInPrepareHeader");
	pfnnew_waveInReset = GetAddress("waveInReset");
	pfnnew_waveInStart = GetAddress("waveInStart");
	pfnnew_waveInStop = GetAddress("waveInStop");
	pfnnew_waveInUnprepareHeader = GetAddress("waveInUnprepareHeader");
	pfnnew_waveOutBreakLoop = GetAddress("waveOutBreakLoop");
	pfnnew_waveOutClose = GetAddress("waveOutClose");
	pfnnew_waveOutGetDevCapsA = GetAddress("waveOutGetDevCapsA");
	pfnnew_waveOutGetDevCapsW = GetAddress("waveOutGetDevCapsW");
	pfnnew_waveOutGetErrorTextA = GetAddress("waveOutGetErrorTextA");
	pfnnew_waveOutGetErrorTextW = GetAddress("waveOutGetErrorTextW");
	pfnnew_waveOutGetID = GetAddress("waveOutGetID");
	pfnnew_waveOutGetNumDevs = GetAddress("waveOutGetNumDevs");
	pfnnew_waveOutGetPitch = GetAddress("waveOutGetPitch");
	pfnnew_waveOutGetPlaybackRate = GetAddress("waveOutGetPlaybackRate");
	pfnnew_waveOutGetPosition = GetAddress("waveOutGetPosition");
	pfnnew_waveOutGetVolume = GetAddress("waveOutGetVolume");
	pfnnew_waveOutMessage = GetAddress("waveOutMessage");
	pfnnew_waveOutOpen = GetAddress("waveOutOpen");
	pfnnew_waveOutPause = GetAddress("waveOutPause");
	pfnnew_waveOutPrepareHeader = GetAddress("waveOutPrepareHeader");
	pfnnew_waveOutReset = GetAddress("waveOutReset");
	pfnnew_waveOutRestart = GetAddress("waveOutRestart");
	pfnnew_waveOutSetPitch = GetAddress("waveOutSetPitch");
	pfnnew_waveOutSetPlaybackRate = GetAddress("waveOutSetPlaybackRate");
	pfnnew_waveOutSetVolume = GetAddress("waveOutSetVolume");
	pfnnew_waveOutUnprepareHeader = GetAddress("waveOutUnprepareHeader");
	pfnnew_waveOutWrite = GetAddress("waveOutWrite");
	pfnnew_wid32Message = GetAddress("wid32Message");
	pfnnew_winmmDbgOut = GetAddress("winmmDbgOut");
	pfnnew_winmmSetDebugLevel = GetAddress("winmmSetDebugLevel");
	pfnnew_wod32Message = GetAddress("wod32Message");
	return TRUE;
}	
DWORD WINAPI ThreadProc(LPVOID lpThreadParameter)
{

	HANDLE hProcess;

	//PVOID addr1 = reinterpret_cast<PVOID>(0x00401000);
	BYTE data1[] = { 0xFF ,0x83 ,0xF8 ,0x04 ,0x74 ,0x09 ,0xC7 ,0x45 ,0xF8 ,0x01 };
	TCHAR mcode[MAX_PATH];

	std::vector <DWORD> vResultContainer = FindSigX32(GetCurrentProcessId(), "FF83F8047409C745F800", (DWORD)GetModuleHandle("CommEngine.dll"), 0x7fffffff);

	hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId());
	if (hProcess)
	{
		int nSize1 = 0;
		for (auto it = vResultContainer.begin(); it != vResultContainer.end();it++)
		{
			PVOID addr1 = reinterpret_cast<PVOID>(*it);
			WriteProcessMemory(hProcess, addr1, data1, sizeof(data1), NULL);
			wsprintf(mcode, TEXT("地址为:%x"), *it);
			//MessageBox(NULL, mcode, TEXT("AheadLib"), MB_ICONINFORMATION);
			nSize1++;
		}
		wsprintf(mcode, TEXT("数量为:%d"), nSize1);
		//MessageBox(NULL, mcode, TEXT("AheadLib"), MB_ICONINFORMATION);
		CloseHandle(hProcess);
	}

	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		if (Load() && Init())
		{
			TCHAR szAppName1[MAX_PATH] = TEXT("ClassIn.exe");//请修改宿主进程名
			TCHAR szCurName1[MAX_PATH];

			GetModuleFileName(NULL, szCurName1, MAX_PATH);
			PathStripPath(szCurName1);

			//是否判断宿主进程名
			if (StrCmpI(szCurName1, szAppName1) == 0)
			{
				//启动补丁线程或者其他操作
				MessageBox(NULL, "已获取教师权限！", TEXT("xuqinyang"), MB_ICONINFORMATION);
				HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
				if (hThread)
				{
					CloseHandle(hThread);
				}
			}
			//TCHAR szAppName2[MAX_PATH] = TEXT("屏录专家HD.exe");//请修改宿主进程名
			//TCHAR szCurName2[MAX_PATH];

			//GetModuleFileName(NULL, szCurName2, MAX_PATH);
			//PathStripPath(szCurName2);

			//是否判断宿主进程名
			//if (StrCmpI(szCurName2, szAppName2) == 0)
			//{
			//	//启动补丁线程或者其他操作
			//	HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
			//	if (hThread)
			//	{
			//		CloseHandle(hThread);
			//	}
			//}
		}
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		Free();
	}

	return TRUE;
}

EXTERN_C __declspec(naked) void __cdecl new_Unnamed2(void)
{
	__asm jmp pfnnew_Unnamed2;
}

EXTERN_C __declspec(naked) void __cdecl new_CloseDriver(void)
{
	__asm jmp pfnnew_CloseDriver;
}

EXTERN_C __declspec(naked) void __cdecl new_DefDriverProc(void)
{
	__asm jmp pfnnew_DefDriverProc;
}

EXTERN_C __declspec(naked) void __cdecl new_DriverCallback(void)
{
	__asm jmp pfnnew_DriverCallback;
}

EXTERN_C __declspec(naked) void __cdecl new_DrvGetModuleHandle(void)
{
	__asm jmp pfnnew_DrvGetModuleHandle;
}

EXTERN_C __declspec(naked) void __cdecl new_GetDriverModuleHandle(void)
{
	__asm jmp pfnnew_GetDriverModuleHandle;
}

EXTERN_C __declspec(naked) void __cdecl new_MigrateAllDrivers(void)
{
	__asm jmp pfnnew_MigrateAllDrivers;
}

EXTERN_C __declspec(naked) void __cdecl new_MigrateSoundEvents(void)
{
	__asm jmp pfnnew_MigrateSoundEvents;
}

EXTERN_C __declspec(naked) void __cdecl new_NotifyCallbackData(void)
{
	__asm jmp pfnnew_NotifyCallbackData;
}

EXTERN_C __declspec(naked) void __cdecl new_OpenDriver(void)
{
	__asm jmp pfnnew_OpenDriver;
}

EXTERN_C __declspec(naked) void __cdecl new_PlaySound(void)
{
	__asm jmp pfnnew_PlaySound;
}

EXTERN_C __declspec(naked) void __cdecl new_PlaySoundA(void)
{
	__asm jmp pfnnew_PlaySoundA;
}

EXTERN_C __declspec(naked) void __cdecl new_PlaySoundW(void)
{
	__asm jmp pfnnew_PlaySoundW;
}

EXTERN_C __declspec(naked) void __cdecl new_SendDriverMessage(void)
{
	__asm jmp pfnnew_SendDriverMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_WOW32DriverCallback(void)
{
	__asm jmp pfnnew_WOW32DriverCallback;
}

EXTERN_C __declspec(naked) void __cdecl new_WOW32ResolveMultiMediaHandle(void)
{
	__asm jmp pfnnew_WOW32ResolveMultiMediaHandle;
}

EXTERN_C __declspec(naked) void __cdecl new_WOWAppExit(void)
{
	__asm jmp pfnnew_WOWAppExit;
}

EXTERN_C __declspec(naked) void __cdecl new_WinmmLogoff(void)
{
	__asm jmp pfnnew_WinmmLogoff;
}

EXTERN_C __declspec(naked) void __cdecl new_WinmmLogon(void)
{
	__asm jmp pfnnew_WinmmLogon;
}

EXTERN_C __declspec(naked) void __cdecl new_aux32Message(void)
{
	__asm jmp pfnnew_aux32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_auxGetDevCapsA(void)
{
	__asm jmp pfnnew_auxGetDevCapsA;
}

EXTERN_C __declspec(naked) void __cdecl new_auxGetDevCapsW(void)
{
	__asm jmp pfnnew_auxGetDevCapsW;
}

EXTERN_C __declspec(naked) void __cdecl new_auxGetNumDevs(void)
{
	__asm jmp pfnnew_auxGetNumDevs;
}

EXTERN_C __declspec(naked) void __cdecl new_auxGetVolume(void)
{
	__asm jmp pfnnew_auxGetVolume;
}

EXTERN_C __declspec(naked) void __cdecl new_auxOutMessage(void)
{
	__asm jmp pfnnew_auxOutMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_auxSetVolume(void)
{
	__asm jmp pfnnew_auxSetVolume;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxAddGfx(void)
{
	__asm jmp pfnnew_gfxAddGfx;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxBatchChange(void)
{
	__asm jmp pfnnew_gfxBatchChange;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxCreateGfxFactoriesList(void)
{
	__asm jmp pfnnew_gfxCreateGfxFactoriesList;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxCreateZoneFactoriesList(void)
{
	__asm jmp pfnnew_gfxCreateZoneFactoriesList;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxDestroyDeviceInterfaceList(void)
{
	__asm jmp pfnnew_gfxDestroyDeviceInterfaceList;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxEnumerateGfxs(void)
{
	__asm jmp pfnnew_gfxEnumerateGfxs;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxLogoff(void)
{
	__asm jmp pfnnew_gfxLogoff;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxLogon(void)
{
	__asm jmp pfnnew_gfxLogon;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxModifyGfx(void)
{
	__asm jmp pfnnew_gfxModifyGfx;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxOpenGfx(void)
{
	__asm jmp pfnnew_gfxOpenGfx;
}

EXTERN_C __declspec(naked) void __cdecl new_gfxRemoveGfx(void)
{
	__asm jmp pfnnew_gfxRemoveGfx;
}

EXTERN_C __declspec(naked) void __cdecl new_joy32Message(void)
{
	__asm jmp pfnnew_joy32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_joyConfigChanged(void)
{
	__asm jmp pfnnew_joyConfigChanged;
}

EXTERN_C __declspec(naked) void __cdecl new_joyGetDevCapsA(void)
{
	__asm jmp pfnnew_joyGetDevCapsA;
}

EXTERN_C __declspec(naked) void __cdecl new_joyGetDevCapsW(void)
{
	__asm jmp pfnnew_joyGetDevCapsW;
}

EXTERN_C __declspec(naked) void __cdecl new_joyGetNumDevs(void)
{
	__asm jmp pfnnew_joyGetNumDevs;
}

EXTERN_C __declspec(naked) void __cdecl new_joyGetPos(void)
{
	__asm jmp pfnnew_joyGetPos;
}

EXTERN_C __declspec(naked) void __cdecl new_joyGetPosEx(void)
{
	__asm jmp pfnnew_joyGetPosEx;
}

EXTERN_C __declspec(naked) void __cdecl new_joyGetThreshold(void)
{
	__asm jmp pfnnew_joyGetThreshold;
}

EXTERN_C __declspec(naked) void __cdecl new_joyReleaseCapture(void)
{
	__asm jmp pfnnew_joyReleaseCapture;
}

EXTERN_C __declspec(naked) void __cdecl new_joySetCapture(void)
{
	__asm jmp pfnnew_joySetCapture;
}

EXTERN_C __declspec(naked) void __cdecl new_joySetThreshold(void)
{
	__asm jmp pfnnew_joySetThreshold;
}

EXTERN_C __declspec(naked) void __cdecl new_mci32Message(void)
{
	__asm jmp pfnnew_mci32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_mciDriverNotify(void)
{
	__asm jmp pfnnew_mciDriverNotify;
}

EXTERN_C __declspec(naked) void __cdecl new_mciDriverYield(void)
{
	__asm jmp pfnnew_mciDriverYield;
}

EXTERN_C __declspec(naked) void __cdecl new_mciExecute(void)
{
	__asm jmp pfnnew_mciExecute;
}

EXTERN_C __declspec(naked) void __cdecl new_mciFreeCommandResource(void)
{
	__asm jmp pfnnew_mciFreeCommandResource;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetCreatorTask(void)
{
	__asm jmp pfnnew_mciGetCreatorTask;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetDeviceIDA(void)
{
	__asm jmp pfnnew_mciGetDeviceIDA;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetDeviceIDFromElementIDA(void)
{
	__asm jmp pfnnew_mciGetDeviceIDFromElementIDA;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetDeviceIDFromElementIDW(void)
{
	__asm jmp pfnnew_mciGetDeviceIDFromElementIDW;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetDeviceIDW(void)
{
	__asm jmp pfnnew_mciGetDeviceIDW;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetDriverData(void)
{
	__asm jmp pfnnew_mciGetDriverData;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetErrorStringA(void)
{
	__asm jmp pfnnew_mciGetErrorStringA;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetErrorStringW(void)
{
	__asm jmp pfnnew_mciGetErrorStringW;
}

EXTERN_C __declspec(naked) void __cdecl new_mciGetYieldProc(void)
{
	__asm jmp pfnnew_mciGetYieldProc;
}

EXTERN_C __declspec(naked) void __cdecl new_mciLoadCommandResource(void)
{
	__asm jmp pfnnew_mciLoadCommandResource;
}

EXTERN_C __declspec(naked) void __cdecl new_mciSendCommandA(void)
{
	__asm jmp pfnnew_mciSendCommandA;
}

EXTERN_C __declspec(naked) void __cdecl new_mciSendCommandW(void)
{
	__asm jmp pfnnew_mciSendCommandW;
}

EXTERN_C __declspec(naked) void __cdecl new_mciSendStringA(void)
{
	__asm jmp pfnnew_mciSendStringA;
}

EXTERN_C __declspec(naked) void __cdecl new_mciSendStringW(void)
{
	__asm jmp pfnnew_mciSendStringW;
}

EXTERN_C __declspec(naked) void __cdecl new_mciSetDriverData(void)
{
	__asm jmp pfnnew_mciSetDriverData;
}

EXTERN_C __declspec(naked) void __cdecl new_mciSetYieldProc(void)
{
	__asm jmp pfnnew_mciSetYieldProc;
}

EXTERN_C __declspec(naked) void __cdecl new_mid32Message(void)
{
	__asm jmp pfnnew_mid32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_midiConnect(void)
{
	__asm jmp pfnnew_midiConnect;
}

EXTERN_C __declspec(naked) void __cdecl new_midiDisconnect(void)
{
	__asm jmp pfnnew_midiDisconnect;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInAddBuffer(void)
{
	__asm jmp pfnnew_midiInAddBuffer;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInClose(void)
{
	__asm jmp pfnnew_midiInClose;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInGetDevCapsA(void)
{
	__asm jmp pfnnew_midiInGetDevCapsA;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInGetDevCapsW(void)
{
	__asm jmp pfnnew_midiInGetDevCapsW;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInGetErrorTextA(void)
{
	__asm jmp pfnnew_midiInGetErrorTextA;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInGetErrorTextW(void)
{
	__asm jmp pfnnew_midiInGetErrorTextW;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInGetID(void)
{
	__asm jmp pfnnew_midiInGetID;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInGetNumDevs(void)
{
	__asm jmp pfnnew_midiInGetNumDevs;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInMessage(void)
{
	__asm jmp pfnnew_midiInMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInOpen(void)
{
	__asm jmp pfnnew_midiInOpen;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInPrepareHeader(void)
{
	__asm jmp pfnnew_midiInPrepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInReset(void)
{
	__asm jmp pfnnew_midiInReset;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInStart(void)
{
	__asm jmp pfnnew_midiInStart;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInStop(void)
{
	__asm jmp pfnnew_midiInStop;
}

EXTERN_C __declspec(naked) void __cdecl new_midiInUnprepareHeader(void)
{
	__asm jmp pfnnew_midiInUnprepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutCacheDrumPatches(void)
{
	__asm jmp pfnnew_midiOutCacheDrumPatches;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutCachePatches(void)
{
	__asm jmp pfnnew_midiOutCachePatches;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutClose(void)
{
	__asm jmp pfnnew_midiOutClose;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutGetDevCapsA(void)
{
	__asm jmp pfnnew_midiOutGetDevCapsA;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutGetDevCapsW(void)
{
	__asm jmp pfnnew_midiOutGetDevCapsW;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutGetErrorTextA(void)
{
	__asm jmp pfnnew_midiOutGetErrorTextA;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutGetErrorTextW(void)
{
	__asm jmp pfnnew_midiOutGetErrorTextW;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutGetID(void)
{
	__asm jmp pfnnew_midiOutGetID;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutGetNumDevs(void)
{
	__asm jmp pfnnew_midiOutGetNumDevs;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutGetVolume(void)
{
	__asm jmp pfnnew_midiOutGetVolume;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutLongMsg(void)
{
	__asm jmp pfnnew_midiOutLongMsg;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutMessage(void)
{
	__asm jmp pfnnew_midiOutMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutOpen(void)
{
	__asm jmp pfnnew_midiOutOpen;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutPrepareHeader(void)
{
	__asm jmp pfnnew_midiOutPrepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutReset(void)
{
	__asm jmp pfnnew_midiOutReset;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutSetVolume(void)
{
	__asm jmp pfnnew_midiOutSetVolume;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutShortMsg(void)
{
	__asm jmp pfnnew_midiOutShortMsg;
}

EXTERN_C __declspec(naked) void __cdecl new_midiOutUnprepareHeader(void)
{
	__asm jmp pfnnew_midiOutUnprepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamClose(void)
{
	__asm jmp pfnnew_midiStreamClose;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamOpen(void)
{
	__asm jmp pfnnew_midiStreamOpen;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamOut(void)
{
	__asm jmp pfnnew_midiStreamOut;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamPause(void)
{
	__asm jmp pfnnew_midiStreamPause;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamPosition(void)
{
	__asm jmp pfnnew_midiStreamPosition;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamProperty(void)
{
	__asm jmp pfnnew_midiStreamProperty;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamRestart(void)
{
	__asm jmp pfnnew_midiStreamRestart;
}

EXTERN_C __declspec(naked) void __cdecl new_midiStreamStop(void)
{
	__asm jmp pfnnew_midiStreamStop;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerClose(void)
{
	__asm jmp pfnnew_mixerClose;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetControlDetailsA(void)
{
	__asm jmp pfnnew_mixerGetControlDetailsA;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetControlDetailsW(void)
{
	__asm jmp pfnnew_mixerGetControlDetailsW;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetDevCapsA(void)
{
	__asm jmp pfnnew_mixerGetDevCapsA;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetDevCapsW(void)
{
	__asm jmp pfnnew_mixerGetDevCapsW;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetID(void)
{
	__asm jmp pfnnew_mixerGetID;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetLineControlsA(void)
{
	__asm jmp pfnnew_mixerGetLineControlsA;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetLineControlsW(void)
{
	__asm jmp pfnnew_mixerGetLineControlsW;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetLineInfoA(void)
{
	__asm jmp pfnnew_mixerGetLineInfoA;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetLineInfoW(void)
{
	__asm jmp pfnnew_mixerGetLineInfoW;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerGetNumDevs(void)
{
	__asm jmp pfnnew_mixerGetNumDevs;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerMessage(void)
{
	__asm jmp pfnnew_mixerMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerOpen(void)
{
	__asm jmp pfnnew_mixerOpen;
}

EXTERN_C __declspec(naked) void __cdecl new_mixerSetControlDetails(void)
{
	__asm jmp pfnnew_mixerSetControlDetails;
}

EXTERN_C __declspec(naked) void __cdecl new_mmDrvInstall(void)
{
	__asm jmp pfnnew_mmDrvInstall;
}

EXTERN_C __declspec(naked) void __cdecl new_mmGetCurrentTask(void)
{
	__asm jmp pfnnew_mmGetCurrentTask;
}

EXTERN_C __declspec(naked) void __cdecl new_mmTaskBlock(void)
{
	__asm jmp pfnnew_mmTaskBlock;
}

EXTERN_C __declspec(naked) void __cdecl new_mmTaskCreate(void)
{
	__asm jmp pfnnew_mmTaskCreate;
}

EXTERN_C __declspec(naked) void __cdecl new_mmTaskSignal(void)
{
	__asm jmp pfnnew_mmTaskSignal;
}

EXTERN_C __declspec(naked) void __cdecl new_mmTaskYield(void)
{
	__asm jmp pfnnew_mmTaskYield;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioAdvance(void)
{
	__asm jmp pfnnew_mmioAdvance;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioAscend(void)
{
	__asm jmp pfnnew_mmioAscend;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioClose(void)
{
	__asm jmp pfnnew_mmioClose;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioCreateChunk(void)
{
	__asm jmp pfnnew_mmioCreateChunk;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioDescend(void)
{
	__asm jmp pfnnew_mmioDescend;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioFlush(void)
{
	__asm jmp pfnnew_mmioFlush;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioGetInfo(void)
{
	__asm jmp pfnnew_mmioGetInfo;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioInstallIOProcA(void)
{
	__asm jmp pfnnew_mmioInstallIOProcA;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioInstallIOProcW(void)
{
	__asm jmp pfnnew_mmioInstallIOProcW;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioOpenA(void)
{
	__asm jmp pfnnew_mmioOpenA;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioOpenW(void)
{
	__asm jmp pfnnew_mmioOpenW;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioRead(void)
{
	__asm jmp pfnnew_mmioRead;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioRenameA(void)
{
	__asm jmp pfnnew_mmioRenameA;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioRenameW(void)
{
	__asm jmp pfnnew_mmioRenameW;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioSeek(void)
{
	__asm jmp pfnnew_mmioSeek;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioSendMessage(void)
{
	__asm jmp pfnnew_mmioSendMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioSetBuffer(void)
{
	__asm jmp pfnnew_mmioSetBuffer;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioSetInfo(void)
{
	__asm jmp pfnnew_mmioSetInfo;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioStringToFOURCCA(void)
{
	__asm jmp pfnnew_mmioStringToFOURCCA;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioStringToFOURCCW(void)
{
	__asm jmp pfnnew_mmioStringToFOURCCW;
}

EXTERN_C __declspec(naked) void __cdecl new_mmioWrite(void)
{
	__asm jmp pfnnew_mmioWrite;
}

EXTERN_C __declspec(naked) void __cdecl new_mmsystemGetVersion(void)
{
	__asm jmp pfnnew_mmsystemGetVersion;
}

EXTERN_C __declspec(naked) void __cdecl new_mod32Message(void)
{
	__asm jmp pfnnew_mod32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_mxd32Message(void)
{
	__asm jmp pfnnew_mxd32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_sndPlaySoundA(void)
{
	__asm jmp pfnnew_sndPlaySoundA;
}

EXTERN_C __declspec(naked) void __cdecl new_sndPlaySoundW(void)
{
	__asm jmp pfnnew_sndPlaySoundW;
}

EXTERN_C __declspec(naked) void __cdecl new_tid32Message(void)
{
	__asm jmp pfnnew_tid32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_timeBeginPeriod(void)
{
	__asm jmp pfnnew_timeBeginPeriod;
}

EXTERN_C __declspec(naked) void __cdecl new_timeEndPeriod(void)
{
	__asm jmp pfnnew_timeEndPeriod;
}

EXTERN_C __declspec(naked) void __cdecl new_timeGetDevCaps(void)
{
	__asm jmp pfnnew_timeGetDevCaps;
}

EXTERN_C __declspec(naked) void __cdecl new_timeGetSystemTime(void)
{
	__asm jmp pfnnew_timeGetSystemTime;
}

EXTERN_C __declspec(naked) void __cdecl new_timeGetTime(void)
{
	__asm jmp pfnnew_timeGetTime;
}

EXTERN_C __declspec(naked) void __cdecl new_timeKillEvent(void)
{
	__asm jmp pfnnew_timeKillEvent;
}

EXTERN_C __declspec(naked) void __cdecl new_timeSetEvent(void)
{
	__asm jmp pfnnew_timeSetEvent;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInAddBuffer(void)
{
	__asm jmp pfnnew_waveInAddBuffer;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInClose(void)
{
	__asm jmp pfnnew_waveInClose;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInGetDevCapsA(void)
{
	__asm jmp pfnnew_waveInGetDevCapsA;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInGetDevCapsW(void)
{
	__asm jmp pfnnew_waveInGetDevCapsW;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInGetErrorTextA(void)
{
	__asm jmp pfnnew_waveInGetErrorTextA;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInGetErrorTextW(void)
{
	__asm jmp pfnnew_waveInGetErrorTextW;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInGetID(void)
{
	__asm jmp pfnnew_waveInGetID;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInGetNumDevs(void)
{
	__asm jmp pfnnew_waveInGetNumDevs;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInGetPosition(void)
{
	__asm jmp pfnnew_waveInGetPosition;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInMessage(void)
{
	__asm jmp pfnnew_waveInMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInOpen(void)
{
	__asm jmp pfnnew_waveInOpen;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInPrepareHeader(void)
{
	__asm jmp pfnnew_waveInPrepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInReset(void)
{
	__asm jmp pfnnew_waveInReset;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInStart(void)
{
	__asm jmp pfnnew_waveInStart;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInStop(void)
{
	__asm jmp pfnnew_waveInStop;
}

EXTERN_C __declspec(naked) void __cdecl new_waveInUnprepareHeader(void)
{
	__asm jmp pfnnew_waveInUnprepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutBreakLoop(void)
{
	__asm jmp pfnnew_waveOutBreakLoop;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutClose(void)
{
	__asm jmp pfnnew_waveOutClose;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetDevCapsA(void)
{
	__asm jmp pfnnew_waveOutGetDevCapsA;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetDevCapsW(void)
{
	__asm jmp pfnnew_waveOutGetDevCapsW;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetErrorTextA(void)
{
	__asm jmp pfnnew_waveOutGetErrorTextA;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetErrorTextW(void)
{
	__asm jmp pfnnew_waveOutGetErrorTextW;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetID(void)
{
	__asm jmp pfnnew_waveOutGetID;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetNumDevs(void)
{
	__asm jmp pfnnew_waveOutGetNumDevs;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetPitch(void)
{
	__asm jmp pfnnew_waveOutGetPitch;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetPlaybackRate(void)
{
	__asm jmp pfnnew_waveOutGetPlaybackRate;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetPosition(void)
{
	__asm jmp pfnnew_waveOutGetPosition;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutGetVolume(void)
{
	__asm jmp pfnnew_waveOutGetVolume;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutMessage(void)
{
	__asm jmp pfnnew_waveOutMessage;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutOpen(void)
{
	__asm jmp pfnnew_waveOutOpen;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutPause(void)
{
	__asm jmp pfnnew_waveOutPause;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutPrepareHeader(void)
{
	__asm jmp pfnnew_waveOutPrepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutReset(void)
{
	__asm jmp pfnnew_waveOutReset;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutRestart(void)
{
	__asm jmp pfnnew_waveOutRestart;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutSetPitch(void)
{
	__asm jmp pfnnew_waveOutSetPitch;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutSetPlaybackRate(void)
{
	__asm jmp pfnnew_waveOutSetPlaybackRate;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutSetVolume(void)
{
	__asm jmp pfnnew_waveOutSetVolume;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutUnprepareHeader(void)
{
	__asm jmp pfnnew_waveOutUnprepareHeader;
}

EXTERN_C __declspec(naked) void __cdecl new_waveOutWrite(void)
{
	__asm jmp pfnnew_waveOutWrite;
}

EXTERN_C __declspec(naked) void __cdecl new_wid32Message(void)
{
	__asm jmp pfnnew_wid32Message;
}

EXTERN_C __declspec(naked) void __cdecl new_winmmDbgOut(void)
{
	__asm jmp pfnnew_winmmDbgOut;
}

EXTERN_C __declspec(naked) void __cdecl new_winmmSetDebugLevel(void)
{
	__asm jmp pfnnew_winmmSetDebugLevel;
}

EXTERN_C __declspec(naked) void __cdecl new_wod32Message(void)
{
	__asm jmp pfnnew_wod32Message;
}

