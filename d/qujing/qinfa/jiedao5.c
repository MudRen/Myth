// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ��������߻����̵����̣�����סլͥԺ��ǽ�������ٻ�
���ݡ����ϸ�ɫ����������������Ϊ���֣�����ĵ����ſ�ɹ
��һЩƤ����

LONG);

  set("exits", ([
        "west"    : __DIR__"jiedao4",
        "east"    : __DIR__"wugu",
        "north"    : __DIR__"yaopu",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

