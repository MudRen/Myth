// Room: some place in ��ţ����
// inside1.c

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

Ժ�м��󣬴Ӵ���ȥ����������¥��һ�����鹬���ڣ�˵����
�Ǿ����ľӡ�Ժ�����Ÿ����ɻ���ݣ�Ҳ�Ǿ��ķֻ�����ɫ���ġ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"houyuan",
  "west" : __DIR__"inside5",
  "south" : __DIR__"gate1",
  "northup" : __DIR__"jingtang",
]));
  set("outdoors", 1);

  setup();
}
