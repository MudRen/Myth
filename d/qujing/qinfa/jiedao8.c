// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ��������߻����̵����̣�����סլͥԺ��ǽ�������ٻ�
���ݡ����ϸ�ɫ����������������Ϊ���֣�����������п͵�
��Զ;�ÿ�Ъ�ţ��ϱ���һ�����š�

LONG);

  set("exits", ([
        "north"    : __DIR__"nanshi",
        "south"    : __DIR__"nanmen",
        "west"    : __DIR__"guafu",
        "east"    : __DIR__"xiaoer",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

