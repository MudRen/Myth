// Room: /d/jjf/dining_room.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�����м���һ�Ŵ����ӣ��������������ʮ���ˡ����ӵ�һ��
ͨ����������һ�߿���ȥ���������������˶�ʱ���������ﶼ����
�£��ɴ���ǰԺ�յ���¶�����硣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kitchen_road1",
  "west" : __DIR__"keting",
]));

  setup();
}
