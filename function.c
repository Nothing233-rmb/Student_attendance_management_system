#include"statement.h"

/*OK
* ���ã������������ʾ�˵�
* ��������
* ����ֵ����
*/
void print_first_hint(void)
{
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                MENU                                 |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|----------------------------|׷�ӡ�¼��|-----------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|1.ѡ��¼��ѧ����Ϣ���䵱�յ��μ�¼����������¼��ѧ����Ϣ�ĵ��μ�¼   |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|-------------------------------|��ʾ|--------------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|2.���ն�����ʾ����ѧ������ȫ����һ������ĳٵ��������Լ��������μ�¼ |\n", stdout);
	fputs("|3.ֻ��ʾ����ѧ�������䵱ǰ�ܿ��Ρ��ٵ��������                       |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|----------------------------|���ҡ�����|-----------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|4.����ѧ�����������ܿ��κͳٵ���                                     |\n", stdout);
	fputs("|5.����ѧ����������ȫ����һ������ĳٵ��������Լ��������μ�¼         |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|-----------------------------|��������|------------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("|                                                                     |\n", stdout);
	fputs("|6.�鿴��־                                                           |\n", stdout);
	fputs("|7.ɾ���ó����ڸõ����ϴ洢�����������ļ�                             |\n", stdout);
	fputs("|8.��������                                                           |\n", stdout);
	fputs("|9.�˳�                                                               |\n", stdout);
	fputs("-----------------------------------------------------------------------\n", stdout);
	fputs("��������Ҫ���еĲ�����", stdout);
}


/*OK
* ���ã�������������ʾ�˵�
* ��������
* ����ֵ����
*/
void print_input_hint(void)
{
	fputs("-----------------------------------------------------------------------------------------\n", stdout);
	fputs("|---------------------------------------|ע������|--------------------------------------|\n", stdout);
	fputs("-----------------------------------------------------------------------------------------\n", stdout);
	fputs("|-Ϊ���Σ�=Ϊ�ٵ���_Ϊ��٣�+Ϊ�������Σ�*Ϊ�޿�                                        |\n", stdout);
	fputs("|ÿ�����ݼ������ÿո�ָ�������������Ϻ�ENTER������                                  |\n", stdout);
	fputs("|                                                                                       |\n", stdout);
	fputs("|���磨[ENTER]ָ���Ǽ����ϵĻس����������룩��                                          |\n", stdout);
	fputs("|-=++_+[ENTER]                                                                          |\n", stdout);
	fputs("|ʵ��Ч����                                                                             |\n", stdout);
	fputs("|����    �ٵ�    ����    ���    ����                                                   |\n", stdout);
	fputs("|                                                                                       |\n", stdout);
	fputs("|---------------------------------------------------------------------------------------|\n", stdout);
	fputs("|ע�⣡���б�Ǳ�����Ӣ��״̬�����룡                                                   |\n", stdout);
	fputs("-----------------------------------------------------------------------------------------\n", stdout);
}


/*OK
* ���ã��ж��ļ��м����е��ļ��Ƿ����
* ������fpΪָ��洢�����ļ��Ķ���ָ�룬logΪָ��洢��־�ļ��Ķ���ָ��,otherΪָ��洢
*       �����ļ��Ķ���ָ��
* ����ֵ��true��false��Ϊtrue������ָ��ָ����ļ�����������ļ��ж����ڣ��������᳢��
* ������������ʧ�ܣ��򷵻�false
*/
void exist(FILE** fp, FILE** log, FILE** other)
{//��ȡ�����ļ���ȷ���ļ����Ƿ��������
	if (_access("C:\\Program_Data", 0) == -1)
		system("MD C:\\Program_Data");
	fopen_s(fp, "C:\\Program_Data\\data.dat", "rb");
	if (!(*fp))
	{
		fopen_s(fp, "C:\\Program_Data\\data.dat", "wb");
		if (!(*fp))
		{
			system("CLS");
			fputs("�����ļ�����ʧ�ܣ��������(-2),���Ժ����³��Ի���ϵ������\n", stdout);
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
			fputs("��־�ļ�����ʧ�ܣ��������(-3),���Ժ����³��Ի���ϵ������\n", stdout);
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
			fputs("�����ļ�����ʧ�ܣ��������(-4),���Ժ����³��Ի���ϵ������\n", stdout);
			system("PAUSE");
			exit(-4);
		}
	}
	fclose(*other);
}

/*OK
* ���ã���ȡ���ڲ���Ϊ����ֵ����
* ��������
* ����ֵ����ϵͳ��ȡ�����ڣ�ʮ����������
*/
int get_week(void)
{
	time_t t;
	struct tm p;//ʹ�øýṹ���������ʱ��
	time(&t);
	gmtime_s(&p, &t);
	return p.tm_wday;
}

/*OK
* ���ã���ȡϵͳʱ�䲢����ֱ�ֵ�����������գ����º���Ϊһλ������ı��־λflag��ֵ
* ������year������Ϊ�洢�꣬mon�洢�£�day�洢�գ���־λflagΪ0ʱ���º��ն�Ϊ��λ����
*	   Ϊ1ʱ����Ϊһλ����Ϊ2ʱ���º��ն�Ϊһλ��
* ����ֵ����־λflag��������������Ҫ�ֶ�ʹ�øú�������ֵ���±�־λflag��ֵ
*/
Bit get_time(int* year, int* mon, int* day, Bit flag)
{
	time_t t;
	struct tm p;//ʹ�øýṹ���������ʱ��
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
* ���ã��������������չ���Ϊһ���ַ��������洢���ַ���t�У����º���Ϊһλ����������ǰ
*       ���0�������󽫱�־λ����Ϊ0
* ������t������Ϊ�洢������ɵ��ַ�����yearΪ���ʮ��������monΪ�µ�ʮ��������dayΪ��
*       ��ʮ����������־λflagΪ0ʱ���������0��Ϊ1ʱ������ǰ���0��Ϊ2ʱ���º���ǰ��
*       ���0
* ����ֵ����
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
* ���ã�����һ�����洢ʱ������ַ���
* ������tΪ��Ҫд��ʱ����ַ���
* ����ֵ����
*/
void make_time_str(char _t[])
{
	time_t t;
	struct tm p;//ʹ�øýṹ���������ʱ��
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
* ���ã����ļ�¼��ѧ���Լ��䵽�������Ϣ
* ������pΪָ����Ҫ¼����Ϣ���ļ���num����Ϊ��ʱ��¼�ʹ洢ѧ���ĳٵ��������Լ���������
* ����ֵ����
*/
void input_data(FILE* p, int num[])
{
	char a[6] = { '\0' };
	char ch;
	int count = 0;
s:
	fputs("��������Ҫ¼��ĵ��������ʶ����", stdout);
	while ((ch = getchar()) != '\n' && count != 6)
		a[count++] = ch;
	if (ch != '\n')//�����볬������������뻺������������ȷ����
		CL
	for (count = 0; count < 6; count++)
	{
		if (a[count] != '-' && a[count] != '_' && a[count] != '=' && a[count] != '+' && a[count] != '*')
		{
			fputs("�����ʶ���������������룡", stdout);
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
			fputs("����", p);
			break;
		}
		case '_':
		{
			num[1]++;
			fputs("���", p);
			break;
		}
		case '=':
		{
			num[2]++;
			fputs("�ٵ�", p);
			break;
		}
		case '+':
			fputs("����", p);
			break;
		case '*':
			fputs("�޿�", p);
			break;
		}
		if (count != 5)
			fputs("    ", p);
	}
	fputs("\n=\n", p);
}

/*OK
* ���ã���fp1�ļ��е��������ݶ���fp2�ļ���
* ������fp1Ϊָ����Ҫ��fp2¼����Ϣ���ļ���fp2��ǡǡ�෴
* ����ֵ���ɹ�¼�뷵��true����֮����false
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
* ���ã�¼����־�ļ�
* ������logΪָ��洢��־�ļ���ָ�룬algebraΪ����ɸѡ��ͬ�������������־�ļ�¼��ʲô��
*	    Ϣ��Ϊ��ֵͬʱ���еĲ�����һ����������t��_t�ֱ�Ϊ�洢�����պ�ʱ������ַ���
* ����ֵ��true��false��Ϊtrue��д��ɹ�������Ϊfalse
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
	fputs("��-", log);
	fputc('{', log);
	fputs(t, log);
	fputc(' ', log);
	fputs(_t, log);
	fputs("} ", log);
	switch (algebra)
	{
		case 1://ѡ��¼��ѧ����Ϣ���䵱�յ��μ�¼����������¼��ѧ����Ϣ�ĵ��μ�¼
			fputs("�ڸ�̨������Ͻ����ˣ�[ѡ��¼��ѧ����Ϣ���䵱�յ��μ�¼����������¼��ѧ����Ϣ�ĵ��μ�¼]����\n", log);
			break;
		case 2://���ն�����ʾ����ѧ������ȫ����һ������ĳٵ��������Լ��������μ�¼
			fputs("�ڸ�̨������Ͻ����ˣ�[���ն�����ʾ����ѧ������ȫ����һ������ĳٵ��������Լ��������μ�¼]����\n", log);
			break;
		case 3://ֻ��ʾ����ѧ�������䵱ǰ�ܿ��Ρ��ٵ��������
			fputs("�ڸ�̨������Ͻ����ˣ�[ֻ��ʾ����ѧ�������䵱ǰ�ܿ��Ρ��ٵ��������]����\n", log);
			break;
		case 4://����ѧ�����������ܿ��κͳٵ���
			fputs("�ڸ�̨������Ͻ����ˣ�[����ѧ�����������ܿ��κͳٵ���]����\n", log);
			break;
		case 5://����ѧ����������ȫ����һ������ĳٵ��������Լ��������μ�¼
			fputs("�ڸ�̨������Ͻ����ˣ�[����ѧ����������ȫ����һ������ĳٵ��������Լ��������μ�¼]����\n", log);
			break;
		case 6://�鿴��־
			fputs("�ڸ�̨������Ͻ����ˣ�[�鿴��־]����\n", log);
			break;
		case 7://�˳�
			fputs("�ڸ�̨������Ͻ����ˣ�[�˳�]����\n", log);
			break;
		case 8://��������
			fputs("�ڸ�̨������Ͻ����ˣ�[��������]����\n", log);
			break;
		case 9://[һѡ�����]¼���Ѵ���ѧ�����յĵ��μ�¼
			fputs("�ڸ�̨������Ͻ�����һѡ��Ķ��������µģ�[¼���Ѵ���ѧ�����յĵ��μ�¼]����\n", log);
			break;
		case 10://[һѡ�����]�����ѧ��Ȼ��¼���䵱�յ��μ�¼
			fputs("�ڸ�̨������Ͻ�����һѡ��Ķ��������µģ�[�����ѧ��Ȼ��¼���䵱�յ��μ�¼]����\n", log);
			break;
		case 11://[һѡ�����]�˻���һ��
			fputs("�ڸ�̨������Ͻ�����һѡ��Ķ��������µģ�[�˻���һ��]����\n", log);
			break;
		default:
			fputs("�ڸ�̨�����������ѡ��ʱû�а�����ʾ�������룬�����������\n", log);
	}
	fclose(log);
	return true;
}

/*OK
* ���ã���other�ļ��е��������ִ��ַ���ʽת��Ϊ������ʽ
* ������otherΪָ��洢�����ļ��Ķ���ָ�룬num��洢��otherָ���ж�ȡ�ı�����Ϊʮ���Ƶ���
*       ��
* ����ֵ���ɹ�¼�뷵��true����֮����false
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
* ���ã�����������������ת��Ϊ�ַ�����ʽ��¼��ָ���ļ���
* ������fp1Ϊָ��洢�����ļ��Ķ���ָ�룬num��洢��Ҫ����fp1��ָ����ļ���ʮ��������
* ����ֵ���ɹ�¼�뷵��true����֮����false
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