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
        "northeast"   : __DIR__"shan14",
        "southup"   : __DIR__"yalong2",
        "southeast"   : __DIR__"yalong3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



