// Room: /u/mimi/zhuziguo/square.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "Ǭ���㳡");
  set ("long", @LONG

�����ǳ������ˣ�·���Լ�����С�����㶵�۵��ص��������򱱿���
�����ڼ����Ļʹ�����������һƬ��լ���������ߵĴ�·���в�����
�꣬���Ƿ��������������ڼ��������˳���ϰ��԰�����ҵ��һƬ��
���ٵľ���

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"estreet2",
    "north" : __DIR__"nstreet.c",
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}

