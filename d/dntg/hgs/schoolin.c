// Room: /d/4world/schoolin.c
inherit ROOM;

void create ()
{
  set ("short", "�쾮");
  set ("long", @LONG

�����������Ժ���쾮��ͷ��������һ�ɼ�������ա���������
�ݵĴ�����ʱ���������д����ˡ������Ǽ������ס�ķ��ӣ���
�����д����˵��᷿���쾮����������滨��ݡ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"schoolbook",
  "south" : __DIR__"schoolrest",
  "west" : __DIR__"schoolhall",
]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gardener" : 1,
]));

  setup();
}
