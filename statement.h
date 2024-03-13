
/*
* �ó�����2023��11��27��8:49:20��ʼ��д
* �����2023��12��2��17:08:20
* ��ȫ�����2023��12��3��13:55:10
*/

#pragma once
#ifndef _INC_S
#define _INC_S

#define TEST 0
#define LEN 11
#define CL while ((ch = getchar()) != '\n' && ch != EOF){ ; }
#define COURSE_STR "                  ����ϰ  ��һ��  �ڶ���  ������  ���Ľ�  ����ϰ\n"
#define P_DATA "C:\\Program_Data\\data.dat"
#define P_TEM "C:\\Program_Data\\tem.dat"
#define P_OTEM "C:\\Program_Data\\o_tem.dat"
#define P_LOG "C:\\Program_Data\\log.dat"
#define P_OTHER "C:\\Program_Data\\other.dat"

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<io.h>

typedef struct lib {
	unsigned int bit_2 : 2;
	unsigned int bit_1 : 1;
	unsigned int : 0;
}Bit;

void print_first_hint(void);//�����������ʾ�˵�[OK]

void print_input_hint(void);//������������ʾ�˵�[OK]

void exist(FILE** fp, FILE** log, FILE** other);//�ж��ļ��м����е��ļ��Ƿ����[OK]

int get_week(void);//��ȡ���ڲ���Ϊ����ֵ����[OK]

Bit get_time(int* year, int* mon, int* day, Bit flag);//��ȡϵͳʱ�䲢����ֱ�ֵ������������[OK]

void make_str(char t[], int year, int mon, int day, Bit* flag);//�������������չ���Ϊһ���ַ���[OK]

void make_time_str(char _t[]);//����һ�����洢ʱ������ַ���[OK]

void input_data(FILE* p, int num[]);//���ļ�¼��ѧ���Լ��䵽�������Ϣ[OK]

bool input_fil(FILE* fp1, FILE* fp2);//��fp1�ļ��е��������ݶ���fp2�ļ���[OK]

bool input_log(FILE* log, int algebra, char t[], char _t[]);//��ÿ�ε��øú���ʱ����־�ļ�¼����־��Ϣ[OK]

bool other_num(FILE** other, int num[]);//��other�ļ��е��������ִ��ַ���ʽת��Ϊ������ʽ[OK]

void num_fp(FILE** fp1, int num[]);//����������������ת��Ϊ�ַ�����ʽ��¼��ָ���ļ���[OK]

#endif