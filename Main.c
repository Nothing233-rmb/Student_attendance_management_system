#include"statement.h"

//C:\\Program_Data\\data.dat

/*实际效果
* P.S.名字和星期之间的空格数为18，且星期和到课情况之间有一个空格
* 
* 某某某
*                   早自习  第一节  第二节  第三节  第四节  晚自习
* 星期一(2023/11/27) 旷课    迟到    到课    请假    无课    旷课
* 星期二(2023/11/28) 旷课    迟到    到课    请假    无课    旷课
* 星期三(2023/11/29) 旷课    迟到    到课    请假    无课    旷课
* 星期四(2023/11/30) 旷课    迟到    到课    请假    无课    旷课
* 星期五(2023/12/01) 旷课    迟到    到课    请假    无课    旷课
* 
*                   早自习  第一节  第二节  第三节  第四节  晚自习
* 星期一(2023/12/02) 旷课    迟到    到课    请假    无课    旷课
* 星期二(2023/12/03) 旷课    迟到    到课    请假    无课    旷课
* 星期三(2023/12/04) 旷课    迟到    到课    请假    无课    旷课
* 星期四(2023/12/05) 旷课    迟到    到课    请假    无课    旷课
* 星期五(2023/12/06) 旷课    迟到    到课    请假    无课    旷课
* 
*                   早自习  第一节  第二节  第三节  第四节  晚自习
* 星期一(2023/12/07) 旷课    迟到    到课    请假    无课    旷课
* 星期二(2023/12/08) 旷课    迟到    到课    请假    无课    旷课
* 星期三(2023/12/09) 旷课    迟到    到课    请假    无课    旷课
* 星期四(2023/12/10) 旷课    迟到    到课    请假    无课    旷课
* 星期五(2023/12/11) 旷课    迟到    到课    请假    无课    旷课
* 
* …………
*/


/*需要添加的新功能[OK]
* 录入学生信息连续[OK]
* 关闭录入连续以及开启连续以及暂时关闭和开启该功能[OK]
* 若关闭录入学生信息连续，则每次录入完毕后会有继续录入询问，开启后则自动连续录入（输入exit退出）[OK]
* 若暂时关闭该功能则录入完毕后不会询问直接退回上一级，只有在开启该功能后才能选择开关前两个选项[OK]
* 新功能操作时需要录入日志（录入日志函数需要修改）[OK]
*/


/*获取年月日并将其转换为一个字符串
* flag = get_time(&year, &mon, &day, flag);
* make_str(t, year, mon, day, &flag);
*/


/*各文件指针用途
* fp为访问和操作存储学生主要信息的文件指针
* tem为用于访问临时文件的文件指针
* o_tem为用于访问根据other文件而创建的临时文件的文件指针
* log为访问和操作存储日志信息的文件指针
* other为访问和操作存储其它重要信息的文件指针（如星期等，以方便使用这些信息操作其它文件）
*/

/*错误码含义
* 特殊问题 0
* 文件写入失败：-1
* 数据文件创建失败 -2
* 日志文件创建失败 -3
* 特殊文件创建失败 -4
*/

/*致歉
* 因为该程序的所有注释都是在编写代码的过程中视情况而写的，中途的代码和函数参数以及其它数据
* 也不免会出现错误而修改，所以可能会出现以下的一种或多种情况：
* 1.注释的意思和描述无法对应代码（如执行的操作，函数参数或功能等）
* 2.奇怪的注释（如：“//OK该处需要从特殊文件中获取周几的数字，然后将其作为数组索引”），这是
*   因为我习惯把需要实现的功能或注意事项等写成注释，然后在完成并测试完毕该功能后在其上添加
*   记号做以标记，而且在完成后基本也不会删除
* P.S.很多代码段未书写注释，这是因为我个人只会在容易遗忘或逻辑较为复杂的代码段处书写注释，
*	  有小部分情况也会在普通代码段中书写注释
* 望谅解
*/

/*不同数字时使用不同操作
* 
* 1.关闭录入连续功能 总=0
* 2.开启录入连续功能 总=1（默认）
* 3.关闭连续录入提示 标志位=0
* 4.开启连续录入提示 标志位=1（默认）
*/
Bit sign = { .bit_1 = 1,.bit_2 = 1 };//bit_1为总功能开关(0,1)，bit_2为功能标志位(0,1)

