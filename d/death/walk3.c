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

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"walk2",
  "east" : __DIR__"room5",
  "west" : __DIR__"room6",
  "north" : __DIR__"walk4",
]));
  set("hell", 1);

  setup();
}
