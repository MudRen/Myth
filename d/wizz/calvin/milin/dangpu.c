//Cracked by Roath
#include <room.h>
inherit HOCKSHOP;

void create ()
{
  set ("short", "���ֵ���");
  set ("long", @LONG

�������ֵ���Ψһ��һ�ҵ����ˡ�������������ƽ�ųơ��ſڹ���һ
������ (paizi)�����ϰ��Ǹ��ܾ����������ˣ��������˽������ܿ�
���غ��㺮�ѣ����۾���ȴû��ʲôЦ�⣬�������ش������㡣
LONG);

  set("exits", ([ /* sizeof() == 1 */
       "north" : "/d/calvin/milin/milin5",    
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
�͹ٿ��������
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %  �䵱(pawn)              %
    %  ����(sell)              %
    %  ����(value)             %
    %  ���(retrieve stamp)    %
    %  ����(buy) ��list�鿴 �  %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
���ֻ��ͭǮ���������ƽ���Ʊ����ʯһ��ͨ�á�

"]));
  set("objects", ([ /* sizeof() == 1 */
//  "/u/calvin/npc/���ֵ����ϰ�" : 1,
]));
  set("no_clean_up", 1);

  setup();
}
int clean_up()
{
      return 0;
}
