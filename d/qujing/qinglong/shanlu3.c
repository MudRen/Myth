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
        "westup"   : __DIR__"shanlu2",
        "eastdown"   : __DIR__"dongshan",
      ]));
  set("outdoors", __DIR__);

  setup();
}



