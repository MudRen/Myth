// Room: /u/mimi/zhuziguo/bedroom.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "�޹�");
  set ("long", @LONG

���������ͣ�����װ�ξ���ϸ�塣��������һ��������������һ
Щ������������һ���Ǵ�����������Ž��޻���������ͨ��¶���
СԺ�ӡ�

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"garden",
  ]));
  set("sleep_room",1);
  set("if_bed",1);

  setup();
}

