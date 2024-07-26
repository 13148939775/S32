@echo off
setlocal

set SOURCE_FILE=server_arm_64
set DESTINATION_DIR=/home/root/log/
set BOARD_IP=169.254.30.190
set SSH_USERNAME=root
set SSH_PASSWORD=

echo Pushing file %SOURCE_FILE% to board %BOARD_IP%...

pause

(
    echo put "%SOURCE_FILE%"
    echo quit
) | sftp %SSH_USERNAME%@%BOARD_IP%:%DESTINATION_DIR%

echo File pushed successfully.

pause

endlocal
