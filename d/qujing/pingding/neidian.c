// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�ڵ�");
  set ("long", @LONG

ʯ����������������γ�һ�������������а��˸ߵ�ʯ�飬
������ų�ľ�壬������ʯ�ĺ�ʯ׮�ӡ���Ķ��������ң���
����ͨ��ʯ�ȡ�

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shilang2",
        "east"   : __DIR__"wofang1",
        "southwest"   : __DIR__"wofang2",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 3,
      ]));

  setup();
}


