//Cracked by Roath
// Room: /changan/broadway1.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��
�ϲ��غ���������ֱ����ƹ��������ǡ�������һ�����С
·����֪ͨ��δ���
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"fendui.c",
  //"west" : "/d/moon/xiaolu3",
  "south" : __DIR__"zhongnan",
  "north" : __DIR__"sbridge",
  "west" : __DIR__"binyiguan.c",
]));
  set("outdoors", 2);

  if(random(2))
    set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
  else
    set("objects", ([ "/d/obj/weapon/throwing/smallshi.c" : 1, ]));

  setup();
}






