// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG

ƫ��Ϊһ�����εĿ�Ѩ�����߳�����ʯ�񣬶����ϵ���һЩ��
��ʯ�������ϲ��ż��ѻ�棬�Թ�����֮�á��̽�����Ѭ��һ
Ƭ��ڡ�

LONG);

  set("exits", ([
        "east"   : __DIR__"zhong",
        "southwest"   : __DIR__"nei",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



