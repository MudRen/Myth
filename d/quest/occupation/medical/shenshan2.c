// ְҵ���� ��ҽʦ��
// created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
�����һ���������̵�ɽ�֣������ͱ��Ͽ��Կ���������಻֪����С
�ݣ�����Щ�ݿ���ȥ����ͨ�����Ǿ�˵�����ҽʦ�Ƕ�����Щ
С��Ϊ���ԭ��������������ȥ��ǿ���ҩƷ��ԭ�ϡ�
LONG
        );

        set("exits", ([  
                "southwest" : __DIR__"shenshan",
                "south" : __DIR__"shenshan3",
        ]));
        set("objects", ([  
        ])); 
        setup();
}
