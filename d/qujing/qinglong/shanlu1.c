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
        "southeast"   : __DIR__"shanlu2",
        "northup"   : __DIR__"shantou",
      ]));
  set("outdoors", __DIR__);

  setup();
}



