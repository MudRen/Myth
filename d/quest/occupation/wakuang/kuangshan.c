// ְҵ���� ���ڿ�
// created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
�����һ���������̵Ŀ�ɽ��ɽ��͵������ܿ����ö�ö�Ŀ�����
��ؼ�Ϊ�ḻ����˵��������ڳ��������¼���������װ���õĺÿ�ʯ��
������Ӧ�������ԣ�
LONG
        );

        set("exits", ([   
                "west" : "/d/changan/eside5",
        ]));
        set("objects", ([   
                __DIR__"kuangmai" : 5,
                __DIR__"npc/xunbu" : 2,
        ])); 
        set("no_fight",1);
        set("no_magic",1);
        set("no_steal",1);
        setup();
}

