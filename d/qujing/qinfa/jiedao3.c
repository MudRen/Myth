// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ��������߻����̵����̣�����סլͥԺ��ǽ�������ٻ�
���ݡ����ϸ�ɫ����������������Ϊ���֣��ϱ������·�ڣ�
����Ʈ��������㡣

LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao6",
        "north"    : __DIR__"jiedao1",
        "east"    : __DIR__"jiupu",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

