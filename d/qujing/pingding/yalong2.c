// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ѹ��ɽ");
  set ("long", @LONG

ɽ��������������һƬ���ڴ˿ɼ��Ĵ�ɭ��ï�ܣ�һЩɽ��
������ľ������������������̦���£�ɫ��������⡣С·
��ɽ�������ѵش�����

LONG);

  set("exits", ([
        "northdown"   : __DIR__"yalong1",
        "eastdown"   : __DIR__"yalong3",
        "southwest"   : __DIR__"shimen",
      ]));
  set("outdoors", __DIR__);

  setup();
}



