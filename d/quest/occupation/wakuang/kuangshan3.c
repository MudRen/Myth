// kuangshan ��ɽ
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
                "eastdown" : "/d/qujing/pingding/shan8", 
        ]));
        set("objects", ([   
                __DIR__"kuangmai" : 10,
        ])); 
        set("no_fight",1);
        set("no_magic",1);
        set("no_steal",1);
        setup();
}
