// created by snowcat.c 5/23/1997
// room: /d/pantao/palace5.c

inherit ROOM;

void create ()
{
  set ("short", "Ϧ����");
  set ("long", @LONG

                      ��Ϧ�����

���������������ʣ�����ǧ���������ơ��������ȣ�����
������͸�������Ĵأ�������ﰿ�衣��������Ԫ˧��ԱԱ��
�����������½�����ˣ�����ִ����ޡ����б�ɫ����̨����
һ�����������ҫĿ��������Ȼ������

LONG);

  set("exits", ([
        "north"      : __DIR__"palace4",
        "south"      : __DIR__"palace6",
      ]));

  set("objects", ([
         __DIR__"npc/tian5" : 1,
     ]));

  setup();
}

