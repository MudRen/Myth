// Room: /u/mimi/zhuziguo/street1  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

������ľïʢ��������ա�������Ҷ������ϡ�ɡ������ౡ�
����ϰϰ��

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "northeast" : __DIR__"shandao2",
    "west" : __DIR__"street2",
    "eastup" : __DIR__"road7",
    "southwest" : __DIR__"shandao3",
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}
