// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽʯ��");
  set ("long", @LONG

ɽʯ���Ĵ�����ʯ�飬ʯ��ķ�϶�ﳤ��һЩ�Ӳݡ�·������
Ϊ��ɫ��ɽ�ң�������С�ʯ��ԶԶ�����س���һЩ��������
ɽ����ҡҷ��

LONG);

  set("exits", ([
        "north"   : __DIR__"jindou1",
        "southeast"   : __DIR__"shanshi2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



