// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "��ǽ");
  set ("long", @LONG

ɽ����бб������һ��ʯͷ��ǽ��ǽ�������߲�ǽͷС�ݡ���
ǰ���Ұ�������ޣ�������ޥ��ɭɭ���м���һ�����Ŷ�����
һС������ͨȥ��

LONG);

  set("exits", ([
        "west"    : __DIR__"qiaolin7",
        "southdown"    : __DIR__"zhuogou",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

