//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "ˮ½���");
  set ("long", @LONG

����̨�ĺ��潨����һ���ߴ�ĵ����ǰ�����˾޴��̨�ӣ�����
������衣����Ϸ�����һ�����ң���ˮ½��ᡱ��ˮ½���Ļ᳡
��һЩ��������š�

LONG);

  set("exits", ([
        "north" : __DIR__"yuwang3",
        "southwest" : __DIR__"pudu",
        "south" : __DIR__"jixian",
        "southeast" : __DIR__"ee",
        "southup" : __DIR__"gate",
      ]));
  set("objects", ([
        __DIR__"npc/zu" :  4,
      ]));

  set("outdoors", __DIR__);

  setup();
}


