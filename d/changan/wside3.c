// Room: /changan/wside3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

��ˮ��ȥ������ǹ��������ڴˣ��㲻�ɵ��Ŀ�����������
������һ��������΢����һ��������Ϣ����֪�ɺδ�Ʈ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wside4",
  "east" : __DIR__"wside2",
]));
  set("objects", ([
	      __DIR__"npc/lusheng":1,
	      ]));

  set("outdoors", 1);

  setup();
}






