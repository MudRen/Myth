// create by snowcat.c 4/20/1997
// room: /d/eastway/guandao3.c

inherit ROOM;

void create ()
{
  set ("short", "�ٵ�");
  set ("long", @LONG

����һ�������Ĺٵ����ٵ��������У������������ٵ�һͷ����
���ϣ�һͷ���򶫱���������һ�����ꡣ
LONG);

  set("exits", ([
        "southwest"  : __DIR__"guandao2",
        "southeast"  : __DIR__"huaqing",
        "east"       : __DIR__"shihuang",
      ]));
  set("outdoors", __DIR__);

  setup();
}






