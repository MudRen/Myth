// Room: /u/mimi/zhuziguo/street2  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "�ٵ�");
  set ("long", @LONG

ƽ����ȥ��һ���ǳأ�������һ��������š����ߵĲݳ���ʱ
��С����ܳ�����������һ��ɽ��ɽ��Ρ��ͦ�Ρ�

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"street1",
    "west" : __DIR__"eastgate",
  ]));
  set("outdoors", __DIR__"");                   
  set("light_up", 1);

  setup();
}

