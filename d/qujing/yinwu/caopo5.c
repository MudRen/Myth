// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ���ϻĲ�һ��Ƭ����������֮�ߣ�������������ǳǳ������
����һ�㡣�������ܰ�ţ�̧ͷ���������죬����ȥ�����ĸ�
���������ش�����

LONG);

  set("exits", ([
        "northeast"    : __DIR__"caopo3",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

