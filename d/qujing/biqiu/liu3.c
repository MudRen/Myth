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
        "northeast"    : __DIR__"liu2",
        "southeast"    : __DIR__"liu4",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

