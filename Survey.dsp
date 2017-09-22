# Microsoft Developer Studio Project File - Name="Survey" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Survey - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Survey.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Survey.mak" CFG="Survey - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Survey - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
# Begin Target

# Name "Survey - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BkDialogST.cpp
# End Source File
# Begin Source File

SOURCE=.\cdxCDynamicDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\cdxCDynamicWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\cdxCDynamicWndEx.cpp
# End Source File
# Begin Source File

SOURCE=.\cdxCSizeIconCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\CeXDib.cpp
# End Source File
# Begin Source File

SOURCE=.\CSpreadSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\Curvefit.cpp
# End Source File
# Begin Source File

SOURCE=.\dib256.cpp
# End Source File
# Begin Source File

SOURCE=.\dibpal.cpp
# End Source File
# Begin Source File

SOURCE=.\Digistatic.cpp
# End Source File
# Begin Source File

SOURCE=.\DigiUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\HMXCheckBox.cpp
# End Source File
# Begin Source File

SOURCE=.\HMXDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\HMXStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\HoverEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\PPTooltip.cpp
# End Source File
# Begin Source File

SOURCE=.\SplitStr.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Survey.cpp
# End Source File
# Begin Source File

SOURCE=.\Survey.rc
# End Source File
# Begin Source File

SOURCE=.\SurveyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\XPButton.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BkDialogST.h
# End Source File
# Begin Source File

SOURCE=.\cdxCDynamicDialog.h
# End Source File
# Begin Source File

SOURCE=.\cdxCDynamicWnd.h
# End Source File
# Begin Source File

SOURCE=.\cdxCDynamicWndEx.h
# End Source File
# Begin Source File

SOURCE=.\cdxCSizeIconCtrl.h
# End Source File
# Begin Source File

SOURCE=.\CeXDib.h
# End Source File
# Begin Source File

SOURCE=.\CSpreadSheet.h
# End Source File
# Begin Source File

SOURCE=.\Curvefit.h
# End Source File
# Begin Source File

SOURCE=.\dib256.h
# End Source File
# Begin Source File

SOURCE=.\dibpal.h
# End Source File
# Begin Source File

SOURCE=.\Digistatic.h
# End Source File
# Begin Source File

SOURCE=.\DigiUtil.h
# End Source File
# Begin Source File

SOURCE=.\HMXCheckBox.h
# End Source File
# Begin Source File

SOURCE=.\HMXDialog.h
# End Source File
# Begin Source File

SOURCE=.\HMXStatic.h
# End Source File
# Begin Source File

SOURCE=.\HoverEdit.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\PPTooltip.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Rgbcolor.h
# End Source File
# Begin Source File

SOURCE=.\SplitStr.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Survey.h
# End Source File
# Begin Source File

SOURCE=.\SurveyDlg.h
# End Source File
# Begin Source File

SOURCE=.\TrackControl.h
# End Source File
# Begin Source File

SOURCE=.\XPButton.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\Info.ico
# End Source File
# Begin Source File

SOURCE=.\res\Sky.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Survey.ico
# End Source File
# Begin Source File

SOURCE=.\res\Survey.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
