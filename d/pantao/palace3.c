// created by snowcat.c 5/23/1997
// room: /d/pantao/palace3.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

                      ��������

���������������ʣ�����ǧ���������ơ��������ȣ�����
������͸�������Ĵأ�������ﰿ�衣��������Ԫ˧��ԱԱ��
�����������½�����ˣ�����ִ����ޡ����б�ɫ����̨����
һ�����������ҫĿ��������Ȼ������

LONG);

  set("exits", ([
        "north"      : __DIR__"palace2",
        "south"      : __DIR__"palace4",
      ]));

  set("objects", ([
         __DIR__"npc/tian3" : 1,
     ]));

  setup();
}

