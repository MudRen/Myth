inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "�������" );
  set ("long", @LONG

������ݵ����ã�һ�ж���������������û�е���ʲôҲ���������
��Լ�������ų��Σ�����ǽ�Ϲ�һ����(qi)��
LONG);
set("item_desc",(["qi":"
        ����������������
        ����ȭ����ʡ����
        ���������ܵУ���
        ����������������\n"
]));
        set("objects", ([
                __DIR__"npc/fan": 1, 
                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"wuguan",
]));
  setup();
}

