// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

����ɽ����һ���޼ʵ���Ұ�������ɽ����գ���ʱ�ɼ�����
��������������һ�㡣ɽ�ϣ�ʯ��ʯ�¼俪�ٳ�һ��С·����
���ϣ�·���������������£����˵�����

LONG);

  set("exits", ([
        "northeast"   : __DIR__"dudi2",
        "southeast"   : __DIR__"dudi4",
      ]));
  set("outdoors", __DIR__);

  setup();
}



