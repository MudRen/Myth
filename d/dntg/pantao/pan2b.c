// created by snowcat.c 5/27/1997
// room: /d/pantao/pan2b.c

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
        "west"       : __DIR__"pan2a",
        "east"       : __DIR__"pan2c",
        "north"      : __DIR__"pan1b",  
        "south"      : __DIR__"pan3b",  
      ]));
  set("objects", ([
         __DIR__"npc/lishi4"  : 1,
         __DIR__"npc/lishi5"  : 1,
      ]));

  set("up","tree2");
  set("outdoors",1);
  setup();
}

