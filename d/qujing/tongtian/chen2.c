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
        "northeast"   : __DIR__"minju3",
        "northwest"   : __DIR__"minju2",
        "north"   : __DIR__"yaopu",
        "west"   : __DIR__"chen1",
        "southeast"   : __DIR__"xiaolu3",
      ]));
  set("objects", ([
        __DIR__"npc/vendor"  : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



