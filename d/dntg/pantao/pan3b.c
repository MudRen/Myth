// created by snowcat.c 5/27/1997
// room: /d/pantao/pan3b.c

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
        "west"       : __DIR__"pan3a",
        "east"       : __DIR__"pan3c",
        "north"      : __DIR__"pan2b",  
//         "south"      : __DIR__"fenga",  
      ]));
  set("up","tree3");
  set("objects", ([
         __DIR__"npc/lishi6"  : 1,
         __DIR__"npc/lishi7"  : 1,
      ]));

  set("outdoors",1);
  setup();
}

