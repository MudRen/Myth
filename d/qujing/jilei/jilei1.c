//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

����ɽ���絶��һ�㣬Ⱥ�������ι�״��Ȯ������ɽ������
����һ�ɹ�Ũ�ҵ���������������Х���չȻ�����Ұ�޵ĺ�
�����Ѿ��ܽ��ˡ�

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shan11",
        "southwest"   : __DIR__"jilei2",
        "southeast"   : __DIR__"jilei3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



