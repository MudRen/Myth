// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��Ѩ�ڻ�谵������˿������һ�������ڶ��ڣ�������ˮ����
�����ض��ڷ׷����£����������һ˿΢���Ĺ����Զ�������
���������

LONG);

  set("exits", ([
        "northeast"    : __DIR__"shidong",
      ]));
  set("objects", ([
        __DIR__"npc/son1"    : 1,
        __DIR__"npc/son2"    : 1,
        __DIR__"npc/son3"    : 1,
        __DIR__"npc/son4"    : 1,
        __DIR__"npc/son5"    : 1,
        __DIR__"npc/son6"    : 1,
        __DIR__"npc/son7"    : 1,
      ]));
  setup();
}

