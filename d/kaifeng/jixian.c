//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���ͳ�");
  set ("long", @LONG

���ͳ��Ĵ�����һ����ʯ��̨����̨�϶˶������ط���һ������ǩ�У�
������Ž�ǩ����̨��������¯�������������̡����ı�����һ����
�ţ�����������ͨ�������ĳ���

LONG);

  set("exits", ([
        "north" : __DIR__"shuilu",
        "west" : __DIR__"pudu",
        "east" : __DIR__"ee",
      ]));
  set("objects", ([
        __DIR__"npc/people" :  3,
       "/d/quest/kaifeng/chen" :  1,
      ]));
  set("no_fight",1);

  setup();
}


