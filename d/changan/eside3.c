// Room: /changan/eside3.c
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
  "west" : __DIR__"eside2",
  "east" : __DIR__"eside4",
]));
  set("outdoors", 1);

  setup();
}






