setlocal
if "%1" equ "eth0" (
    set eth0="�C�[�T�l�b�g"
) else (
    set eth0="%1"
)
REM echo %eth0%
netsh interface set interface %eth0% enabled
