# Arduino YX5300 [![License: GPL v2](https://img.shields.io/badge/License-GPLv2-informational)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html) ![version 0.3](https://img.shields.io/badge/version-0.3-blue)

~~Crude and hastily written~~ *Simple* Arduino library for YX5300/HW-311 Serial MP3 Player.

## docs
Create player object: 

* if connected via UART (pins `0`,`1`/`TX`,`RX`): 
`YXPlayer mp3 = YXPlayer();`

* if connected via PCINT (aka SoftwareSerial): 
`YXPlayer mp3 = YXPlayer(TXpin, RXpin);`

And initialize it: 
`mp3.init();` 
(this basically just sets playback location to SD card).

Available methods: 

| Method | Description |
| --- | --- |
| `play(file);` | Play file (1 - first on SD, 2 - second etc.) |
| `playName(folder, file_prefix);` | Play file from folder with 3-digit file name prefix |
| `playLoop(file);` | Play file in loop |
| `playFolderLoop(folder);` | Play files from folder in loop |
| `playWithVolume(file, volume);` | Play file with given volume |
| `setVolume(volume);` | Set playback volume |
| `incVolume();` | Increase volume by 1 |
| `decVolume();` | Decrease volume by 1 |
| `pause();` | Pause playback |
| `resume();` | Resume playback |
| `stop();` | Stop playback |
| `prev();` | Play previous file |
| `next();` | Play next file |
| `sleep();` | Enter sleep mode |
| `wake();` | Wake from sleep mode |
| `reset();` | Reset player (call `init()` afterwards) |
| `shuffle();` | Play files in shuffle |
| `loop(true\|false);` | Set loop playback on currently playing file |
| `dac(true\|false);` | Turn on/off DAC |