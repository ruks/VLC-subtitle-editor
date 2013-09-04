/* 
 * File:   srtFormat.h
 * Author: rukshan
 *
 * Created on August 30, 2013, 10:54 PM
 */
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#ifndef SRTFORMAT_H
#define	SRTFORMAT_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct node {
        int id;
        string startTime;
        string endTime;
        string duration;
        string text;
    };

    struct dataObject {
        string object;
        string msg;
        int val;
        int x;
        int y;
    };

    typedef struct header_file {
        char chunk_id[4];
        int chunk_size;
        char format[4];
        char subchunk1_id[4];
        int subchunk1_size;
        short int audio_format;
        short int num_channels;
        int sample_rate; // sample_rate denotes the sampling rate.
        int byte_rate;
        short int block_align;
        short int bits_per_sample;
        char subchunk2_id[4];
        int subchunk2_size; // subchunk2_size denotes the number of samples.
    } header;

    struct srtFormat {
        int id;
        char text[1000];
    };

#ifdef	__cplusplus
}
#endif

#endif	/* SRTFORMAT_H */

