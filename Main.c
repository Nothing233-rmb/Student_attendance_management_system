#include"statement.h"

//C:\\Program_Data\\data.dat

/*ʵ��Ч��
* P.S.���ֺ�����֮��Ŀո���Ϊ18�������ں͵������֮����һ���ո�
* 
* ĳĳĳ
*                   ����ϰ  ��һ��  �ڶ���  ������  ���Ľ�  ����ϰ
* ����һ(2023/11/27) ����    �ٵ�    ����    ���    �޿�    ����
* ���ڶ�(2023/11/28) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/11/29) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/11/30) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/12/01) ����    �ٵ�    ����    ���    �޿�    ����
* 
*                   ����ϰ  ��һ��  �ڶ���  ������  ���Ľ�  ����ϰ
* ����һ(2023/12/02) ����    �ٵ�    ����    ���    �޿�    ����
* ���ڶ�(2023/12/03) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/12/04) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/12/05) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/12/06) ����    �ٵ�    ����    ���    �޿�    ����
* 
*                   ����ϰ  ��һ��  �ڶ���  ������  ���Ľ�  ����ϰ
* ����һ(2023/12/07) ����    �ٵ�    ����    ���    �޿�    ����
* ���ڶ�(2023/12/08) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/12/09) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/12/10) ����    �ٵ�    ����    ���    �޿�    ����
* ������(2023/12/11) ����    �ٵ�    ����    ���    �޿�    ����
* 
* ��������
*/


/*��Ҫ��ӵ��¹���[OK]
* ¼��ѧ����Ϣ����[OK]
* �ر�¼�������Լ����������Լ���ʱ�رպͿ����ù���[OK]
* ���ر�¼��ѧ����Ϣ��������ÿ��¼����Ϻ���м���¼��ѯ�ʣ����������Զ�����¼�루����exit�˳���[OK]
* ����ʱ�رոù�����¼����Ϻ󲻻�ѯ��ֱ���˻���һ����ֻ���ڿ����ù��ܺ����ѡ�񿪹�ǰ����ѡ��[OK]
* �¹��ܲ���ʱ��Ҫ¼����־��¼����־������Ҫ�޸ģ�[OK]
*/


/*��ȡ�����ղ�����ת��Ϊһ���ַ���
* flag = get_time(&year, &mon, &day, flag);
* make_str(t, year, mon, day, &flag);
*/


/*���ļ�ָ����;
* fpΪ���ʺͲ����洢ѧ����Ҫ��Ϣ���ļ�ָ��
* temΪ���ڷ�����ʱ�ļ����ļ�ָ��
* o_temΪ���ڷ��ʸ���other�ļ�����������ʱ�ļ����ļ�ָ��
* logΪ���ʺͲ����洢��־��Ϣ���ļ�ָ��
* otherΪ���ʺͲ����洢������Ҫ��Ϣ���ļ�ָ�루�����ڵȣ��Է���ʹ����Щ��Ϣ���������ļ���
*/

/*�����뺬��
* �������� 0
* �ļ�д��ʧ�ܣ�-1
* �����ļ�����ʧ�� -2
* ��־�ļ�����ʧ�� -3
* �����ļ�����ʧ�� -4
*/

/*��Ǹ
* ��Ϊ�ó��������ע�Ͷ����ڱ�д����Ĺ������������д�ģ���;�Ĵ���ͺ��������Լ���������
* Ҳ�������ִ�����޸ģ����Կ��ܻ�������µ�һ�ֻ���������
* 1.ע�͵���˼�������޷���Ӧ���루��ִ�еĲ����������������ܵȣ�
* 2.��ֵ�ע�ͣ��磺��//OK�ô���Ҫ�������ļ��л�ȡ�ܼ������֣�Ȼ������Ϊ������������������
*   ��Ϊ��ϰ�߰���Ҫʵ�ֵĹ��ܻ�ע�������д��ע�ͣ�Ȼ������ɲ�������ϸù��ܺ����������
*   �Ǻ����Ա�ǣ���������ɺ����Ҳ����ɾ��
* P.S.�ܶ�����δ��дע�ͣ�������Ϊ�Ҹ���ֻ���������������߼���Ϊ���ӵĴ���δ���дע�ͣ�
*	  ��С�������Ҳ������ͨ���������дע��
* ���½�
*/

