//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���ฮ");
  set ("long", @LONG

���ฮ���ɫ���㣬�����ǻ�ʯ��ͭ�ذ壬��������˿�������ƣ���
������һʽ����ľ̫ʦ�Ρ���˵����������������̫��һ�ѣ�̫��
���������ฮרӪ�������ף�������ξ�ٹ����ฮ�ĳ��͡�

LONG);

  set("exits", ([
        "east" : __DIR__"shun2",
        "west" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  2,
      ]));

  setup();
}


