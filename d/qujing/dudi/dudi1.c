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
        "southwest"   : __DIR__"dudi2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



