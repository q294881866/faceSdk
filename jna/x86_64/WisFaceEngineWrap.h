/*
QiansouFaceSDKV4,http://qiansou.cn
Copyright (c) 2015-2017 Qiansou
support QQ : 2843028512
*/

#pragma once
#include <stdio.h>
#include "windows.h"

#define QsHANDLE long long
#define FEATURE_SIZE 512
#ifndef BYTE
#define BYTE unsigned char
#endif // !BYTE


typedef struct {
	int 	left;			// ���ο����Ͻ�x����
	int 	top;			// ���ο����Ͻ�y����
	int 	right;			// ���ο����½�x����
	int 	bottom;			// ���ο����½�y����
} QsRect;

typedef struct {
	QsRect  rect;
	float 	confidence;		// ���Ŷ�
	float 	angle_roll;		// �������������Z����ת��localRotationZ��
	float 	angle_yaw;		// ���򣬽�������Y����ת��localRotationY��
	float 	angle_pitch;	// ��������������X����ת��localRotationX��
	float 	age;			// ����
	int   	gender;			// �Ա�
	BYTE    feature[FEATURE_SIZE]; 	//�������� size = FEATURE_SIZE
} QsFace;


/// <summary>
/// ��������ʶ������
/// </summary>
/// <param name="tag">tag = 0 </param>
/// <returns>��������������engine if >0 sucess, or falied</returns>
QsHANDLE qs_Wis_Create(int tag = 0);


/// <summary>
/// �������
/// </summary>
/// <param name="engine">qs_Wis_Create()���ص�����������</param>
/// <param name="image">��ƬimgBgr24</param>
/// <param name="width">ͼ����</param>
/// <param name="height">ͼ��߶�</param>
/// <param name="widthstep">widthstep�Ǵ洢һ��ͼ����ռ���ֽڣ������������ָ��Ĳ�ֵ��</param>
/// <param name="faces">���ص�����λ��,size = ����maxCount</param>
/// <param name="maxCount">�������������</param>
/// <returns>��⵽����������</returns>
int qs_Wis_DetectFaces(QsHANDLE handler, unsigned char* imgBgr24, int width, int height, int widthstep, QsFace* faces,const int maxCount);

/// <summary>
/// �������
/// </summary>
/// <param name="engine">qs_Wis_Create()���ص�����������</param>
/// <param name="image">��ƬimgBgr24</param>
/// <param name="width">ͼ����</param>
/// <param name="height">ͼ��߶�</param>
/// <param name="widthstep">widthstep�Ǵ洢һ��ͼ����ռ���ֽڣ������������ָ��Ĳ�ֵ��</param>
/// <param name="faceRects">���ص�����λ��,size = ����maxCount</param>
/// <param name="maxCount">�������������</param>
/// <returns>��⵽����������</returns>
int qs_Wis_DetectFacesV2(int handler, unsigned char* imgBgr24, int width, int height, int widthstep, QsFace* faceRects,const int maxCount);



/// <summary>
/// �������,��ǿ�棬�ٶȱ�qs_Wis_DetectFaces��
/// </summary>
/// <param name="engine">qs_Wis_Create()���ص�����������</param>
/// <param name="image">��ƬimgBgr24</param>
/// <param name="width">ͼ����</param>
/// <param name="height">ͼ��߶�</param>
/// <param name="widthstep">widthstep�Ǵ洢һ��ͼ����ռ���ֽڣ������������ָ��Ĳ�ֵ��</param>
/// <param name="faces">���ص�����λ��,size = ����maxCount</param>
/// <param name="maxCount">�������������</param>
/// <returns>��⵽����������</returns>
int qs_Wis_DetectFaces_Reinforce(QsHANDLE handler, unsigned char* imgBgr24, int width, int height, int widthstep, QsFace* faces,const int maxCount);


/// <summary>
/// ������ȡ
/// </summary>
/// <param name="engine">qs_Wis_Create()���ص�����������</param>
/// <param name="imgBgr24">��ƬimgBgr24</param>
/// <param name="width">ͼ����</param>
/// <param name="height">ͼ��߶�</param>
/// <param name="widthstep">widthstep�Ǵ洢һ��ͼ����ռ���ֽڣ������������ָ��Ĳ�ֵ��</param>
/// <param name="face">�����ṹ�壬����������ȡ֮ǰ���Ѿ�����rect��������ִ��������ȡ�ɹ��󣬸�����������ֵ���Զ��洢��face.feature��</param>
/// <returns>0 success, ����ʧ��</returns>
int qs_Wis_ExtractFeature(QsHANDLE handler, unsigned char* imgBgr24, int width, int height, int widthstep,  QsFace* face);

/// <summary>
/// �����ȶ�
/// </summary>
/// <param name="engine">qs_Wis_Create()���ص�����������</param>
/// <param name="ptFeature1">��һ����������</param>
/// <param name="ptFeature2">��һ����������</param>
/// <returns>���ƶ�</returns>
float qs_Wis_Compare2Feature(QsHANDLE handler,BYTE* ptFeature1,BYTE* ptFeature2);

/// <summary>
/// ������Ƭ�ȶԣ�����������Ƭ�������������������ƶ�score. if score > 0.8 ˵��������Ƭ���ƶȺܸߣ�
/// </summary>
/// <param name="engine">qs_Wis_Create()���ص�����������</param>
/// <param name="imgFile1">��һ����Ƭ·�������or���Ծ��ɣ�</param>
/// <param name="imgFile2">�ڶ�����Ƭ·��</param>
/// <returns>���ƶ�</returns>
float qs_Wis_Compare2Image(QsHANDLE handler, const char* imgFile1, const char* imgFile2);

