//Cracked by Roath
// Room: /d/nanhai/road1
inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG
����һ��ͨ����ɽ��С·����·����Խ��Խ�����ߣ��ֲ�ҲԽ��Խ
���ˣ������Թ�һ����һ��С�ľͻ���ʧ���򣬶���˳ԭ·���߲���ȥ��
�㲻�������������Ҫ��Ҫ������ǰ���أ�
LONG);

  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhulin0.c",
  "southeast" : __DIR__"road3",
  "southwest" : __DIR__"road33",
]));

  setup();
}
