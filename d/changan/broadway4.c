//Cracked by Roath
// Room: /changan/broadway4.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��
�ϲ��غ���������ֱ����ƹ��������ǡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"broadway5",
  "north" : __DIR__"broadway3",
]));
  set("outdoors", 1);

    if(random(2))
	    set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
      else
	      set("objects", ([ "/d/obj/weapon/throwing/smallshi.c" : 1, ]));

  setup();
}






