# Arduino YX5300

~~Crude and hastily written~~ *Simple* Arduino library for YX5300/HW-311 Serial MP3 Player.

## *"documentation"*
In `setup()` create player object: 
`player mp3 = player(TX, RX);`

And initialize it: 
`mp3.init()`

Available methods: 
```
play(folder, file);
playLoop(folder);
setVolume(volume);
increaseVolume();
decreaseVolume();
pause();
resume();
stop();
prev();
next();
```