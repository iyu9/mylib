setlocal
if "%1" equ "eth0" (
    set eth0="イーサネット"
) else (
    set eth0="%1"
)
REM echo %eth0%
netsh interface set interface %eth0% enabled
