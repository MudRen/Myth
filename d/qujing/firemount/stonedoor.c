// Room: /u/wuliao/firemount/stonedoor.c
inherit ROOM;

void create ()
{
  set ("short", "ʯ����");
  set ("long", @LONG
�����������ʯ����ɽ�����ݶ��ɡ�����һ����ʯ������Ϊ����
����ʱ׼���ġ�
LONG);

  set("light_up", 1);
  set("outdoors", "firemount");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongkou",
]));

  setup();
}
