// rewritten by snowcat on 4/11/1997
// Room: wuming1

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

����С·�������ۣ�ǰ��ɿ���һ��С��ͺͺ��ɽ�����ܲ���һ��
������ֻ�к�ɫ��ɰʯ��

LONG);

  set("exits", ([
        "northeast" : __DIR__"shalu",
        "southwest" : __DIR__"wuming2",
      ]));
  set("outdoors", "firemount");

  setup();
}
