// created by snowcat.c 5/23/1997
// room: /d/pantao/palace7.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ب��");
  set ("long", @LONG

                      ��ب���

���������������ʣ�����ǧ���������ơ��������ȣ�����
������͸�������Ĵأ�������ﰿ�衣��������Ԫ˧��ԱԱ��
�����������½�����ˣ�����ִ����ޡ����б�ɫ����̨����
һ�����������ҫĿ��������Ȼ������

LONG);

  set("exits", ([
        "north"      : __DIR__"palace6",
        "south"      : __DIR__"fengb",
      ]));

  set("objects", ([
         __DIR__"npc/tian7" : 1,
     ]));

  setup();
}

void init()
{write(REF);}
