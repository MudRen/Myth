//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

Ҫ������ñ����͵��ҵ����ո�ǿ�Ĺ������������
Զ�������ı����������ӣ�������ϰ���԰���ӹ�
��������������������ϡ�
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "west" : "/d/qujing/zhuzi/zhuzi3",
        ]));
        set("objects", ([  
                __DIR__"npc/boss" : 1,
        ])); 
        setup();
}
