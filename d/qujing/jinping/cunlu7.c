// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

��ƮƮ����������һ�ۼ�Ŀ��ȥֻ��ũ������ģ�����С����
������ǵ�㡣�����Ǻ�ʵ������·���������﹡����ʱ����
����Ϫˮ�ڹ���������

LONG);

  set("exits", ([
        "north"   : __DIR__"cunlu6",
        "southeast"   : __DIR__"cunlu8",
      ]));
  set("outdoors", __DIR__);

  setup();
}



