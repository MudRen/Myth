// shishi4.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
����һ�����µ�����ʯ�ң�������Ըо��õ���ֻ��ǿ�ҵ�ɱ�����Լ�
����ص׵�һЩ���ŵ���ζ����΢���ĵƹ��£��㾹Ȼ�����и���վ�����
�������º�����·��
LONG );
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	setup();
}

