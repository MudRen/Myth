// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

С·�������䣬·��������ʯ���ѱ������ĳ���ѹ��������ӡ��
·����һ�ÿ����������Ÿ�������������������·��������
ũ������ׯ�ڡ�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"chen2",
        "northeast"   : "/d/qujing/chechi/shatan5",
      ]));
  set("outdoors", __DIR__);

  setup();
}



