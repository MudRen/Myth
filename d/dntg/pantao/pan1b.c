// created by snowcat.c 5/27/1997
// room: /d/pantao/pan1b.c

inherit ROOM;
inherit "/d/dntg/pantao/climbtree.c";

void create ()
{
  set ("short", "��ǧ�����԰");
  set ("long", @LONG

���԰�ڻ���Ҷ�̣�زز���ƻ�ӯ�����ſ�֦֦��ѹ֦��ֻ��
�ǣ�ʱ��ʱ��ǧ���죬�����޶����س٣�����ģ�����������
�����ģ�������Ƥ���ø���֬�����̣�ӳ���Ե��ˡ�

LONG);

  set("exits", ([
        "west"       : __DIR__"pan1a",
        "east"       : __DIR__"pan1c",
//         "north"      : __DIR__"yaoa",  
        "south"      : __DIR__"pan2b",  
      ]));
  set("objects", ([
         __DIR__"npc/lishi1"  : 1,
         __DIR__"npc/lishi2"  : 1,
         __DIR__"npc/lishi3"  : 1,
     ]));
  set("up","tree1");

  set("outdoors",1);
  setup();
}

