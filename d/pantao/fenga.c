// created by snowcat.c 5/23/1997
// room: /d/pantao/fenga.c

inherit ROOM;

void create ()
{
  set ("short", "�ʷ���");
  set ("long", @LONG

����̨����Ϊ�ʷ��������ڱ������ɣ������Ų�����յ����
����������Ů���������ɴ�£����ǳ����á����⿪��ǧǧ��
��л��������

LONG);

  set("exits", ([
        "east"  : __DIR__"fengb",
      ]));

  set("objects", ([
         __DIR__"npc/female" : 1,
      ]));

  setup();
}

