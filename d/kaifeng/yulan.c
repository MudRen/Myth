//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����ͤ");
  set ("long", @LONG

����ͤ����ɫ��������������ǽ����һ�컨�񣬼�������ݴ��ϴ���
����������һ��������������һ���񻨱�Ͳһ�����⡣ͤ���ϱ�����
��ͤ�������е�ͨ�����ͤ��

LONG);

  set("exits", ([
        "north" : __DIR__"cuilan",
        "south" : __DIR__"xianglan",
      ]));
  set("objects", ([
        __DIR__"npc/yahuan" :  1,
//        __DIR__"npc/yulan" :  1,
      ]));

  setup();
}


