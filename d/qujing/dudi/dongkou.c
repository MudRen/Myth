// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ������������ɽ�������һ�����ڣ�����ð������������
���İ���һ�㡣�߸ߵ�ʯ���Ͽ���������Ŀ�Ĵ��֣�������ɽ
���Ŷ����������Ϸ�����һ��ڡ�

LONG);

  set("exits", ([
        "southwest"   : __DIR__"dudi2",
        "enter"   : __DIR__"yidong",
      ]));
  set("outdoors", __DIR__);

  setup();
}



