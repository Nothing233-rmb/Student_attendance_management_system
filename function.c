#include"statement.h"

/*OK
* 作用：输出主界面提示菜单
* 参数：无
* 返回值：无
*/
void print_first_hint(void)
{
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                MENU                                 |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|----------------------------|追加、录入|-----------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|1.选择录入学生信息及其当日到课记录，或增加已录入学生信息的到课记录   |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|-------------------------------|显示|--------------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|2.在终端上显示所有学生及其全部周一至周五的迟到、旷课以及正常到课记录 |\n", stdout);
	fputs("|3.只显示所有学生名及其当前总旷课、迟到和请假数                       |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|----------------------------|查找、检索|-----------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|4.输入学生名查找其总旷课和迟到数                                     |\n", stdout);
	fputs("|5.输入学生名查找其全部周一至周五的迟到、旷课以及正常到课记录         |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|-----------------------------|其它操作|------------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|6.查看日志                                                           |\n", stdout);
	fputs("|7.删除该程序在该电脑上存储的所有数据文件                             |\n", stdout);
	fputs("|8.输入设置                                                           |\n", stdout);
	fputs("|9.退出                                                               |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("请输入需要进行的操作：", stdout);
}


/*OK
* 作用：输出输入界面提示菜单
* 参数：无
* 返回值：无
*/
void print_input_hint(void)
{
	fputs("-----------------------------------------------------------------------------------------\n", stdout);
	fputs("|---------------------------------------|注意事项|--------------------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------------------------\n", stdout);
	fputs("|-为旷课，=为迟到，_为请假，+为正常到课，*为无课                                        |\n", stdout);
	fputs("|每个数据间无需用空格分隔，单行输入完毕后按ENTER键结束                                  |\n", stdout);
	fputs("|                                                                                       |\n", stdout);
	fputs("|例如（[ENTER]指的是键盘上的回车，而非输入）：                                          |\n", stdout);
	fputs("|-=++_+[ENTER]                                                                          |\n", stdout);
	fputs("|实际效果：                                                                             |\n", stdout);
	fputs("|旷课    迟到    到课    请假    到课                                                   |\n", stdout);
	fputs("|                                                                                       |\n", stdout);
	fputs("|---------------------------------------------------------------------------------------|\n", stdout);
	fputs("|注意！所有标记必须以英文状态下输入！                                                   |\n", stdout);
	fputs("-----------------------------------------------------------------------------------------\n", stdout);
}


/*OK
* 作用：判断文件夹及其中的文件是否存在
* 参数：fp为指向存储数据文件的二级指针，log为指向存储日志文件的二级指针,other为指向存储
*       特殊文件的二级指针
* 返回值：true或false，为true则两个指针指向的文件及包含其的文件夹都存在，否则程序会尝试
* 创建，若创建失败，则返回false
*/
void exist(FILE** fp, FILE** log, FILE** other)
{//读取特殊文件以确定文件中是否存在数据
	if (_access("C:\\Program_Data", 0) == -1)
		system("MD C:\\Program_Data");
	fopen_s(fp, "C:\\Program_Data\\data.dat", "rb");
	if (!(*fp))
	{
		fopen_s(fp, "C:\\Program_Data\\data.dat", "wb");
		if (!(*fp))
		{
			system("CLS");
			fputs("数据文件创建失败，错误代码(-2),请稍后重新尝试或联系开发者\n", stdout);
			system("PAUSE");
			exit(-2);
		}
		fclose(*fp);
	}
	fclose(*fp);
	fopen_s(log, "C:\\Program_Data\\log.dat", "rb");
	if (!(*log))
	{
		fopen_s(log, "C:\\Program_Data\\log.dat", "wb");
		if (!(*log))
		{
			system("CLS");
			fputs("日志文件创建失败，错误代码(-3),请稍后重新尝试或联系开发者\n", stdout);
			system("PAUSE");
			exit(-3);
		}
	}
	fclose(*log);
	fopen_s(other, "C:\\Program_Data\\other.dat", "rb");
	if (!(*other))
	{
		fopen_s(other, "C:\\Program_Data\\other.dat", "wb");
		if (!(*other))
		{
			system("CLS");
			fputs("特殊文件创建失败，错误代码(-4),请稍后重新尝试或联系开发者\n", stdout);
			system("PAUSE");
			exit(-4);
		}
	}
	fclose(*other);
}

/*OK
* 作用：获取星期并作为返回值返回
* 参数：无
* 返回值：从系统获取的星期（十进制整数）
*/
int get_week(void)
{
	time_t t;
	struct tm p;//使用该结构体变量访问时间
	time(&t);
	gmtime_s(&p, &t);
	return p.tm_wday;
}

/*OK
* 作用：获取系统时间并将其分别赋值给变量年月日，若月和日为一位数，则改变标志位flag的值
* 参数：year的作用为存储年，mon存储月，day存储日，标志位flag为0时，月和日都为两位数，
*	   为1时，日为一位数，为2时，月和日都为一位数
* 返回值：标志位flag，在主调函数需要手动使用该函数返回值更新标志位flag的值
*/
Bit get_time(int* year, int* mon, int* day, Bit flag)
{
	time_t t;
	struct tm p;//使用该结构体变量访问时间
	time(&t);
	gmtime_s(&p, &t);
	*year = p.tm_year + 1900;
	*mon = p.tm_mon + 1;
	*day = p.tm_mday;
	if (!(*day / 10))
	{
		flag.bit_2 = 1;
		if (!(*mon / 10))
			flag.bit_2 = 2;
	}
	return flag;
}

/*OK
* 作用：将整数的年月日构建为一个字符串，并存储在字符串t中，若月和日为一位数，则在其前
*       添加0，结束后将标志位重置为0
* 参数：t的作用为存储构建完成的字符串，year为年的十进制数，mon为月的十进制数，day为日
*       的十进制数，标志位flag为0时，无需添加0，为1时，在日前添加0，为2时，月和日前都
*       添加0
* 返回值：无
*/
void make_str(char t[], int year, int mon, int day, Bit* flag)
{
	int count = 9;
	while (day)
	{
		t[count--] = (day % 10) + '0';
		if (flag->bit_2)
			t[count--] = '0';
		day /= 10;
	}
	t[count--] = '/';
	while (mon)
	{
		t[count--] = (mon % 10) + '0';
		if (flag->bit_2 == 2)
			t[count--] = '0';
		mon /= 10;
	}
	t[count--] = '/';
	while (year)
	{
		t[count--] = (year % 10) + '0';
		year /= 10;
	}
	t[LEN - 1] = '\0';
	flag->bit_2 = 0;
}

/*OK
* 作用：构建一个仅存储时分秒的字符串
* 参数：t为需要写入时间的字符串
* 返回值：无
*/
void make_time_str(char _t[])
{
	time_t t;
	struct tm p;//使用该结构体变量访问时间
	Bit flag = { .bit_2 = 0 };
	int tem[3] = { 0 };
	int len = 8;
	time(&t);
	gmtime_s(&p, &t);
	tem[0] = p.tm_hour + 8;
	tem[1] = p.tm_min;
	tem[2] = p.tm_sec;
	_t[len--] = '\0';
	for (int count = 2; count >= 0; count--)
	{
		if (tem[count] == 0)
		{
			_t[len--] = '0';
			_t[len--] = '0';
			_t[len--] = ':';
			continue;
		}
		else if (tem[count] < 10)
			flag.bit_2 = 1;
		while (tem[count])
		{
			_t[len--] = (tem[count] % 10) + '0';
			tem[count] /= 10;
			if (flag.bit_2 == 1)
			{
				_t[len--] = '0';
				flag.bit_2 = 0;
			}
		}
		if (count)
			_t[len--] = ':';
	}
}

/*OK
* 作用：向文件录入学生以及其到课情况信息
* 参数：p为指向需要录入信息的文件，num数组为暂时记录和存储学生的迟到、旷课以及请假情况的
* 返回值：无
*/
void input_data(FILE* p, int num[])
{
	char a[6] = { '\0' };
	char ch;
	int count = 0;
s:
	fputs("请输入需要录入的到课情况标识符：", stdout);
	while ((ch = getchar()) != '\n' && count != 6)
		a[count++] = ch;
	if (ch != '\n')//若输入超长，则清空输入缓冲区，保留正确输入
		CL
	for (count = 0; count < 6; count++)
	{
		if (a[count] != '-' && a[count] != '_' && a[count] != '=' && a[count] != '+' && a[count] != '*')
		{
			fputs("读入标识符错误，请重新输入！", stdout);
			Sleep(1000);
			system("CLS");
			print_input_hint();
			goto s;
		}
	}
	for (count = 0; count < 6; count++)
	{
		switch (a[count])
		{
		case '-':
		{
			num[0]++;
			fputs("旷课", p);
			break;
		}
		case '_':
		{
			num[1]++;
			fputs("请假", p);
			break;
		}
		case '=':
		{
			num[2]++;
			fputs("迟到", p);
			break;
		}
		case '+':
			fputs("到课", p);
			break;
		case '*':
			fputs("无课", p);
			break;
		}
		if (count != 5)
			fputs("    ", p);
	}
	fputs("\n=\n", p);
}

/*OK
* 作用：将fp1文件中的所有内容读入fp2文件中
* 参数：fp1为指向需要向fp2录入信息的文件，fp2则恰恰相反
* 返回值：成功录入返回true，反之返回false
*/
bool input_fil(FILE* fp1, FILE* fp2)
{
	if (!fp1 || !fp2)
		return false;
	char ch;
	rewind(fp1);
	rewind(fp2);
	while ((ch = fgetc(fp1)) != EOF)
		fputc(ch, fp2);
	return true;
}

/*
* 作用：录入日志文件
* 参数：log为指向存储日志文件的指针，algebra为用于筛选不同情况来决定向日志文件录入什么信
*	    息（为不同值时进行的操作不一样），数组t和_t分别为存储年月日和时分秒的字符串
* 返回值：true或false，为true则写入成功，否则为false
*/
bool input_log(FILE* log, int algebra, char t[], char _t[])
{
	if (!log)
	{
		fopen_s(&log, P_LOG, "ab");
		if (!log)
			return false;
	}
	Bit flag = { .bit_2 = 0,.bit_1 = 0 };
	int year;
	int mon;
	int day;
	make_time_str(_t);
	flag = get_time(&year, &mon, &day, flag);
	make_str(t, year, mon, day, &flag);
	fputs("于-", log);
	fputc('{', log);
	fputs(t, log);
	fputc(' ', log);
	fputs(_t, log);
	fputs("} ", log);
	switch (algebra)
	{
		case 1://选择录入学生信息及其当日到课记录，或增加已录入学生信息的到课记录
			fputs("在该台计算机上进行了：[选择录入学生信息及其当日到课记录，或增加已录入学生信息的到课记录]操作\n", log);
			break;
		case 2://在终端上显示所有学生及其全部周一至周五的迟到、旷课以及正常到课记录
			fputs("在该台计算机上进行了：[在终端上显示所有学生及其全部周一至周五的迟到、旷课以及正常到课记录]操作\n", log);
			break;
		case 3://只显示所有学生名及其当前总旷课、迟到和请假数
			fputs("在该台计算机上进行了：[只显示所有学生名及其当前总旷课、迟到和请假数]操作\n", log);
			break;
		case 4://输入学生名查找其总旷课和迟到数
			fputs("在该台计算机上进行了：[输入学生名查找其总旷课和迟到数]操作\n", log);
			break;
		case 5://输入学生名查找其全部周一至周五的迟到、旷课以及正常到课记录
			fputs("在该台计算机上进行了：[输入学生名查找其全部周一至周五的迟到、旷课以及正常到课记录]操作\n", log);
			break;
		case 6://查看日志
			fputs("在该台计算机上进行了：[查看日志]操作\n", log);
			break;
		case 7://退出
			fputs("在该台计算机上进行了：[退出]操作\n", log);
			break;
		case 8://输入设置
			fputs("在该台计算机上进行了：[输入设置]操作\n", log);
			break;
		case 9://[一选项二级]录入已存在学生当日的到课记录
			fputs("在该台计算机上进行了一选项的二级操作下的：[录入已存在学生当日的到课记录]操作\n", log);
			break;
		case 10://[一选项二级]添加新学生然后录入其当日到课记录
			fputs("在该台计算机上进行了一选项的二级操作下的：[添加新学生然后录入其当日到课记录]操作\n", log);
			break;
		case 11://[一选项二级]退回上一级
			fputs("在该台计算机上进行了一选项的二级操作下的：[退回上一级]操作\n", log);
			break;
		default:
			fputs("在该台计算机上输入选项时没有按照提示正常输入，导致输入错误\n", log);
	}
	fclose(log);
	return true;
}

/*OK
* 作用：将other文件中的三个数字从字符形式转换为数字形式
* 参数：other为指向存储其它文件的二级指针，num则存储从other指针中读取的被翻译为十进制的整
*       数
* 返回值：成功录入返回true，反之返回false
*/
bool other_num(FILE** other, int num[])
{
	char ch;
	int count = 0;
	for (count = 0; count < 3; count++)
		num[count] = 0;
	for (count = 0; fgetc(*other) != EOF && count != 3; count++)
	{
		fseek(*other, -1L, SEEK_CUR);
		while ((ch = fgetc(*other)) != ' ' && ch != '\n')
		{
			num[count] *= 10;
			num[count] += ch - '0';
		}
	}
	return true;
}

/*OK
* 作用：将数组中三个数字转换为字符串形式并录入指定文件中
* 参数：fp1为指向存储其它文件的二级指针，num则存储需要读入fp1所指向的文件的十进制整数
* 返回值：成功录入返回true，反之返回false
*/
void num_fp(FILE** fp1, int num[])
{
	for (int count = 0; count < 3; count++)
	{
		if (num[count] < 10)
		{
			fputc(num[count] % 10 + '0', *fp1);
			num[count] /= 10;
		}
		else
		{
			fputc(num[count] / 10 + '0', *fp1);
			fputc(num[count] % 10 + '0', *fp1);
		}
		fputc(' ', *fp1);
	}
	fputc('\n', *fp1);
}