// created by snowcat.c 5/23/1997
// room: /d/pantao/palace1.c

inherit ROOM;

void create ()
{
  set ("short", "��Ǭ��");
  set ("long", @LONG

                      ����Ǭ���

���������������ʣ�����ǧ���������ơ��������ȣ�����
������͸�������Ĵأ�������ﰿ�衣��������Ԫ˧��ԱԱ��
�����������½�����ˣ�����ִ����ޡ����б�ɫ����̨����
һ�����������ҫĿ��������Ȼ������

LONG);

  set("exits", ([
        "north"      : __DIR__"yaob",
        "south"      : __DIR__"palace2",
      ]));

  set("objects", ([
         __DIR__"npc/tian1"  : 1,
     ]));

  setup();
}

