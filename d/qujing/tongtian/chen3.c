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
        "north"   : __DIR__"chen1",
        "west"   : __DIR__"xiaolu2",
        "east"   : __DIR__"minju5",
        "south"   : __DIR__"jitan",
        "southeast"   : __DIR__"minju6",
      ]));
  set("outdoors", __DIR__);

  setup();
}



