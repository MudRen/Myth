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
        "northwest"   : __DIR__"shanlu6",
        "south"   : "/d/qujing/jinping/cunlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}



