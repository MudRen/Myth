// created by snowcat.c 4/4/1997
// room: /d/nuerguo/xiaolu4.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

����һ����ϸ�ֳ���ɽ��С����һ����ߣ�һ����͡�·��
�����ǲ�֪����Ұ��Ұ�ݡ�����ٵ����ţ�����ɽ����һ��
���͡�

LONG);

  set("exits", ([
    "southdown" : __DIR__"xiaolu3",
    "northup"   : __DIR__"changbie",
  ]));
  set("outdoors", __DIR__"");

  setup();
}






