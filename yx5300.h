#ifndef YX5300_H
#define YX5300_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class YXPlayer{
    public:
        YXPlayer(int tx_pin, int rx_pin);
        YXPlayer();
        ~YXPlayer();
        void init();
        void play(int8_t file);
        void playName(int8_t folder, int8_t file_prefix);
        void playLoop(int8_t file);
        void playFolderLoop(int8_t folder);
        void playWithVolume(int8_t file, int8_t volume);
        void setVolume(int8_t volume);
        void incVolume();
        void decVolume();
        void pause();
        void resume();
        void stop();
        void prev();
        void next();
        void sleep();
        void wake();
        void reset();
        void shuffle();
        void loop(bool status);
        void dac(bool status);

    
    private:
        void send(uint8_t command, uint8_t parameter1, uint8_t parameter2, bool feedback);
        void send(uint8_t command, uint8_t parameter);
        bool software;
        SoftwareSerial* serialPlayer;
        enum cmd{
            NULCMD = 0x00,
            NEXTFILE = 0x01,
            PREVFILE = 0x02,
            PLAYINDEX = 0x03,
            VOLUMEUP = 0x04,
            VOLUMEDOWN = 0x05,
            VOLUMESET = 0x06,
            PLAYLOOP = 0x08,
            SELECTDEV = 0x09,
            SLEEP = 0x0A,
            WAKEUP = 0x0B,
            RESETDEV = 0x0C,
            RESUME = 0x0D,
            PAUSE = 0x0E,
            PLAYNAME = 0x0F,
            STOP = 0x16,
            LOOPFOLDER = 0x17,
            SHUFFLE = 0x18,
            LOOP = 0x19,
            DAC = 0x1A,
            PLAYVOLUME = 0x22
        };
};

#endif
