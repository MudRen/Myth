// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

һ��������Ұ���·��·��������ʯ�ӣ�·�߿����������ݡ�
��·��ƽ̹��ԭҰ�����������ѡ�Զ���ɼ�����Ⱥ���������
��֮�С�

LONG);

  set("exits", ([
        "north"   : __DIR__"nanmen",
        "south"   : __DIR__"dalu4",
      ]));
  set("outdoors", __DIR__);

  setup();
}



