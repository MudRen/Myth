// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

һ��С·�Ի�԰���������С·��������С��ʯ�ӡ��ԱߵĻ�
����Ʈ�������㣬���ϱ���һȥ��������һ���ɾ���ʯ�෿
�ӡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"huayuan3",
        "southeast"   : __DIR__"zhai",
      ]));
  set("outdoors", __DIR__);

  setup();
}



