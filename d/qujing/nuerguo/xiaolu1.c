// created by snowcat.c 4/4/1997
// room: /d/nuerguo/xiaolu1.c

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
    "east"       : __DIR__"jieyang",
    "westup"     : __DIR__"xiaolu2",
  ]));
  set("outdoors", __DIR__"");

  setup();
}






