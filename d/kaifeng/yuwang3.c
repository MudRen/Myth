//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����̨");
  set ("long", @LONG

�ߴ������̨���������ϣ���������ɫ�����֣����ɴ�������д���
��Ƿ�������̨ׯ�����£�̨�����Ŵ�С��ʯ�飬������һ���ͨ��
̨�⣬�ϱ���һ�����

LONG);

  set("exits", ([
        "westdown" : __DIR__"yuwang2",
        "south" : __DIR__"shuilu",
      ]));
  set("objects", ([
        __DIR__"npc/zu" :  2,
      ]));

  set("outdoors", __DIR__);

  setup();
}


