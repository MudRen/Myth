inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��ǽΡ�룬�������������ܻ��������ǡ������š�����
����ǻʹ������ˣ�һ��İ��յ��˽�Ȼֹ��������������
Խ�ʼҽ��ء�

LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/weishi" : 2,
  ]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/city/xuanwu-n1",
  "north" : __DIR__"damen",
]));

  setup();
}


