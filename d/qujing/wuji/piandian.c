// Room: /u/mimi/zhuziguo/piandian.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create()
{
  set("short", "ǰ��");
  set("long", @LONG

ֻ�����ߺ����������������һ�Խ�գ�װ�ܵ��������һ��
������ף�һ����üԲ�ۣ������������ã��������ӳƮ�硣

LONG);
  set("no_clean_up", 0);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
    "out" : __DIR__"temple",
    "north" : __DIR__"zheng",
  ]));

  setup();
  replace_program(ROOM);
}
