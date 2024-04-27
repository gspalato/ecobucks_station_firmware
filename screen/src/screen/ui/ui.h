// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"

// SCREEN: ui_SplashScreen
void ui_SplashScreen_screen_init(void);
extern lv_obj_t * ui_SplashScreen;
extern lv_obj_t * ui_SplashScreenSpinner;
// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
extern lv_obj_t * ui_MainScreen;
extern lv_obj_t * ui_FlexContainer;
extern lv_obj_t * ui_MainScreenLogo;
void ui_event_GoToDisposalRegisterScreenButton(lv_event_t * e);
extern lv_obj_t * ui_GoToDisposalRegisterScreenButton;
extern lv_obj_t * ui_GoToDisposalRegisterScreenButtonLabel;
void ui_event_SwipeUpSettings(lv_event_t * e);
extern lv_obj_t * ui_SwipeUpSettings;
// SCREEN: ui_DisposalRegisterScreen
void ui_DisposalRegisterScreen_screen_init(void);
void ui_event_DisposalRegisterScreen(lv_event_t * e);
extern lv_obj_t * ui_DisposalRegisterScreen;
extern lv_obj_t * ui_DisposalRegisterPanel;
extern lv_obj_t * ui_DisposalRegisterHeader;
void ui_event_DisposalRegisterHeaderBackButton(lv_event_t * e);
extern lv_obj_t * ui_DisposalRegisterHeaderBackButton;
extern lv_obj_t * ui_DisposalRegisterHeaderBackButtonIcon;
extern lv_obj_t * ui_DisposalRegisterHeaderTitle;
extern lv_obj_t * ui_DisposalRegisterContainer;
extern lv_obj_t * ui_CurrentWeightLabel;
extern lv_obj_t * ui_WeightRelativeToMaxWeightBar;
extern lv_obj_t * ui_LowerBarContainer;
extern lv_obj_t * ui_WasteTypeDropdown;
void ui_event_RegisterButton(lv_event_t * e);
extern lv_obj_t * ui_RegisterButton;
extern lv_obj_t * ui_RegisterButtonLabel;
// SCREEN: ui_QRCodeScreen
void ui_QRCodeScreen_screen_init(void);
extern lv_obj_t * ui_QRCodeScreen;
extern lv_obj_t * ui_QRCodeScreenPanel;
extern lv_obj_t * ui_CreditsLabel;
extern lv_obj_t * ui_QRCodeContainer;
void ui_event_FinishButton(lv_event_t * e);
extern lv_obj_t * ui_FinishButton;
extern lv_obj_t * ui_FinishButtonLabel;
// SCREEN: ui_SettingsScreen
void ui_SettingsScreen_screen_init(void);
extern lv_obj_t * ui_SettingsScreen;
extern lv_obj_t * ui_ConfigurationPanel;
extern lv_obj_t * ui_SettingsHeader;
void ui_event_SettingsHeaderBackButton(lv_event_t * e);
extern lv_obj_t * ui_SettingsHeaderBackButton;
extern lv_obj_t * ui_SettingHeaderBackButtonIcon;
extern lv_obj_t * ui_SettingsHeaderTitle;
extern lv_obj_t * ui_SettingsOptionsContainer;
void ui_event_WifiConfigurationButton(lv_event_t * e);
extern lv_obj_t * ui_WifiConfigurationButton;
extern lv_obj_t * ui_WifiConfigurationButtonLabel;
// SCREEN: ui_WifiSettingsScreen
void ui_WifiSettingsScreen_screen_init(void);
extern lv_obj_t * ui_WifiSettingsScreen;
extern lv_obj_t * ui_WifiSettingsPanel;
extern lv_obj_t * ui_WifiSettingsHeader;
void ui_event_WifiSettingsHeaderBackButton(lv_event_t * e);
extern lv_obj_t * ui_WifiSettingsHeaderBackButton;
extern lv_obj_t * ui_WifiSettingsHeaderBackIcon;
extern lv_obj_t * ui_WifiSettingsHeaderTitle;
extern lv_obj_t * ui_WifiSettingsContainer;
extern lv_obj_t * ui_WifiSSIDContainer;
extern lv_obj_t * ui_SSIDLabel;
extern lv_obj_t * ui_SSIDDropdown;
void ui_event_RefreshWifisButton(lv_event_t * e);
extern lv_obj_t * ui_RefreshWifisButton;
extern lv_obj_t * ui_RefreshWifisButtonIcon;
extern lv_obj_t * ui_WifiPasswordContainer;
extern lv_obj_t * ui_PasswordLabel;
void ui_event_PasswordTextArea(lv_event_t * e);
extern lv_obj_t * ui_PasswordTextArea;
void ui_event_ConnectToWifiButton(lv_event_t * e);
extern lv_obj_t * ui_ConnectToWifiButton;
extern lv_obj_t * ui_ConnectToWifiButtonLabel;
void ui_event_SetupWifiKeyboard(lv_event_t * e);
extern lv_obj_t * ui_SetupWifiKeyboard;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_1456473992);    // assets/Ecobucks-Station-Firmware-Banner.png
LV_IMG_DECLARE(ui_img_ecobuckstextgradient_png);    // assets/EcobucksTextGradient.png
LV_IMG_DECLARE(ui_img_904781469);    // assets/angle-left-50x50.png
LV_IMG_DECLARE(ui_img_1471181834);    // assets/arrows-rotate-icon-50x50.png



LV_FONT_DECLARE(ui_font_SpaceGrotesk16);
LV_FONT_DECLARE(ui_font_SpaceGrotesk20);
LV_FONT_DECLARE(ui_font_SpaceGrotesk30);
LV_FONT_DECLARE(ui_font_SpaceGroteskBold30);
LV_FONT_DECLARE(ui_font_SpaceGroteskBold16);
LV_FONT_DECLARE(ui_font_SpaceGroteskBold20);
LV_FONT_DECLARE(ui_font_SpaceGroteskBold24);
LV_FONT_DECLARE(ui_font_SpaceGroteskMedium24);
LV_FONT_DECLARE(ui_font_SpaceGroteskMedium16);
LV_FONT_DECLARE(ui_font_SpaceGroteskBold40);
LV_FONT_DECLARE(ui_font_SpaceGroteskMedium20);
LV_FONT_DECLARE(ui_font_SpaceGroteskMedium60);
LV_FONT_DECLARE(ui_font_SyneExtraBold30);
LV_FONT_DECLARE(ui_font_SyneBold30);
LV_FONT_DECLARE(ui_font_SyneSemiBold30);
LV_FONT_DECLARE(ui_font_SyneSemiBold24);



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif