/* 
 * File:   smem.h
 * Author: rukshan
 *
 * Created on August 29, 2013, 9:28 AM
 */

#ifndef SMEM_H
#define	SMEM_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <vlc/vlc.h>
#include "MainWindow.h"
#include <QThread>

class smem : public QThread {
public:
    smem();
    smem(const smem& orig);
    virtual ~smem();
private:

protected:
    void run();
public:
    static void cbAudioPrerender(void* p_audio_data, uint8_t** pp_pcm_buffer, unsigned int size);
    static void cbAudioPostrender(void* p_audio_data, uint8_t* p_pcm_buffer, unsigned int channels, unsigned int rate, unsigned int nb_samples, unsigned int bits_per_sample, unsigned int size, int64_t pts);
    static void cbVideoPrerender(void *p_video_data, uint8_t **pp_pixel_buffer, int size);
    static void cbVideoPostrender(void *p_video_data, uint8_t *p_pixel_buffer, int width, int height, int pixel_pitch, int size, int64_t pts);
    static void handleEvent(const libvlc_event_t* pEvt, void* pUserData);
//    void main();
    void writefile(int val);
    void setMainWindow(MainWindow *m);
};

#endif	/* SMEM_H */

