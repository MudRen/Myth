// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��ɽ��");
  set ("long", @LONG

����һƬ��������һ��������ٲ�����ɽ�����������������
��ɽ����������ƽ����ɽ���ڽ��´�������������������
һ��Ȼʯ��ʰ�����ϡ�

LONG);

  set("exits", ([
        "southeast"   : __DIR__"shanjian",
        "westup"   : __DIR__"shanlu3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



