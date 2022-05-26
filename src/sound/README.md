=======
# Sound Libraries for Chiventure

# TTS
## About
* A simple struct which interfaces with the espeak-ng text-to-speech library
* Find the espeak github here: https://github.com/espeak-ng/espeak-ng

## Basic Structure
```c
    typedef struct{
        char* voicename; // The name of the speaker
        /* voicename cannot be anything - you can find a list of all
        possible voices by running espeak --voices. */
        char* text; // The text which will be spoken
        int buflength; // The buffer length in ms of sound buffers
    } tts_t;
```
## Key Functions
```c
// malloc and fill a tts_t struct with the necessary data
tts_t* init_tts(char* voicename, char* text, int buflength);

// free the malloc'd components of a tts_t struct and the struct itself
void free_tts(tts_t* t);

// use the espeak library to speak the text content of a tts_t struct
void speak(tts_t* t);
```
## Example Demo
There is a working demo of the tts struct in /src/sound/examples called test-tts.c The demo itself is fairly simple, which is a testament to the hassle of using espeak that the struct saves. You can try the demo out for yourself by running the following in /src/sound/examples:
```
make tts
./test-tts
```
Note: for the demo to compile and run properly you will need to have the espeak libraries installed. This can be done with:
```
sudo apt install espeak-ng libespeak-ng1 libespeak-ng-dev
```
## Current Status and Future Changes
The struct and library function, but only at a basic level. The espeak library offers a wide range of options and parameters to alter, which could be fairly easily accounted for by modifying the contents of the struct and altering the calls to speak(). Of course, some additional lines will need to be added to init_tts() and free_tts(), but this is also not a challenge. I leave these tasks for a future group who wants to get their feet wet and understand espeak and the tts struct. It should be a fairly easy 30 points :)

# SDL
## About
* A simple SDL Audio library that will be used to load/play sound file
* The code was inspired from https://gigi.nullneuron.net/gigilabs/playing-a-wav-file-using-sdl2/
* The code referenced for the demo is from https://youtu.be/YB2MbgDsLaA)
* Also recommended to take a look at https://github.com/jakebesworth/Simple-SDL2-Audio, this git repository has an excellent sound library with functioning play/load functions using SDL library 
* Basic structure and design are provided, but the actual implementation are still premature

## Basic Structure
```c
    typedef struct{
        //name of wav file
        char *name;
        // wav file information
        SDL_AudioSpec wavSpec;
        // length of the wav sound file
        uint32_t wavLength;
        // wav file buffer
        uint8_t *wavBuffer;
        //below for hash table
        int id; 
        // makes struct hashable
        UT_hash_handle hh; 
    } sound_t;
```
## Key load/play Functions
```c
// This function must be able to load the sound file to the SDL queue
int load_wav(sound_t *sound);

// This function must be able to play the sound from the SDL queue
int play_sound(sound_t *sound);
```

## Sandbox Demo
Sandbox demo plays the sound file differently to the current sound module. There are multiple ways of playing sound using SDL library, and it would be the next team's task to modularize it effectively. Within the sound.h file, there are demo load and play functions that use the provided library functions from SDL2 and SDL2 mixer. 
From the sandbox directory, you can run 
```
make clean
make
./demo
```

This should build a demo program that opens a window. Once the window opens, background music will play. Anytime key 1 is pressed, a sword slash effect will be played. Pressing q will pause the background music and play a music chunk of Wap by Cardi B. 


## Major Drawbacks
The primary issue with playing sound was our struggle with the CS linux servers and trying to write code through the SSH connection. Multiple members were able to play sounds on our local devices but we were unable to replicate the result on our local machines to the CS server through SSH. Therefore, prior to writing any audio program, we recommend that your terminal can locate audio devices. On the Linux terminal, you can run
```
arecord -l
```

Similar commands for mac/Windows users are
```
system_profiler SPAudioDataType -xm
```
```
Get-CimInstance win32_sounddevice | fl *
```
This command will list all audio devices and sound cards installed in your computer. The primary error message we got when running this command on the CS Linux Servers was:

```
arecord: device_list:274: no soundcards found...
```

The output should look something like this:

```
$ arecord -l
**** List of CAPTURE Hardware Devices ****
card 0: I82801AAICH [Intel 82801AA-ICH], device 0: Intel ICH [Intel 82801AA-ICH]
Subdevices: 1/1
Subdevice #0: subdevice #0
card 0: I82801AAICH [Intel 82801AA-ICH], device 1: Intel ICH - MIC ADC [Intel 82801AA-ICH - MIC ADC]
Subdevices: 1/1
Subdevice #0: subdevice #0
```

The error message from the CS Linux servers resulted from SSH being unable to access our local audio hardware.devices. A simple test to see if your audio works in SSH is to play a YouTube video. If sound cannot play, SSH most likely isn't using your computer's audio devices. The primary workaround was to install Virtuall Box and install a Linux image/CS Linux image and work through the Virtual Box. 

More information can be found in the references [page](https://github.com/uchicago-cs/chiventure/wiki/Sound-~-References)

## Current Status
The basic design is provided. However, the current version of sound module contains many compiler errors that the team was unfortunately not able to complete due to the lack of time. We are hoping that the next team could pick up from where we have left.

## Residual Backlog Issues from Sound Team Spring 2021:
Implement play/load sound function:
Play sound within src/sound/sound.c appears to be working, but the sound_init() function does not incorporate the given variables correctly. This doesn’t seem to be an issue when playing a sound, so perhaps sound_init() is unnecessary. Additionally, to play the sound we are able to use SDL_OpenAudioDevice(), SDL_QueueAudio(), SDL_delay() functionally while also ending and closing the sound file with SDL_CloseAudioDevice(), SDL_FreeWAV(), and SDL_Quit().
