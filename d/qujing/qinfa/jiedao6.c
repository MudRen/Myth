// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ��������߻����̵����̣�����סլͥԺ��ǽ�������ٻ�
���ݡ����ϸ�ɫ����������������Ϊ���֣����������¥����
��ͨ�������Ľֵ���

LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao3",
        "east"    : __DIR__"jiedao7",
        "west"    : __DIR__"wugu",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

