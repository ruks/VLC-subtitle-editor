/* 
 * File:   printbits.cpp
 * Author: rukshan
 * 
 * Created on August 29, 2013, 7:05 PM
 */

extern "C" {
#define __STDC_CONSTANT_MACROS // for UINT64_C
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

#include "printbits.h"
#include "soundfile.h"
#include <stdlib.h>
#include <QThread>
#include "MainWindow.h"
#include "srtFormat.h"
#include <algorithm>
#include "sndfile.h"
#include <QQueue>

//#include <libavcodec/avcodec.h>
//#include <libavformat/avformat.h>
////#include <libavutil/samplefmt.h>
//#include <stdio.h>

#ifndef OLDCPP
#include <iostream>
using namespace std;
#else
#include <iostream.h>
#endif


int spaceQ = 1;
MainWindow* win;
typedef struct header_file* header_p;

printbits::printbits() {
    stat = true;
}

printbits::printbits(const printbits& orig) {
}

printbits::~printbits() {
}

void printbits::ffmpegPCM() {
    av_register_all();
    AVFormatContext *pFormatCtx;

    AVFormatContext* container = avformat_alloc_context();
    const char* file = "video.mp4";

    if (avformat_open_input(&container, file, NULL, NULL) < 0) {
        printf("Could not open file");
    }

    if (avformat_find_stream_info(container, NULL) < 0) {
        printf("Could not find file info");
    }

    // Dump information about file onto standard error
        dump_format(container, 0, file, 0);
        cout<<container->filename<<endl;

    int stream_id = -1;
    int i;
    for (i = 0; i < container->nb_streams; i++) {
        if (container->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
            stream_id = i;
            break;
        }
    }
    if (stream_id == -1) {
        printf("Could not find Audio Stream");
    }

    AVDictionary *metadata = container->metadata;
    AVCodecContext *ctx = container->streams[stream_id]->codec;
    AVCodec *codec = avcodec_find_decoder(ctx->codec_id);

    if (codec == NULL) {
        printf("cannot find codec!");
    }

    if (avcodec_open2(ctx, codec, NULL) < 0) {
        printf("Codec cannot be found");
    }

    AVPacket packet;
    av_init_packet(&packet);
    AVFrame *frame = avcodec_alloc_frame();

    int buffer_size = AVCODEC_MAX_AUDIO_FRAME_SIZE + FF_INPUT_BUFFER_PADDING_SIZE;
    uint8_t buffer[buffer_size];
    packet.data = buffer;
    packet.size = buffer_size;

    //    FILE *outfile = fopen("test.raw", "wb");

    int len;
    int frameFinished = 0;

    int l = 0, r = 0;
    while (av_read_frame(container, &packet) >= 0) {
        if (packet.stream_index == stream_id) {
            int len = avcodec_decode_audio4(ctx, frame, &frameFinished, &packet);
            if (frameFinished) {
                char* ptr_l = (char*) frame->extended_data[0];
                char* ptr_r = (char*) frame->extended_data[1];
                size_t size = sizeof (int16_t);
                for (i = 0; i < frame->linesize[0]; i += size) {
                    qL.push_back(*(ptr_l));
//                    qR.push_back(*(ptr_r));
                    ptr_l += size;
                    ptr_r += size;
                }

            } else {
                printf("not \n");
            }
        }
    }

    av_close_input_file(container);
    //    win->setSampleList(qL,qR);
    dataObject ob;
    ob.object = "printBits";
    ob.msg = "setGraph";
    Notify(ob);
}

void printbits::setMainWindow(MainWindow* m) {
    win = m;
}

void printbits::run() {
    //    sndFilePCM();
    ffmpegPCM();
}

void printbits::sndFilePCM() {
    SNDFILE *SoundFile;
    SF_INFO SoundFileInfo;
    short int *Samples;
    //        SoundFile = sf_open("chimes.wav", SFM_READ, &SoundFileInfo);
    SoundFile = sf_open("audio.wav", SFM_READ, &SoundFileInfo);
    Samples = new short int[SoundFileInfo.channels * SoundFileInfo.frames];
    sf_readf_short(SoundFile, Samples, SoundFileInfo.frames);
    int frames = SoundFileInfo.frames;
    //    cout << SoundFileInfo.samplerate << endl;
    win->setSampleList(Samples, SoundFileInfo.frames, SoundFileInfo.samplerate);
}

QQueue<int> printbits::getLeftlist() {
    return qL;
}

QQueue<int> printbits::getRightlist() {
    return qR;
}