//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����ͤ");
  set ("long", @LONG

����ͤ��Ʈ��һ������ζ�����ߵ�ͤ�ǹ���һֻ����������������
���Ÿ衣ͤ���Ϲ���һ��ϸ��ɽˮ����ͤ����һ�������Ρ��ϱ���ͨ
������ͤ���š�

LONG);

  set("exits", ([
        "south" : __DIR__"yulan",
      ]));
  set("objects", ([
        __DIR__"npc/yahuan" :  1,
//        __DIR__"npc/cuilan" :  1,
      ]));

  setup();
}


