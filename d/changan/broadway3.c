//Cracked by Roath
// Room: /changan/broadway3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��
�ϲ��غ���������ֱ����ƹ��������ǡ�������һ����ʯ·��
������ͨ���������
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad1",
  "south" : __DIR__"broadway4",
  "north" : __DIR__"nanyue",
/*
lost add
����û�У���ʱ����ˣ�˭�������ٴ�
  "east" :"/d/leox/tianpeng/ye4",
*/
]));
  set("outdoors", 1);

    if(random(2))
	    set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
      else
	      set("objects", ([ "/d/obj/weapon/throwing/smallshi.c" : 1, ]));

  setup();
}






