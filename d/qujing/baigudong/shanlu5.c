// Room: writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

  ֻ��ɽʯ���ͣ�·������������Ũ����ǰ������·����
���ٳ�·�����ֲ�����ָ�������Ѽ����ա�ģģ�����ܿ�
��ɽ����һ���޴�Ķ��ڣ�ͻͻ��ð�ź��̡�
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "eastdown"      : __DIR__"shanlu4",
  "west" : __DIR__"shanlu6",
]));

  setup();
}






