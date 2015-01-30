@ECHO OFF
TITLE Clean
CLS
ECHO *
ECHO *******************************************************************************
ECHO *                            STM32F10x-IAP-UART
ECHO *
ECHO *
ECHO * Filename    : Clean.bat
ECHO * Description : Batch file to clean the listing files, output files and so on.
ECHO * Usage       : Clean
ECHO * Author      : ЛЊаж
ECHO * Email       : 591881218@qq.com
ECHO *******************************************************************************
ECHO *
ECHO.
ECHO Cleaning files ...
ECHO.
ECHO.
PAUSE
DEL .\MDK-ARM\Listing\*.* /f /q
DEL .\MDK-ARM\Output\*.* /f /q