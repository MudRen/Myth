// Room: /changan/eside4.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

��ˮ��ȥ������ǹ��������ڴˣ��㲻�ɵ��Ŀ�����������
������һ��������΢����һ��������Ϣ����֪�ɺδ�Ʈ����
LONG);

  set("exits", ([ /* sizeof() == 3 */
//  "south" : "/d/quest/erlang/guanjiang",
  "west" : __DIR__"eside3",
  "east" : __DIR__"eside5",
]));
  set("outdoors", 1);

  set("objects", ([ /* sizeof() == 2 */
 "/d/city/npc/leigong":1,
]));
  setup();
}






