//Cracked by Roath
// bingqifang.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "������"); 
	set("long",@LONG
������ݵı���������,ǹ,��,��,���ȸ�ʽ����������������
��ذڷ��ڼ����ϡ����Ҫ��������ǹ�����ԣ�ͻȻһ�Ѹֵ���
�����ϵ����������û����С��Ҫ�ˡ�   
LONG);

	set("exits",([
		"west" : __DIR__"xiaojing3",
		])); 
	set("objects",([
		__DIR__"obj/blade":		1,
		__DIR__"obj/changjian":	1,
		__DIR__"obj/gun":		1,
		]));
	
	setup();
} 
