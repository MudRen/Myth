// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ű�");
  set ("long", @LONG

����ű�ʮ�����֣��в�������Ĵ���Ҳ���۵ơ���������һ
��С·�����ϱ��ǽ����ͷ����ˮ������������������������
����ȥ��

LONG);

  set("exits", ([
        "northwest"   : __DIR__"cunlu2",
        "south"   : __DIR__"qiao",
      ]));
  set("outdoors", __DIR__);

  setup();
}



