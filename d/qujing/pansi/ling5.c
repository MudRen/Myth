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
        "southeast"    : "/d/qujing/zhuzi/lin3",
        "southwest"    : __DIR__"ling7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

