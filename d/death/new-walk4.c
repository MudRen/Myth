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
  "east" : __DIR__"new-walk2",
  "west" : __DIR__"new-yinyangta",
  "north" : __DIR__"new-lunhui",
  "south": __DIR__"new-yinsi2",
]));
  set("hell", 1);

  setup();
}

