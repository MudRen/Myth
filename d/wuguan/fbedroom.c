//Cracked by Roath
// Room: fbedroom.c
// written by Kittt

inherit ROOM;

void create()
{
      set("short", "Ů��Ϣ��");
      set("long", @LONG
���Ǽ���ݵ�Ů��Ϣ�ң����ڹ��ߺܻ谵����Χ���ż���
�Ĵ������ž�������˯�������Ա߷������澵�ӣ�����Ů����
����ǰ����ͷ��
LONG);

	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_steal",1);
	set("no_get", 1);
	set("exits",([
		"east" : __DIR__"zoulang",
		]));
	
	setup();
}
