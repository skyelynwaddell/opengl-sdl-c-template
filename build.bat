@echo off
echo Creating bin folder...
if not exist bin mkdir bin

echo Compiling...
gcc -g -Wall -std=c99 src\*.c src\lib\glad\*.c src\system\*.c src\gameloop\*.c -Isrc\lib\glad -IC:\dev\SDL2-2.30.8\include -LC:\dev\SDL2-2.30.8\lib\x64 -lSDL2main -lSDL2 -o bin/game.exe

if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b %errorlevel%
)

echo Compilation successful! Launching game with GDB...

:: Launch gdb with suppressed thread messages and no paging
gdb -q bin/game.exe -ex "set pagination off" -ex "set verbose off" -ex "set print thread-events off" -ex run
