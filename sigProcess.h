#pragma once
#ifndef _SIGPROCESS_H_
#define _SIGPROCESS_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"hmath.h"
#include"fft.h"


void circshift(Vector v, int shift);
int find(Vector v, double thre, int FrontOrEndFlag);
void pad_signal(Vector* yP, Vector x, int Npad);
void unpad_signal(Vector* yP, Vector x, int res, int target_sz );


void FFT(Vector s, int invert);
/*
When called s holds nn complex values stored in the
sequence   [ r1 , i1 , r2 , i2 , .. .. , rn , in ] where
n = VectorSize(s) DIV 2, n must be a power of 2. On exit s
holds the fft (or the inverse fft if invert == 1)
*/

/*---------Ԥ����----------------*/
/*zero mean a complete speech waveform nSamples long*/
void ZeroMean(IntVec data);
/*Ԥ����,kһ��ȡ0.9-1�����ȡk=0,�����κ�Ԥ����*/
void PreEmphasise(Vector s, double k);

/*-----------------�����������Լ��Ӵ�����---------------*/
/*����������,���λ��*/
double calBrightness(Vector fftx);
/*�����Ӵ�����,����Ӵ�����ռ�������ı�ֵ*/
void calSubBankE(Vector fftx, Vector subBankEnergy);
/*��������ʣ����ع����������һ֡�Ĳ�����ĸ���*/
double zeroCrossingRate(Vector s, int frameSize);

/*������ϵ��*/
/*�����ֱ�Ϊ��������Ҫ��ֵ�ÿ֡�Ĳ���������֡����ÿ���ƶ��Ĳ��������ϵ����ԭ�źŵľ��룬0��0���Ƿ�򵥲��*/
void Regress(Vector data, int vSize, int n, int step, int offset, int delwin, int head, int tail, bool simpleDiffs);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !_SIGPROCESS_H_