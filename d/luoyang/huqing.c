#include <ansi.h>
inherit BANK;

void reset_balance(object me);

void create ()
{
        set ("short","�ĺ�Ǯׯ" );
        set ("long", @LONG

�ĺ�Ǯׯ������������Ǯׯ��Ҳ�Ƿǳ����������ֺš��ϰ�������
����һ�޼֣��춥���˺�ѩԴ����ɽ�����ϣ����Ǯׯ������үү��үү
��үү��үү�Ǳ���ʼ����һֱ��������������ǳ��ã���ȫ������
���зֵꡣ�����е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ������(paizi)��
LONG);
        set("item_desc", ([
                "paizi": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

account         ���ʡ�
deposit         ��
withdraw        ȡ�
convert         �һ�Ǯ�ҡ�

TEXT
        ]) );

        set("exits", ([
                "north" : __DIR__"wroad1",
        ]));

        set("objects", ([
                __DIR__"npc/hu" : 1
        ]));

        set("no_clean_up", 0);
        setup();
}
