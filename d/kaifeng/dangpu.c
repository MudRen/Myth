//Cracked by Roath
#include <room.h>

inherit HOCKSHOP;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������������һ�ҵ��̡����ӵ��ſ��Ϸ�����һ�����ġ�������
���ƣ�������һ�߸ߵĳ���̨�����ϰ���������������̵�ǽ����һ
��(bian)��������Ң����֡�

LONG);

  set("exits", ([
    "west" : __DIR__"yao3",
  ]));
  set("item_desc", ([ /* sizeof() == 1 */
    "bian" : "
�͹ٿ����ڱ����̣�
  �䵱(pawn)         
  ����(sell)       
  ����(value)         
  ���(retrieve stamp) 
  ����(buy) ��list�鿴��

  "]));
  set("objects", ([
    __DIR__"npc/xu" : 1,
  ]));
  set("no_clean_up", 1);
 set("noget_room",1);

  setup();
}

int clean_up()
{
      return 0;
}


