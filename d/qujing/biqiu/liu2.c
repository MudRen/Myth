// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��һ�������£�ֻ�������������£����ܳ�������֦�����
�Ỻ����Ʈ���š�Զ����һƬũ��������ǣ�����Ұ��۲�
����ǧ�����������١�

LONG);

  set("exits", ([
        "west"    : __DIR__"liu1",
        "southwest"    : __DIR__"liu3",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

