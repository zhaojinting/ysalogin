#############################################################################
# Makefile for building: ysalogin
# Generated by qmake (3.0) (Qt 5.6.3)
# Project:  ysalogin.pro
# Template: app
# Command: C:\Qt\Qt5.6.3\5.6.3\msvc2013_64\bin\qmake.exe -spec win32-msvc2013 -o Makefile ysalogin.pro
#############################################################################

MAKEFILE      = Makefile

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = C:\Qt\Qt5.6.3\5.6.3\msvc2013_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: ysalogin.pro ..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\win32-msvc2013\qmake.conf ..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\spec_pre.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\common\angle.conf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\common\msvc-base.conf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\common\msvc-desktop.conf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\qconfig.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dcore.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dcore_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dinput.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dinput_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dlogic.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dlogic_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquick.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquick_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickinput.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickinput_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickrender.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickrender_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3drender.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3drender_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axbase.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axserver.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_clucene_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_core.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_core_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_dbus.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_dbus_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_designer.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_gui.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_help.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_help_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_labscontrols_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_labstemplates_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_location.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_location_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_network.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_network_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_nfc.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_opengl.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_platformsupport_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_positioning.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qml.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quick.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_script.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_script_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_scripttools.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_scripttools_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sensors.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialbus.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialbus_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialport.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sql.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_svg.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_testlib.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_uiplugin.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_uitools.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webchannel.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webchannel_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webengine.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webengine_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginecore.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginecore_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_websockets.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webview.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webview_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_widgets.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_winextras.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xml.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_zlib_private.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\qt_functions.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\qt_config.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\qt_config.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\win32-msvc2013\qmake.conf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\spec_post.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\exclusive_builds.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\default_pre.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\default_pre.prf \
		..\NConfig\NConfig_inc.pri \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\resolve_config.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\exclusive_builds_post.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\default_post.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\rtti.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\precompile_header.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\warn_on.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\qt.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\resources.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\moc.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\opengl.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\uic.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\file_copies.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\windows.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\testcase_targets.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\exceptions.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\yacc.prf \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\lex.prf \
		ysalogin.pro \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\qtmain.prl \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Widgets.prl \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Gui.prl \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Network.prl \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Sql.prl \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5SerialPort.prl \
		..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Core.prl
	$(QMAKE) -spec win32-msvc2013 -o Makefile ysalogin.pro
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\spec_pre.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\common\angle.conf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\common\msvc-base.conf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\common\msvc-desktop.conf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\qconfig.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dcore.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dcore_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dinput.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dinput_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dlogic.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dlogic_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquick.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquick_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickinput.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickinput_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickrender.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3dquickrender_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3drender.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_3drender_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axbase.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axserver.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_clucene_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_concurrent.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_core.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_core_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_dbus.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_dbus_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_designer.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_designer_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_gui.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_gui_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_help.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_help_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_labscontrols_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_labstemplates_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_location.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_location_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimedia.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_network.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_network_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_nfc.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_opengl.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_platformsupport_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_positioning.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_printsupport.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qml.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qml_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qmltest.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quick.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quick_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_script.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_script_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_scripttools.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_scripttools_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sensors.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialbus.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialbus_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialport.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sql.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_sql_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_svg.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_svg_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_testlib.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_uiplugin.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_uitools.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webchannel.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webchannel_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webengine.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webengine_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginecore.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginecore_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_websockets.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webview.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_webview_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_widgets.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_winextras.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xml.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xml_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\modules\qt_lib_zlib_private.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\qt_functions.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\qt_config.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\qt_config.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\win32-msvc2013\qmake.conf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\spec_post.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\exclusive_builds.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\default_pre.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\default_pre.prf:
..\NConfig\NConfig_inc.pri:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\resolve_config.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\exclusive_builds_post.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\default_post.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\rtti.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\precompile_header.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\warn_on.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\qt.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\resources.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\moc.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\opengl.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\uic.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\file_copies.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\win32\windows.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\testcase_targets.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\exceptions.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\yacc.prf:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\mkspecs\features\lex.prf:
ysalogin.pro:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\qtmain.prl:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Widgets.prl:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Gui.prl:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Network.prl:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Sql.prl:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5SerialPort.prl:
..\..\Qt\Qt5.6.3\5.6.3\msvc2013_64\lib\Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-msvc2013 -o Makefile ysalogin.pro

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
	-$(DEL_FILE) ..\..\bin\ysalogin.exp
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) ..\..\bin\ysalogin.lib

release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
