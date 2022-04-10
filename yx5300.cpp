#include "yx5300.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

YXPlayer::YXPlayer(int tx_pin, int rx_pin){
    serialPlayer = new SoftwareSerial(tx_pin, rx_pin, false);
    software = true;
}

YXPlayer::YXPlayer(){
    software = false;
}

YXPlayer::~YXPlayer(){}

//send command with all 3 parameters
void YXPlayer::send(uint8_t command, uint8_t parameter1, uint8_t parameter2, bool feedback=false){
    delay(20);

    uint8_t cmdbuf[8] = {
        0x7e,       //command start
        0xff,       //version
        0x06,       //command length
        command, 
        feedback ? (uint8_t)0x01 : (uint8_t)0x00, 
        parameter1, 
        parameter2, 
        0xef        //ending
    };
    if(software)
        for (int i = 0; i < 8; i++){
            serialPlayer->write(cmdbuf[i]);
        }
    else for (int i = 0; i < 8; i++){
            Serial.write(cmdbuf[i]);
        }
}

//send command with less than 3 parameters:
//if only command given:
//  send(command, 0x00, 0x00)
//if parameter given:
//  send(command, 0x00, parameter)
void YXPlayer::send(uint8_t command, uint8_t parameter=0x00){
    send(command, 0x00, parameter);
}

void YXPlayer::init(){
    if(software) serialPlayer->begin(9600);
    else Serial.begin(9600);
    delay(500);
    send(SELECTDEV, 0x02);
    delay(200);
}

void YXPlayer::play(int8_t file){
    send(PLAYINDEX, file);
}

void YXPlayer::playName(int8_t folder, int8_t file_prefix){
    send(PLAYNAME, folder, file_prefix);
}

void YXPlayer::playLoop(int8_t file){
    send(PLAYLOOP, file);
}

void YXPlayer::playFolderLoop(int8_t folder){
    send(LOOPFOLDER, folder);
}

void YXPlayer::playWithVolume(int8_t file, int8_t volume){
    send(PLAYVOLUME, volume, file);
}

void YXPlayer::setVolume(int8_t volume){
    send(VOLUMESET, volume);
}

void YXPlayer::incVolume(){
    send(VOLUMEUP);
}

void YXPlayer::decVolume(){
    send(VOLUMEDOWN);
}

void YXPlayer::pause(){
    send(PAUSE);
}

void YXPlayer::resume(){
    send(RESUME);
}

void YXPlayer::stop(){
    send(STOP);
}

void YXPlayer::prev(){
    send(PREVFILE);
}

void YXPlayer::next(){
    send(NEXTFILE);
}

void YXPlayer::sleep(){
    send(SLEEP);
}

void YXPlayer::wake(){
    send(WAKEUP);
}

void YXPlayer::reset(){
    send(RESETDEV);
}

void YXPlayer::shuffle(){
    send(SHUFFLE);
}

void YXPlayer::loop(bool status){
    send(LOOP, status ? (uint8_t)0x01 : (uint8_t)0x00);
}

void YXPlayer::dac(bool status){
    send(DAC, status ? (uint8_t)0x01 : (uint8_t)0x00);
}