//Cracked by Roath
// Room: mbedroom.c
// written by Kittt

inherit ROOM;

void create()
{
      set("short", "����Ϣ��");
      set("long", @LONG
���Ǽ���ݵ�����Ϣ�ң����ڹ��ߺܻ谵����Χ���ż���
�Ĵ������ž�������˯���������һ���Ű���˯����������
LONG);

	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_get",1);
	set("exits",([
		"north" : __DIR__"zoulang",
		]));
	
	setup();
}
