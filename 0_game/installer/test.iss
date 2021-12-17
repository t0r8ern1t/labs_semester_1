; Имя приложения
#define   Name       "The hungry mage's story"
; Версия приложения
#define   Version    "6.6.6"
; Фирма-разработчик
#define   Publisher  "Sofia Shirokaya"
; Сафт фирмы разработчика
#define   URL        "https://vk.com/felllllllllllllllllllllllllllix"
; Имя исполняемого модуля
#define   ExeName    "The_hungry_mages_story.exe"

;------------------------------------------------------------------------------
;   Параметры установки
;------------------------------------------------------------------------------
[Setup]

; Уникальный идентификатор приложения, 
;сгенерированный через Tools -> Generate GUID
AppId={{17E79D87-F11A-43C0-94F8-EEE85F139BD1}

; Прочая информация, отображаемая при установке
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

; Путь установки по-умолчанию
DefaultDirName={pf}\{#Name}
; Имя группы в меню "Пуск"
DefaultGroupName={#Name}

; Каталог, куда будет записан собранный setup и имя исполняемого файла
OutputDir=E:\gitkraken\0_game\installer\out
OutputBaseFileName=The_hungry_mages_story

; Файл иконки
SetupIconFile=E:\gitkraken\0_game\img\icon.ico

; Параметры сжатия
Compression=lzma
SolidCompression=yes

;------------------------------------------------------------------------------
;   Устанавливаем языки для процесса установки
;------------------------------------------------------------------------------
[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

;------------------------------------------------------------------------------
;   Опционально - некоторые задачи, которые надо выполнить при установке
;------------------------------------------------------------------------------
[Tasks]
; Создание иконки на рабочем столе
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

;------------------------------------------------------------------------------
;   Файлы, которые надо включить в пакет установщика
;------------------------------------------------------------------------------
[Files]

; Исполняемый файл
Source: "E:\build\0_game\Release\The_hungry_mages_story.exe"; DestDir: "{app}"; Flags: ignoreversion

; Прилагающиеся ресурсы
Source: "E:\gitkraken\0_game\img\*"; DestDir: "{app}\img\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "E:\gitkraken\0_game\fonts\*"; DestDir: "{app}\fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs

; VS Redistributable package
Source: "E:\gitkraken\labs-ver2\0_game\installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
;------------------------------------------------------------------------------
;   Указываем установщику, где он должен взять иконки
;------------------------------------------------------------------------------ 
[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon

[Run]
;------------------------------------------------------------------------------
;   Установка распространяемого пакета VS
;------------------------------------------------------------------------------
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...
