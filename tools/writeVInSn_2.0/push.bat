@echo off
setlocal

set SOURCE_FILE=VinSn.txt
set BOARD_IP=10.19.194.207
set DESTINATION_DIR=/home/fanbh
set SSH_USERNAME=fanbh
set SSH_PASSWORD=fanbh

echo 1. ping %BOARD_IP%
ping %BOARD_IP% -n 1 > nul
if %errorlevel% neq 0 (
    echo %BOARD_IP% is unreachable.
	pause
    exit /b
)
echo %BOARD_IP% is reachable.

echo.
echo 2. start Pushing file %SOURCE_FILE% to board %BOARD_IP%...
scp "%SOURCE_FILE%" "%SSH_USERNAME%@%BOARD_IP%:%DESTINATION_DIR%"
if %errorlevel% neq 0 (
    echo Failed to copy %SOURCE_FILE% to %BOARD_IP%:%DESTINATION_DIR%
  	pause
    exit /b
)
echo %SOURCE_FILE% pushing to %BOARD_IP%:%DESTINATION_DIR% successfully
 
echo.
echo 3.start converting
ssh %SSH_USERNAME%:%SSH_PASSWORD%@%BOARD_IP% "cd %DESTINATION_DIR% && sed -i 's/\r//'  VinSn.txt"
if %errorlevel% equ 0 (
    echo converting executed successfully.
) else (
    echo converting failed.
	exit /b
)

echo.  
echo 已成功写入%SOURCE_FILE%到%BOARD_IP%:%DESTINATION_DIR%
pause
endlocal
