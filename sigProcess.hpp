#pragma once
#ifndef _SIGPROCESS_HPP_
#define _SIGPROCESS_HPP_


#include<cmath>
#include<cstdio>
#include<cstdlib>
#include"hmath.hpp"

namespace hsigProcess {

/*circle shift*/
void circshift(hmath::Vector v, int shift);

/*Ѱ�ҵ�һ������thre����ֵ*/
int find(hmath::Vector v, double thre, int FrontOrEndFlag);

/*pad signal*/
void pad_signal(hmath::Vector* yP, hmath::Vector x, int Npad);

/*unpad signal*/
void unpad_signal(hmath::Vector* yP, hmath::Vector x, int res, int target_sz );

/*frame the origin int signal according to frame size and frame shift size*/
/*return a double hmath::matrix,each row contains a frame*/
hmath::Matrix frameRawSignal(hmath::IntVec v, int wlen, int inc,double preEmphasiseCoefft,int enableHamWindow);


/*---------Ԥ����----------------*/
/*zero mean a complete speech waveform nSamples long*/
void ZeroMean(hmath::IntVec data);

/*Ԥ����,kһ��ȡ0.9-1�����ȡk=0,�����κ�Ԥ����*/
void PreEmphasise(hmath::Vector s, double k);

/*-----------------�����������Լ��Ӵ�����---------------*/
/*����������,���λ��*/
double calBrightness(hmath::Vector fftx);

/*�����Ӵ�����,����Ӵ�����ռ�������ı�ֵ*/
void calSubBankE(hmath::Vector fftx, hmath::Vector subBankEnergy);

/*��������ʣ����ع����������һ֡�Ĳ�����ĸ���*/
double zeroCrossingRate(hmath::Vector s, int frameSize);

/*�������ϵ��
�����ֱ�Ϊ��������Ҫ��ֵ�ÿ֡�Ĳ���������֡����ÿ���ƶ��Ĳ��������ϵ����ԭ�źŵľ��룬0��0���Ƿ�򵥲��*/
void Regress(double* data, int vSize, int n, int step, int offset, int delwin, int head, int tail, int simpleDiffs);

/*������*/
void RegressMat(hmath::Matrix* m,int delwin, int regressOrder);

/*n��׼��log��ֵ*/
void NormaliseLogEnergy(double *data, int n, int step, double silFloor, double escale);

/*Z-norm����������ο�Regress����*/
void ZNormalize(double *data, int vSize, int n, int step);

/* ����Ham�� */
hmath::Vector GenHamWindow(int frameSize);

/*���ź�s��Ӧ��Ham��*/
void Ham(hmath::Vector s, hmath::Vector hamWin, int hamWinSize);

}

#endif // !_SIGPROCESS_H_