/*��ͬ����ʱʹ�ò�ͬ����
* 
* 1.�ر�¼���������� ��=0
* 2.����¼���������� ��=1��Ĭ�ϣ�
* 3.�ر�����¼����ʾ ��־λ=0
* 4.��������¼����ʾ ��־λ=1��Ĭ�ϣ�
*/
Bit sign = { .bit_1 = 1,.bit_2 = 1 };//bit_1Ϊ�ܹ��ܿ���(0,1)��bit_2Ϊ���ܱ�־λ(0,1)

int main(void)
{
#if TEST==0
	if (get_week() == 6)
	{
		print_first_hint();
		fputs("\n������ֹʹ�øó����밴����ʾ�����˳���ֱ�ӹرոó���!\n", stdout);
		system("PAUSE");
		exit(0);
	}
#endif
	FILE* fp = NULL;//���ʴ洢ѧ����Ϣ�ļ�ָ��
	FILE* tem = NULL;//��ʱָ�룬���ڷ�����ʱ�ļ�
	FILE* o_tem = NULL;//��ʱָ�룬���ڷ��ʸ���other�ļ���������ʱ�ļ�ָ��
	FILE* log = NULL;//������־�ļ�ָ��
	FILE* other = NULL;//���ʴ�������ؼ������ļ���ָ��
	Bit flag = { .bit_2 = 0 ,.bit_1 = 0 };//��־λ��Ϊ1���������Ϊһλ����Ϊ2������·ݺ����ڶ�Ϊһλ��
	char name[100];//�洢ѧ��������
	char* week[6] = { "������","����һ","���ڶ�","������","������","������" };
	char t[LEN];//�洢������ʱ���ַ�������
	char _t[9];//�洢ʱ����ʱ���ַ�������
	int num[3];//�ݴ�ѧ���Ŀ��Ρ��ٵ��Լ����������ʵ��Ϊһ��ת�����ģ��������ݽ�������Ҫ�ĳ����������
	int year, mon, day;//�洢�����յ����ͱ���
	int n;//�洢�˵����������ѡ��
	char ch;//������뻺����ר�ñ���������Ҫʹ�ú�CL���������ñ���
	memset(name, '\0', 100);
	for (;; n = -1)
	{
		system("CLS");//====================
		print_first_hint();
		scanf_s("%d", &n);
		CL
		switch (n)
		{
			case 1://ѡ��¼��ѧ����Ϣ���䵱�յ��μ�¼����������¼��ѧ����Ϣ�ĵ��μ�¼
			{
				exist(&fp, &log, &other);
				input_log(log, 1, t, _t);//��Ҫ��Ӷ�����־��Ϣ�Ĵ��루������
				cur:
				system("CLS");
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("|                              �����˵�                             |\n", stdout);
				fputs("|1.¼���Ѵ���ѧ�����յĵ��μ�¼                                     |\n", stdout);
				fputs("|2.�����ѧ��Ȼ��¼���䵱�յ��μ�¼                                 |\n", stdout);
				fputs("|3.�˻���һ��                                                       |\n", stdout);
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("��������Ҫ���еĲ�����", stdout);
				scanf_s("%d", &n);
				CL
				switch (n)
				{
					case 1://¼���Ѵ���ѧ�����յĵ��μ�¼
					{
						input_log(log, 9, t, _t);//��Ҫ��Ӷ�����־��Ϣ�Ĵ��루������====================================================
						fopen_s(&fp, P_DATA, "rb+");
						n = fgetc(fp);
						if (n == EOF)
						{
							fputs("�ļ��ڲ����κ�ѧ����Ϣ������¼����Ϣ��", stdout);
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
							printf("����ѧ����Ϊ��%s", name);
							fputs(name, tem);
							while (fgetc(fp) != '=')
							{
								fseek(fp, -1L, SEEK_CUR);
								fputc(fgetc(fp), tem);
							}
							if (get_week() == 1)
								fputs(COURSE_STR, tem);
							//OK�ô���Ҫ�������ļ��л�ȡ�ܼ������֣�Ȼ������Ϊ��������
							fputs(week[get_week()], tem);//==================
							fputc('(', tem);
							flag = get_time(&year, &mon, &day, flag);
							make_str(t, year, mon, day, &flag);
							fputs(t, tem);
							fputs(") ", tem);
							fseek(fp, 1L, SEEK_CUR);//���ļ�ָ��λ�������ƶ�һλ��ʹ��ָ����һ��ѧ�����֣��ƶ�ǰ�ļ�ָ��ָ��=�ź��\n��
							input_data(tem, num);//OK������Ҫ��ӻ�ȡ���벢�����ļ��Ĵ��루������������Ҫ�ڶ�����Ϻ��ڽ�βд�뻻�к�=��\n=\n��
							num_fp(&o_tem, num);//ȱһ����num�е�����д����ʱ�ļ��ĺ���
						}
						if (!input_fil(tem, fp))//OK����ȱһ����tem�ļ������ݶ���data�ļ��ĺ���
						{
							system("CLS");
							fputs("�ļ�д��ʧ�ܣ��������(-1),���Ժ����³��Ի���ϵ������\n", stdout);
							system("PAUSE");
							exit(-1);
						}
						if (!input_fil(o_tem, other))//OK����ȱһ����o_tem�ļ������ݶ���other�ļ��ĺ���
						{
							system("CLS");
							fputs("�ļ�д��ʧ�ܣ��������(-1),���Ժ����³��Ի���ϵ������\n", stdout);
							system("PAUSE");
							exit(-1);
						}
						fclose(tem);
						fclose(o_tem);
						remove(P_TEM);//�����ɾ��tem�ļ�
						remove(P_OTEM);//�����ɾ��otem�ļ�
						fclose(fp);
						fclose(other);
						break;
					}
					case 2://�����ѧ��Ȼ��¼���䵱�յ��μ�¼
					{
						input_log(log, 10, t, _t);
						do 
						{
							system("CLS");
							print_input_hint();
							fopen_s(&fp, P_DATA, "ab");
							fopen_s(&other, P_OTHER, "ab");
							if (sign.bit_1 && !sign.bit_2)//����������빦�ܴ��ڿ���״̬��������ʾ���ڹر�״̬
								fputs("��������Ҫ¼���ѧ������������exit�˳�����", stdout);
							else
								fputs("��������Ҫ¼���ѧ��������", stdout);
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
							//OK�ô���Ҫ��ȡ�ܼ������֣�Ȼ������Ϊ��������
							fputs(week[get_week()], fp);//==================
							fputc('(', fp);
							flag = get_time(&year, &mon, &day, flag);
							make_str(t, year, mon, day, &flag);
							fputs(t, fp);
							fputs(") ", fp);
							for (int count = 0; count < 3; count++)
								num[count] = 0;
							input_data(fp, num);//OK������Ҫ��ӻ�ȡ���벢�����ļ��Ĵ��루������������Ҫ�ڶ�����Ϻ��ڽ�βд�뻻�к�=��\n=\n��
							num_fp(&other, num);
							fclose(fp);
							fclose(other);
							if (sign.bit_1 == 1 && sign.bit_2 == 1)
							{
								fputs("����Ҫ���������𣿣������ַ�/ENTER����", stdout);
								name[0] = getchar();
								if (name[0] != '\n')
								{
									CL
									break;
								}
							}
								
						} while (sign.bit_1);//���¼����������Ϊ�ر�״̬
						//�������ѧ��������Ҫ�ļ���¼���ʼֵ����׷��ģʽ¼��
						//��Ҫ�ڶ���󽫳ٵ��Ϳ����������ļ��У�����ֱ���ǳ���
						fputs("ѧ�����͵������¼����ϣ�\n", stdout);
						system("PAUSE");
						break;
					}
					case 3://�˻���һ��
						input_log(log, 11, t, _t);
						continue;
					default://�����벻��ȷ
					{
						input_log(log, -1, t, _t);
						fputs("��������ȷֵ��", stdout);
						Sleep(1000);
						goto cur;
					}
				}
				break;
			}
			case 2://���ն�����ʾ����ѧ������ȫ����һ������ĳٵ��������Լ��������μ�¼
			{
				input_log(log, 2, t, _t);
				system("CLS");
				fopen_s(&fp, P_DATA, "rb");
				if (!fp)
				{
					system("CLS");
					fputs("�ļ������ڣ��봴����¼����Ϣ�����ԣ�\n", stdout);
					fputs("�����ɴ������⣬���Ժ����Ի���ϵ������\n", stdout);
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
				fputs("����ѧ�����䵽������Ѿ���ʾ���\n", stdout);
				system("PAUSE");
				break;
			}
			case 3://ֻ��ʾ����ѧ�������䵱ǰ�ܿ��Ρ��ٵ��������
			{
				/*����ʵ�ַ���[ok]
				* ��other�ļ������ڣ����ڴ����ļ���ÿ���˵ĳٵ��Ϳ���������Ϊ0[�ϳ��뷨]
				* �����ڣ�����ÿ��¼��ѧ����Ϣʱ���ݷ��������еķ��������������ٵ�����ε�����
				* ¼��other�ļ�ʱ����Ҫ��¼�������ת��Ϊ�ַ�����ȡҲͬ����Ҫ����ת��
				* ����Ҫ��ʾ����ѧ�����ܿ��κͳٵ���ʱ����other�ļ������ζ�ȡ����
				*/
				//��ʽ��
				//����    ������ �ٵ���
				//ĳĳĳ  21     11
				input_log(log, 3, t, _t);
				system("CLS");
				fputs(" ����   ������ ����� �ٵ���\n", stdout);
				fopen_s(&fp, P_DATA, "rb");
				fopen_s(&other, P_OTHER, "rb");
				if (!fp || !other)
				{
					system("CLS");
					fputs("�ļ������ڣ��봴����¼����Ϣ�����ԣ�\n", stdout);
					fputs("�����ɴ������⣬���Ժ����Ի���ϵ������\n", stdout);
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
					//��������֮����Ҫ������ո��������һ���˵ĵ����������Ҫ�ں���ӻ��з�
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
			case 4://����ѧ�����������ܿ��κͳٵ���
			{
				input_log(log, 4, t, _t);
				system("CLS");
				fopen_s(&fp, P_DATA, "rb");
				fopen_s(&other, P_OTHER, "rb");
				if (!fp || !other)
				{
					system("CLS");
					fputs("�ļ������ڣ��봴����¼����Ϣ�����ԣ�\n", stdout);
					fputs("�����ɴ������⣬���Ժ����Ի���ϵ������\n", stdout);
					system("PAUSE");
					continue;
				}
				int count;
				char tem[100];
				fputs("��������Ҫ���ҵ�ѧ������������Ϻ���ENTER��������", stdout);
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
						fputs(" ����   ������ ����� �ٵ���\n", stdout);
						printf("%-10s", tem);
						for (int count = 0; count < 3; count++)
							printf("%-7d", num[count]);
						putchar('\n');
						break;
					}
				}
				if (ch == EOF)
				{
					fputs("δ�ҵ���ѧ���������¼������ԣ�\n", stdout);
					fputs("�����ɴ������⣬���Ժ����Ի���ϵ������\n", stdout);
				}
				fclose(fp);
				fclose(other);
				system("PAUSE");
				break;
			}
			case 5://����ѧ����������ȫ����һ������ĳٵ��������Լ��������μ�¼
			{
				input_log(log, 5, t, _t);
				system("CLS");
				fopen_s(&fp, P_DATA, "rb");
				if (!fp)
				{
					system("CLS");
					fputs("�ļ������ڣ��봴����¼����Ϣ�����ԣ�\n", stdout);
					fputs("�����ɴ������⣬���Ժ����Ի���ϵ������\n", stdout);
					system("PAUSE");
					continue;
				}
				int count;
				char tem[100];
				fputs("��������Ҫ���ҵ�ѧ������������Ϻ���ENTER��������", stdout);
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
					fputs("δ�ҵ���ѧ���������¼������ԣ�\n", stdout);
					fputs("�����ɴ������⣬���Ժ����Ի���ϵ������\n", stdout);
				}
				fclose(fp);
				system("PAUSE");
				break;
			}
			case 6://�鿴��־
			{
				/*��Ļѡ��
				1.ѡ��¼��ѧ����Ϣ���䵱�յ��μ�¼����������¼��ѧ����Ϣ�ĵ��μ�¼
				2.���ն�����ʾ����ѧ������ȫ����һ������ĳٵ��������Լ��������μ�¼
				3.ֻ��ʾ����ѧ�������䵱ǰ�ܿ��Ρ��ٵ��������
				4.����ѧ�����������ܿ��κͳٵ���
				5.����ѧ����������ȫ����һ������ĳٵ��������Լ��������μ�¼
				6.�鿴��־
				7.ɾ���ó����ڸõ����ϴ洢�����������ļ�
				8.�˳�

				��Ļѡ��1����ѡ��
				1.¼���Ѵ���ѧ�����յĵ��μ�¼
				2.�����ѧ��Ȼ��¼���䵱�յ��μ�¼
				3.�˻���һ��
				*/
				input_log(log, 6, t, _t);
				fopen_s(&log, P_LOG, "rb");
				if (!log)
				{
					system("CLS");
					fputs("��־�ļ������ڣ��봴�������ԣ�\n", stdout);
					fputs("�����ɴ������⣬���Ժ����Ի���ϵ������\n", stdout);
					system("PAUSE");
					continue;
				}
				system("CLS");
				while ((ch = fgetc(log)) != EOF)
					putchar(ch);
				fclose(log);
				fputs("\nȫ����־��Ϣ����������\n", stdout);
				system("PAUSE");
				break;
			}
			case 7://ɾ���ó����ڸõ����ϴ洢�����������ļ�
			{
				system("CLS");
				fputs("ȷ��Ҫɾ�����д洢�ڸü���������ϵ������ļ���[��ɾ���ڴ����б�����ļ������ݣ���������Ҫ�û�ɾ��]��ENTER/n����", stdout);
				if (getchar() == '\n')
				{
					if (!system("RD /S /Q C:\\Program_Data"))
						fputs("���б����ڴ˼�����ϵ������ļ����ѱ�ɾ��\n", stdout);
					else
					{
						system("CLS");
						fputs("δ�ҵ����ļ����봴��������!\n", stdout);
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
			case 8://��������
			{
				input_log(log, 8, t, _t);
				cur1:
				system("CLS");
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("|                              �����˵�                             |\n", stdout);
				fputs("|1.�ر�¼����������                                                 |\n", stdout);
				fputs("|2.����¼����������                                                 |\n", stdout);
				fputs("|3.�ر�����¼����ʾ                                                 |\n", stdout);
				fputs("|4.��������¼����ʾ                                                 |\n", stdout);
				fputs("|5.�˻���һ��                                                       |\n", stdout);
				fputs("---------------------------------------------------------------------\n", stdout);
				fputs("��������Ҫ���еĲ�����", stdout);
				scanf_s("%d", &n);
				CL
				switch (n)
				{
					case 1://�ر�¼����������
					{
						/*��ͬ����ʱʹ�ò�ͬ����
						*
						* 1.�ر�¼���������� ��=0
						* 2.����¼���������� ��=1��Ĭ�ϣ�
						* 3.�ر�����¼����ʾ ��־λ=0
						* 4.��������¼����ʾ ��־λ=1��Ĭ�ϣ�
						*/
						if (sign.bit_1)
						{
							sign.bit_1 = 0;//bit_1Ϊ�ܹ��ܿ���(0,1)��bit_2Ϊ���ܱ�־λ(0,1)
							fputs("¼�����������ѹر�", stdout);
						}
						else
							fputs("¼�����������Ѵ��ڹر�״̬�������ظ��ر�", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 2://����¼���������ܣ�Ĭ�ϣ�
					{
						if (!sign.bit_1)
						{
							sign.bit_1 = 1;//bit_1Ϊ�ܹ��ܿ���(0,1)��bit_2Ϊ���ܱ�־λ(0,1)
							fputs("¼�����������ѿ���", stdout);
						}
						else
							fputs("¼�����������Ѵ��ڿ���״̬�������ظ�����", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 3://�ر�����¼����ʾ
					{
						if (sign.bit_1 && sign.bit_2)
						{
							sign.bit_2 = 0;//bit_1Ϊ�ܹ��ܿ���(0,1)��bit_2Ϊ���ܱ�־λ(0,1)
							fputs("����¼����ʾ�ѹر�", stdout);
						}
						else if (!sign.bit_1)
							fputs("����¼�빦���Ѵ��ڹر�״̬���޷�����������", stdout);
						else if (!sign.bit_2)
							fputs("����¼����ʾ�Ѵ��ڹر�״̬�������ظ��ر�", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 4://��������¼����ʾ��Ĭ�ϣ�
					{
						if (!sign.bit_2)
						{
							sign.bit_2 = 1;//bit_1Ϊ�ܹ��ܿ���(0,1)��bit_2Ϊ���ܱ�־λ(0,1)
							fputs("����¼����ʾ�ѿ���", stdout);
						}
						else if (!sign.bit_1)
							fputs("����¼�빦���Ѵ��ڹر�״̬���޷�����������", stdout);
						else if (sign.bit_2)
							fputs("����¼����ʾ�Ѵ��ڿ���״̬�������ظ�����", stdout);
						Sleep(1250);
						goto cur1;
					}
					case 5:
						continue;
					default:
					{
						input_log(log, -1, t, _t);
						fputs("��������ȷֵ��", stdout);
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
				fputs("��ӭ�´�ʹ��\n", stdout);
				system("PAUSE");
				return 0;
			}
			default://�����벻��ȷ
			{
				input_log(log, -1, t, _t);
				fputs("��������ȷֵ��", stdout);
				Sleep(1000);
			}
		}
	}
	return 0;
}