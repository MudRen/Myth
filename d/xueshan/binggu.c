//sgzl
inherit ROOM;

void create ()
{
	set ("short", "ѩɽ����");
	set ("long", @LONG

���Ų�����һ����ɽ���С�����ɽ���վ���̧ͷ������ɽ����
��������Ԯʱ������躮��Ǧ�Ƶ�ѹ�����罥�����������
��Ʈ��һƬƬ��ѩ����
LONG);


	set("exits", 
	([ //sizeof() == 4
		"northup" : __DIR__"xuelu1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();
}



