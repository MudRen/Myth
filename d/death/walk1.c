// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "��˾");
  set ("long", @LONG

����������ܵظ�֮�У�ż������������������˾��ǣ��Щ����
��������������ȥ����Χ��һ������¥�󹬵������Ҳ�൱�ĸ�
���ûʣ���ֵ��Ƕ���һ�ȶ��Ž𶤵ĺ�ľ�ź�һ�������ż���
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room2",
  "west" : __DIR__"room1",
  "north" : __DIR__"walk2",
  "south": __DIR__"zhengtang",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/genggui" : 1,
//  __DIR__"npc/zhangmen" : 1,
]));

  setup();
}
