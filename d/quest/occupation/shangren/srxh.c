//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "����Э��");
        set ("long", @LONG

����Э����������ҵ��ϢŨ������ù�������ÿ�춼��ͥ���У�
����ϣ����Ϊһ����Ǯ���Ǻܶ��˵�Ը���ɡ�
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "east" : "/d/qujing/tianzhu/dalu5",
        ]));
        set("objects", ([  
                __DIR__"npc/huizhang" : 1,
        ])); 
        setup();
}
