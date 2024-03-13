
/*
* 该程序于2023年11月27日8:49:20开始编写
* 完成于2023年12月2日17:08:20
* 完全完成于2023年12月3日13:55:10
*/

#pragma once
#ifndef _INC_S
#define _INC_S

#define TEST 0
#define LEN 11
#define CL while ((ch = getchar()) != '\n' && ch != EOF){ ; }
#define COURSE_STR "                  早自习  第一节  第二节  第三节  第四节  晚自习\n"
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

void print_first_hint(void);//输出主界面提示菜单[OK]

void print_input_hint(void);//输出输入界面提示菜单[OK]

void exist(FILE** fp, FILE** log, FILE** other);//判断文件夹及其中的文件是否存在[OK]

int get_week(void);//获取星期并作为返回值返回[OK]

Bit get_time(int* year, int* mon, int* day, Bit flag);//获取系统时间并将其分别赋值给变量年月日[OK]

void make_str(char t[], int year, int mon, int day, Bit* flag);//将整数的年月日构建为一个字符串[OK]

void make_time_str(char _t[]);//构建一个仅存储时分秒的字符串[OK]

void input_data(FILE* p, int num[]);//向文件录入学生以及其到课情况信息[OK]

bool input_fil(FILE* fp1, FILE* fp2);//将fp1文件中的所有内容读入fp2文件中[OK]

bool input_log(FILE* log, int algebra, char t[], char _t[]);//在每次调用该函数时向日志文件录入日志信息[OK]

bool other_num(FILE** other, int num[]);//将other文件中的三个数字从字符形式转换为数字形式[OK]

void num_fp(FILE** fp1, int num[]);//将数组中三个数字转换为字符串形式并录入指定文件中[OK]

#endif