//changan city

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short","���µ�һ��" );
        set ("long", @LONG

����һ���а�����ʷ�����ֺ����У��ഫ����Ϊ���������������͢
�䱦�������ױ�Ϊ�������¡����µ�һ�������Ӵ�����������������
���������ﲻ�������е��ſڹ���һ������(paizi)��
LONG);
        set("item_desc", ([
                "paizi": @TEXT
����������������н���ȡ������Ǯ5%�������ѡ�

paimai ��Ʒ with Ǯ��������Ϊ��λ�� 
paimailist         ����ѯ��ǰ��������Ʒ
yao                �� ȡ���Լ��Ķ���

bidd Ǯ��     ��  �μӾ���

TEXT
        ]) );

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"bank",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/paimaishi" : 1,
        ]));


//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
}
