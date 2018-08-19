#pragma once
#ifndef  _FILEIO_HPP_
#define _FILEIO_HPP_


#include<cstdio>
#include"hmath.hPP"

namespace hfileIO {

/*A struct for saving binary file with 12 bytes in head*/
typedef struct
{
	int numFrames;
	int lengthFrame;
	short sizeFrameInByte;
	short typeFlag;
	hmath::Matrix data;
}BinaryFileStruct;

void FreeBinaryFileStruct(BinaryFileStruct* bfp);

/*һ�������ļ������ĺ��������������ָ�뷵���ļ�ͷ��*/
int numRowInFile(FILE* f);

/*Read binary file with 12 bytes in head*/
BinaryFileStruct readBinaryFile(FILE* f);

/*Write binary file with 12 byte in head */
void writeBinaryFile(FILE* f, BinaryFileStruct bf);

}

#endif // ! _FILEIO_H
