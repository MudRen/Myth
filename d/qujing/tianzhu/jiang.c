// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ԶԶ�����ŵ����˵�ζ�����������һ���Ӵ���ף���
�����Ÿ�ʽ������ˣ�����������ʯ��ѹ�ų�ˮ����������ľ
�ǽ��׸��ϡ�

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao71",
      ]));
  set("objects", ([
        "/d/obj/food/salt" : 2,
      ]));

  setup();
}


