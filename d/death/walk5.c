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
  "south" : __DIR__"walk4",
  "west" : __DIR__"room9",
  "north" : __DIR__"walk6",
]));
  set("hell", 1);
  set("out_doors", 1);

  setup();
}
