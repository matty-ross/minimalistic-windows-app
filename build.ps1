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
""

Remove-Item -Path ".\obj\*"
& cl.exe $CompilerOptions ".\src\*"


Remove-Item -Path ".\bin\*"
& link.exe $LinkerOptions ".\obj\*"