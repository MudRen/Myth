//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "��Э��");
        set ("long", @LONG

��Э�������ڷ羰��ٳ����ˮ֮������Ҫ�Ҹ��ù�����
�������������ԡ�
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "south" : "/d/changan/wside5",
        ]));
        set("objects", ([   
                __DIR__"npc/kuangzhang" : 1,
        ])); 
        setup();
}
