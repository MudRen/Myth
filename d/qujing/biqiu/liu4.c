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
        "northwest"    : __DIR__"liu3",
        "south"    : __DIR__"xibei",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

