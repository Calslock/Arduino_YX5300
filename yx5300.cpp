#include "yx5300.hh"
#include <Arduino.h>
#include <SoftwareSerial.h>

player::player(int tx_pin, int rx_pin){
    serializer = SoftwareSerial(tx_pin, rx_pin);
}

void player::command(int8_t command, int8_t parameter1, int8_t parameter2){
    delay(20);

    cmdbuf[8] = {
        0x7e, 0xff, 0x06, command, 0x00, parameter1, parameter2, 0xef
    };
    for (int i = 0; i < 8; i++){
        serializer.write(cmdbuf[i]);
    }
}

void player::init(){
    delay(500);
    command(0x09, 0x00, 0x02);
    delay(200);
}

void player::play(int8_t folder, int8_t file_prefix){
    command(0x0F, folder, file_prefix);
}

void player::playLoop(int8_t folder){
    command(0x17, folder, 0x00);
}

void player::setVolume(int8_t volume){
    command(0x06, 0x00, volume);
}

void player::increaseVolume(){
    command(0x04, 0x00, 0x00);
}

void player::decreaseVolume(){
    command(0x05, 0x00, 0x00);
}

void player::pause(){
    command(0x0e, 0x00, 0x00);
}

void player::resume(){
    command(0x0d, 0x00, 0x00);
}

void player::stop(){
    command(0x16, 0x00, 0x00);
}

void player::prev(){
    command(0x02, 0x00, 0x00);
}

void player::next(){
    command(0x01, 0x00, 0x00);
}