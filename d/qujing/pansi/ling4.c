// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

��ɽ�����������ƣ���ԭçç�ĵ�������������һ�����ߵ���
���ϣ�ʱ�����ͱ�ֱ��ʱ�����н�ˮ����������Ұ���̹⵭��
ʯ��ɽɫ�䡣

LONG);

  set("exits", ([
        "westdown"    : __DIR__"ling3",
        "northeast"    : __DIR__"ling2",
        "southeast"    : __DIR__"qiaolin1",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

