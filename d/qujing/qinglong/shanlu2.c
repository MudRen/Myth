// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ��һ���ޱߵ���ɫɭ�֣���紵��������ŭ��Զ�����޺�
����������ɽ·��ɽ���ƣ����¿���ȥʮ�ֶ��ͣ�·�����
�Ҽ�Ϊ��խ��

LONG);

  set("exits", ([
        "eastdown"   : __DIR__"shanlu3",
        "northwest"   : __DIR__"shanlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}



