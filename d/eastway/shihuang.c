// create by snowcat.c 4/20/1997
// room: /d/eastway/shihuang.c

inherit ROOM;

void create ()
{
  set ("short", "ʼ����");
  set ("long", @LONG

���������ڹٵ��Զ���һ�������꣬�ʸ����͡�վ������
�ϼ�ĿԶ���������Ŀ��������Ա���һ���ߴ��ʯ����
����ʼ���ꡱ��

LONG);

  set("exits", ([
        "east"       : __DIR__"bingma",
        "west"       : __DIR__"guandao3",
      ]));
  set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/wujiang" : 2,
         __DIR__"npc/bing" : 3,
      ]));

  set("outdoors", __DIR__);

  setup();
}






