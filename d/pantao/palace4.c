// created by snowcat.c 5/23/1997
// room: /d/pantao/palace4.c

inherit ROOM;

void create ()
{
  set ("short", "��徵�");
  set ("long", @LONG

                      ��徵��

���������������ʣ�����ǧ���������ơ��������ȣ�����
������͸�������Ĵأ�������ﰿ�衣��������Ԫ˧��ԱԱ��
�����������½�����ˣ�����ִ����ޡ����б�ɫ����̨����
һ�����������ҫĿ��������Ȼ������

LONG);

  set("exits", ([
        "north"      : __DIR__"palace3",
        "south"      : __DIR__"palace5",
      ]));

  set("objects", ([
         __DIR__"npc/tian4" : 1,
     ]));

  setup();
}

