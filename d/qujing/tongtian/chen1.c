// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�¼�ׯ");
  set ("long", @LONG

�¼�ׯ��ס�Ŵ��СС���˼ң����ճ¹�Ϊ�¼�ׯ��ׯ���ﲻ
ʱ���������ֵ������������ż������С�һЩ�˼ҵ��̴���ð
���������̣�������ɢ���Ų����㡣

LONG);

  set("exits", ([
        "north"   : __DIR__"minju1",
        "west"   : __DIR__"minju4",
        "east"   : __DIR__"chen2",
        "south"   : __DIR__"chen3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



