// Room: /changan/eside2.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

��ˮ��ȥ������ǹ��������ڴˣ��㲻�ɵ��Ŀ�����������
������һ��������΢����һ��������Ϣ����֪�ɺδ�Ʈ����
���濿��ǽ��һ��С����
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qiaofu" : 1,
  __DIR__"npc/fisher" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"eside1",
  "east" : __DIR__"eside3",
  "northup" : __DIR__"xiaoqiu",
]));

  setup();
}






