// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "é��");
  set ("long", @LONG
   
  ������һ���ķ���,����������ǽ����һϯ���ò�����
��ϯ�����˲��ڼң������������˺���һ��ҡ�ֻ�м�ֻ
�����󣬵���һ˫С�۾������ɵĿ����ⲻ��֮�͡�����ɢ
����һ��ˮ�ޣ������������롣
��
LONG);
  
  set("objects", ([
        __DIR__"npc/rat"   : 2,
      ]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
     "east" :__DIR__"sroad7",
]));

  setup();
}






