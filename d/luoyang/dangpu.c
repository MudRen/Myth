#include <room.h>
inherit HOCKSHOP;

void create()
{
        set("short", "����");
        set("long", @LONG
����������������һ�ҵ����ˣ�������������ƽ�ųơ�����������
�����ġ������֣�ʹ��һĿ��Ȼ�������ſں����һ��������ߵĹ�̨��
�������ڵ�һ�е��˸�����ʵʵ���������һ������ (paizi)���������
��Щ��ͷ����ԣ���˳����ĵط���
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "down" : __DIR__"cunchu",
                "east" : __DIR__"sroad1",
        ]));
        
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
�͹ٿ��������
    ������������������������������
    ��  �䵱(pawn)              ��
    ��  ����(sell)              ��
    ��  ����(value)             ��
    ��  ���(retrieve stamp)    ��
    ��  ����(buy) ��list�鿴��  ��
    ������������������������������
���ֻ��ͭǮ���������ƽ���Ʊһ��ͨ�á�

"]));

        set("objects", ([
                __DIR__"npc/qi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
int clean_up()
{
      return 0;
}

