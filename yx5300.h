#ifndef YX5300_H
#define YX5300_H

class player{
    public:
        player(int tx_pin, int rx_pin);
        void init();
        void play(int8_t folder, int8_t file_prefix);
        void playLoop(int8_t folder);
        void setVolume(int8_t volume);
        void increaseVolume();
        void decreaseVolume();
        void pause();
        void resume();
        void stop();
        void prev();
        void next();
    
    private:
        void command(int8_t command, int8_t parameter1, int8_t parameter2);
        SoftwareSerial serializer;
};

#endif
