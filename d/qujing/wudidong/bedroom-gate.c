// Room: /d/qujing/wudidong/bedroom-gate.c

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

��һ������������ǽ���ߣ������������滨��һ�Ƚ��յ�СС���ţ�
Ҳ��������ӳ�����Ե������дС��ſ�վ������С�������õ�Ҳ��
���������������Ƕ������巿��
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kanmen" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"houdong",
  "east" : __DIR__"inner-bedroom",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "east" && 
      me->query("family/master_id") != "yu shu" &&
      member_array("tian shu",me->parse_command_id_list())==-1 &&
      member_array("yu shu",me->parse_command_id_list())==-1)
    return notify_fail("����ֻ�ж��������Ų���������롣\n");
  return ::valid_leave(me, dir);
}
