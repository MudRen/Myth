//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ϼ������������ǧ�أ��������ƣ����������������һ
�޴�Ľ𶤲ؾ����Ա���һ��������ľ���������л���ϻ��
�����Ÿ��ֺ�ǩ��

LONG);

  set("exits", ([
        "down"   : __DIR__"baoge1",
      ]));
  set("objects", ([
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

