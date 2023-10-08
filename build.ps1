$CompilerOptions =
"/Fo.\obj\",
"/c",
"/std:c++latest",
""


$LinkerOptions =
"/OUT:.\bin\windows_app.exe",
"/ENTRY:Start",
"/SUBSYSTEM:CONSOLE",
"/DEFAULTLIB:Kernel32.lib",
"/DEFAULTLIB:User32.lib",
""


Remove-Item -Path ".\obj\*"
& cl.exe $CompilerOptions (Get-ChildItem -Path ".\src\*" -Filter "*.cpp" -Recurse -File).FullName

Remove-Item -Path ".\bin\*" -Exclude "config.ini"
& link.exe $LinkerOptions ".\obj\*"