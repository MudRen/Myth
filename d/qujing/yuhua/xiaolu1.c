// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

�ڻ�Ұ�ϣ�һ��С·����������ϸ�ֳ���·�߷紵������ݺ�
������Զ������ɽ���������������ϡϡ���ܣ�·���߰ٲ���
���ޡ�

LONG);

  set("exits", ([
        "southwest"   : __DIR__"xiaolu2",
        "northeast"   : "/d/qujing/zhujie/shanlu18",
      ]));
  set("outdoors", __DIR__);

  setup();
}