int main(void)
{
#if TEST==0
	if (get_week() == 6)
	{
		print_first_hint();
		fputs("\n周六禁止使用该程序，请按照提示操作退出或直接关闭该程序!\n", stdout);
		system("PAUSE");
		exit(0);
	}
#endif
	FILE* fp = NULL;//访问存储学生信息文件指针
	FILE* tem = NULL;//临时指针，用于访问临时文件
	FILE* o_tem = NULL;//临时指针，用于访问根据other文件创建的临时文件指针
	FILE* log = NULL;//访问日志文件指针
	FILE* other = NULL;//访问存放其它关键数据文件的指针
	Bit flag = { .bit_2 = 0 ,.bit_1 = 0 };//标志位，为1则代表日期为一位数，为2则代表月份和日期都为一位数
	char name[100];//存储学生名数组
	char* week[6] = { "星期天","星期一","星期二","星期三","星期四","星期五" };
	char t[LEN];//存储年月日时间字符串数组
	char _t[9];//存储时分秒时间字符串数组
	int num[3];//暂存学生的旷课、迟到以及请假数量，实际为一个转运中心，负责将数据交付给需要的程序或函数处理
	int year, mon, day;//存储年月日的整型变量
	int n;//存储菜单界面输入的选项
	char ch;//清空输入缓冲区专用变量，若需要使用宏CL则必须包含该变量
	memset(name, '\0', 100);
	for (;; n = -1)
	{
		system("CLS");//====================
		print_first_hint();
		scanf_s("%d", &n);
		CL
		switch (n)
		{
			case 1://选择录入学生信息及其当日到课记录，或增加已录入学生信息的到课记录
			{
				exist(&fp, &log, &other);
				input_log(log, 1, t, _t);//需要添加读入日志信息的代码（或函数）
				cur:
				system("CLS");
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("|                              二级菜单                             |\n", stdout);
				fputs("|1.录入已存在学生当日的到课记录                                     |\n", stdout);
				fputs("|2.添加新学生然后录入其当日到课记录                                 |\n", stdout);
				fputs("|3.退回上一级                                                       |\n", stdout);
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("请输入需要进行的操作：", stdout);
				scanf_s("%d", &n);
				CL
				switch (n)
				{
					case 1://录入已存在学生当日的到课记录
					{
						input_log(log, 9, t, _t);//需要添加读入日志信息的代码（或函数）====================================================
						fopen_s(&fp, P_DATA, "rb+");
						n = fgetc(fp);
						if (n == EOF)
						{
							fputs("文件内部无任何学生信息，请先录入信息！", stdout);
							Sleep(1000);
							fclose(fp);
							goto cur;
						}
						fseek(fp, -1L, SEEK_CUR);
						fopen_s(&tem, P_TEM, "wb+");
						fopen_s(&other, P_OTHER, "rb+");
						fopen_s(&o_tem, P_OTEM, "wb+");
						while (fgetc(fp) != EOF)
						{
							other_num(&other, num);
							system("CLS");
							print_input_hint();
							fseek(fp, -1L, SEEK_CUR);
							fgets(name, 100, fp);
							printf("本次学生名为：%s", name);
							fputs(name, tem);
							while (fgetc(fp) != '=')
							{
								fseek(fp, -1L, SEEK_CUR);
								fputc(fgetc(fp), tem);
							}
							if (get_week() == 1)
								fputs(COURSE_STR, tem);
							//OK该处需要从特殊文件中获取周几的数字，然后将其作为数组索引
							fputs(week[get_week()], tem);//==================
							fputc('(', tem);
							flag = get_time(&year, &mon, &day, flag);
							make_str(t, year, mon, day, &flag);
							fputs(t, tem);
							fputs(") ", tem);
							fseek(fp, 1L, SEEK_CUR);//将文件指针位置向右移动一位，使其指向下一个学生名字（移动前文件指针指向=号后的\n）
							input_data(tem, num);//OK这里需要添加获取输入并读入文件的代码（或函数，而且需要在读入完毕后在结尾写入换行和=号\n=\n）
							num_fp(&o_tem, num);//缺一个将num中的数据写入临时文件的函数
						}
						if (!input_fil(tem, fp))//OK这里缺一个将tem文件的数据读入data文件的函数
						{
							system("CLS");
							fputs("文件写入失败，错误代码(-1),请稍后重新尝试或联系开发者\n", stdout);
							system("PAUSE");
							exit(-1);
						}
						if (!input_fil(o_tem, other))//OK这里缺一个将o_tem文件的数据读入other文件的函数
						{
							system("CLS");
							fputs("文件写入失败，错误代码(-1),请稍后重新尝试或联系开发者\n", stdout);
							system("PAUSE");
							exit(-1);
						}
						fclose(tem);
						fclose(o_tem);
						remove(P_TEM);//读入后，删除tem文件
						remove(P_OTEM);//读入后，删除otem文件
						fclose(fp);
						fclose(other);
						break;
					}
					case 2://添加新学生然后录入其当日到课记录
					{
						input_log(log, 10, t, _t);
						do 
						{
							system("CLS");
							print_input_hint();
							fopen_s(&fp, P_DATA, "ab");
							fopen_s(&other, P_OTHER, "ab");
							if (sign.bit_1 && !sign.bit_2)//如果连续输入功能处于开启状态且输入提示处于关闭状态
								fputs("请输入需要录入的学生姓名（输入exit退出）：", stdout);
							else
								fputs("请输入需要录入的学生姓名：", stdout);
							scanf_s("%s", name, 100);
							CL
							if (sign.bit_1 && name[0] == 'e' && name[1] == 'x' && name[2] == 'i' && name[3] == 't')
							{
								fclose(fp);
								fclose(other);
								break;
							}
							fputs(name, fp);
							fputc('\n', fp);
							fputs(COURSE_STR, fp);
							//OK该处需要获取周几的数字，然后将其作为数组索引
							fputs(week[get_week()], fp);//==================
							fputc('(', fp);
							flag = get_time(&year, &mon, &day, flag);
							make_str(t, year, mon, day, &flag);
							fputs(t, fp);
							fputs(") ", fp);
							for (int count = 0; count < 3; count++)
								num[count] = 0;
							input_data(fp, num);//OK这里需要添加获取输入并读入文件的代码（或函数，而且需要在读入完毕后在结尾写入换行和=号\n=\n）
							num_fp(&other, num);
							fclose(fp);
							fclose(other);
							if (sign.bit_1 == 1 && sign.bit_2 == 1)
							{
								fputs("还需要继续输入吗？（任意字符/ENTER）：", stdout);
								name[0] = getchar();
								if (name[0] != '\n')
								{
									CL
									break;
								}
							}
								
						} while (sign.bit_1);//如果录入连续功能为关闭状态
						//在添加新学生后向重要文件中录入初始值，以追加模式录入
						//需要在读入后将迟到和旷课数读入文件中，而非直接是常量
						fputs("学生名和到课情况录入完毕！\n", stdout);
						system("PAUSE");
						break;
					}
					case 3://退回上一级
						input_log(log, 11, t, _t);
						continue;
					default://若输入不正确
					{
						input_log(log, -1, t, _t);
						fputs("请输入正确值！", stdout);
						Sleep(1000);
						goto cur;
					}
				}
				break;
			}
			case 2://在终端上显示所有学生及其全部周一至周五的迟到、旷课以及正常到课记录
			{
				input_log(log, 2, t, _t);
				system("CLS");
				fopen_s(&fp, P_DATA, "rb");
				if (!fp)
				{
					system("CLS");
					fputs("文件不存在，请创建并录入信息后再试！\n", stdout);
					fputs("若依旧存在问题，则稍后再试或联系开发者\n", stdout);
					system("PAUSE");
					continue;
				}
				while ((ch = fgetc(fp)) != EOF)
				{
					if (ch != '=')
						putchar(ch);
					else
						fputs("\n\n", stdout);
				}
				fclose(fp);
				fputs("所有学生及其到课情况已经显示完毕\n", stdout);
				system("PAUSE");
				break;
			}
			case 3://只显示所有学生名及其当前总旷课、迟到和请假数
			{
				/*功能实现方法[ok]
				* 若other文件不存在，则在创建文件后将每个人的迟到和旷课数都置为0[废除想法]
				* 若存在，则在每次录入学生信息时根据符号数组中的符号来决定递增迟到或旷课的数量
				* 录入other文件时，需要将录入的数据转换为字符，读取也同样需要反向转换
				* 在需要显示所有学生的总旷课和迟到数时，从other文件中依次读取即可
				*/
				//格式：
				//姓名    旷课数 迟到数
				//某某某  21     11
				input_log(log, 3, t, _t);
				system("CLS");
				fputs(" 姓名   旷课数 请假数 迟到数\n", stdout);
				fopen_s(&fp, P_DATA, "rb");
				fopen_s(&other, P_OTHER, "rb");
				if (!fp || !other)
				{
					system("CLS");
					fputs("文件不存在，请创建并录入信息后再试！\n", stdout);
					fputs("若依旧存在问题，则稍后再试或联系开发者\n", stdout);
					system("PAUSE");
					continue;
				}
				while (fgetc(fp) != EOF)
				{
					fseek(fp, -1L, SEEK_CUR);
					fgets(name, sizeof(char) * 100, fp);
					for (int count = 0; count < (int)strlen(name); count++)
						if (name[count] == '\n')
							name[count] = '\0';
					printf("%-10s", name);
					//fputs("13     20\n", stdout);
					//两个数字之间需要有五个空格，且输出完一个人的到课情况后需要在后面加换行符
					other_num(&other, num);
					for (int count = 0; count < 3; count++)
						printf("%-7d", num[count]);
					putchar('\n');
					while (fgetc(fp) != '=');
					fseek(fp, 1L, SEEK_CUR);
				}
				fclose(fp);
				fclose(other);
				system("PAUSE");
				break;
			}
			case 4://输入学生名查找其总旷课和迟到数
			{
				input_log(log, 4, t, _t);
				system("CLS");
				fopen_s(&fp, P_DATA, "rb");
				fopen_s(&other, P_OTHER, "rb");
				if (!fp || !other)
				{
					system("CLS");
					fputs("文件不存在，请创建并录入信息后再试！\n", stdout);
					fputs("若依旧存在问题，则稍后再试或联系开发者\n", stdout);
					system("PAUSE");
					continue;
				}
				int count;
				char tem[100];
				fputs("请输入需要查找的学生名（输入完毕后以ENTER结束）：", stdout);
				scanf_s("%s", name, 100);
				CL
				while ((ch = fgetc(fp)) != EOF)
				{
					fseek(fp, -1L, SEEK_CUR);
					fgets(tem, sizeof(char) * 100, fp);
					while (fgetc(fp) != '=');
					fseek(fp, 1L, SEEK_CUR);
					for (count = 0; tem[count] != '\n'; count++);
					tem[count] = '\0';
					other_num(&other, num);
					if (!strcmp(tem, name))
					{
						system("CLS");
						fputs(" 姓名   旷课数 请假数 迟到数\n", stdout);
						printf("%-10s", tem);
						for (int count = 0; count < 3; count++)
							printf("%-7d", num[count]);
						putchar('\n');
						break;
					}
				}
				if (ch == EOF)
				{
					fputs("未找到该学生，请检查或录入后再试！\n", stdout);
					fputs("若依旧存在问题，则稍后再试或联系开发者\n", stdout);
				}
				fclose(fp);
				fclose(other);
				system("PAUSE");
				break;
			}
			case 5://输入学生名查找其全部周一至周五的迟到、旷课以及正常到课记录
			{
				input_log(log, 5, t, _t);
				system("CLS");
				fopen_s(&fp, P_DATA, "rb");
				if (!fp)
				{
					system("CLS");
					fputs("文件不存在，请创建并录入信息后再试！\n", stdout);
					fputs("若依旧存在问题，则稍后再试或联系开发者\n", stdout);
					system("PAUSE");
					continue;
				}
				int count;
				char tem[100];
				fputs("请输入需要查找的学生名（输入完毕后以ENTER结束）：", stdout);
				scanf_s("%s", name, 100);
				CL
				for (count = 0; name[count] != '\0'; count++);
				name[count] = '\n';
				name[count + 1] = '\0';
				while (fgetc(fp) != EOF)
				{
					fseek(fp, -1L, SEEK_CUR);
					fgets(tem, sizeof(char) * 100, fp);
					if (!strcmp(tem, name))
					{
						system("CLS");
						printf("%s", name);
						while ((ch = fgetc(fp)) != '=' && ch != EOF)
							putchar(ch);
						break;
					}
					while (fgetc(fp) != '=');
					fseek(fp, 1L, SEEK_CUR);
				}
				if (fgetc(fp) == EOF)
				{
					fputs("未找到该学生，请检查或录入后再试！\n", stdout);
					fputs("若依旧存在问题，则稍后再试或联系开发者\n", stdout);
				}
				fclose(fp);
				system("PAUSE");
				break;
			}
			case 6://查看日志
			{
				/*开幕选项
				1.选择录入学生信息及其当日到课记录，或增加已录入学生信息的到课记录
				2.在终端上显示所有学生及其全部周一至周五的迟到、旷课以及正常到课记录
				3.只显示所有学生名及其当前总旷课、迟到和请假数
				4.输入学生名查找其总旷课和迟到数
				5.输入学生名查找其全部周一至周五的迟到、旷课以及正常到课记录
				6.查看日志
				7.删除该程序在该电脑上存储的所有数据文件
				8.退出

				开幕选项1二级选项
				1.录入已存在学生当日的到课记录
				2.添加新学生然后录入其当日到课记录
				3.退回上一级
				*/
				input_log(log, 6, t, _t);
				fopen_s(&log, P_LOG, "rb");
				if (!log)
				{
					system("CLS");
					fputs("日志文件不存在，请创建后再试！\n", stdout);
					fputs("若依旧存在问题，则稍后再试或联系开发者\n", stdout);
					system("PAUSE");
					continue;
				}
				system("CLS");
				while ((ch = fgetc(log)) != EOF)
					putchar(ch);
				fclose(log);
				fputs("\n全部日志信息均以输出完毕\n", stdout);
				system("PAUSE");
				break;
			}
			case 7://删除该程序在该电脑上存储的所有数据文件
			{
				system("CLS");
				fputs("确定要删除所有存储在该计算机磁盘上的所有文件吗？[仅删除在磁盘中保存的文件和数据，本程序需要用户删除]（ENTER/n）：", stdout);
				if (getchar() == '\n')
				{
					if (!system("RD /S /Q C:\\Program_Data"))
						fputs("所有保存在此计算机上的数据文件都已被删除\n", stdout);
					else
					{
						system("CLS");
						fputs("未找到该文件，请创建后重试!\n", stdout);
					}
				}
				else
				{
					CL
					system("CLS");
					break;
				}
				system("PAUSE");
				system("CLS");
				break;
			}
			case 8://输入设置
			{
				input_log(log, 8, t, _t);
				cur1:
				system("CLS");
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("|                              二级菜单                             |\n", stdout);
				fputs("|1.关闭录入连续功能                                                 |\n", stdout);
				fputs("|2.开启录入连续功能                                                 |\n", stdout);
				fputs("|3.关闭连续录入提示                                                 |\n", stdout);
				fputs("|4.开启连续录入提示                                                 |\n", stdout);
				fputs("|5.退回上一级                                                       |\n", stdout);
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("请输入需要进行的操作：", stdout);
				scanf_s("%d", &n);
				CL
				switch (n)
				{
					case 1://关闭录入连续功能
					{
						/*不同数字时使用不同操作
						*
						* 1.关闭录入连续功能 总=0
						* 2.开启录入连续功能 总=1（默认）
						* 3.关闭连续录入提示 标志位=0
						* 4.开启连续录入提示 标志位=1（默认）
						*/
						if (sign.bit_1)
						{
							sign.bit_1 = 0;//bit_1为总功能开关(0,1)，bit_2为功能标志位(0,1)
							fputs("录入连续功能已关闭", stdout);
						}
						else
							fputs("录入连续功能已处于关闭状态！请勿重复关闭", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 2://开启录入连续功能（默认）
					{
						if (!sign.bit_1)
						{
							sign.bit_1 = 1;//bit_1为总功能开关(0,1)，bit_2为功能标志位(0,1)
							fputs("录入连续功能已开启", stdout);
						}
						else
							fputs("录入连续功能已处于开启状态！请勿重复开启", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 3://关闭连续录入提示
					{
						if (sign.bit_1 && sign.bit_2)
						{
							sign.bit_2 = 0;//bit_1为总功能开关(0,1)，bit_2为功能标志位(0,1)
							fputs("连续录入提示已关闭", stdout);
						}
						else if (!sign.bit_1)
							fputs("连续录入功能已处于关闭状态！无法设置其子项", stdout);
						else if (!sign.bit_2)
							fputs("连续录入提示已处于关闭状态！请勿重复关闭", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 4://开启连续录入提示（默认）
					{
						if (!sign.bit_2)
						{
							sign.bit_2 = 1;//bit_1为总功能开关(0,1)，bit_2为功能标志位(0,1)
							fputs("连续录入提示已开启", stdout);
						}
						else if (!sign.bit_1)
							fputs("连续录入功能已处于关闭状态！无法设置其子项", stdout);
						else if (sign.bit_2)
							fputs("连续录入提示已处于开启状态！请勿重复开启", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 5:
						continue;
					default:
					{
						input_log(log, -1, t, _t);
						fputs("请输入正确值！", stdout);
						Sleep(1000);
						goto cur1;
					}	
				}
				break;
			}
			case 9://exit
			{
				input_log(log, 7, t, _t);
				system("CLS");
				fputs("欢迎下次使用\n", stdout);
				system("PAUSE");
				return 0;
			}
			default://若输入不正确
			{
				input_log(log, -1, t, _t);
				fputs("请输入正确值！", stdout);
				Sleep(1000);
			}
		}
	}
	return 0;
}